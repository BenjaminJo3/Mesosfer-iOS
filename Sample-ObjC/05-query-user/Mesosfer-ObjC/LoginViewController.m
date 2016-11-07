/**
 * Copyright (c) 2016, Mesosfer
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import "LoginViewController.h"
#import "UIViewController+Helper.h"
#import <Mesosfer/Mesosfer.h>

@implementation LoginViewController

- (IBAction)handleLoginButton:(UIButton *)sender {
    NSString *email = self.textEmailAddress.text;
    NSString *password = self.textPassword.text;
    
    [MFUser logInAsyncWithEmail:email password:password block:^(MFUser * _Nullable user, NSError * _Nullable error) {
        if (error) {
            [self showErrorWithTitle:@"Error login" error:error handler:nil];
            return;
        }
        
        [self dismissViewControllerAnimated:YES completion:nil];
    }];
}
@end
