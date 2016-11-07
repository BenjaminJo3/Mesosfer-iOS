/**
 * Copyright (c) 2016, Mesosfer
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <UIKit/UIKit.h>

@interface LoginViewController : UIViewController

@property (weak, nonatomic) IBOutlet UITextField *textEmailAddress;
@property (weak, nonatomic) IBOutlet UITextField *textPassword;

- (IBAction)handleLoginButton:(UIButton *)sender;
@end
