/**
 * Copyright (c) 2016, Mesosfer
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import "SplashViewController.h"
#import "UIViewController+Helper.h"
#import <Mesosfer/Mesosfer.h>

@implementation SplashViewController

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    
    MFUser *user = [MFUser currentUser];
    if (user) {
        [user fetchAsyncWithBlock:^(MFUser * _Nullable user, NSError * _Nullable error) {
            if (error) {
                [self showErrorWithTitle:@"Error fetching user" error:error handler:nil];
                return;
            }
            
            [self performSegueWithIdentifier:@"segueMain" sender:self];
        }];
    } else {
        [self performSegueWithIdentifier:@"segueLogin" sender:self];
    }
}

- (void)coding {
    MFData *data;
    [data saveAsyncWithBlock:^(BOOL succeeded, NSError * _Nullable error) {
        if (succeeded) {
            // data updated, show success message
        } else {
            // failed to update data, show error message
        }
    }];
}

@end
