//
//  SCFileManager.h
//  syncano-ios
//
//  Created by Jan Lipmann on 05/01/16.
//  Copyright © 2016 Syncano. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCConstants.h"


@interface SCFileManager : NSObject
+ (NSString *)syncanoDocumentsDirectoryPath;
+ (NSString *)syncanoDBFilePath;
@end

@class SCRequest;

@interface SCFileManager (Request)
+ (void)writeAsyncSerializedRequest:(SCRequest *)request queueIdentifier:(NSString *)queueIdentifier completionBlock:(SCCompletionBlock)completionBlock;
@end
