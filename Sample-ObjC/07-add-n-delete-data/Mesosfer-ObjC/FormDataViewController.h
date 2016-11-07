/**
 * Copyright (c) 2016, Mesosfer
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class MFData;

@protocol FormDataViewControllerDelegate <NSObject>
- (void)onSavedDataBeacon:(MFData *_Nonnull)beacon isNewData:(BOOL)isNewData;
@end

@interface FormDataViewController : UITableViewController

@property (weak, nonatomic) IBOutlet UITextField *textUUID;
@property (weak, nonatomic) IBOutlet UITextField *textMajor;
@property (weak, nonatomic) IBOutlet UITextField *textMinor;
@property (weak, nonatomic) IBOutlet UISwitch *switchIsActive;

@property (nonatomic, weak, nullable) id <FormDataViewControllerDelegate> delegate;

- (IBAction)saveSelector:(UIBarButtonItem *)sender;

@end

NS_ASSUME_NONNULL_END
