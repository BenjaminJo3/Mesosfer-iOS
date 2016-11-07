/**
 * Copyright (c) 2016, Mesosfer
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

import Foundation
import UIKit
import Mesosfer

class QueryUserViewController: UITableViewController {
    
    var users: [MFUser]?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.tableView.estimatedRowHeight = 100
        self.tableView.rowHeight = UITableViewAutomaticDimension
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        self.queryUser()
    }
    
    func queryUser(firstname: String? = nil) {
        let query = MFUser.query()
        if let firstname = firstname {
            query.whereKey("firstname", equalTo: firstname)
        }
        query.findAsync { (users, error) in
            if let e = error as? NSError {
                self.showError(title: "Query user failed", error: e)
                return
            }
            
            if let users = users as? [MFUser] {
                self.users = users
                self.tableView.reloadData()
            }
        }
    }
}

extension QueryUserViewController {
    override func numberOfSections(in tableView: UITableView) -> Int {
        if let users = self.users {
            return users.count
        }
        return 0
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return 1
    }
    
    override func tableView(_ tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
        if let users = self.users {
            return users[section].objectId
        }
        return nil
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "cellUser", for: indexPath)
        
        if let users = self.users {
            let user = users[indexPath.section]
            
            if let dict = user.dictionary() as? [String:AnyObject] {
                cell.textLabel?.text = "\(dict)"
            }
        }
        
        return cell
    }
}

extension QueryUserViewController: UISearchBarDelegate {
    func searchBarSearchButtonClicked(_ searchBar: UISearchBar) {
        searchBar.showsCancelButton = true
        self.queryUser(firstname: searchBar.text)
    }
    
    func searchBarCancelButtonClicked(_ searchBar: UISearchBar) {
        searchBar.showsCancelButton = false
        searchBar.text = nil
        self.queryUser()
    }
}
