//
//  ViewController.h
//  GoogleOAuthDemo
//
//  Created by qingjiezhao on 5/18/15.
//  Copyright (c) 2015 qingjiezhao. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GoogleOAuth.h"

@interface ViewController : UIViewController <UITableViewDataSource,UITableViewDelegate,GoogleOAuthDelegate>

@property (nonatomic, weak) IBOutlet UITableView *_table;
@property (nonatomic, strong) NSMutableArray *arrProfileInfo;
@property (nonatomic, strong) NSMutableArray *arrProfileInfoLabel;
@property (nonatomic, strong) GoogleOAuth *_googleOAuth;

- (IBAction)showProfile:(id)sender;
- (IBAction)revokeAccess:(id)sender;


@end

