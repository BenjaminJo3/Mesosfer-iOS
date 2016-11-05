//
//  ViewController.swift
//  Mesosfer-Swift
//
//  Created by Eyro Labs on 11/3/16.
//  Copyright © 2016 Eyro Labs. All rights reserved.
//

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

