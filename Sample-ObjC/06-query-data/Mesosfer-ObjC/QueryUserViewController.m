/**
 * Copyright (c) 2016, Mesosfer
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import "QueryUserViewController.h"
#import "UIViewController+Helper.h"
#import <Mesosfer/Mesosfer.h>

@interface QueryUserViewController () <UISearchBarDelegate>

@property (nullable, nonatomic, strong) NSArray<MFUser *>* users;

@end

@implementation QueryUserViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.tableView.estimatedRowHeight = 100;
    self.tableView.rowHeight = UITableViewAutomaticDimension;
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    
    [self queryUserWithUsername:nil];
}

- (void)queryUserWithUsername:(NSString*)username {
    MFQuery *query = [MFUser query];
    if (username) {
        [query whereKey:@"firstname" equalTo:username];
    }
    [query findAsyncWithBlock:^(NSArray * _Nullable objects, NSError * _Nullable error) {
        if (error) {
            [self showErrorWithTitle:@"Query user failed" error:error handler:nil];
            return;
        }
        
        if (objects) {
            self.users = objects;
            [self.tableView reloadData];
        }
    }];
}

#pragma mark - UITableViewDelegate

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    if (self.users) {
        return self.users.count;
    }
    
    return 0;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return 1;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
    if (self.users) {
        return self.users[section].objectId;
    }
    return nil;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cellUser" forIndexPath:indexPath];
    
    if (self.users) {
        MFUser *user = self.users[indexPath.section];
        
        if ([user dictionary]) {
            cell.textLabel.text = [NSString stringWithFormat:@"%@", [user dictionary]];
        }
    }
    
    return cell;
}

#pragma mark - UISearchBarDelegate

- (void)searchBarSearchButtonClicked:(UISearchBar *)searchBar {
    searchBar.showsCancelButton = YES;
    [self queryUserWithUsername:searchBar.text];
}

- (void)searchBarCancelButtonClicked:(UISearchBar *)searchBar {
    searchBar.showsCancelButton = NO;
    searchBar.text = nil;
    [self queryUserWithUsername:nil];
}

@end
