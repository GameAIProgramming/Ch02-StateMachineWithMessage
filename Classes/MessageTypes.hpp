//
//  MessageTypes.hpp
//  Ai001_StateMachine
//
//  Created by 남준현 on 2015. 9. 24..
//  Copyright © 2015년 남준현. All rights reserved.
//

#pragma once

#include "Entities.hpp"
#include "Locations.hpp"
#include "MessageTypes.hpp"
#include <string>
#include <chrono>

enum class MessageType : short
{
    kHiHoneyGiveMeFood,

	kFoodCompleted,
	kEatCompleted,
	kToiletUseCompleted,
    kStudyCompleted,
    kWatchTVCompleted,
    kSleepCompleted,
    
    kBedArrived,
	kMineArrived,
	kBankArrived,
	kHomeArrived,
    kToiletArrived,
    kKitchenArrived,
    kSchoolArrived,
    
    kMoveEntity,
    kPushLog
};


class MoveEntityDataBundle
{
    
public:
    
    Entity entity;
    Location dest;
    double spendTime;
    
    MoveEntityDataBundle() : entity(Entity::kDefault), dest(Location::kDefault), spendTime(0.0f)
    {}
    
    MoveEntityDataBundle(Entity entity, Location dest, double spendTime) : entity(entity), dest(dest), spendTime(spendTime)
    {}
    
    MoveEntityDataBundle(const MoveEntityDataBundle& rhs) : entity(rhs.entity), dest(rhs.dest), spendTime(rhs.spendTime)
    {}
    
    MoveEntityDataBundle& operator=(const MoveEntityDataBundle& rhs)
    {
        if(this == &rhs)
        {
            return *this;
        }
        entity = rhs.entity;
        dest = rhs.dest;
        spendTime = rhs.spendTime;
        return *this;
    }
    
};


class PushLogDataBundle
{
    
public:
    
    Entity entity;
    std::string text;
    
    PushLogDataBundle() : entity(Entity::kDefault)
    {}
    
    PushLogDataBundle(Entity entity, std::string text) : entity(entity), text(text)
    {}
    
    PushLogDataBundle(const PushLogDataBundle& rhs) : entity(rhs.entity), text(rhs.text)
    {}
    
    PushLogDataBundle& operator=(const PushLogDataBundle& rhs)
    {
        if(this == &rhs)
        {
            return *this;
        }
        entity = rhs.entity;
        text = rhs.text;
        return *this;
    }
};

class PushMessageQueueDataBundle
{
    
public:
    
    std::string                     sender;
    std::string                     receiver;
    double                          remainSeconds;
    MessageType                     messageType;
    
    PushMessageQueueDataBundle() :
    sender(sender),
    receiver(receiver),
    remainSeconds(remainSeconds),
    messageType(messageType)
    {}
    
    PushMessageQueueDataBundle(std::string  sender, std::string  receiver, double remainSeconds, MessageType messageType) :
    sender(sender),
    receiver(receiver),
    remainSeconds(remainSeconds),
    messageType(messageType)
    {}
    
    PushMessageQueueDataBundle(const PushMessageQueueDataBundle& rhs) :
    sender(rhs.sender),
    receiver(rhs.receiver),
    remainSeconds(rhs.remainSeconds),
    messageType(rhs.messageType)
    {}
    
    PushMessageQueueDataBundle& operator=(const PushMessageQueueDataBundle& rhs)
    {
        if(this == &rhs)
        {
            return *this;
        }
        sender = rhs.sender;
        receiver = rhs.receiver;
        remainSeconds = rhs.remainSeconds;
        messageType = rhs.messageType;
        return *this;
    }
    
};











