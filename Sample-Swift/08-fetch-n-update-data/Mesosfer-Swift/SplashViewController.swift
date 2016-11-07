/**
 * Copyright (c) 2016, Mesosfer
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

import UIKit
import Mesosfer

class SplashViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        if let user = MFUser.currentUser() {
            // found session user, fetch the latest data from Mesosfer cloud
            user.fetchAsync(block: { (user, error) in
                if let e = error as? NSError {
                    self.showError(title: "Error fetching user", error: e)
                    return
                }
                
                // user successfully fetched
                self.performSegue(withIdentifier: "segueMain", sender: self)
            })
            
        } else {
            // session user not found
            self.performSegue(withIdentifier: "segueLogin", sender: self)
        }
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

