/**
 * Copyright (c) 2016, Mesosfer
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import "UIViewController+Helper.h"

@implementation UIViewController(Helper)

- (void) showAlertWithTitle:(NSString*_Nullable)title
                    message:(NSString*_Nonnull)message
                    handler:(void (^ __nullable)(UIAlertAction *_Nonnull action))handler {
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:title
                                                                   message:message
                                                            preferredStyle:UIAlertControllerStyleAlert];
    [alert addAction:[UIAlertAction actionWithTitle:@"OK"
                                              style:UIAlertActionStyleCancel
                                            handler:handler]];
    [self presentViewController:alert animated:YES completion:^{
        
    }];
}

- (void) showErrorWithTitle:(NSString*_Nonnull)title
                      error:(NSError*_Nonnull)error
                    handler:(void (^ __nullable)(UIAlertAction *_Nonnull action))handler {
    NSString *message = [NSString stringWithFormat:@"Code=%ld\nDescription=%@", (long)error.code, error.localizedDescription];
    [self showAlertWithTitle:title message:message handler:handler];
}

@end
