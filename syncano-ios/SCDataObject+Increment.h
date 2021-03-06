//
//  SCDataObject+Increment.h
//  syncano-ios
//
//  Created by Jakub Machoń on 04.02.2016.
//  Copyright © 2016 Syncano. All rights reserved.
//

#import "SCDataObject.h"

@interface SCDataObject (Increment)

- (void)incrementKeys:(NSDictionary<NSString*,NSNumber*>*)keys usingAPIClient:(SCAPIClient *)apiClient withCompletion:(SCCompletionBlock)completion revisionMismatchValidationBlock:(SCDataObjectRevisionMismatchCompletionBlock)revisionMismatchBlock;

@end
