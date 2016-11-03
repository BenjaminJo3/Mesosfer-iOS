/**
 * Copyright (c) 2016, Mesosfer
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <Foundation/Foundation.h>

///--------------------------------------
#pragma mark - SDK Version
///--------------------------------------

#define MESOSFER_VERSION @"0.1.0"

@class MFDataSchema;
@class MFData;
@class MFUser;

///--------------------------------------
#pragma mark - Object types
///--------------------------------------

/**
 `MFObjectType` enum contains all object types that are used in Mesosfer framework.
 
 These codes are used when setting a custom object on `MFData` and `MFUser` class.
 
 @see MFData.-setObject:forKey:
 @see MFUser.-setObject:forKey:
 */
typedef NS_ENUM(uint8_t, MFObjectType) {
    /**
     Object with string type.
     */
    MFObjectTypeString,
    /**
     Object with number type.
     */
    MFObjectTypeNumber,
    /**
     Object with boolean type.
     */
    MFObjectTypeBoolean,
    /**
     Object with date type.
     */
    MFObjectTypeDate,
    /**
     Object with object type.
     */
    MFObjectTypeObject,
    /**
     Object with array type.
     */
    MFObjectTypeArray
};

///--------------------------------------
#pragma mark - Logging Levels
///--------------------------------------

/**
 `MFLogLevel` enum specifies different levels of logging that could be used to limit or display more messages in logs.
 
 @see Mesosfer.+setLogLevel:
 @see Mesosfer.+logLevel
 */
typedef NS_ENUM(uint8_t, MFLogLevel) {
    /**
     Log level that disables all logging.
     */
    MFLogLevelNone = 0,
    /**
     Log level that if set is going to output error messages to the log.
     */
    MFLogLevelError = 1,
    /**
     Log level that if set is going to output the following messages to log:
     - Errors
     - Warnings
     */
    MFLogLevelWarning = 2,
    /**
     Log level that if set is going to output the following messages to log:
     - Errors
     - Warnings
     - Informational messages
     */
    MFLogLevelInfo = 3,
    /**
     Log level that if set is going to output the following messages to log:
     - Errors
     - Warnings
     - Informational messages
     - Debug messages
     */
    MFLogLevelDebug = 4
};

///--------------------------------------
#pragma mark - Errors
///--------------------------------------

/**
 Error domain used for all `NSError`s in the SDK.
 */
extern NSString *const _Nonnull MesosferErrorDomain;

/**
 `MesosferErrorCode` enum contains all custom error codes that are used as `code` for `NSError` for callbacks on all classes.
 
 These codes are used when `domain` of `NSError` that you receive is set to `MesosferErrorDomain`.
 */
typedef NS_ENUM(NSInteger, MesosferErrorCode) {
    /**
     Internal server error. No information available.
     */
    kErrorInternalServer = 1,
    /**
     Application id or client key is invalid.
     */
    kErrorInvalidAppIdAndClientKey = 2,
    /**
     The connection to the Mesosfer servers failed.
     */
    kErrorConnectionFailed = 100,
    /**
     Object doesn't exist, or has an incorrect password.
     */
    kErrorObjectNotFound = 101,
    /**
     You tried to find values matching a datatype that doesn't
     support exact database matching, like an array or a dictionary.
     */
    kErrorInvalidQuery = 102,
    /**
     Missing or invalid bucket name. Bucket names are case-sensitive.
     They must start with a letter, and `a-zA-Z0-9` are the only valid characters.
     */
    kErrorInvalidBucketName = 103,
    /**
     Missing object id.
     */
    kErrorMissingObjectId = 104,
    /**
     Invalid key name. Keys are case-sensitive.
     They must start with a letter, and `a-zA-Z0-9` are the only valid characters.
     */
    kErrorInvalidKeyName = 105,
    /**
     Malformed pointer. Pointers must be arrays of a classname and an object id.
     */
    kErrorInvalidPointer = 106,
    /**
     Malformed json object. A json dictionary is expected.
     */
    kErrorInvalidJSON = 107,
    /**
     Tried to access a feature only available internally.
     */
    kErrorCommandUnavailable = 108,
    /**
     Field set to incorrect type.
     */
    kErrorIncorrectType = 111,
    /**
     Invalid channel name. A channel name is either an empty string (the broadcast channel)
     or contains only `a-zA-Z0-9_` characters and starts with a letter.
     */
    kErrorInvalidChannelName = 112,
    /**
     Invalid device token.
     */
    kErrorInvalidDeviceToken = 114,
    /**
     Push is misconfigured. See details to find out how.
     */
    kErrorPushMisconfigured = 115,
    /**
     That operation isn't allowed for clients.
     */
    kErrorOperationForbidden = 119,
    /**
     The results were not found in the cache.
     */
    kErrorCacheMiss = 120,
    /**
     Keys in `NSDictionary` values may not include `$` or `.`.
     */
    kErrorInvalidNestedKey = 121,
    /**
     Invalid file name.
     A file name can contain only `a-zA-Z0-9_.` characters and should be between 1 and 36 characters.
     */
    kErrorInvalidFileName = 122,
    /**
     Invalid ACL. An ACL with an invalid format was saved. This should not happen if you use `ACL`.
     */
    kErrorInvalidACL = 123,
    /**
     The request timed out on the server. Typically this indicates the request is too expensive.
     */
    kErrorTimeout = 124,
    /**
     The email address was invalid.
     */
    kErrorInvalidEmailAddress = 125,
    /**
     A unique field was given a value that is already taken.
     */
    kErrorDuplicateValue = 137,
    /**
     Role's name is invalid.
     */
    kErrorInvalidRoleName = 139,
    /**
     The Apple server response is not valid.
     */
    kErrorInvalidServerResponse = 148,
    /**
     Application has exceeded its request limit.
     */
    kErrorRequestLimitExceeded = 155,
    /**
     Invalid event name.
     */
    kErrorInvalidEventName = 160,
    /**
     Username is missing or empty.
     */
    kErrorUsernameMissing = 200,
    /**
     Password is missing or empty.
     */
    kErrorUserPasswordMissing = 201,
    /**
     Username has already been taken.
     */
    kErrorUsernameTaken = 202,
    /**
     Email has already been taken.
     */
    kErrorUserEmailTaken = 203,
    /**
     The email is missing, and must be specified.
     */
    kErrorUserEmailMissing = 204,
    /**
     A user with the specified email was not found.
     */
    kErrorUserWithEmailNotFound = 205,
    /**
     The user cannot be altered by a client without the session.
     */
    kErrorUserCannotBeAlteredWithoutSession = 206,
    /**
     Users can only be created through sign up.
     */
    kErrorUserCanOnlyBeCreatedThroughSignUp = 207,
    /**
     Error code indicating that the current session token is invalid.
     */
    kErrorInvalidSessionToken = 209,
    /**
     Error code indicating that the current session token is invalid.
     */
    kErrorUserIdMismatch = 209,
};


#pragma mark - Blocks

/**
 A block to be called when the task is completed.
 E.g. task for registering user, saving object etc.
 
 For `succeeded` parameter, it will return `YES` when task is succeeded, otherwise `NO`.
 For `error` parameter, it will return `NSError` when task got an error, otherwise `nil`.
 */
typedef void (^MFBooleanResultBlock)(BOOL succeeded, NSError *_Nullable error);

/**
 A block to be called when the task is completed.
 E.g. task for counting objects.
 
 For `number` parameter, it will return an `int` number when task is succeeded, otherwise `0` (zero).
 For `error` parameter, it will return `NSError` when task got an error, otherwise `nil`.
 */
typedef void (^MFIntegerResultBlock)(int number, NSError *_Nullable error);

/**
 A block to be called when the task is completed.
 E.g. task for querying objects.
 
 For `objects` parameter, it will return `NSArray` of objects when task is succeeded, otherwise `nil`.
 For `error` parameter, it will return `NSError` when task got an error, otherwise `nil`.
 */
typedef void (^MFArrayResultBlock)(NSArray *_Nullable objects, NSError *_Nullable error);

/**
 A block to be called when the task is completed.
 E.g. task for fetching or getting single `MFDataSchema` object.
 
 For `schema` parameter, it will return a `MFDataSchema` when task is succeeded, otherwise `nil`.
 For `error` parameter, it will return `NSError` when task got an error, otherwise `nil`.
 */
typedef void (^MFDataSchemaResultBlock)(MFDataSchema *_Nullable schema,  NSError *_Nullable error);

/**
 A block to be called when the task is completed.
 E.g. task for fetching or getting single `MFData` object.
 
 For `data` parameter, it will return a `MFData` when task is succeeded, otherwise `nil`.
 For `error` parameter, it will return `NSError` when task got an error, otherwise `nil`.
 */
typedef void (^MFDataResultBlock)(MFData *_Nullable data,  NSError *_Nullable error);

/**
 A block to be called when the task is completed.
 E.g. task for fetching `MFUser` object or login for a user.
 
 For `user` parameter, it will return a `MFUser` when task is succeeded, otherwise `nil`.
 For `error` parameter, it will return `NSError` when task got an error, otherwise `nil`.
 */
typedef void (^MFUserResultBlock)(MFUser *_Nullable user,  NSError *_Nullable error);

/**
 A block to be called when the task is completed.
 E.g. task for logging out a user.
 
 For `error` parameter, it will return `NSError` when task got an error, otherwise `nil`. */
typedef void (^MFUserLogoutResultBlock)(NSError *_Nullable error);

/**
 A block to be called when the task is completed.
 E.g. task for getting single `MFData` or `MFDataSchema` object.
 
 For `object` parameter, it will return a `id` when task is succeeded, otherwise `nil`.
 For `error` parameter, it will return `NSError` when task got an error, otherwise `nil`.
 */
typedef void (^MFObjectResultBlock)(id _Nullable object,  NSError *_Nullable error);

///--------------------------------------
#pragma mark - Swift Macros
///--------------------------------------

#ifndef MF_SWIFT_UNAVAILABLE
#  ifdef NS_SWIFT_UNAVAILABLE
#    define MF_SWIFT_UNAVAILABLE NS_SWIFT_UNAVAILABLE("")
#  else
#    define MF_SWIFT_UNAVAILABLE
#  endif
#endif


/**
 The `MFConstant` class contains constant, enum and block typedef for the Mesosfer framework.
 */
@interface MFConstant : NSObject

- (nonnull instancetype) init NS_UNAVAILABLE;
+ (nonnull instancetype) new NS_UNAVAILABLE;

@end
