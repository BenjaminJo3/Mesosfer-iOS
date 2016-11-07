# Mesosfer Starter Project for iOS #


A Framework that gives you access to the powerful Mesosfer cloud platform from your iOS app. 
For more information about Mesosfer and its features, see [Mesosfer Website][mesosfer.com] and [Mesosfer Documentations][docs].

## Register User
The first thing your app will do is probably ask the user to register. The following code illustrates a typical register:

```objective-c
// create new instance of Mesosfer User
MFUser *user = [MFUser user];

// set default field
user.email = @"user.one@mesosfer.com";
user.password = @"user1234";
user.firstname = @"User";
user.lastname = @"One";

// set custom field
user["dateOfBirth"] = [NSDate date];
user["height"] = @177.5;
user["weight"] = @78;
user["isMarried"] = @YES;
user["myObject"] = [NSDictionary dictionary];
user["myArray"] = [NSArray array];

// execute register user asynchronous
[user registerAsyncWithBlock:^(BOOL succeeded, NSError * _Nullable error) {
    if (succeeded) {
        // register succeeded
    } else {
        // register failed, show error message
    }
}
```

This call will `asynchronously` create a new user in your Mesosfer App. Before it does this, it checks to make sure that the `email` are unique. Also, it securely hashes the `password` in the cloud using bcrypt. We never store passwords in plaintext, nor will we ever transmit passwords back to the client in plaintext.

If a register isn’t successful, you should read the `NSError` that is returned. The most likely case is that the `email` has already been taken by another user. You should clearly communicate this to your users, and ask them try a different `email`.

## License
    Copyright (c) 2016, Mesosfer.
    All rights reserved.

    This source code is licensed under the BSD-style license found in the
    LICENSE file in the root directory of this source tree.

[mesosfer.com]:https://mesosfer.com
[docs]:https://docs.mesosfer.com/
[cloud]:https://cloud.mesosfer.com/
[framework]:https://github.com/mesosfer/Mesosfer-iOS/releases/latest
