/**
 * Copyright (c) 2016, Mesosfer
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import "ProfileViewController.h"
#import "UIViewController+Helper.h"
#import <Mesosfer/Mesosfer.h>

@implementation ProfileViewController

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    
    [self reloadUserData];
}

- (void)reloadUserData {
    MFUser *user = [MFUser currentUser];
    if (user) {
        self.textEmail.text = user.email;
        self.textFirstName.text = user.firstname;
        self.textLastName.text = user.lastname;
        
        NSDate *date = [user dateForKey:@"dateOfBirth"];
        if (date) {
            self.textDateOfBirth.text = [[MFDateFormatter sharedFormatter] stringFromDate:date isTimestamp:NO];
        }
        self.textHeight.text = [NSString stringWithFormat:@"%@", [user numberForKey:@"height"]];
        self.textWeight.text = [NSString stringWithFormat:@"%@", [user numberForKey:@"weight"]];
        self.switchIsMarried.on = [user booleanForKey:@"isMarried"];
    }
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    // update profile
    if (indexPath.section == 2 && indexPath.row == 0) {
        NSString *email = self.textEmail.text;
        NSString *firstname = self.textFirstName.text;
        NSString *lastname = self.textLastName.text;
        
        NSString *dateOfBirth = self.textDateOfBirth.text;
        NSString *height = self.textHeight.text;
        NSString *weight = self.textWeight.text;
        BOOL isMarried = self.switchIsMarried.on;
        
        MFUser *user = [MFUser currentUser];
        if (user) {
            // set required field
            user.email = email;
            user.firstname = firstname;
            user.lastname = lastname;
            // set custom field
            NSDate *date = [[MFDateFormatter sharedFormatter] dateFromString:dateOfBirth];
            if (date) {
                user[@"dateOfBirth"] = date;
            }
            user[@"height"] = [NSNumber numberWithDouble:[height doubleValue]];
            user[@"weight"] = [NSNumber numberWithInt:[weight intValue]];
            user[@"isMarried"] = [NSNumber numberWithBool:isMarried];
            // update user data async
            [user saveAsyncWithBlock:^(BOOL succeeded, NSError * _Nullable error) {
                if (error) {
                    [self showErrorWithTitle:@"Failed to update profile" error:error handler:nil];
                    return;
                }
                
                [self showAlertWithTitle:@"Profile updated"
                                 message:@"Your profile's has been successfully updated." handler:nil];
            }];
        }
    } // change password
    else if (indexPath.section == 4 && indexPath.row == 0) {
        NSString *oldPassword = self.textOldPassword.text;
        NSString *newPassword = self.textNewPassword.text;
        NSString *confirmPassword = self.textConfirmPassword.text;
        
        if ([oldPassword isEqualToString:newPassword]) {
            [self showAlertWithTitle:nil message:@"Old and new password are equal." handler:nil];
            return;
        }
        
        if (![newPassword isEqualToString:confirmPassword]) {
            [self showAlertWithTitle:nil message:@"New and confirm password are not equal." handler:nil];
            return;
        }
        
        MFUser *user = [MFUser currentUser];
        if (user) {
            [user changePasswordAsyncWithOldPassword:oldPassword
                                         newPassword:newPassword
                                               block:^(BOOL succeeded, NSError * _Nullable error) {
                if (error) {
                    [self showErrorWithTitle:@"Failed to change password" error:error handler:nil];
                    return;
                }
                
                [self showAlertWithTitle:nil message:@"Password changed successfully." handler:nil];
            }];
        }
    }
}

@end
