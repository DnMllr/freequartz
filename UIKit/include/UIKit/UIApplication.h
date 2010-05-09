#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIResponder.h>
#import <UIKit/UIInterface.h>
#import <UIKit/UIDevice.h>
#import <UIKit/UIAlert.h>

typedef enum {

    UIStatusBarStyleDefault,
    UIStatusBarStyleBlackTranslucent,
    UIStatusBarStyleBlackOpaque
} UIStatusBarStyle;


typedef enum {

    UIInterfaceOrientationPortrait           = UIDeviceOrientationPortrait,
    UIInterfaceOrientationPortraitUpsideDown = UIDeviceOrientationPortraitUpsideDown,
    UIInterfaceOrientationLandscapeLeft      = UIDeviceOrientationLandscapeRight,
    UIInterfaceOrientationLandscapeRight     = UIDeviceOrientationLandscapeLeft
} UIInterfaceOrientation;

#define UIDeviceOrientationIsValidInterfaceOrientation(orientation)  \
((orientation) == UIDeviceOrientationPortrait ||                     \
 (orientation) == UIDeviceOrientationPortraitUpsideDown ||           \
 (orientation) == UIDeviceOrientationLandscapeLeft ||                \
 (orientation) == UIDeviceOrientationLandscapeRight)

#define UIInterfaceOrientationIsPortrait(orientation)       \
((orientation) == UIInterfaceOrientationPortrait ||         \
 (orientation) == UIInterfaceOrientationPortraitUpsideDown)

#define UIInterfaceOrientationIsLandscape(orientation)    \
((orientation) == UIInterfaceOrientationLandscapeLeft ||  \
 (orientation) == UIInterfaceOrientationLandscapeRight)

typedef enum {
    UIRemoteNotificationTypeNone    = 0,
    UIRemoteNotificationTypeBadge   = 1 << 0,
    UIRemoteNotificationTypeSound   = 1 << 1,
    UIRemoteNotificationTypeAlert   = 1 << 2
} UIRemoteNotificationType;

@class UIView, UIWindow;
@protocol UIApplicationDelegate;

UIKIT_EXTERN_CLASS @interface UIApplication : UIResponder <UIActionSheetDelegate>
{
  
    struct {
    // ...
    } _uiapplicationFlags;
}

+ (UIApplication *)sharedApplication;

- (void)beginIgnoringInteractionEvents;               
- (void)endIgnoringInteractionEvents;
- (BOOL)isIgnoringInteractionEvents;                  
- (BOOL)openURL:(NSURL*)url;
- (BOOL)canOpenURL:(NSURL *)url;
- (void)sendEvent:(UIEvent *)event;
- (BOOL)sendAction:(SEL)action to:(id)target from:(id)sender forEvent:(UIEvent *)event;
- (void)setStatusBarStyle:(UIStatusBarStyle)statusBarStyle animated:(BOOL)animated;
- (void)setStatusBarHidden:(BOOL)hidden animated:(BOOL)animated;
- (void)setStatusBarOrientation:(UIInterfaceOrientation)interfaceOrientation animated:(BOOL)animated;

#ifdef OBJC2
@property(nonatomic,assign) id<UIApplicationDelegate> delegate;
@property(nonatomic,getter=isIdleTimerDisabled) BOOL idleTimerDisabled;
@property(nonatomic,readonly) UIWindow *keyWindow;
@property(nonatomic,readonly) NSArray  *windows;
@property(nonatomic,getter=isNetworkActivityIndicatorVisible) BOOL networkActivityIndicatorVisible; 
@property(nonatomic) UIStatusBarStyle statusBarStyle; 
@property(nonatomic,getter=isStatusBarHidden) BOOL statusBarHidden;
@property(nonatomic) UIInterfaceOrientation statusBarOrientation;
@property(nonatomic,readonly) NSTimeInterval statusBarOrientationAnimationDuration;
@property(nonatomic,readonly) CGRect statusBarFrame; 
@property(nonatomic) NSInteger applicationIconBadgeNumber;
@property(nonatomic) BOOL applicationSupportsShakeToEdit;
#else /* OBJC2 */

//delegate
id<UIApplicationDelegate> delegate;
- (id)delegate;
- (void)setDelegate:(id)theDelegate;
//idleTimerDisabled
BOOL idleTimerDisabled;
- (BOOL)isIdleTimerDisabled;
- (void)setIdleTimerDisabled:(BOOL)theIdleTimer;
//keyWindow
UIWindow *keyWindow;
- (UIWindow *)keyWindow;
//windows
NSArray  *windows;
- (UIWindow *)windows;
//networkActivityIndicatorVisible
BOOL networkActivityIndicatorVisible;
- (BOOL)isNetworkActivityIndicatorVisible;
- (void)setNetworkActivityIndicatorVisible:(BOOL)networkActivityIndicatorVisibleFlag;
//statusBarStyle
 UIStatusBarStyle statusBarStyle;
- (UIStatusBarStyle)statusBarStyle;
- (void)setStatusBarStyle:(UIStatusBarStyle)theStatusBarStyle;
//statusBarHidden
BOOL statusBarHidden;
- (BOOL)isStatusBarHidden;
- (void)setStatusBarHidden:(BOOL)statusBarHiddenFlag;
//statusBarOrientation
UIInterfaceOrientation statusBarOrientation;
- (UIInterfaceOrientation)statusBarOrientation;
- (void)setStatusBarOrientation:(UIInterfaceOrientation)theStatusBarOrientation;
//statusBarOrientationAnimationDuration
 NSTimeInterval statusBarOrientationAnimationDuration;
- (NSTimeInterval)statusBarOrientationAnimationDuration;
//statusBarFrame
CGRect statusBarFrame;
- (CGRect)statusBarFrame;
//applicationIconBadgeNumber
NSInteger applicationIconBadgeNumber;
- (NSInteger)applicationIconBadgeNumber;
- (void)setApplicationIconBadgeNumber:(NSInteger)theApplicationIconBadgeNumber;
//applicationSupportsShakeToEdit
BOOL applicationSupportsShakeToEdit;
- (BOOL)applicationSupportsShakeToEdit;
- (void)setApplicationSupportsShakeToEdit:(BOOL)applicationSupportsShakeToEditFlag;
#endif /* OBJC2 */

@end

@interface UIApplication (UIRemoteNotifications)

- (void)registerForRemoteNotificationTypes:(UIRemoteNotificationType)types;
- (void)unregisterForRemoteNotifications;
- (UIRemoteNotificationType)enabledRemoteNotificationTypes;

@end

#ifdef OBJC2
@protocol UIApplicationDelegate<NSObject>

@optional

- (void)applicationDidFinishLaunching:(UIApplication *)application;
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
- (void)applicationDidBecomeActive:(UIApplication *)application;
- (void)applicationWillResignActive:(UIApplication *)application;
- (BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)url;  
- (void)applicationDidReceiveMemoryWarning:(UIApplication *)application;      
- (void)applicationWillTerminate:(UIApplication *)application;
- (void)applicationSignificantTimeChange:(UIApplication *)application;        
- (void)application:(UIApplication *)application willChangeStatusBarOrientation:(UIInterfaceOrientation)newStatusBarOrientation duration:(NSTimeInterval)duration;
- (void)application:(UIApplication *)application didChangeStatusBarOrientation:(UIInterfaceOrientation)oldStatusBarOrientation;
- (void)application:(UIApplication *)application willChangeStatusBarFrame:(CGRect)newStatusBarFrame;   
- (void)application:(UIApplication *)application didChangeStatusBarFrame:(CGRect)oldStatusBarFrame;
- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;
- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error;
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo;

@end
#else /* OBJC2 */
@interface NSObject (UIApplicationDelegate)

- (void)applicationDidFinishLaunching:(UIApplication *)application;
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
- (void)applicationDidBecomeActive:(UIApplication *)application;
- (void)applicationWillResignActive:(UIApplication *)application;
- (BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)url;  
- (void)applicationDidReceiveMemoryWarning:(UIApplication *)application;      
- (void)applicationWillTerminate:(UIApplication *)application;
- (void)applicationSignificantTimeChange:(UIApplication *)application;        
- (void)application:(UIApplication *)application willChangeStatusBarOrientation:(UIInterfaceOrientation)newStatusBarOrientation duration:(NSTimeInterval)duration;
- (void)application:(UIApplication *)application didChangeStatusBarOrientation:(UIInterfaceOrientation)oldStatusBarOrientation;
- (void)application:(UIApplication *)application willChangeStatusBarFrame:(CGRect)newStatusBarFrame;   
- (void)application:(UIApplication *)application didChangeStatusBarFrame:(CGRect)oldStatusBarFrame;
- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;
- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error;
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo;

@end
#endif /* OBJC2 */

@interface UIApplication(UIApplicationDeprecated)

#ifdef OBJC2
@property(nonatomic,getter=isProximitySensingEnabled) BOOL proximitySensingEnabled;
#else /* OBJC2 */
- (BOOL)isProximitySensingEnabled;
- (void)setProximitySensingEnabled:(BOOL)proximitySensingEnabledFlag;
#endif /* OBJC2 */
@end


UIKIT_EXTERN int UIApplicationMain(int argc, char *argv[], NSString *principalClassName, NSString *delegateClassName);

UIKIT_EXTERN NSString *const UITrackingRunLoopMode;
UIKIT_EXTERN NSString *const UIApplicationDidFinishLaunchingNotification;
UIKIT_EXTERN NSString *const UIApplicationDidBecomeActiveNotification;
UIKIT_EXTERN NSString *const UIApplicationWillResignActiveNotification;
UIKIT_EXTERN NSString *const UIApplicationDidReceiveMemoryWarningNotification;
UIKIT_EXTERN NSString *const UIApplicationWillTerminateNotification;
UIKIT_EXTERN NSString *const UIApplicationSignificantTimeChangeNotification;
UIKIT_EXTERN NSString *const UIApplicationWillChangeStatusBarOrientationNotification; 
UIKIT_EXTERN NSString *const UIApplicationDidChangeStatusBarOrientationNotification;
UIKIT_EXTERN NSString *const UIApplicationStatusBarOrientationUserInfoKey;          
UIKIT_EXTERN NSString *const UIApplicationWillChangeStatusBarFrameNotification;     
UIKIT_EXTERN NSString *const UIApplicationDidChangeStatusBarFrameNotification;      
UIKIT_EXTERN NSString *const UIApplicationStatusBarFrameUserInfoKey;                
UIKIT_EXTERN NSString *const UIApplicationLaunchOptionsURLKey;
UIKIT_EXTERN NSString *const UIApplicationLaunchOptionsSourceApplicationKey;
UIKIT_EXTERN NSString *const UIApplicationLaunchOptionsRemoteNotificationKey;
