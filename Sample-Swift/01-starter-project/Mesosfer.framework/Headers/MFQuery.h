/**
 * Copyright (c) 2016, Mesosfer
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <Foundation/Foundation.h>
#import "MFConstant.h"

/**
 The `MFQuery` class defines a query that is used to query for `MFDataSchema`s, `MFData`s or `MFUser`s.
 */
@interface MFQuery : NSObject

///--------------------------------------
#pragma mark - Instance Class Query
///--------------------------------------

- (nonnull instancetype) init NS_UNAVAILABLE;
+ (nonnull instancetype) new NS_UNAVAILABLE;


/**
 Creates a new `MFQuery` instance for querying `MDataSchema` objects.

 @return A new `MFQuery` instance.
 */
+ (nonnull instancetype) querySchema;

/**
 Creates a new `MFQuery` instance for querying `MFUser` objects.
 
 @return A new `MFQuery` instance.
 
 @see MFQuery.+queryUser
 */
+ (nonnull instancetype) queryUser;

///--------------------------------------
#pragma mark - Paginating Results
///--------------------------------------

/**
 Add limit on the number of objects to return. The default limit is `100`, with a
 maximum of 1000 results being returned at a time.
 
 @param limit The number of limit that objects should return.
 
 @return The same instance of `MFQuery` as the receiver. This allows method chaining.
 */
- (nonnull instancetype)setLimit:(NSInteger) limit;

/**
 Add the number of objects to skip before returning any.
 
 @param skip The number of objects to skip
 
 @return The same instance of `MFQuery` as the receiver. This allows method chaining.
 */
- (nonnull instancetype)setSkip:(NSInteger) skip;

///--------------------------------------
#pragma mark - Basic Constraints
///--------------------------------------

/**
 Add a constraint that requires a particular key exists.
 
 @param key The key that should exist.
 
 @return The same instance of `MFQuery` as the receiver. This allows method chaining.
 */
- (nonnull instancetype)whereKeyExists:(nonnull NSString *)key;

/**
 Add a constraint that requires a key not exist.
 
 @param key The key that should not exist.
 
 @return The same instance of `MFQuery` as the receiver. This allows method chaining.
 */
- (nonnull instancetype)whereKeyDoesNotExist:(nonnull NSString *)key;

/**
 Add a constraint to the query that requires a particular key's object to be equal to the provided object.
 
 @param key The key to be constrained.
 @param object The object that must be equalled.
 
 @return The same instance of `MFQuery` as the receiver. This allows method chaining.
 */
- (nonnull instancetype)whereKey:(nonnull NSString *)key equalTo:(nonnull id)object;

/**
 Add a constraint to the query that requires a particular key's object to be less than the provided object.
 
 @param key The key to be constrained.
 @param object The object that provides an upper bound.
 
 @return The same instance of `MFQuery` as the receiver. This allows method chaining.
 */
- (nonnull instancetype)whereKey:(nonnull NSString *)key lessThan:(nonnull id)object;

/**
 Add a constraint to the query that requires a particular key's object
 to be less than or equal to the provided object.
 
 @param key The key to be constrained.
 @param object The object that must be equalled.
 
 @return The same instance of `MFQuery` as the receiver. This allows method chaining.
 */
- (nonnull instancetype)whereKey:(nonnull NSString *)key lessThanOrEqualTo:(nonnull id)object;

/**
 Add a constraint to the query that requires a particular key's object
 to be greater than the provided object.
 
 @param key The key to be constrained.
 @param object The object that must be equalled.
 
 @return The same instance of `MFQuery` as the receiver. This allows method chaining.
 */
- (nonnull instancetype)whereKey:(nonnull NSString *)key greaterThan:(nonnull id)object;

/**
 Add a constraint to the query that requires a particular key's
 object to be greater than or equal to the provided object.
 
 @param key The key to be constrained.
 @param object The object that must be equalled.
 
 @return The same instance of `MFQuery` as the receiver. This allows method chaining.
 */
- (nonnull instancetype)whereKey:(nonnull NSString *)key greaterThanOrEqualTo:(nonnull id)object;

/**
 Add a constraint to the query that requires a particular key's object
 to be not equal to the provided object.
 
 @param key The key to be constrained.
 @param object The object that must not be equalled.
 
 @return The same instance of `MFQuery` as the receiver. This allows method chaining.
 */
- (nonnull instancetype)whereKey:(nonnull NSString *)key notEqualTo:(nonnull id)object;

///--------------------------------------
#pragma mark - Adding String Constraints
///--------------------------------------

/**
 Add a constraint for finding string values that contain a provided substring.
 
 @warning This will be slow for large datasets.
 
 @param key The key that the string to match is stored in.
 @param substring The substring that the value must contain.
 
 @return The same instance of `MFQuery` as the receiver. This allows method chaining.
 */
- (nonnull instancetype)whereKey:(nonnull NSString *)key containsString:(nullable NSString *)substring;

/**
 Add a constraint for finding string values that start with a provided prefix.
 
 This will use smart indexing, so it will be fast for large datasets.
 
 @param key The key that the string to match is stored in.
 @param prefix The substring that the value must start with.
 
 @return The same instance of `MFQuery` as the receiver. This allows method chaining.
 */
- (nonnull instancetype)whereKey:(nonnull NSString *)key hasPrefix:(nullable NSString *)prefix;

/**
 Add a constraint for finding string values that end with a provided suffix.
 
 @warning This will be slow for large datasets.
 
 @param key The key that the string to match is stored in.
 @param suffix The substring that the value must end with.
 
 @return The same instance of `MFQuery` as the receiver. This allows method chaining.
 */
- (nonnull instancetype)whereKey:(nonnull NSString *)key hasSuffix:(nullable NSString *)suffix;

///--------------------------------------
#pragma mark - Sorting
///--------------------------------------

/**
 Sort the results in *ascending* order with the given key.
 
 @param key The key to order by.
 
 @return The same instance of `MFQuery` as the receiver. This allows method chaining.
 */
- (nonnull instancetype)orderByAscending:(nonnull NSString *)key;

/**
 Additionally sort in *ascending* order by the given key.
 
 The previous keys provided will precedence over this key.
 
 @param key The key to order by.
 */
- (nonnull instancetype)addAscendingOrder:(nonnull NSString *)key;

/**
 Sort the results in *descending* order with the given key.
 
 @param key The key to order by.
 
 @return The same instance of `MFQuery` as the receiver. This allows method chaining.
 */
- (nonnull instancetype)orderByDescending:(nonnull NSString *)key;

/**
 Additionally sort in *descending* order by the given key.
 
 The previous keys provided will precedence over this key.
 
 @param key The key to order by.
 */
- (nonnull instancetype)addDescendingOrder:(nonnull NSString *)key;

///--------------------------------------
#pragma mark - Executors
///--------------------------------------

/**
 Finds objects *asynchronously* and calls the given block with the results.
 
 @param block The block to execute.
 It should have the following argument signature: `^(NSArray *objects, NSError *error)`
 */
-(void) findAsyncWithBlock:(nullable MFArrayResultBlock) block;

/**
 Counts objects *asynchronously* and calls the given block with the counts.
 
 @param block The block to execute.
 It should have the following argument signature: `^(int count, NSError *error)`
 */
-(void) countAsyncWithBlock:(nullable MFIntegerResultBlock) block;

/**
 Gets a `MFDataSchema` or `MFData` asynchronously and calls the given block with the result.
 
 @warning This method cannot be used for getting object using `MFUser` objectId's
 
 @warning This method mutates the query.
 It will reset limit to `1`, skip to `0` and remove all conditions, leaving only `objectId`.
 
 @param objectId The id of the object that is being requested.
 @param block The block to execute.
 The block should have the following argument signature: `^(id object, NSError *error)`
 */
-(void) getObjectAsyncWithId:(nonnull NSString*)objectId withBlock:(nullable MFObjectResultBlock)block;

///--------------------------------------
#pragma mark - Cancelling a Query
///--------------------------------------

/**
 Cancels the current network request (if any). Ensures that callbacks won't be called.
 */
- (void)cancel;

@end
