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

extension UIViewController {
    func showAlert(title: String? = nil, message: String, handler: ((UIAlertAction) -> Swift.Void)? = nil) {
        let alert = UIAlertController(title: title, message: message, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "OK", style: .default, handler: handler))
        self.present(alert, animated: true, completion: {
            
        })
    }
    
    func showError(title: String, error: NSError, handler: ((UIAlertAction) -> Swift.Void)? = nil) {
        let message = "Code=\(error.code)\nDescription=\(error.localizedDescription)"
        self.showAlert(title: title, message: message, handler: handler)
    }
}
