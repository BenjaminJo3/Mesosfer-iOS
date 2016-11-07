/**
 * Copyright (c) 2016, Mesosfer
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import "MainViewController.h"
#import "UIViewController+Helper.h"
#import <Mesosfer/Mesosfer.h>

@interface MainViewController ()

@end

@implementation MainViewController

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    if (indexPath.row == 3) {
        [MFUser logOutAsyncWithBlock:^(NSError * _Nullable error) {
            if (error) {
                [self showErrorWithTitle:@"Failed to Logout" error:error handler:nil];
                return;
            }
            
            // successfully logout, dismiss main view controller
            [self dismissViewControllerAnimated:YES completion:nil];
        }];
    }
}

@end
