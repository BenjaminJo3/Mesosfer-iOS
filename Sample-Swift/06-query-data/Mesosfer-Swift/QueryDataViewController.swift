//
//  QueryDataViewController.swift
//  Mesosfer-Swift
//
//  Created by Eyro Labs on 11/5/16.
//  Copyright © 2016 Eyro Labs. All rights reserved.
//

import Foundation
import UIKit
import Mesosfer

class QueryDataViewController: UITableViewController {
    var datas: [MFData]?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.tableView.estimatedRowHeight = 100
        self.tableView.rowHeight = UITableViewAutomaticDimension
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        self.querydata()
    }
    
    func querydata() {
        let bucket = "Beacon"
        MFData.query(withBucket: bucket).findAsync { (datas, error) in
            if let e = error as? NSError {
                self.showError(title: "Query data failed", error: e)
                return
            }
            
            if let datas = datas as? [MFData] {
                self.title = "Query '\(bucket)'"
                self.datas = datas
                self.tableView.reloadData()
            }
        }
    }
}

extension QueryDataViewController {
    override func numberOfSections(in tableView: UITableView) -> Int {
        if let datas = self.datas {
            return datas.count
        }
        return 0
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return 1
    }
    
    override func tableView(_ tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
        if let datas = self.datas {
            return datas[section].objectId
        }
        return nil
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "cellData", for: indexPath)
        
        if let datas = self.datas {
            let data = datas[indexPath.section]
            
            if let dict = data.dictionary() as? [String:AnyObject] {
                cell.textLabel?.text = "\(dict)"
            }
        }
        
        return cell
    }
}
