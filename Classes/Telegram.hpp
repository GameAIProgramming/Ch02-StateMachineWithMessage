//
//  Telegram.hpp
//  Ai001_StateMachine
//
//  Created by 남준현 on 2015. 9. 24..
//  Copyright © 2015년 남준현. All rights reserved.
//

#pragma once

#include "MessageTypes.hpp"
#include <cmath>
#include <chrono>

class BaseEntity;

class Telegram
{
    
public:
    
    std::chrono::duration<double>                       dispatchTime;
    BaseEntity*                                         receiver;
    BaseEntity*                                         sender;
    MessageType                                         msg;
    void*                                               extraInfo;
    
    Telegram(double delaySeconds,
             BaseEntity* receiver,
             BaseEntity* sender,
             MessageType msg,
             void* info = nullptr) :
            receiver(receiver),
            sender(sender),
            msg(msg),
            extraInfo(info)
    {
        dispatchTime = std::chrono::duration<double>(delaySeconds);
    }
    
};

const long long smallestDelay = 0.25;

inline bool operator==(const Telegram& t1, const Telegram& t2)
{
    return (fabs(t1.dispatchTime.count() - t2.dispatchTime.count()) < smallestDelay) &&
    (t1.sender == t2.sender) &&
    (t1.receiver == t2.receiver) &&
    (t1.msg == t2.msg);
}

inline bool operator<(const Telegram& t1, const Telegram& t2)
{
    if (t1 == t2)
    {
        return false;
    }
    
    else
    {
        return  (t1.dispatchTime < t2.dispatchTime);
    }
}


















