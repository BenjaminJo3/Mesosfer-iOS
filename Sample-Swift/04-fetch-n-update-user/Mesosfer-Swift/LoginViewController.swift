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

class LoginViewController: UIViewController {
    @IBOutlet weak var textEmailAddress: UITextField!
    @IBOutlet weak var textPassword: UITextField!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func handleLoginButton(_ sender: UIButton) {
        let email = self.textEmailAddress.text
        let password = self.textPassword.text
        
        MFUser.logInAsync(withEmail: email!, password: password!) { (user, error) in
            if let e = error as? NSError {
                self.showError(title: "Error login", error: e)
                return
            }
            
            // dismiss this controller
            self.dismiss(animated: true)
        }
    }
}
