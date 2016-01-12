//
//  SCAPIClient.h
//  syncano4-ios
//
//  Created by Jan Lipmann on 27/03/15.
//  Copyright (c) 2015 Syncano. All rights reserved.
//

#import "AFNetworking/AFHTTPSessionManager.h"
#import "SCConstants.h"

@class Syncano, SCRequest;

/**
 *  Base class for API calls
 */
@interface SCAPIClient : AFHTTPSessionManager


/**
 *  Creates API Client for provided Syncano instance
 *
 *  @param syncano Syncano instance
 *
 *  @return SCAPIClient object
 */
+ (SCAPIClient *)apiClientForSyncano:(Syncano *)syncano;

- (void)setSocialAuthTokenKey:(NSString *)authToken;

/**
 *  "Abstract" method to GET method call
 *
 *  @param path       path to request endpoint
 *  @param params     NSDictionary with params for request
 *  @param completion SCAPICompletionBlock completion callback block
 *
 *  @return void
 */
- (void)GETWithPath:(NSString *)path params:(NSDictionary *)params completion:(SCAPICompletionBlock)completion;

/**
 *  "Abstract" method to POST method call
 *
 *  @param path       path to request endpoint
 *  @param params     NSDictionary with params for request
 *  @param completion SCAPICompletionBlock completion callback block
 *
 *  @return void
 */
- (void)POSTWithPath:(NSString *)path params:(NSDictionary *)params completion:(SCAPICompletionBlock)completion;

/**
 *  "Abstract" method to PUT method call
 *
 *  @param path       path to request endpoint
 *  @param params     NSDictionary with params for request
 *  @param completion SCAPICompletionBlock completion callback block
 *
 *  @return void
 */
- (void)PUTWithPath:(NSString *)path params:(NSDictionary *)params completion:(SCAPICompletionBlock)completion;

/**
 *  "Abstract" method to PATCH method call
 *
 *  @param path       path to request endpoint
 *  @param params     NSDictionary with params for request
 *  @param completion SCAPICompletionBlock completion callback block
 *
 *  @return void
 */
- (void)PATCHWithPath:(NSString *)path params:(NSDictionary *)params completion:(SCAPICompletionBlock)completion;

/**
 *  "Abstract" method to DELETE method call
 *
 *  @param path       path to request endpoint
 *  @param params     NSDictionary with params for request
 *  @param completion SCAPICompletionBlock completion callback block
 *
 *  @return NSURLSessionDataTask object
 */
- (void)DELETEWithPath:(NSString *)path params:(NSDictionary *)params completion:(SCAPICompletionBlock)completion;


- (void)POSTUploadWithPath:(NSString *)path propertyName:(NSString *)propertyName fileData:(NSData *)fileData completion:(SCAPICompletionBlock)completion;

@end

@interface SCAPIClient (Reachability)
- (void)initializeReachabilityManager;
- (BOOL)reachable;
@end
