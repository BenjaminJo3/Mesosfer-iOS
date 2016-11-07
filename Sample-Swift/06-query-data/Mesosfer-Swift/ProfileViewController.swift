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

class ProfileViewController: UITableViewController {
    @IBOutlet weak var textEmail: UITextField!
    @IBOutlet weak var textFirstName: UITextField!
    @IBOutlet weak var textLastName: UITextField!
    @IBOutlet weak var textDateOfBirth: UITextField!
    @IBOutlet weak var textHeight: UITextField!
    @IBOutlet weak var textWeight: UITextField!
    @IBOutlet weak var switchIsMarried: UISwitch!
    @IBOutlet weak var textOldPassword: UITextField!
    @IBOutlet weak var textNewPassword: UITextField!
    @IBOutlet weak var textConfirmPassword: UITextField!
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        // reload user data and set into form
        self.reloadUserData()
    }
    
    func reloadUserData() {
        if let user = MFUser.currentUser() {
            self.textEmail.text = user.email
            self.textFirstName.text = user.firstname
            self.textLastName.text = user.lastname
            
            if let date = user.date(forKey: "dateOfBirth") {
                self.textDateOfBirth.text = MFDateFormatter.shared().string(from: date, isTimestamp: false)
            }
            self.textHeight.text = "\(user.double(forKey: "height"))"
            self.textWeight.text = "\(user.integer(forKey: "weight"))"
            self.switchIsMarried.isOn = user.boolean(forKey: "isMarried")
        }
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        // update profile
        if indexPath.section == 2 && indexPath.row == 0 {
            let email = self.textEmail.text
            let firstname = self.textFirstName.text
            let lastname = self.textLastName.text
            
            let dateOfBirth = self.textDateOfBirth.text
            let height = self.textHeight.text
            let weight = self.textWeight.text
            let isMarried = self.switchIsMarried.isOn
            
            if let user = MFUser.currentUser() {
                // set required field
                user.email = email
                user.firstname = firstname
                user.lastname = lastname
                // set custom field
                if let date = MFDateFormatter.shared().date(from: dateOfBirth!) {
                    user["dateOfBirth"] = date
                }
                user["height"] = Double(height!)
                user["weight"] = Int(weight!)
                user["isMarried"] = isMarried
                // update user data async
                user.saveAsync(block: { (succeeded, error) in
                    if let e = error as? NSError {
                        self.showError(title: "Failed to update profile", error: e)
                        return
                    }
                    
                    self.showAlert(title: "Profile updated", message: "Your profile's has been successfully updated.")
                })
            }
        } // change password
        else if indexPath.section == 4 && indexPath.row == 0 {
            let oldPassword = self.textOldPassword.text
            let newPassword = self.textNewPassword.text
            let confirmPassword = self.textConfirmPassword.text
            
            if oldPassword == newPassword {
                self.showAlert(message: "Old and new password are equal.")
                return
            }
            
            if newPassword != confirmPassword {
                self.showAlert(message: "new and confirm password are not equal.")
                return
            }
            
            if let user = MFUser.currentUser() {
                user.changePasswordAsync(withOldPassword: oldPassword!, newPassword: newPassword!, block: { (succeeded, error) in
                    if let e = error as? NSError {
                        self.showError(title: "Failed to change password", error: e)
                        return
                    }
                    
                    self.showAlert(message: "Password changed successfully.")
                })
            }
        }
    }
}
