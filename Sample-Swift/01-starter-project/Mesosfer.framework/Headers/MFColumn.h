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
 The `MFColumn` is a model class that save `key->type` pair of column for `MFDataSchema`.
 */
@interface MFColumn : NSObject

/**
 Initialize the schema column with name and type.
 
 @param name The column name of schema object.
 @param type The column `MFObjectType` of schema object.
 */
+ (nonnull instancetype) columnWithName:(nonnull NSString*) name andType:(MFObjectType) type;

/**
 Specifies the name of column.
 */
@property (strong, nonatomic, nonnull) NSString* name;

/**
 Specifies the `MFObjectType` of column.
 */
@property (assign) MFObjectType type;

@end
