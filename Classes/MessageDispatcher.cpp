//
//  MessageDispatcher.cpp
//  Ai001_StateMachine
//
//  Created by 남준현 on 2015. 9. 24..
//  Copyright © 2015년 남준현. All rights reserved.
//

#include "MessageDispatcher.hpp"
#include "BaseEntity.hpp"
#include "Telegram.hpp"
#include "SceneListener.hpp"
#include <chrono>
#include "BBiBBi.hpp"
#include "MuscleMan.hpp"
#include "KidStone.hpp"

MessageDispatcher* MessageDispatcher::getInstance()
{
    static MessageDispatcher instance;
    return &instance;
}

void MessageDispatcher::_discharge(const Telegram& msg)
{
    if(msg.receiver->handleMessage(msg) == false)
    {
        // message is not dispatched,
        // push one seconed delayed same message.
        Dispatch->pushMessage(1.0, msg.receiver, msg.sender, msg.msg, msg.extraInfo);
    }
}

void MessageDispatcher::pushMessage(double delaySeconds,
                                    BaseEntity* receiver,
                                    BaseEntity* sender,
                                    MessageType type,
                                    void* extraInfo)
{
    Telegram tel(delaySeconds, receiver, sender, type, extraInfo);
    if(tel.dispatchTime <= std::chrono::duration<double>::zero())
    {
        _discharge(tel);
    }
    else
    {
        std::chrono::duration<double> curr = std::chrono::system_clock::now().time_since_epoch();
        tel.dispatchTime += curr;
        _priorityQ.insert(tel);
    }
}

void MessageDispatcher::dispatchDelayedMessages()
{
    std::chrono::duration<double> curr = std::chrono::system_clock::now().time_since_epoch();
    
    while (!_priorityQ.empty() &&
           (_priorityQ.begin()->dispatchTime < curr) &&
           (_priorityQ.begin()->dispatchTime >= std::chrono::duration<double>::zero()))
    {
        const Telegram& telegram = *_priorityQ.begin();
        _discharge(telegram);
        _priorityQ.erase(_priorityQ.begin());
    }
}

std::vector<PushMessageQueueDataBundle> MessageDispatcher::getUseableMessages() const
{
    std::vector<PushMessageQueueDataBundle> ret;
    
    for(auto &d : _priorityQ)
    {
        if(d.receiver == SceneLisner)
            continue;
        
        std::chrono::duration<double> sec = d.dispatchTime - std::chrono::system_clock::now().time_since_epoch();
        if(sec.count() <= 0.0)
            continue;
        
        std::string receiver;
        std::string sender;
        
        // get receiver
        if(dynamic_cast<MuscleMan*>(d.receiver) != nullptr)
        {
            receiver = "'근육맨'";
        }
        else if(dynamic_cast<BBiBBi*>(d.receiver) != nullptr)
        {
            receiver = "'삐삐'";
        }
        else if(dynamic_cast<KidStone*>(d.receiver) != nullptr)
        {
            receiver = "'꼬마돌'";
        }
        
        // get sender
        if(dynamic_cast<MuscleMan*>(d.sender) != nullptr)
        {
            sender = "'근육맨'";
        }
        else if(dynamic_cast<BBiBBi*>(d.sender) != nullptr)
        {
            sender = "'삐삐'";
        }
        else if(dynamic_cast<KidStone*>(d.sender) != nullptr)
        {
            sender = "'꼬마돌'";
        }
        
        ret.push_back(PushMessageQueueDataBundle(sender, receiver, sec.count(), d.msg));
        
    }
    
    return ret;
}















