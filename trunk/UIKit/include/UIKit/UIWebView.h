#import <Foundation/Foundation.h>
#import <UIKit/UIView.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIDataDetectors.h>

enum {

    UIWebViewNavigationTypeLinkClicked,
    UIWebViewNavigationTypeFormSubmitted,
    UIWebViewNavigationTypeBackForward,
    UIWebViewNavigationTypeReload,
    UIWebViewNavigationTypeFormResubmitted,
    UIWebViewNavigationTypeOther
};
typedef NSUInteger UIWebViewNavigationType;

@class UIWebViewInternal;
@protocol UIWebViewDelegate;

UIKIT_EXTERN_CLASS @interface UIWebView : UIView <NSCoding> { 
 
}

- (void)loadRequest:(NSURLRequest *)request;
- (void)loadHTMLString:(NSString *)string baseURL:(NSURL *)baseURL;
- (void)loadData:(NSData *)data MIMEType:(NSString *)MIMEType textEncodingName:(NSString *)textEncodingName baseURL:(NSURL *)baseURL;
- (void)reload;
- (void)stopLoading;
- (void)goBack;
- (void)goForward;
- (NSString *)stringByEvaluatingJavaScriptFromString:(NSString *)script;

#ifdef OBJC2
@property(nonatomic,assign) id<UIWebViewDelegate> delegate;
@property(nonatomic,readonly,retain) NSURLRequest *request;
@property(nonatomic,readonly,getter=canGoBack) BOOL canGoBack;
@property(nonatomic,readonly,getter=canGoForward) BOOL canGoForward;
@property(nonatomic,readonly,getter=isLoading) BOOL loading;
@property(nonatomic) BOOL scalesPageToFit;
@property(nonatomic) BOOL detectsPhoneNumbers;
@property(nonatomic) UIDataDetectorTypes dataDetectorTypes;
#else  /* OBJC2 */
// TODO
#endif /* OBJC2 */

@end

@protocol UIWebViewDelegate <NSObject>

@optional
- (BOOL)webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType;
- (void)webViewDidStartLoad:(UIWebView *)webView;
- (void)webViewDidFinishLoad:(UIWebView *)webView;
- (void)webView:(UIWebView *)webView didFailLoadWithError:(NSError *)error;

@end
