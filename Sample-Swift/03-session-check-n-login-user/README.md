# Mesosfer Starter Project for iOS #


A Framework that gives you access to the powerful Mesosfer cloud platform from your iOS app. 
For more information about Mesosfer and its features, see [Mesosfer Website][mesosfer.com] and [Mesosfer Documentations][docs].

## Session User
It would be bothersome if the user had to login every time they open your app. You can avoid this by using the cached `currentUser` object.

Whenever you use any `register` or `login` methods, the user is cached on disk. You can treat this cache as a session, and automatically assume the user is logged in:

```swift
if let user = MFUser.currentUser() {
    // user logged in, open main view
} else {
    // session not found, open login view
}
```
## Log In User
After you allow users to register, you need be able to let them login to their account in the future. To do this, you can use the class method `logInAsync`.

```swift
MFUser.logInAsync(withEmail: "username@mail.com", 
                   password: "myPlainPassword") { (user, error) in
    if let e = error as? NSError {
        // error happen, show error message
        return
    }
    
    // log in succeeded
}
```

## Log Out User
You can clear the current user by logging them out:

```swift
MFUser.logOutAsync { (error) in
    if let e = error as? NSError {
        // error happend, show error message
        return
    }
    
    // log out succeeded
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