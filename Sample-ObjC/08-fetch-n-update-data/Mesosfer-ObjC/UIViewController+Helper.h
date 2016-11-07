/**
 * Copyright (c) 2016, Mesosfer
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface UIViewController (Helper)

- (void) showAlertWithTitle:(NSString*_Nullable)title
                    message:(NSString*_Nonnull)message
                    handler:(void (^ __nullable)(UIAlertAction *_Nonnull action))handler;

- (void) showErrorWithTitle:(NSString*_Nonnull)title
                      error:(NSError*_Nonnull)error
                    handler:(void (^ __nullable)(UIAlertAction *_Nonnull action))handler;

@end
