# Mesosfer Starter Project for Android #


A Framework that gives you access to the powerful Mesosfer cloud platform from your iOS app. 
For more information about Mesosfer and its features, see [Mesosfer Website][mesosfer.com] and [Mesosfer Documentations][docs].

## Download
1. Download the latest Mesosfer framework [here][framework].
2. Then drag `Mesosfer.framework` into the `Frameworks` sections in your XCode project.
3. Ensure the following frameworks and a library exist in your project :
    - `SystemConfiguration.framework`
    - `Security.framework`
    - `QuartzCore.framework`
    - `CoreLocation.framework`
    - `CoreGraphics.framework`
    - `CFNetwork.framework`
    - `AudioToolbox.framework`
    - `libsqlite3.0.tbd`

## Setup
1. Register first to [Mesosfer Cloud][cloud]
2. Create an application to get `applicationId` and `clientKey`
3. Add this line below to your `Application` class to initialize Mesosfer SDK

```swift
Mesosfer.initialize(withApplicationId: "YOUR-APPLICATION-ID", 
                            clientKey: "YOUR-CLIENT-KEY")
```

(Optional) You can add some custom setup :

* Enable Mesosfer SDK debug logging by calling `Mesosfer.+setLogLevel:` before initialize SDK.
* Mesosfer `MFLogLevel` mode : `none`, `error`, `warning`, `info`, `debug`

Everything is done!

## License
    Copyright (c) 2016, Mesosfer.
    All rights reserved.

    This source code is licensed under the BSD-style license found in the
    LICENSE file in the root directory of this source tree.

[mesosfer.com]:https://mesosfer.com
[docs]:https://docs.mesosfer.com/
[cloud]:https://cloud.mesosfer.com/
[framework]:https://github.com/mesosfer/Mesosfer-Android/releases/latest