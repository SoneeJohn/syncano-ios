# Syncano iOS Library

## Overview
---

Syncano's iOS library is written in Objective-C and provides communication with Syncano ([www.syncano.com](http://www.syncano.com/)) via HTTPS RESTful interface and TCP sockets.

Its full source code can be found in GitHub, feel free to browse it, and contribute! 

[Syncano iOS on GitHub](https://github.com/Syncano/syncano-ios)

Click here to learn more about [Syncano](http://www.syncano.com) or [create an account!](https://login.syncano.com/sign_up)

## Build Library
-------------

We are using CocoaPods for external libraries dependencies and their installation. You have to install CocoaPods plugin and use it to install external libraries we depend on. 
 
To install CocoaPods on your Mac type: 

	$ [sudo] gem install cocoapods

To install libraries used by `syncano-ios` execute command in the same directory as 'Podfile' file:

	$ pod install

To compile the library you should use `syncano-ios.xcworkspace` not `.xcodeproj`!

## Downloading
---

You can download archived sources of the latest version of Syncano’s iOS Library by right clicking on following link and choosing “Save As…”:

[syncano-ios archive on GitHub](https://github.com/Syncano/syncano-ios/archive/master.zip)

Our library depends on following third party frameworks, so you will need to download them as well:

[CocoaAsyncSocket](https://github.com/robbiehanson/CocoaAsyncSocket)
 
[AFNetworking](https://github.com/AFNetworking/AFNetworking)

[Mantle](https://github.com/Mantle/Mantle)

If you want to use CocoaPods, add this to your Podfile:

```bash
pod ‘syncano-ios’, ‘~>3.1.1’
```
	
## Installing
---

Unzip previously downloaded files, drag the `.xcodeproject` files to your project/workspace, and add their targets as your app dependency.

If you use CocoaPods, after adding our library to your Podfile, type the following into your terminal:

	$ pod install

## Modification
------------

To add external library dependency, edit 'Podfile' in main directory and type:

	pod 'library name' 

To remove external library, remove line with this library in 'Podfile', save it and execute command:

	$ pod install

Documentation and further information on CocoaPods available: http://cocoapods.org/

## Documentation
-------------

 Appledoc documentation can be generated by building a `Documentation` target in `syncano-ios.xcworkspace`. Docs will be in `Syncano-Docs` directory and will be installed to Xcode documentation, too. In case something is wrong, logs are put into `appledoc.log` file. Before that `appledoc` should be installed, available at [https://github.com/tomaz/appledoc/](https://github.com/tomaz/appledoc/).

 For writing documentation, it is recommended to use [`VVDocumenter` XCode plugin](https://github.com/onevcat/VVDocumenter-Xcode). It makes writing correctly structured documentation a little easier. Simply place cursor above method/class/anything you wish to describe, and type `///` to generate a documentation template snippet for that item.

## Getting started
---

### Import Syncano header

```objective-c
/// Used for REST connection
#import <Syncano/Syncano.h>
```

### Create main Syncano object 
(This will be used to send requests to your instance of Syncano.):

```objective-c
Syncano *syncano = [Syncano syncanoForDomain:@“YOUR-SYNCANO-DOMAIN” apiKey:@“YOUR-API-KEY-123456”];
```

### Send data to Syncano 
(Use a project ID and collection ID from your admin GUI, i.e. YourDomain.syncano.com, for the below. You can use the “default” values or create your own.):

```objective-c
NSString *textToSend = @“Some sample text”;
UIImage *imageToSend = [UIImage imageNamed:@“sampleImage.png”];

SyncanoParameters_DataObjects_New *params = [[SyncanoParameters_DataObjects_New alloc] initWithProjectId:@“PROJECT_ID” collectionId:@“COLLECTION_ID” state:@"pending"];
params.text = textToSend;
params.image = imageToSend;

///For an asynchronous connection, enter the below and work with the returned response
[syncano dataNew:params callback:^(SyncanoResponse_DataObjects_New *response) {
	if (response.isResponseOK) {
	}
}
```

### Download data from Syncano:

```objective-c
///Describe what you want to download by using parameters
SyncanoParameters_DataObjects_Get *params = [[SyncanoParameters_DataObjects_Get alloc] initWithProjectId:@“PROJECT_ID” collectionId:@“COLLECTION_ID”];
params.dataId = @“123456”; // set if you want to download one particular object. Leave empty if you want to download all objects from that collection

///For an asynchronous connection, enter the below and work with the returned response
	[syncano dataGet:params callback:^(SyncanoResponse_DataObjects_Get *response) {
	if (response.isResponseOK) {
		SyncanoData *data = response.data;
	}
}
```

We also offer synchronous connections if you’d like to manage threading yourself. You can use the exact same methods to connect with Syncano using TCP socket - just use SyncanoSyncServer class object instead of Syncano class.

## License

Syncano's iOS Library (syncano-ios) is available under the MIT license. See the LICENSE file for more info.
