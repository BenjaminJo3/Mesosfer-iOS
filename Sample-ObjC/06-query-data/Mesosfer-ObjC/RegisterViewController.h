/**
 * Copyright (c) 2016, Mesosfer
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <UIKit/UIKit.h>

@interface RegisterViewController : UITableViewController

@property (weak, nonatomic) IBOutlet UITextField *textEmail;
@property (weak, nonatomic) IBOutlet UITextField *textPassword;
@property (weak, nonatomic) IBOutlet UITextField *textFirstName;
@property (weak, nonatomic) IBOutlet UITextField *textLastName;
@property (weak, nonatomic) IBOutlet UITextField *textDateOfBirth;
@property (weak, nonatomic) IBOutlet UITextField *textHeight;
@property (weak, nonatomic) IBOutlet UITextField *textWeight;
@property (weak, nonatomic) IBOutlet UISwitch *switchIsMarried;

- (IBAction)closeButtonSelector:(UIBarButtonItem *)sender;

@end
