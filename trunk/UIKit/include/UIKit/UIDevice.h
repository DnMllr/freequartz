#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>

typedef enum {
    UIDeviceOrientationUnknown,
    UIDeviceOrientationPortrait,            
    UIDeviceOrientationPortraitUpsideDown,  
    UIDeviceOrientationLandscapeLeft,       
    UIDeviceOrientationLandscapeRight,      
    UIDeviceOrientationFaceUp,              
    UIDeviceOrientationFaceDown             
} UIDeviceOrientation;

typedef enum {
    UIDeviceBatteryStateUnknown,
    UIDeviceBatteryStateUnplugged,   
    UIDeviceBatteryStateCharging,    
    UIDeviceBatteryStateFull,        
} UIDeviceBatteryState;              

#define UIDeviceOrientationIsPortrait(orientation)  ((orientation) == UIDeviceOrientationPortrait || (orientation) == UIDeviceOrientationPortraitUpsideDown)
#define UIDeviceOrientationIsLandscape(orientation) ((orientation) == UIDeviceOrientationLandscapeLeft || (orientation) == UIDeviceOrientationLandscapeRight)

UIKIT_EXTERN_CLASS @interface UIDevice : NSObject {

    struct {
	
    } _uideviceFlags;
}

+ (UIDevice *)currentDevice;

- (void)beginGeneratingDeviceOrientationNotifications;      
- (void)endGeneratingDeviceOrientationNotifications;

#ifdef OBJC2
@property(nonatomic,readonly,retain) NSString    *name;              
@property(nonatomic,readonly,retain) NSString    *model;             
@property(nonatomic,readonly,retain) NSString    *localizedModel;    
@property(nonatomic,readonly,retain) NSString    *systemName;        
@property(nonatomic,readonly,retain) NSString    *systemVersion;     
@property(nonatomic,readonly) UIDeviceOrientation orientation;       
@property(nonatomic,readonly,retain) NSString    *uniqueIdentifier;  
@property(nonatomic,readonly,getter=isGeneratingDeviceOrientationNotifications) BOOL generatesDeviceOrientationNotifications;
@property(nonatomic,getter=isBatteryMonitoringEnabled) BOOL batteryMonitoringEnabled; 
@property(nonatomic,readonly) UIDeviceBatteryState batteryState;  
@property(nonatomic,readonly) float batteryLevel; 
@property(nonatomic,getter=isProximityMonitoringEnabled) BOOL proximityMonitoringEnabled;
@property(nonatomic,readonly) BOOL proximityState ;
#else  /* OBJC2 */
- (NSString *)name;
- (NSString *)model;
- (NSString *)localizedModel;
- (NSString *)systemName;
- (NSString *)systemVersion;
- (UIDeviceOrientation)orientation;
- (NSString *)uniqueIdentifier;
- (BOOL)generatesDeviceOrientationNotifications;
- (BOOL)isGeneratingDeviceOrientationNotifications;
- (BOOL)batteryMonitoringEnabled;
- (BOOL)isBatteryMonitoringEnabled;
- (UIDeviceBatteryState)batteryState;
- (float)batteryLevel;
- (BOOL)proximityMonitoringEnabled;
- (BOOL)proximityState;
#endif /* OBJC2 */

@end

UIKIT_EXTERN NSString *const UIDeviceOrientationDidChangeNotification;
UIKIT_EXTERN NSString *const UIDeviceBatteryStateDidChangeNotification;
UIKIT_EXTERN NSString *const UIDeviceBatteryLevelDidChangeNotification;
UIKIT_EXTERN NSString *const UIDeviceProximityStateDidChangeNotification;
