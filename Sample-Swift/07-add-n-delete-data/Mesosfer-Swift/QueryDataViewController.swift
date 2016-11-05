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
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if segue.identifier == "segueAdd" {
            let formView = segue.destination as! FormDataViewController
            formView.delegate = self
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
    
    override func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCellEditingStyle, forRowAt indexPath: IndexPath) {
        if editingStyle == .delete {
            if let datas = self.datas {
                let data = datas[indexPath.section]
                data.deleteAsync(block: { (succeeded, error) in
                    if succeeded {
                        // remove deleted data from array
                        self.datas!.remove(at: indexPath.section)
                        // update table data
                        self.tableView.beginUpdates()
                        self.tableView.deleteSections(IndexSet(integer: indexPath.section), with: .automatic)
                        self.tableView.endUpdates()
                    } else {
                        self.showError(title: "Delete data failed", error: error as! NSError)
                    }
                })
            }
        }
    }
}

extension QueryDataViewController : FormDataViewControllerDelegate {
    func onSavedData(beacon: MFData, isNewData: Bool) {
        if isNewData {
            // append new saved data into array
            if self.datas == nil {
                self.datas = [MFData]()
            }
            self.datas!.append(beacon)
            // update table data
            self.tableView.beginUpdates()
            self.tableView.insertSections(IndexSet(integer: self.datas!.count - 1), with: .automatic)
            self.tableView.endUpdates()
        }
    }
}
