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
