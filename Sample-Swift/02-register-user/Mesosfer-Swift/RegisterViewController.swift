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

class RegisterViewController: UITableViewController {
    @IBOutlet weak var textEmail: UITextField!
    @IBOutlet weak var textPassword: UITextField!
    @IBOutlet weak var textFirstName: UITextField!
    @IBOutlet weak var textLastName: UITextField!
    @IBOutlet weak var textDateOfBirth: UITextField!
    @IBOutlet weak var textHeight: UITextField!
    @IBOutlet weak var textWeight: UITextField!
    @IBOutlet weak var switchIsMarried: UISwitch!
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        // handle register user clicked row
        if indexPath.section == 2 && indexPath.row == 0 {
            let email = self.textEmail.text
            let password = self.textPassword.text
            let firstname = self.textFirstName.text
            let lastname = self.textLastName.text
            
            let dateOfBirth = self.textDateOfBirth.text
            let height = self.textHeight.text
            let weight = self.textWeight.text
            let isMarried = self.switchIsMarried.isOn
            
            let user = MFUser()
            // set required field
            user.email = email
            user.password = password
            user.firstname = firstname
            user.lastname = lastname
            // set custom field
            if let date = MFDateFormatter.shared().date(from: dateOfBirth!) {
                user["dateOfBirth"] = date
            }
            user["height"] = Double(height!)
            user["weight"] = Int(weight!)
            user["isMarried"] = isMarried
            // register user async
            user.registerAsync(block: { (succeeded, error) in
                if succeeded {
                    self.showAlert(title: "Register Succeeded", message: "Thank you for registering on Mesosfer.")
                } else {
                    self.showError(title: "Register failed", error: (error as? NSError)!)
                }
            })
        }
    }
    
    @IBAction func closeButtonSelector(_ sender: UIBarButtonItem) {
        self.dismiss(animated: true)
    }
}
