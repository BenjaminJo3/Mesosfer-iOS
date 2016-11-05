//
//  MainViewController.swift
//  Mesosfer-Swift
//
//  Created by Eyro Labs on 11/3/16.
//  Copyright © 2016 Eyro Labs. All rights reserved.
//

import Foundation
import UIKit
import Mesosfer

class MainViewController: UITableViewController {
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        // profile
        if indexPath.row == 2 {
            MFUser.logOutAsync(block: { (error) in
                if let e = error as? NSError {
                    self.showError(title: "Failed to Logout", error: e)
                    return
                }
                
                // successfully logout, dismiss main view controller
                self.dismiss(animated: true)
            })
        }
    }
}
