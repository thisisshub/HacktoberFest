//
//  JeweledCountdownTimer.swift
//  JeweledKit
//
//  Created by Борис Анели on 17.09.2020.
//

import Foundation

public protocol JeweledCountdownTimerDelegate: class {
    func countdownTimerDidUpdate(_ timer: JeweledCountdownTimer, timeLeft: JeweledCountdownTimer.Time)
    func didFinishCountdown(_ timer: JeweledCountdownTimer)
}

public class JeweledCountdownTimer {
    
    public struct Time {
        
        public let seconds: Int
        public let minutes: Int
        public let hours: Int
        public let timeInterval: TimeInterval
        
        init(timeInterval: TimeInterval) {
            self.hours = Int((timeInterval / .hour).truncatingRemainder(dividingBy: .minute))
            self.minutes = Int((timeInterval / .minute).truncatingRemainder(dividingBy: .minute))
            self.seconds = Int(timeInterval.truncatingRemainder(dividingBy: .minute))
            
            self.timeInterval = timeInterval
        }
    }
    
    public weak var delegate: JeweledCountdownTimerDelegate?
    
    private weak var timer: Timer?
    
    private var countdownSeconds: TimeInterval?
    private var seconds: TimeInterval? {
        didSet {
            countdownSeconds = seconds
        }
    }
    
    deinit {
        timer?.invalidate()
    }
    
    public func fire(seconds: TimeInterval) {
        timer?.invalidate()
        
        self.seconds = round(seconds)
        delegate?.countdownTimerDidUpdate(self, timeLeft: Time(timeInterval: round(seconds)))
        
        let timer = Timer(timeInterval: 1.0,
                          target: self,
                          selector: #selector(fireTimer),
                          userInfo: nil,
                          repeats: true)
        self.timer = timer
        
        RunLoop.main.add(timer, forMode: .common)
    }
    
    public func stopTimer() {
        timer?.invalidate()
        timer = nil
    }
    
    @objc private func fireTimer() {
        guard var secondsLeft = countdownSeconds else {
            assertionFailure()
            return
        }
        
        secondsLeft -= 1
        countdownSeconds = secondsLeft
        
        delegate?.countdownTimerDidUpdate(self, timeLeft: Time(timeInterval: secondsLeft))
        
        if secondsLeft == 0 {
            timer?.invalidate()
            delegate?.didFinishCountdown(self)
        }
    }
}

