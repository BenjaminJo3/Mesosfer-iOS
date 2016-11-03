/**
 * Copyright (c) 2016, Mesosfer
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <Foundation/Foundation.h>

/**
 The `MFDateFormatter` is singleton class that contains functions to formatting `NSDate` into `NSString` or
 parsing `NSString` into `NSDate` for the Mesosfer framework.
 */
@interface MFDateFormatter : NSObject

- (nonnull instancetype) init NS_UNAVAILABLE;
+ (nonnull instancetype) new NS_UNAVAILABLE;

///--------------------------------------
#pragma mark - Shared instance
///--------------------------------------

/**
 Gets `MFDateFormatter` shared instance.
 
 @return Shared instance of `MFDateFormatter`.
 */
+ (nonnull instancetype)sharedFormatter;

///--------------------------------------
#pragma mark - String from Date
///--------------------------------------

/**
 Converts `NSDate` into `NSString` representation using the following format: yyyy-MM-dd'T'HH:mm:ss.SSS'Z'
 
 @param date `NSDate` to convert.
 
 @return Formatted `NSString` representation.
 @see MFDateFormatter.-stringFromDate:isTimestamp:
 */
- (nonnull NSString *)stringFromDate:(nonnull NSDate *)date;

/**
 Converts `NSDate` into `NSString` representation using the following format: yyyy-MM-dd or yyyy-MM-dd'T'HH:mm:ss.SSS'Z'
 
 @param date `NSDate` to convert.
 @param flag The flag to convert `NSDate` to timestamp
 
 @return Formatted `NSString` representation.
 @see MFDateFormatter.-stringFromDate:
 */
- (nonnull NSString *)stringFromDate:(nonnull NSDate *)date isTimestamp:(BOOL) flag;

///--------------------------------------
#pragma mark - Date from String
///--------------------------------------

/**
 Converts `NSString` representation of a date into `NSDate` object.
 
 Following date formats are supported:
 yyyy-MM-dd
 yyyy-MM-dd HH:mm'Z'
 yyyy-MM-dd HH:mm:ss'Z'
 yyyy-MM-dd HH:mm:ss.SSS'Z'
 yyyy-MM-dd'T'HH:mm'Z'
 yyyy-MM-dd'T'HH:mm:ss'Z'
 yyyy-MM-dd'T'HH:mm:ss.SSS'Z'
 
 @param string `NSString` representation to convert.
 
 @return `NSDate` incapsulating the date.
 */
- (nullable NSDate *)dateFromString:(nonnull NSString *)string;

@end
