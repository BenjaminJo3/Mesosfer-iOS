//
//  FormDataViewController.swift
//  Mesosfer-Swift
//
//  Created by Eyro Labs on 11/5/16.
//  Copyright © 2016 Eyro Labs. All rights reserved.
//

import Foundation
import UIKit
import Mesosfer

protocol FormDataViewControllerDelegate {
    func onSavedData(beacon: MFData, isNewData: Bool)
}

class FormDataViewController: UITableViewController {
    @IBOutlet weak var textUUID: UITextField!
    @IBOutlet weak var textMajor: UITextField!
    @IBOutlet weak var textMinor: UITextField!
    @IBOutlet weak var switchIsActive: UISwitch!
    
    var delegate: FormDataViewControllerDelegate? = nil
    
    @IBAction func saveSelector(_ sender: UIBarButtonItem) {
        let bucket = "Beacon"
        let proximityUUID = self.textUUID.text
        let major = Int(self.textMajor.text!)
        let minor = Int(self.textMinor.text!)
        let isActive = self.switchIsActive.isOn
        let timestamp = NSDate()
        
        let beacon = MFData(withBucket: bucket)
        beacon["proximityUUID"] = proximityUUID
        beacon["major"] = major
        beacon["minor"] = minor
        beacon["isActive"] = isActive
        beacon["timestamp"] = timestamp
        beacon.saveAsync { (succeeded, error) in
            if succeeded {
                self.showAlert(message: "Data beacon saved", handler: { (action) in
                    guard let delegate = self.delegate else {
                        return
                    }
                    delegate.onSavedData(beacon: beacon, isNewData: true)
                    _ = self.navigationController?.popViewController(animated: true)
                })
            } else {
                self.showError(title: "Failed to save data", error: error as! NSError)
            }
        }
    }
    
}
