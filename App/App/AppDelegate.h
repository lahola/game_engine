//
//  AppDelegate.h
//  App
//
//  Created by Louis Ahola on 5/24/14.
//  Copyright (c) 2014 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "GLView.h"

@interface AppDelegate : UIResponder <UIApplicationDelegate> {
    GLView* view;
}

@property (strong, nonatomic) UIWindow *window;

@end
