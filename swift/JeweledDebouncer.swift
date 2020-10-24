//
//  JeweledDebouncer.swift
//  JeweledKit
//
//  Created by Борис Анели on 19.09.2020.
//

import Foundation

public class JeweledDebouncer {
    
    private var workItem: DispatchWorkItem?
    private let delay: TimeInterval

    public init(delay: TimeInterval) {
        self.delay = delay
    }

    public func run(action: @escaping () -> Void) {
        workItem?.cancel()
        let workItem = DispatchWorkItem(block: action)
        self.workItem = workItem
        DispatchQueue.main.asyncAfter(deadline: .now() + delay, execute: workItem)
    }
}
