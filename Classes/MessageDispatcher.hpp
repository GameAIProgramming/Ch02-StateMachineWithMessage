//
//  MessageDispatcher.hpp
//  Ai001_StateMachine
//
//  Created by 남준현 on 2015. 9. 24..
//  Copyright © 2015년 남준현. All rights reserved.
//

#pragma once

#include <set>
#include <vector>
#include "MessageTypes.hpp"

class Telegram;
class BaseEntity;

#define Dispatch MessageDispatcher::getInstance()

class MessageDispatcher
{
    
private:
    
    std::set<Telegram>          _priorityQ;
    
    void _discharge(const Telegram& msg);
    
    MessageDispatcher() {};
    MessageDispatcher(const MessageDispatcher&) = delete;
    MessageDispatcher& operator=(const MessageDispatcher&) = delete;
    
public:
    
    static MessageDispatcher* getInstance();
    void pushMessage(double delaySeconds, BaseEntity* receiver, BaseEntity* sender, MessageType type, void* extraInfo);
    void dispatchDelayedMessages();
    std::vector<PushMessageQueueDataBundle> getUseableMessages() const;
    
};






