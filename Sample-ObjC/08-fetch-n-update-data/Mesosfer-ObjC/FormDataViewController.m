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

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    
    // fetch current updated data from Mesosfer cloud
    [self fetchData];
}

- (void)fetchData {
    if (self.beacon) {
        [self.beacon fetchAsyncWithBlock:^(MFData * _Nullable data, NSError * _Nullable error) {
            if (error) {
                [self showErrorWithTitle:@"Failed to fetch data" error:error handler:nil];
                return;
            }
            
            if (data) {
                self.beacon = data;
                [self setDataToForm];
            }
        }];
    }
}

- (void)setDataToForm {
    self.textUUID.text = [self.beacon stringForKey:@"proximityUUID"];
    self.textMajor.text = [NSString stringWithFormat:@"%@", [self.beacon numberForKey:@"major"]];
    self.textMinor.text = [NSString stringWithFormat:@"%@", [self.beacon numberForKey:@"minor"]];
    self.switchIsActive.on = [self.beacon booleanForKey:@"isActive"];
}

- (IBAction)saveSelector:(UIBarButtonItem *)sender {
    NSString *bucket = @"Beacon";
    NSString *proximityUUID = self.textUUID.text;
    NSString *major = self.textMajor.text;
    NSString *minor = self.textMinor.text;
    BOOL isActive = self.switchIsActive.on;
    NSDate *timestamp = [NSDate date];
    
    MFData *beacon;
    if (self.beacon) {
        beacon = self.beacon;
    } else {
        beacon = [MFData dataWithBucket:bucket];
    }
    beacon[@"proximityUUID"] = proximityUUID;
    beacon[@"major"] = [NSNumber numberWithInt:[major intValue]];
    beacon[@"minor"] = [NSNumber numberWithInt:[minor intValue]];
    beacon[@"isActive"] = [NSNumber numberWithBool:isActive];
    beacon[@"timestamp"] = timestamp;
    [beacon saveAsyncWithBlock:^(BOOL succeeded, NSError * _Nullable error) {
        if (succeeded) {
            [self showAlertWithTitle:nil message:@"Data beacon saved" handler:^(UIAlertAction * _Nonnull action) {
                if (self.delegate) {
                    [self.delegate onSavedDataBeacon:beacon isNewData:self.beacon == nil];
                    [self.navigationController popViewControllerAnimated:YES];
                }
            }];
        } else {
            [self showErrorWithTitle:@"Failed to save data" error:error handler:nil];
        }
    }];
}

@end
