/**
 * Copyright (c) 2016, Mesosfer
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import "FormDataViewController.h"
#import "UIViewController+Helper.h"
#import <Mesosfer/Mesosfer.h>

@interface FormDataViewController ()

@end

@implementation FormDataViewController

- (IBAction)saveSelector:(UIBarButtonItem *)sender {
    NSString *bucket = @"Beacon";
    NSString *proximityUUID = self.textUUID.text;
    NSString *major = self.textMajor.text;
    NSString *minor = self.textMinor.text;
    BOOL isActive = self.switchIsActive.on;
    NSDate *timestamp = [NSDate date];
    
    MFData *beacon = [MFData dataWithBucket:bucket];
    beacon[@"proximityUUID"] = proximityUUID;
    beacon[@"major"] = [NSNumber numberWithInt:[major intValue]];
    beacon[@"minor"] = [NSNumber numberWithInt:[minor intValue]];
    beacon[@"isActive"] = [NSNumber numberWithBool:isActive];
    beacon[@"timestamp"] = timestamp;
    [beacon saveAsyncWithBlock:^(BOOL succeeded, NSError * _Nullable error) {
        if (succeeded) {
            [self showAlertWithTitle:nil message:@"Data beacon saved" handler:^(UIAlertAction * _Nonnull action) {
                if (self.delegate) {
                    [self.delegate onSavedDataBeacon:beacon isNewData:YES];
                    [self.navigationController popViewControllerAnimated:YES];
                }
            }];
        } else {
            [self showErrorWithTitle:@"Failed to save data" error:error handler:nil];
        }
    }];
}

@end
