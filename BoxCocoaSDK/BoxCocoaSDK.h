//
//  BoxCocoaSDK.h
//  BoxCocoaSDK
//
//  Created on 7/29/13.
//  Copyright (c) 2013 Box. All rights reserved.
//
//  NOTE: this file is a mirror of BoxSDK/BoxSDK.h. Changes made here should be reflected there.
//

#import <Foundation/Foundation.h>
// constants and logging
#import "BoxSDKConstants.h"
#import "BoxLog.h"
#import "BoxSDKErrors.h"

// OAuth2
//#import "BoxAuthorizationViewController.h"
#import "BoxOAuth2Session.h"
#import "BoxSerialOAuth2Session.h"
#import "BoxParallelOAuth2Session.h"

// API Operation queues
#import "BoxAPIQueueManager.h"
#import "BoxSerialAPIQueueManager.h"
#import "BoxParallelAPIQueueManager.h"

// API Operations
#import "BoxAPIOperation.h"
#import "BoxAPIOAuth2ToJSONOperation.h"
#import "BoxAPIAuthenticatedOperation.h"
#import "BoxAPIJSONOperation.h"
#import "BoxAPIMultipartToJSONOperation.h"
#import "BoxAPIDataOperation.h"

// Request building
#import "BoxAPIRequestBuilder.h"
#import "BoxFilesRequestBuilder.h"
#import "BoxFoldersRequestBuilder.h"
#import "BoxSharedObjectBuilder.h"
#import "BoxUsersRequestBuilder.h"

// API Resource Managers
#import "BoxAPIResourceManager.h"
#import "BoxFilesResourceManager.h"
#import "BoxFoldersResourceManager.h"
#import "BoxUsersResourceManager.h"

// API models
#import "BoxModel.h"
#import "BoxCollection.h"
#import "BoxItem.h"
#import "BoxFile.h"
#import "BoxFolder.h"
#import "BoxUser.h"
#import "BoxWebLink.h"

extern NSString *const BoxAPIBaseURL;

/**
 * The BoxCocoaSDK class is a class that exposes a [Box V2 API Rest Client](http://developers.box.com/docs/).
 *
 * Access to this class and all other components of the BoxCocoaSDK can be granted by including `"BoxCocoaSDK.h"`
 * in your source code.
 *
 * This class provides a class method sharedSDK which provides a preconfigured SDK client,
 * including a BoxOAuth2Session and a BoxAPIQueueManager.
 *
 * This class also exposes several BoxAPIResourceManager instances. These include:
 *
 * - BoxFilesResourceManager
 * - BoxFoldersResourceManager
 *
 * This class may be instantiated directly. It is up to the caller to connect the BoxOAuth2Session and
 * BoxAPIQueueManager to the BoxAPIResourceManager instances in this case.
 *
 * @warning If you wish to support multiple BoxOAuth2Session instances (multi-account support),
 * the recommended approach is to instantiate multiple instances of BoxCocoaSDK. Each BoxCocoaSDK instance's
 * OAuth2Session and queueManager hold references to each other to enable automatic token refresh.
 */

@interface BoxCocoaSDK : NSObject
/** @name SDK client objects */

/** The base URL for all API operations including OAuth2. */
@property (nonatomic, readwrite, strong) NSString *APIBaseURL;

/**
 * The BoxCocoaSDK's OAuth2 session. This session is shared with the queueManager,
 * filesManager, and foldersManager.
 */
@property (nonatomic, readwrite, strong) BoxOAuth2Session *OAuth2Session;

/**
 * The BoxCocoaSDK's queue manager. All API calls are scheduled by this queue manager.
 * The queueManager is shared with the OAuth2Session (for making authorization and refresh
 * calls) and the filesManager and foldersManager (for making API calls).
 */
@property (nonatomic, readwrite, strong) BoxAPIQueueManager *queueManager;

/** @name API resource managers */

/**
 * The filesManager grants the ability to make API calls related to files on Box.
 * These API calls include getting file information, uploading new files, uploading
 * new file versions, and downloading files.
 */
@property (nonatomic, readwrite, strong) BoxFilesResourceManager *filesManager;

/**
 * The foldersManager grants the ability to make API calls related to folders on Box.
 * These API calls include getting file information, listing the contents of a folder,
 * and managing the trash.
 */
@property (nonatomic, readwrite, strong) BoxFoldersResourceManager *foldersManager;

/**
 * The usersManager grants the ability to make API calls related to users on Box.
 * These API calls include getting user information, getting the currently authorized
 * user's information, and admin user management.
 */
@property (nonatomic, readwrite, strong) BoxUsersResourceManager *usersManager;

#pragma mark - Globally accessible API singleton instance
/** @name Shared SDK client */

/**
 * Returns the BoxCocoaSDK's default SDK client
 *
 * This method is guaranteed to only instantiate one sharedSDK over the lifetime of an app.
 *
 * This client must be configured with your client ID and client secret (see the
 * [Box OAuth2 documentation](http://developers.box.com/oauth/)). One possibility is to
 * configure the SDK in your application's App Delegate like so:
 *
 * <pre><code>// somewhere in your application delegate's - (BOOL)application:didFinishLaunchingWithOptions:
 * [BoxCocoaSDK sharedSDK].OAuth2Session.clientID = @"your_client_ID";
 * [BoxCocoaSDK sharedSDK].OAuth2Session.clientSecret = @"your_client_secret";</pre></code>
 *
 * *Note*: sharedSDK returns a BoxCocoaSDK configured with a BoxParallelOAuth2Session and a BoxParallelAPIQueueManager.
 *   These allow for up to 10 parallel uploads and 10 parallel downloads, while still providing threadsafe
 *   OAuth2 tokens.
 * @return a preconfigured SDK client
 */
+ (BoxCocoaSDK *)sharedSDK;

#pragma mark - Setters
/** @name Setters */

/**
 * Sets the SDK client API base URL and sets the URL on OAuth2Session and instances of BoxAPIResourceManager
 *
 * @param APIBaseURL An NSString containing the API base URL. The
 *   [Box API V2 documentation](http://developers.box.com/docs/#api-basics) states that this url is
 *   https://api.box.com. This String should not include the API Version
 */
- (void)setAPIBaseURL:(NSString *)APIBaseURL;

#pragma mark - Ressources Bundle
/** @name Ressources Bundle */

/**
 * The bundle containing SDK resource assets and icons.
 */
+ (NSBundle *)resourcesBundle;

@end
