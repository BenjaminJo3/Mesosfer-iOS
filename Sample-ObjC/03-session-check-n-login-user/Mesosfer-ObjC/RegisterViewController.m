/**
 * Copyright (c) 2016, Mesosfer
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import "RegisterViewController.h"
#import "UIViewController+Helper.h"
#import <Mesosfer/Mesosfer.h>

@implementation RegisterViewController

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    // handle register user clicked row
    if (indexPath.section == 2 && indexPath.row == 0) {
        NSString *email = self.textEmail.text;
        NSString *password = self.textPassword.text;
        NSString *firstname = self.textFirstName.text;
        NSString *lastname = self.textLastName.text;
        
        NSDate *dateOfBirth = [[MFDateFormatter sharedFormatter] dateFromString:self.textDateOfBirth.text];
        NSNumber *height = [NSNumber numberWithDouble:[self.textHeight.text doubleValue]];
        NSNumber *weight = [NSNumber numberWithInt:[self.textWeight.text intValue]];
        NSNumber *isMarried = [NSNumber numberWithBool:self.switchIsMarried.isOn];
        
        MFUser *user = [MFUser user];
        // set required field
        user.email = email;
        user.password = password;
        user.firstname = firstname;
        user.lastname = lastname;
        // set custom field
        if (dateOfBirth) {
            user[@"dateOfBirth"] = dateOfBirth;
        }
        if (height) {
            user[@"height"] = height;
        }
        if (weight) {
            user[@"weight"] = weight;
        }
        if (isMarried) {
            user[@"isMarried"] = isMarried;
        }
        
        // register user async
        [user registerAsyncWithBlock:^(BOOL succeeded, NSError * _Nullable error) {
            if (succeeded) {
                [self showAlertWithTitle:@"Register Succeeded"
                                 message:@"Thank you for registering on Mesosfer." handler:nil];
            } else {
                [self showErrorWithTitle:@"Register failed" error:error handler:nil];
            }
        }];
    }
}

- (IBAction)closeButtonSelector:(UIBarButtonItem *)sender {
    [self dismissViewControllerAnimated:YES completion:nil];
}
@end
