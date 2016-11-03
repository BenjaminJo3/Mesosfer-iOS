/**
 * Copyright (c) 2016, Mesosfer
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <Foundation/Foundation.h>
#import <Mesosfer/MFConstant.h>

@class MFColumn;
@class MFQuery;

/**
 The `MFDataSchema` class is a local representation of schema persisted to the Mesosfer cloud.
 This is the main class that is used to interact with objects in your app.
 */
@interface MFDataSchema : NSObject

#pragma mark - Properties

/**
 Specifies the bucket name of schema.
 */
@property (strong, nonatomic, readonly, nullable) NSString* bucket;

/**
 Specifies the list of `MFColumn` of schema.
 */
@property (strong, nonatomic, readonly, nonnull) NSArray<MFColumn*>* columns;

/**
 Specifies the unique id of schema.
 
 This field will be assigned by fetching current object that exists or
 by saving new user to Mesosfer cloud.
 */
@property (strong, nonatomic, readonly, nullable) NSString* objectId;

/**
 Specifies the created timestamp of schema.
 
 This field will be assigned by fetching current object that exists or
 by saving new user to Mesosfer cloud.
 */
@property (strong, nonatomic, readonly, nullable) NSDate* createdAt;

/**
 Specifies the last updated timestamp of schema.
 
 This field will be assigned by fetching current object that exists or
 by saving new user to Mesosfer cloud.
 */
@property (strong, nonatomic, readonly, nullable) NSDate* updatedAt;

#pragma mark - Initialization
- (nonnull instancetype) init NS_UNAVAILABLE;
+ (nonnull instancetype) new NS_UNAVAILABLE;

/**
 Creates schema with bucket name.

 @param bucket The bucket name.
 @return A new schema object.
 */
+ (nonnull instancetype) schemaWithBucket:(nonnull NSString*) bucket NS_SWIFT_NAME(init(withBucket:));

/**
 Creates a reference to an existing `MFDataSchema` for use in creating associations between MFDataSchemas.
 
 @warning You need to call `MFDataSchema.-fetchAsyncWithBlock:` to fetch object from Mesosfer cloud.

 @param objectId The object id for the referenced `MFDataSchema` object.
 
 @return A new instance object without data.
 
 @see MFData.-fetchAsyncWithBlock:
 */
+ (nonnull instancetype) schemaWithObjectId:(nonnull NSString*) objectId NS_SWIFT_NAME(init(withObjectId:));

#pragma mark - Getter method

/**
 Creates a new `MFQuery` instance for querying `MDataSchema` objects.

 @return A new `MFQuery` instance.
 */
+ (nonnull MFQuery*) query;

/**
 Creates a new `MFQuery` instance for querying `MDataSchema` objects using bucket name.

 @param bucket The bucket name to query.
 @return A new `MFQuery` instance.
 */
+ (nonnull MFQuery*) queryWithBucket:(nonnull NSString *) bucket;

/**
 Gets all key and value pair of `MFData` object in a dictionary.

 @return The dictionary of all key and value pair object.
 */
- (nullable NSDictionary *) dictionary;

#pragma mark - Managing columns

/**
 Adds a schema column with name and `MFObjectType`.

 @param name The name of column.
 @param type The `MFObjectType` of column.
 @return The current instance of schema. This allow method chaining.
 */
- (nonnull instancetype) addColumnWithName:(nonnull NSString*) name andType:(MFObjectType) type;

/**
 Deletes a schema column with name.

 @param name The name of column.
 @return The current instance of schema. This allow method chaining.
 */
- (nonnull instancetype) deleteColumnWithName:(nonnull NSString*) name;

#pragma mark - Asynchoronous executors

/**
 Fetch the current `MFDataSchema` data from Mesosfer cloud *asynchronously* and executes the given callback block.

 @param block The block to execute.
 It shoud have the following argument signature: `^(MFDataSchema *schema, NSError *error)`.
 */
- (void) fetchAsyncWithBlock:(nullable MFDataSchemaResultBlock) block;

/**
 Saves the `MFDataSchema` *asynchronously* and executes the given callback block.

 @param block The block to execute.
 It should have the following argument signature: `^(BOOL succeeded, NSError *error)`.
 */
- (void) saveAsyncWithBlock:(nullable MFBooleanResultBlock) block;

/**
 Delete the `MFDataSchema` object in Mesosfer cloud *asynchronously* and executes the given callback block.

 @param block The block to execute.
 It should have the following argument signature: `^(BOOL succeeded, NSError *error)`.
 */
- (void) deleteAsyncWithBlock:(nullable MFBooleanResultBlock) block;

@end
