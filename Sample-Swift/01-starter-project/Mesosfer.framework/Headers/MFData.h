/**
 * Copyright (c) 2016, Mesosfer
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <Foundation/Foundation.h>
#import <Mesosfer/MFConstant.h>

@class MFDataSchema;
@class MFQuery;

/**
 The `MFData` class is a local representation of data persisted to the Mesosfer cloud.
 This is the main class that is used to interact with objects in your app.
 */
@interface MFData : NSObject

#pragma mark - Properties
/**
 Specifies the bucket name of `MFData`.
 */
@property (strong, nonatomic, readonly, nullable) NSString* bucket;

/**
 Specifies the custom `NSDictionary` data of `MFData`.
 */
@property (strong, nonatomic, readonly, nullable) NSDictionary* data;

/**
 Specifies the unique id of `MFData` object.
 
 This field will be assigned by fetching current object that exists or
 by saving new user to Mesosfer cloud.
 */
@property (strong, nonatomic, readonly, nullable) NSString* objectId;

/**
 Specifies the created timestamp of `MFData` object.
 
 This field will be assigned by fetching current object that exists or
 by saving new user to Mesosfer cloud.
 */
@property (strong, nonatomic, readonly, nullable) NSDate* createdAt;

/**
 Specifies the last updated timestamp of `MFData` object.
 
 This field will be assigned by fetching current object that exists or
 by saving new user to Mesosfer cloud.
 */
@property (strong, nonatomic, readonly, nullable) NSDate* updatedAt;

/**
 Specifies the `MFDataSchema` of `MFData` object.
 
 This field will be assigned by fetching current object that exists or
 by saving new user to Mesosfer cloud.
 */
@property (strong, nonatomic, readonly, nullable) MFDataSchema* schema;

#pragma mark - Initialization
- (nonnull instancetype) init NS_UNAVAILABLE;
+ (nonnull instancetype) new NS_UNAVAILABLE;

/**
 Creates a new `MFData` with a bucket name.
 
 @param bucket A bucket name can be any alphanumeric string that begins with a letter.
 It represents an object in your app, like a 'User' or a 'Document'.
 
 @return the object that is instantiated with the given bucket name.
 */
+ (nonnull instancetype) dataWithBucket:(nonnull NSString*) bucket NS_SWIFT_NAME(init(withBucket:));

/**
 Creates a new `MFData` with a `MFDataSchema` object.
 
 @param schema A `MFDataSchema` object of a bucket.
 
 @return the object that is instantiated with the given `MFDataSchema` object.
 */
+ (nonnull instancetype) dataWithSchema:(nonnull MFDataSchema*) schema NS_SWIFT_NAME(init(withSchema:));

/**
 Creates a reference to an existing `MFData` for use in creating associations between MFDatas.
 
 @warning You need to call `MFData.-fetchAsyncWithBlock:` to fetch object from Mesosfer cloud.
 
 @param objectId The object id for the referenced `MFData` object.
 
 @return A `MFData` instance without data.
 */
+ (nonnull instancetype) dataWithObjectId:(nonnull NSString*) objectId NS_SWIFT_NAME(init(withObjectId:));

#pragma mark - Getters method

/**
 Creates a new `MFQuery` instance for querying `MData` objects using bucket name.

 @param bucket The bucket name.
 @return A new `MFQuery` instance.
 */
+ (nonnull MFQuery*) queryWithBucket:(nonnull NSString *) bucket;

/**
 Creates a new `MFQuery` instance for querying `MFData` objects using `MFDataSchema` object.

 @param dataSchema The `MFDataSchema` object.
 @return A new `MFQuery` instance.
 */
+ (nonnull MFQuery*) queryWithSchema:(nonnull MFDataSchema *) dataSchema;

/**
 Gets all key and value pair of `MFData` object in a dictionary.

 @return The dictionary of all key and value pair object.
 */
- (nullable NSDictionary *) dictionary;

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
- (nullable NSString*) stringForKey:(nonnull NSString*) key;

/**
 Returns the *NSNumber* value associated with a given key.
 
 @param key The key for which to return the corresponding value.
 
 @see -objectForKey:
 @see -objectForKeyedSubscript:
 */
- (nullable NSNumber*) numberForKey:(nonnull NSString*) key;

/**
 Returns the *double* value associated with a given key if it exists
 and is a double or can be coerced to a double, or *NAN* otherwise.
 
 @param key The key for which to return the corresponding value.
 
 @see -objectForKey:
 @see -objectForKeyedSubscript:
 */
- (double) doubleForKey:(nonnull NSString*) key;

/**
 Returns the *int* value associated with a given key if it exists
 and is an int or can be coerced to an int, or *0* otherwise.
 
 @param key The key for which to return the corresponding value.
 
 @see -objectForKey:
 @see -objectForKeyedSubscript:
 */
- (int) integerForKey:(nonnull NSString*) key;

/**
 Returns the *BOOL* value associated with a given key.
 
 @param key The key for which to return the corresponding value.
 
 @see -objectForKey:
 @see -objectForKeyedSubscript:
 */
- (BOOL) booleanForKey:(nonnull NSString*) key;

/**
 Returns the *NSDate* value associated with a given key if it exists
 and is a NSDate or can be coerced to a NSDate, or *nil* otherwise.
 
 @param key The key for which to return the corresponding value.
 
 @see -objectForKey:
 @see -objectForKeyedSubscript:
 */
- (nullable NSDate*) dateForKey:(nonnull NSString*) key;

/**
 Returns the *NSDictionary* value associated with a given key.
 
 @param key The key for which to return the corresponding value.
 
 @see -objectForKey:
 @see -objectForKeyedSubscript:
 */
- (nullable NSDictionary*) dictionaryForKey:(nonnull NSString*) key;

/**
 Returns the *NSArray* value associated with a given key.
 
 @param key The key for which to return the corresponding value.
 
 @see -objectForKey:
 @see -objectForKeyedSubscript:
 */
- (nullable NSArray*) arrayForKey:(nonnull NSString*) key;

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
- (void) setObject:(nonnull id) object forKey:(nonnull NSString *) key;

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

///--------------------------------------
#pragma mark - Increment
///--------------------------------------

/**
 Increments the given key by `1`.
 
 @param key The key.
 
 @return The same instance of `MFData` as the receiver. This allows method chaining.
 */
- (nonnull instancetype)incrementKey:(nonnull NSString *)key;

/**
 Increments the given key by a number.
 
 @param key The key.
 @param amount The amount to increment.
 
 @return The same instance of `MFData` as the receiver. This allows method chaining.
 */
- (nonnull instancetype)incrementKey:(nonnull NSString *)key byAmount:(nonnull NSNumber *)amount;

#pragma mark - Execution

/**
 Fetch the current `MFData` data from Mesosfer cloud *asynchronously* and executes the given callback block.

 @param block The block to execute.
 It shoud have the following argument signature: `^(MFData *data, NSError *error)`.
 */
- (void) fetchAsyncWithBlock:(nullable MFDataResultBlock) block;

/**
 Saves the `MFData` *asynchronously* and executes the given callback block.

 @param block The block to execute.
 It should have the following argument signature: `^(BOOL succeeded, NSError *error)`.
 */
- (void) saveAsyncWithBlock:(nullable MFBooleanResultBlock) block;

/**
 Delete the `MFData` object in Mesosfer cloud *asynchronously* and executes the given callback block.

 @param block The block to execute.
 It should have the following argument signature: `^(BOOL succeeded, NSError *error)`.
 */
- (void) deleteAsyncWithBlock:(nullable MFBooleanResultBlock) block;

@end
