/**
 * Copyright (c) 2016, Mesosfer
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import "QueryDataViewController.h"
#import "UIViewController+Helper.h"
#import <Mesosfer/Mesosfer.h>
#import "FormDataViewController.h"

@interface QueryDataViewController () <FormDataViewControllerDelegate>

@property (nullable, nonatomic, strong) NSMutableArray<MFData *>* datas;

@end

@implementation QueryDataViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.tableView.estimatedRowHeight = 100;
    self.tableView.rowHeight = UITableViewAutomaticDimension;
    
    [self queryData];
}

- (void)queryData {
    NSString *bucket = @"Beacon";
    MFQuery *query = [MFData queryWithBucket:bucket];
    [query findAsyncWithBlock:^(NSArray * _Nullable objects, NSError * _Nullable error) {
        if (error) {
            [self showErrorWithTitle:@"Query data failed" error:error handler:nil];
            return;
        }
        
        if (objects) {
            self.title = [NSString stringWithFormat:@"Query '%@'", bucket];
            self.datas = [NSMutableArray arrayWithArray:objects];
            [self.tableView reloadData];
        }
    }];
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    if ([segue.identifier isEqualToString:@"segueAdd"]) {
        FormDataViewController *formView = segue.destinationViewController;
        formView.delegate = self;
    }
}

#pragma mark - UITableViewDelegate

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    if (self.datas) {
        return self.datas.count;
    }
    
    return 0;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return 1;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
    if (self.datas) {
        return self.datas[section].objectId;
    }
    return nil;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cellData" forIndexPath:indexPath];
    
    if (self.datas) {
        MFData *data = self.datas[indexPath.section];
        
        if ([data dictionary]) {
            cell.textLabel.text = [NSString stringWithFormat:@"%@", [data dictionary]];
        }
    }
    
    return cell;
}

- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath {
    if (editingStyle == UITableViewCellEditingStyleDelete) {
        if (self.datas) {
            MFData *data = self.datas[indexPath.section];
            [data deleteAsyncWithBlock:^(BOOL succeeded, NSError * _Nullable error) {
                if (succeeded) {
                    // remove deleted data from array
                    [self.datas removeObjectAtIndex:indexPath.section];
                    // update table data
                    [self.tableView beginUpdates];
                    [self.tableView deleteSections:[NSIndexSet indexSetWithIndex:indexPath.section]
                                  withRowAnimation:UITableViewRowAnimationAutomatic];
                    [self.tableView endUpdates];
                } else {
                    [self showErrorWithTitle:@"Delete data failed" error:error handler:nil];
                }
            }];
        }
    }
}

#pragma mark - FormDataViewControllerDelegate

- (void)onSavedDataBeacon:(MFData *)beacon isNewData:(BOOL)isNewData {
    if (isNewData) {
        // append new saved data into array
        if (!self.datas) {
            self.datas = [[NSMutableArray alloc] init];
        }
        [self.datas addObject:beacon];
        // update table data
        [self.tableView beginUpdates];
        [self.tableView insertSections:[NSIndexSet indexSetWithIndex:(self.datas.count - 1)]
                      withRowAnimation:UITableViewRowAnimationAutomatic];
        [self.tableView endUpdates];
    }
}

@end
