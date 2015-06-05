//
//  GoogleOAuth.h
//  GoogleOAuthDemo
//
//  Created by qingjiezhao on 5/18/15.
//  Copyright (c) 2015 qingjiezhao. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol GoogleOAuthDelegate
-(void)authorizationWasSuccessful;
-(void)accessTokenWasRevoked;
-(void)responseFromServiceWasReceived:(NSString *)responseJSONAsString andResponseJSONAsData:(NSData *)responseJSONAsData;
-(void)errorOccuredWithShortDescription:(NSString *)errorShortDescription andErrorDetails:(NSString *)errorDetails;
-(void)errorInResponseWithBody:(NSString *)errorMessage;
@end



@interface GoogleOAuth : UIWebView <UIWebViewDelegate, NSURLConnectionDataDelegate>


typedef enum {
    httpMethod_GET,
    httpMethod_POST,
    httpMethod_DELETE,
    httpMethod_PUT
} HTTP_Method;


@property (nonatomic, strong) id<GoogleOAuthDelegate> gOAuthDelegate;


// The client ID from the Google Developers Console.
@property (nonatomic, strong) NSString *_clientID;
// The client secret value from the Google Developers Console.
@property (nonatomic, strong) NSString *_clientSecret;
// The redirect URI after the authorization code gets fetched. For mobile applications it is a standard value.
@property (nonatomic, strong) NSString *_redirectUri;
// The authorization code that will be exchanged with the access token.
@property (nonatomic, strong) NSString *_authorizationCode;
// The refresh token.
@property (nonatomic, strong) NSString *_refreshToken;
// An array for storing all the scopes we want authorization for.
@property (nonatomic, strong) NSMutableArray *_scopes;

// A NSURLConnection object.
@property (nonatomic, strong) NSURLConnection *_urlConnection;
// The mutable data object that is used for storing incoming data in each connection.
@property (nonatomic, strong) NSMutableData *_receivedData;

// The file name of the access token information.
@property (nonatomic, strong) NSString *_accessTokenInfoFile;
// The file name of the refresh token.
@property (nonatomic, strong) NSString *_refreshTokenFile;
// A dictionary for keeping all the access token information together.
@property (nonatomic, strong) NSMutableDictionary *_accessTokenInfoDictionary;

// A flag indicating whether an access token refresh is on the way or not.
@property (nonatomic) BOOL _isRefreshing;

// The parent view where the webview will be shown on.
@property (nonatomic, strong) UIView *_parentView;

-(void)authorizeUserWithClienID:(NSString *)client_ID andClientSecret:(NSString *)client_Secret
                  andParentView:(UIView *)parent_View andScopes:(NSArray *)scopes;

-(void)revokeAccessToken;
-(void)showWebviewForUserLogin;
-(void)exchangeAuthorizationCodeForAccessToken;
-(void)refreshAccessToken;



-(NSString *)urlEncodeString:(NSString *)stringToURLEncode;
-(void)storeAccessTokenInfo;
-(void)loadAccessTokenInfo;
-(void)loadRefreshToken;
-(BOOL)checkIfAccessTokenInfoFileExists;
-(BOOL)checkIfRefreshTokenFileExists;
-(BOOL)checkIfShouldRefreshAccessToken;
-(void)makeRequest:(NSMutableURLRequest *)request;

-(void)webViewDidFinishLoad:(UIWebView *)webView;

-(void)connection:(NSURLConnection *)connection didReceiveData:(NSData *)data;
-(void)connectionDidFinishLoading:(NSURLConnection *)connection;
-(void)connection:(NSURLConnection *)connection didFailWithError:(NSError *)error;
-(void)connection:(NSURLConnection *)connection didReceiveResponse:(NSURLResponse *)response;

-(void)callAPI:(NSString *)apiURL withHttpMethod:(HTTP_Method)httpMethod postParameterNames:(NSArray *)params postParameterValues:(NSArray *)values;

@end
