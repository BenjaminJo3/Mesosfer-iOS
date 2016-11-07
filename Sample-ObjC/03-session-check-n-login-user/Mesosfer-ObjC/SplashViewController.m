/**
 * Copyright (c) 2016, Mesosfer
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import "SplashViewController.h"
#import <Mesosfer/Mesosfer.h>

@implementation SplashViewController

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    
    MFUser *user = [MFUser currentUser];
    if (user) {
        [self performSegueWithIdentifier:@"segueMain" sender:self];
    } else {
        [self performSegueWithIdentifier:@"segueLogin" sender:self];
    }
}

@end
