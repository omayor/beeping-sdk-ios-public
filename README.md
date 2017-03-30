## Beeping iOS SDK
Beeping iOS SDK allows any app to detect and react to audible and inaudible audio cookies called beeps.
This document will show you how to integrate our SDK into your app, configure it, and test to make sure it’s working properly.

## System Requirements

* You should be using a Mac, running OS X.
* You should have the latest version of Xcode.

## App Requirements

* Your App must request an AppId from our Development Team. You will need this key to initialize the Beeping SDK. *Get in touch at dev@beeping.io.*

## Installing the SDK on your App

##### 1. Download `Beeping.framework` folder

* Download `Beeping.framework` folder included in this repo:

    * `Beeping.framework`: Library containing Beeping's audio technology collection and code.

##### 2. Add `Beeping.framework` to your project

In Xcode, please do the following:
* Select the project file from the project navigator on the left side of the project window.
* Select the target for where you want to add frameworks in the project settings editor.
* Select the “Build Phases” tab, and click the small triangle next to “Link Binary With Libraries” to view all of the frameworks in your application.
* To Add frameworks, click the “+” below the list of frameworks.
* Find and add the `Beeping.framework` downloaded from the repo.
 
## Using the SDK

Inside your `ViewController.m` file, do the following:

##### 1. Initializing Beeping

* Import Beeping:
```
#import <Beeping/Beeping.h>
```
* Initialize Beeping with `beepingManager`:
```
Beeping *beepingManager;
```
##### 2. Adding observer with callback

* Add an observer, pointing to a callback function `getBeep`:
```
[NSNotificationCenter defaultCenter] addObserver:self
                                        selector:@selector(getBeep:)
                                            name:@"getBeep"
                                          object:nil];
```
##### 3. Instantiating Beeping and adding your AppId 

* Create an instance of `beepingManager`:
```
beepingManager = [Beeping instance];
```
* Add your `appId` to your `beepingManager` instance:
```
[beepingManager setAppId:@"thisisyourapplicationid"];
```
*IMPORTANT: This method requires an AppId. Please contact our team if you don't have one already.*

##### 4. Using Beeping methods

* Listening for beeps:
```
 [beepingManager listen]
```
*This function triggers your app to start listening for beeps.<br>
When we successfully detect and retrieve a beep, the callback is triggered.*

* Stop listening for beeps:
```
 [beepingManager stop];
```
*As the name suggests, this function triggers your app to stop listening for beeps.*

* Callback function when beep detected/retrieved:
```
- (void)getBeep:(NSNotification *)notification {
    
    NSDictionary *beep = [beepingManager beep] ;
    
    NSLog(@"This is your beep: %@", beep);
    
}
```
*IMPORTANT: When we successfully detect and retrieve a beep, the callback is triggered.<br>
This method will respond with a Beep JSONObject (sample provided below).*

##### Sample Response Beep JSONObject ()
```
  {
      "type": "url",
      "url": "https://www.youtube.com/watch?v=DiTECkLZ8HM",
      "title": "SPIDER-MAN: HOMECOMING - Official Trailer #2 (HD)",
      "brand": "YouTube",
      "imgSrc": "https://i.ytimg.com/vi/DiTECkLZ8HM/maxresdefault.jpg",
      "ogType": "video",
      "_id": "C9bPJJNtij6JAhKeS",
      "avatar": "https://s3.amazonaws.com/beepingfiles/images/beeping_avatar.png",
      "init": 0,
      "final": 10000,
      "createdAt": "2017-03-22T19:18:45.178Z",
      "updatedAt": "2017-03-22T19:18:45.180Z"
  }
```

## Sample iOS App with SDK

* In the `ViewController.m` file add:
```

#import "ViewController.h"

// Importing Beeping Library
#import <Beeping/Beeping.h>

@interface ViewController ()

@end

// Initializing Beeping with beepingManager
Beeping *beepingManager ;

@implementation ViewController

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
    // Adding observer with callback
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(getBeep:)
                                                 name:@"getBeep"
                                               object:nil];
    
    // Instantiating Beeping
    beepingManager = [Beeping instance];
    
    // Adding your provided Application Id
    [beepingManager setAppId:@"d9cb1f17116977cbacdfbe6ab3197589"] ;
    
    // Start listening for beeps
    [beepingManager listen] ;
    
    // Stop listening for beeps
    //[beepingManager stop];
}

- (void)addNotifications {
    
    [[NSNotificationCenter defaultCenter] removeObserver:self];
    
    
}

// Callback function handling response after beep is detected
- (void)getBeep:(NSNotification *)notification {
    
    NSDictionary *beep = [beepingManager beep] ;
    
    NSLog(@"This is your beep: %@", beep);
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.  
}


@end
```

### THE END