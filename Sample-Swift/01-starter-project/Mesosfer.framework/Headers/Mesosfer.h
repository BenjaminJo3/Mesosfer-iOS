/**
 * Copyright (c) 2016, Mesosfer
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <Foundation/Foundation.h>

#import <Mesosfer/MFColumn.h>
#import <Mesosfer/MFConstant.h>
#import <Mesosfer/MFData.h>
#import <Mesosfer/MFDataSchema.h>
#import <Mesosfer/MFDateFormatter.h>
#import <Mesosfer/MFQuery.h>
#import <Mesosfer/MFUser.h>

//! Project version number for Mesosfer.
FOUNDATION_EXPORT double MesosferVersionNumber;

//! Project version string for Mesosfer.
FOUNDATION_EXPORT const unsigned char MesosferVersionString[];

/**
 The `Mesosfer` class contains static functions that handle global configuration for the Mesosfer framework.
 */
@interface Mesosfer : NSObject

#pragma mark - Initialization

/**
 Sets the applicationId and clientKey of your application.
 
 @param applicationId The application id of your Mesosfer application.
 @param clientKey The client key of your Mesosfer application.
 */
+ (void)initializeWithApplicationId:(nonnull NSString *)applicationId clientKey:(nonnull NSString *)clientKey;

/**
 The initialization state of Mesosfer framework.
 */
+ (BOOL) isInitialized;

#pragma mark - Getters

/**
 The current application id that was used to configure Mesosfer framework.
 */
+ (nullable NSString *) applicationId;

/**
 The current client key that was used to configure Mesosfer framework.
 */
+ (nullable NSString *) clientKey;

/**
 The current version of Mesosfer framework.
 */
+ (nonnull NSString *) version;

///--------------------------------------
#pragma mark - Logging
///--------------------------------------

/**
 Sets the level of logging to display.
 
 By default:
 - If running inside an app that was downloaded from iOS App Store - it is set to `MFLogLevelNone`
 - All other cases - it is set to `MFLogLevelWarning`
 
 @param logLevel Log level to set.
 @see MFLogLevel
 */
+ (void) setLogLevel:(MFLogLevel) logLevel;

/**
 Log level that will be displayed.
 
 By default:
 
 - If running inside an app that was downloaded from iOS App Store - it is set to `MFLogLevelNone`
 - All other cases - it is set to `MFLogLevelWarning`
 
 @return A `MFLogLevel` value.
 @see MFLogLevel
 */
+ (MFLogLevel) logLevel;

@end
