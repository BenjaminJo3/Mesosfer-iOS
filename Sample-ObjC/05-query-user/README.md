# Mesosfer Starter Project for iOS #


A Framework that gives you access to the powerful Mesosfer cloud platform from your iOS app. 
For more information about Mesosfer and its features, see [Mesosfer Website][mesosfer.com] and [Mesosfer Documentations][docs].

## Basic Query User
In many cases, there is a condition that need to specify which users you want to retrieve. The `MFQuery` offers different ways to retrieve a list of users. 
The general pattern is to create a `MFQuery`, put conditions on it, and then retrieve an `Array` of matching `MFUser`s using the `findAsync` method with a `MFArrayResultBlock`. For example, to retrieve users with a firstname, use the `whereKey:equalTo:` method to constrain the value for a key:

```objective-c
MFQuery *query = [MFUser query];
[query whereKey:@"firstname" equalTo:@"John"];
[query findAsyncWithBlock:^(NSArray * _Nullable objects, NSError * _Nullable error) {
    if (error) {
        // error happen, show error message
        return;
    }
    
    // users found, display result in table view
}];
```

## Query Constraint
There are several ways to put constraints on the objects found by a `MFQuery`. You can filter out users with a particular key-value pair with `whereKey:notEqualTo:`:

```objective-c
[query whereKey:@"firstname" notEqualTo:@"John"];
```

You can give multiple constraints, and users will only be in the results if they match all of the constraints. In other words, it’s like an AND of constraints.

```objective-c
[query whereKey:@"firstname" notEqualTo:@"John"];
[query whereKey:@"height" greaterThan:@170];
```

You can limit the number of results with `setLimit`. By default, results are limited to 100, but anything from 1 to 1000 is a valid limit:

```objective-c
[query setLimit:20]; // limit to at most 20 results
```

You can skip the first results with `setSkip`. This can be useful for pagination:

```objective-c
[query setSkip:10]; // skip the first 10 results
```

For sortable types like numbers and strings, you can control the order in which results are returned:

```objective-c
// Sorts the results in ascending order by the user height
[query orderByAscending:@"height"];

// Sorts the results in descending order by the user height
[query orderByDescending:@"height"];
```

You can add more sort keys to the query as follows:

```objective-c
// Sorts the results in ascending order by the user height field if the previous sort keys are equal.
[query addAscendingOrder:@"height"];

// Sorts the results in descending order by the user weight field if the previous sort keys are equal.
[query addDescendingOrder:@"weight"];
```

For sortable types, you can also use comparisons in queries:

```objective-c
// Restricts to height < 170
[query whereKey:@"height" lessThan:@170];

// Restricts to height <= 170
[query whereKey:@"height" lessThanOrEqualTo:@170];

// Restricts to height > 170
[query whereKey:@"height" greaterThan:@170];

// Restricts to height >= 170
[query whereKey:@"height" greaterThanOrEqualTo:@170];
```

## Query on String
Use `whereKey:hasPrefix:` to restrict to string values that start with a particular string. Similar to a MySQL LIKE operator, this is indexed so it is efficient for large datasets:

```objective-c
// Finds user email that start with 'john'.
MFQuery *query = [MFUser query];
[query whereKey:@"email" hasPrefix:@"john"];
```

The above example will match any `MFUser` where the value in the `email` String key starts with “john”. For example, both “john.doe@nomail.com” and “john.cena@nomail.com” will match, but “big.john@okmail.com” or “little.john@okmail.com” will not.

Use `whereKey:hasSuffix:` to restrict to string values that end with a particular string. 

```objective-c
// Finds user email that end with '@okmail.com'.
MFQuery *query = [MFUser query];
[query whereKey:@"email" hasSuffix: @"@okmail.com"];
```

The above example will match any `MFUser` where the value in the `email` String key ends with “@okmail.com”. For example, both “big.john@okmail.com” and “little.john@okmail.com” will match, but “john.doe@nomail.com” or “john.cena@nomail.com” will not.

## Counting
If you just need to count how many objects match a query, but you do not need to retrieve all the objects that match, you can use `count` instead of `find`. For example, to count how many users have `height` greater than 170 centimetres:

```objective-c
MFQuery *query = [MFUser query];
[query whereKey:@"height" greaterThan:@170];
[query countAsyncWithBlock:^(int number, NSError * _Nullable error) {
    if (error) {
        // error happen, show error message
        return;
    }
    
    // counting users succeeded, show result
}];
```

## License
    Copyright (c) 2016, Mesosfer.
    All rights reserved.

    This source code is licensed under the BSD-style license found in the
    LICENSE file in the root directory of this source tree.

[mesosfer.com]:https://mesosfer.com
[docs]:https://docs.mesosfer.com/
[cloud]:https://cloud.mesosfer.com/
[framework]:https://github.com/mesosfer/Mesosfer-iOS/releases/latest
