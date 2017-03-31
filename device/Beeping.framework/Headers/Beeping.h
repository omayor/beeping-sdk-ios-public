//
//  Beeping.h
//  Beeping
//
//  Created by Alfred on 21/10/2016.
//  Copyright © 2016 Beeping LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreTelephony/CTCarrier.h>
#import <CoreTelephony/CTTelephonyNetworkInfo.h>

#import "BeepingCore.h"

@interface Beeping : NSObject <NSURLConnectionDelegate> {
    
    // Private properties
    // HTTP REST control response
    NSMutableData *_responseData;
    
    NSURLConnection *_connection;
    
    long _httpStatus ;
    
    // Beeping object
    BeepingCore *_beepingCore;
    
    // Dictionary for storing all data of decoded beeps
    NSMutableDictionary *_beeps ;
    
    // Dictionary for storing all data of decoded beeps
    NSMutableDictionary *_beepTmp ;
    
    // Cache
    NSString *_beepId;
    NSString *_beepURL;
    NSString *_beepData;
    NSString *_appId;
    NSString *_uuId;
    NSString *_isoId;
    
    int _beepTimestamp;
    int _timerCounter ;
    
    // Timers
    NSTimer *_tPing ;
    NSTimer *_tBeep ;
    
}

    // Public properties

    // Singleton method
    +(Beeping *) instance;

    // Public methods
    -(void) setAppId:(NSString *)appid;
    -(void) listen;
    -(void) stop;

    // Dictionary for storing all data single beep being played
    @property (strong) NSDictionary *beep ;

@end


