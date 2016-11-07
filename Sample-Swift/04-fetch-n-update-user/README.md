# Mesosfer Starter Project for iOS #


A Framework that gives you access to the powerful Mesosfer cloud platform from your iOS app. 
For more information about Mesosfer and its features, see [Mesosfer Website][mesosfer.com] and [Mesosfer Documentations][docs].

## Fetch User
If you need to fetch data on a current user with the latest data that is in the cloud, you can call the fetchAsync method like so:

```swift
let user = MFUser.currentUser()
user.fetchAsync { (user, error) in
    if let e = error as? NSError {
        // error happen, show error message
        return
    }
        
    // fetch user data succeeded
}
```

This will automatically update `currentUser` with the latest data from cloud.

## Update User
After logged in, you can update your data that stored in cloud using method `saveAsync`.

```swift
let user = MFUser.currentUser()

// set default field
user.firstname = "Updated firstname"
user.lastname = "Updated lastname"

// set custom field
user["dateOfBirth"] = NSDate()
user["height"] = 177.5
user["weight"] = 78
user["isMarried"] = true

// execute update user
user.saveAsync { (succeeded, error) in
    if succeeded {
        // update succeeded
    } else {
        // update failed, show error message
    }
}
```

## Change Password
If you want to change your current password, use method `changePasswordAsync`:

```swift
let user = MFUser.currentUser()
user.changePasswordAsync(withOldPassword: oldPassword, 
                             newPassword: newPassword, block: { (succeeded, error) in
    if succeeded {
        // password changed successfully
    } else {
        // error happen, show error message
    }
})
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
