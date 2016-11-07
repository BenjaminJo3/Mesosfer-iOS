# Mesosfer Starter Project for iOS #


A Framework that gives you access to the powerful Mesosfer cloud platform from your iOS app. 
For more information about Mesosfer and its features, see [Mesosfer Website][mesosfer.com] and [Mesosfer Documentations][docs].

## Mesosfer Data
Storing data on Mesosfer is built around the `MFData`. Each `MFData` contains key-value pairs of JSON-compatible data. This data is using schema, which means that you need to specify ahead of time what keys exist on each `MFData` from our [Mesosfer Cloud][cloud]. Then you can simply set a key-value pairs you want to save, and our backend will store it.

For example, let's say you're set a Beacon parameters. A single `MFData` could contain :

```json
{
    "isActive":true, 
    "major":1, 
    "name":"Beacon One", 
    "minor":284, 
    "proximityUUID":"CB10023F-A318-3394-4199-A8730C7C1AEC"
}
```

Keys must be alphanumeric strings. Values can be `String`s, `Number`s, `Date`s, `Boolean`s, or even `Array`s and `Object`s - anything that can be JSON-encoded.


## Saving data
Let’s say you want to save the Beacon described above to the [Mesosfer Cloud][cloud]. The interface is similar to a Map, plus the `saveAsync` method:

```swift
let data = MFData(withBucket: "Beacon")

// set data
data["name"] = "Beacon One"
data["proximityUUID"] = "CB10023F-A318-3394-4199-A8730C7C1AEC"
data["major"] = 1
data["minor"] = 284
data["isActive"] = true
data["timestamp"] = NSDate()

// execute save data
data.saveAsync { (succeeded, error) in
    if succeeded {
        // data saved, show success message
    } else {
        // failed to save data, show error message
    }
}
```

## Deleting Data
To delete a data from the Mesosfer Cloud, use method `deleteAsync`:

```swift
data.deleteAsync { (succeeded, error) in
    if succeeded {
        // data deleted, show success message
    } else {
        // failed to delete data, show error message
    } 
}
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
