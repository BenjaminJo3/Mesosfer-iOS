# Mesosfer Starter Project for iOS #


A Framework that gives you access to the powerful Mesosfer cloud platform from your iOS app. 
For more information about Mesosfer and its features, see [Mesosfer Website][mesosfer.com] and [Mesosfer Documentations][docs].

## Basic Query
In many cases, there is a condition that need to specify which `data`s you want to retrieve. The `MFQuery` offers different ways to retrieve a list of `data`s. 
The general pattern is to create a `MFQuery`, put conditions on it, and then retrieve a `Array` of matching `MFData`s using the `findAsync` method with a `MFArrayResultBlock`. For example, to retrieve `Beacon`s data with a `name`, use the `whereKey:equalTo` method to constrain the value for a key:

```objective-c
MFQuery *query = [MFData queryWithBucket:@"Beacon"];
[query whereKey:@"name" equalTo:@"Beacon One"];
[query findAsyncWithBlock:^(NSArray * _Nullable objects, NSError * _Nullable error) {
    if (error) {
        // error happen, show error message
        return;
    }
    
    // data beacon's found, display result in table view
}];
```

## Query Constraint
There are several ways to put constraints on the datas found by a `MFQuery`. You can filter out datas with a particular key-value pair with `whereKey:notEqualTo:`:

```objective-c
[query whereKey:@"name" notEqualTo:@"Beacon One"];
```

You can give multiple constraints, and datas will only be in the results if they match all of the constraints. In other words, it’s like an AND of constraints.

```objective-c
[query whereKey:@"name" notEqualTo:@"Beacon One"];
[query whereKey:@"major" greaterThan:@1];
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
// Sorts the results in ascending order by the beacon's major
[query orderByAscending:@"major"];

// Sorts the results in descending order by the beacon's minor
[query orderByDescending:@"minor"];
```

You can add more sort keys to the query as follows:

```objective-c
// Sorts the results in ascending order by the beacon's major field if the previous sort keys are equal.
[query addAscendingOrder:@"major"];

// Sorts the results in descending order by the beacon's minor field if the previous sort keys are equal.
[query addDescendingOrder:@"minor"];
```

For sortable types, you can also use comparisons in queries:

```objective-c
// Restricts to major < 123
[query whereKey:@"major" lessThan:@123];

// Restricts to major <= 123
[query whereKey:@"major" lessThanOrEqualTo:@123];

// Restricts to major > 123
[query whereKey:@"major" greaterThan:@123];

// Restricts to major >= 123
[query whereKey:@"major" greaterThanOrEqualTo:@123];
```

## Query on String
Use `whereKey:hasPrefix:` to restrict to string values that start with a particular string. Similar to a MySQL LIKE operator, this is indexed so it is efficient for large datasets:

```objective-c
// Finds beacon's name that start with 'Beacon'.
MFData *query = [MFData queryWithBucket:@"Beacon"];
[query whereKey:@"name" hasPrefix:@"Beacon"];
```

The above example will match any `MFData` where the value in the `name` String key starts with “Beacon”. For example, both “Beacon One” and “Beacon Two” will match, but “First Beacon” or “Second Beacon” will not.

Use `whereKey:hasSuffix:` to restrict to string values that end with a particular string. 

```objective-c
// Finds beacon's name that end with 'One'.
MFData *query = [MFData queryWithBucket:@"Beacon"];
[query whereKey:@"name" hasSuffix:@"One"];
```

The above example will match any `MFData` where the value in the `name` String key ends with “One”. For example, “Beacon One” will match, but “One Beacon” will not.

## Counting
If you just need to count how many datas match a query, but you do not need to retrieve all the datas that match, you can use `count` instead of `find`. For example, to count how many beacons have `major` greater than 123:

```objective-c
MFData *query = [MFData queryWithBucket:@"Beacon"];
[query whereKey:@"major" greaterThan:@123];
[query countAsyncWithBlock:^(int number, NSError * _Nullable error) {
    if (error) {
        // error happen, show error message
        return;
    }
    
    // counting data beacon's succeeded, show result number
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
