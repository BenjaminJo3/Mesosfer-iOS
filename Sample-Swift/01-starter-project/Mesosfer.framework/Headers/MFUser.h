/**
 * Copyright (c) 2016, Mesosfer
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <Foundation/Foundation.h>
#import "MFConstant.h"

@class MFDataSchema;
@class MFQuery;

/**
 The `MFUser` class is a local representation of a user persisted to the Mesosfer Data.
 This class is an extended of a `MFData`, and retains the same functionality of a `MFData`,
 but also extends it with various user specific methods, like register, login, and validation uniqueness.
 */
@interface MFUser : NSObject

/**
 Specifies a email address for user that used for login credential.
 */
@property (strong, nonatomic, nullable) NSString *email;

/**
 Specifies a secure password for user that used for login credential.
 */
@property (strong, nonatomic, nullable) NSString *password;

/**
 Specifies first name of user.
 */
@property (strong, nonatomic, nullable) NSString *firstname;

/**
 Specifies last name of user.
 */
@property (strong, nonatomic, nullable) NSString *lastname;

/**
 Specifies all key and value pairs of user data.
 */
@property (strong, nonatomic, readonly, nullable) NSDictionary *data;

/**
 Specifies a unique id of a user.
 
 This field will be assigned by fetching current object that exists or
 by saving new user to Mesosfer cloud.
 */
@property (strong, nonatomic, readonly, nullable) NSString *objectId;

/**
 Specifies a created timestamp of a user.
 
 This field will be assigned by fetching current object that exists or
 by saving new user to Mesosfer cloud.
 */
@property (strong, nonatomic, readonly, nullable) NSDate *createdAt;

/**
 Specifies a last updated timestamp of a user.
 
 This field will be assigned by fetching current object that exists or
 by saving new user to Mesosfer cloud.
 */
@property (strong, nonatomic, readonly, nullable) NSDate *updatedAt;

/**
 Specifies a `MFDataSchema` object of a user.
 
 This field will be assigned by fetching current object that exists or
 by saving new user to Mesosfer cloud.
 */
@property (strong, nonatomic, readonly, nullable) MFDataSchema *schema;

#pragma mark - Initialization

/**
 Creates a new user object.

 @return A new user object.
 
 @see MFUser.-registerAsyncWithBlock:
 */
+ (nonnull instancetype)user NS_SWIFT_NAME(init());

#pragma mark - Getters method

/**
 Gets the currently logged in user from disk and returns an instance of it.
 
 @return Returns a `MFUser` that is the currently logged in user. If there is none, returns `nil`.
 */
+ (nullable instancetype)currentUser NS_SWIFT_NAME(currentUser());

/**
 Creates a new `MFQuery` instance for querying `MFUser` objects.

 @return A new `MFQuery` instance.
 
 @see MFQuery.+queryUser
 */
+ (nonnull MFQuery *)query;

/**
 Gets all key and value pair of `MFUser` object in a dictionary.

 @return The dictionary of all key and value pair object.
 */
- (nullable NSDictionary *)dictionary;


/**
 Returns the value associated with a given key.
 
 @param key The key for which to return the corresponding value.
 
 @see -objectForKeyedSubscript:
 */
- (nullable id)objectForKey:(nonnull NSString *)key;

/**
 Returns the value associated with a given key.
 
 This method enables usage of literal syntax on `MFUser`.
 E.g. `NSString *value = user[@"key"];`
 
 @param key The key for which to return the corresponding value.
 
 @see -objectForKey:
 */
- (nullable id)objectForKeyedSubscript:(nonnull NSString *)key;

/**
 Returns the *NSString* value associated with a given key.
 
 @param key The key for which to return the corresponding value.
 
 @see -objectForKey:
 @see -objectForKeyedSubscript:
 */
- (nullable NSString*)stringForKey:(nonnull NSString*) key;

/**
 Returns the *NSNumber* value associated with a given key.
 
 @param key The key for which to return the corresponding value.
 
 @see -objectForKey:
 @see -objectForKeyedSubscript:
 */
- (nullable NSNumber*)numberForKey:(nonnull NSString*) key;

/**
 Returns the *double* value associated with a given key if it exists 
 and is a double or can be coerced to a double, or *NAN* otherwise.
 
 @param key The key for which to return the corresponding value.
 
 @see -objectForKey:
 @see -objectForKeyedSubscript:
 */
- (double)doubleForKey:(nonnull NSString*) key;

/**
 Returns the *int* value associated with a given key if it exists
 and is an int or can be coerced to an int, or *0* otherwise.
 
 @param key The key for which to return the corresponding value.
 
 @see -objectForKey:
 @see -objectForKeyedSubscript:
 */
- (int)integerForKey:(nonnull NSString*) key;

/**
 Returns the *BOOL* value associated with a given key.
 
 @param key The key for which to return the corresponding value.
 
 @see -objectForKey:
 @see -objectForKeyedSubscript:
 */
- (BOOL)booleanForKey:(nonnull NSString*) key;

/**
 Returns the *NSDate* value associated with a given key if it exists
 and is a NSDate or can be coerced to a NSDate, or *nil* otherwise.
 
 @param key The key for which to return the corresponding value.
 
 @see -objectForKey:
 @see -objectForKeyedSubscript:
 */
- (nullable NSDate*)dateForKey:(nonnull NSString*) key;

/**
 Returns the *NSDictionary* value associated with a given key.
 
 @param key The key for which to return the corresponding value.
 
 @see -objectForKey:
 @see -objectForKeyedSubscript:
 */
- (nullable NSDictionary*)dictionaryForKey:(nonnull NSString*) key;

/**
 Returns the *NSArray* value associated with a given key.
 
 @param key The key for which to return the corresponding value.
 
 @see -objectForKey:
 @see -objectForKeyedSubscript:
 */
- (nullable NSArray*)arrayForKey:(nonnull NSString*) key;

#pragma mark - Setters method

/**
 Unsets a key on the object.
 
 @param key The key.
 */
- (void)removeObjectForKey:(nonnull NSString *)key;

/**
 Sets the object associated with a given key.
 
 @param object The object for `key`. A strong reference to the object is maintained by MFUser.
 Raises an `NSInvalidArgumentException` if `object` is `nil`.
 If you need to represent a `nil` value - use `NSNull`.
 @param key The key for `object`.
 Raises an `NSInvalidArgumentException` if `key` is `nil`.
 
 @see -setObject:forKeyedSubscript:
 */
- (void)setObject:(nonnull id) object forKey:(nonnull NSString *) key;

/**
 Returns the value associated with a given key.
 
 This method enables usage of literal syntax on `MFUser`.
 E.g. `user[@"key"] = @"value";`
 
 @param object The object for `key`. A strong reference to the object is maintained by MFUser.
 Raises an `NSInvalidArgumentException` if `object` is `nil`.
 If you need to represent a `nil` value - use `NSNull`.
 @param key The key for `object`.
 Raises an `NSInvalidArgumentException` if `key` is `nil`.
 
 @see -setObject:forKey:
 */
- (void)setObject:(nonnull id)object forKeyedSubscript:(nonnull NSString *)key;

#pragma mark - Asynchronous executors

/**
 Register new user *asynchronously*.
 
 This will also enforce that the email address isn't already taken.
 
 @warning Make sure that password and email address are set before calling this method.
 
 @param block The block to execute.
 It should have the following argument signature: `^(BOOL succeeded, NSError *error)`.
 */
- (void)registerAsyncWithBlock:(nullable MFBooleanResultBlock)block;

/**
 Makes an *asynchronous* request to log in a user with specified credentials.
 
 Returns an instance of the successfully logged in `MFUser`.
 This also caches the user locally so that calls to `+currentUser` will use the latest logged in user.
 
 @param email The email address of the user.
 @param password The password of the user.
 @param block The block to execute.
 It should have the following argument signature: `^(MFUser *user, NSError *error)`.
 */
+ (void)logInAsyncWithEmail:(nonnull NSString *)email
                   password:(nonnull NSString *)password block:(nullable MFUserResultBlock)block;

/**
 *Asynchronously* logs out the currently logged in user.
 
 This will also remove the session from disk, log out of linked services
 and all future calls to `+currentUser` will return `nil`. 
 
 @param block A block that will be called when logging out completes or fails.
 */
+ (void)logOutAsyncWithBlock:(nullable MFUserLogoutResultBlock)block;

/**
 Saves the `MFUser` *asynchronously* and executes the given callback block.
 
 @param block The block to execute.
 It should have the following argument signature: `^(BOOL succeeded, NSError *error)`.
 */
- (void)saveAsyncWithBlock:(nullable MFBooleanResultBlock)block;

/**
 Fetch the current `MFUser` data from Mesosfer cloud *asynchronously* and executes the given callback block.
 
 @warning Use this method only on `MFUser.+currentUser`, cannot be used on user object found by `MFQuery`

 @param block The block to execute.
 It shoud have the following argument signature: `^(MFUser *user, NSError *error)`.
 */
- (void)fetchAsyncWithBlock:(nullable MFUserResultBlock) block;


/**
 Changes the current `MFUser` password on Mesosfer cloud *asynchronously* and executes the given callback block.
 
 @warning Use this method only on `MFUser.+currentUser`, cannot be used on user object found by `MFQuery`

 @param oldPassword The old existing current user password.
 @param newPassword The new password to set.
 @param block The block to execute.
 It shoud have the following argument signature: `^(BOOL succeeded, NSError *error)`.
 */
- (void) chagePasswordAsyncWithOldPassword:(nonnull NSString*)oldPassword
                               newPassword:(nonnull NSString*)newPassword block:(nullable MFBooleanResultBlock) block;

@end
