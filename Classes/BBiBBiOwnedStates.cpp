//
//  BBiBBiOwnedStates.cpp
//  Ai001_StateMachine
//
//  Created by 남준현 on 2015. 10. 8..
//  Copyright © 2015년 남준현. All rights reserved.
//

#include "BBiBBiOwnedStates.hpp"
#include "Telegram.hpp"
#include "MessageDispatcher.hpp"
#include "EntityManager.hpp"
#include "SceneListener.hpp"


//
// BBiBBiGlobalState
//
BBiBBiGlobalState* BBiBBiGlobalState::getInstance()
{
	static BBiBBiGlobalState instance;
	return &instance;
}

void BBiBBiGlobalState::execute(BBiBBi* owner)
{
}

bool BBiBBiGlobalState::onMessage(BBiBBi* owner, const Telegram& msg)
{
	switch (msg.msg)
	{
		default:
		{
            return false;
		}
	}
}



//
// BBiBBiWorkAtHome
//
BBiBBiWorkAtHome* BBiBBiWorkAtHome::getInstance()
{
	static BBiBBiWorkAtHome instance;
	return &instance;
}

void BBiBBiWorkAtHome::enter(BBiBBi* owner)
{
    PushLogDataBundle extra(Entity::kBBiBBi, "삐삐: 청소기 전원을 켰다.");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extra);
    owner->setLocation(Location::kHome);
}

void BBiBBiWorkAtHome::execute(BBiBBi* owner)
{
    if(owner->getWaterInBody() < kMaxWaterInBody)
    {
        owner->setWaterInBody(owner->getWaterInBody() + 10);
    }
    else
    {
        owner->getFSM()->changeState(BBiBBiGoToToilet::getInstance());
        return ;
    }
    
    PushLogDataBundle extra(Entity::kBBiBBi, "삐삐: 청소기 돌리는 중입니다 ...");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extra);
}

void BBiBBiWorkAtHome::exit(BBiBBi* owner)
{
    PushLogDataBundle extra(Entity::kBBiBBi, "삐삐: 집안일을 마치고 청소기 전원을 껐다.");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extra);
}

bool BBiBBiWorkAtHome::onMessage(BBiBBi* owner, const Telegram& msg)
{
	switch (msg.msg)
	{
        case MessageType::kHiHoneyGiveMeFood:
        {
            owner->getFSM()->changeState(BBiBBiGoToKitchen::getInstance());
            return true;
        }
        default:
        {
            return false;
        }
	}
}




//
// BBiBBiGoToToilet
//
BBiBBiGoToToilet* BBiBBiGoToToilet::getInstance()
{
    static BBiBBiGoToToilet instance;
    return &instance;
}

void BBiBBiGoToToilet::enter(BBiBBi* owner)
{
    PushLogDataBundle extraMsg(Entity::kBBiBBi, "삐삐: 소변이 마렵기 시작했다.");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
    
    MoveEntityDataBundle extra(Entity::kBBiBBi, Location::kToilet, 1.0f);
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kMoveEntity, &extra);
    Dispatch->pushMessage(1.0f, owner, owner, MessageType::kToiletArrived, nullptr);
}

void BBiBBiGoToToilet::execute(BBiBBi* owner)
{
    PushLogDataBundle extraMsg(Entity::kBBiBBi, "삐삐: 화장실로 향하는 중 ...");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

void BBiBBiGoToToilet::exit(BBiBBi* owner)
{
    PushLogDataBundle extraMsg(Entity::kBBiBBi, "삐삐: 화장실 문을 열었다.");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

bool BBiBBiGoToToilet::onMessage(BBiBBi* owner, const Telegram& msg)
{
    switch (msg.msg)
    {
        case MessageType::kToiletArrived:
        {
            owner->getFSM()->changeState(BBiBBiUseToilet::getInstance());
            return true;
        }
        default:
        {
            return false;
        }
            
    }
}



//
// BBiBBiUseToilet
//
BBiBBiUseToilet* BBiBBiUseToilet::getInstance()
{
    static BBiBBiUseToilet instance;
    return &instance;
}

void BBiBBiUseToilet::enter(BBiBBi* owner)
{
    PushLogDataBundle extraMsg(Entity::kBBiBBi, "삐삐: 변기에 앉았음.");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
    
    owner->setLocation(Location::kToilet);
    Dispatch->pushMessage(3.0, owner, owner, MessageType::kToiletUseCompleted, nullptr);
}

void BBiBBiUseToilet::execute(BBiBBi* owner)
{
    PushLogDataBundle extraMsg(Entity::kBBiBBi, "삐삐: 볼 일 보는 중 ...");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

void BBiBBiUseToilet::exit(BBiBBi* owner)
{
    PushLogDataBundle extraMsg(Entity::kBBiBBi, "삐삐: 볼 일 다 보고 변기에서 일어남.");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

bool BBiBBiUseToilet::onMessage(BBiBBi* owner, const Telegram& msg)
{
    switch (msg.msg)
    {
        case MessageType::kToiletUseCompleted:
        {
            owner->setWaterInBody(0);
            owner->getFSM()->changeState(BBiBBiGoToHome::getInstance());
            return true;
        }
        default:
        {
            return false;
        }
            
    }
}



//
// BBiBBiGoToHome
//
BBiBBiGoToHome* BBiBBiGoToHome::getInstance()
{
    static BBiBBiGoToHome instance;
    return &instance;
}

void BBiBBiGoToHome::enter(BBiBBi* owner)
{
    PushLogDataBundle extraMsg(Entity::kBBiBBi, "삐삐: 거실로 향하려고 일어남.");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
    
    MoveEntityDataBundle extra(Entity::kBBiBBi, Location::kHome, 1.0f);
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kMoveEntity, &extra);
    Dispatch->pushMessage(1.0, owner, owner, MessageType::kHomeArrived, nullptr);
}

void BBiBBiGoToHome::execute(BBiBBi* owner)
{
    PushLogDataBundle extraMsg(Entity::kBBiBBi, "삐삐: 거실로 향하는 중 ...");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

void BBiBBiGoToHome::exit(BBiBBi* owner)
{
    PushLogDataBundle extraMsg(Entity::kBBiBBi, "삐삐: 거실 도착.");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

bool BBiBBiGoToHome::onMessage(BBiBBi* owner, const Telegram& msg)
{
    switch (msg.msg)
    {
        case MessageType::kHomeArrived:
        {
            owner->getFSM()->changeState(BBiBBiWorkAtHome::getInstance());
            return true;
        }
        default:
        {
            return false;
        }
    }
}




//
// BBiBBiGoToKitchen
//
BBiBBiGoToKitchen* BBiBBiGoToKitchen::getInstance()
{
    static BBiBBiGoToKitchen instance;
    return &instance;
}

void BBiBBiGoToKitchen::enter(BBiBBi* owner)
{
    PushLogDataBundle extraMsg(Entity::kBBiBBi, "삐삐: 밥을 지어주기 위해 부엌으로 가려고 한다.");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
    
    MoveEntityDataBundle extra(Entity::kBBiBBi, Location::kKitchen, 1.0f);
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kMoveEntity, &extra);
    Dispatch->pushMessage(1.0, owner, owner, MessageType::kKitchenArrived, nullptr);
}

void BBiBBiGoToKitchen::execute(BBiBBi* owner)
{
    PushLogDataBundle extraMsg(Entity::kBBiBBi, "삐삐: 부엌으로 가는 중 ...");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

void BBiBBiGoToKitchen::exit(BBiBBi* owner)
{
    PushLogDataBundle extraMsg(Entity::kBBiBBi, "삐삐: 부엌 도착!");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

bool BBiBBiGoToKitchen::onMessage(BBiBBi* owner, const Telegram& msg)
{
    switch (msg.msg)
    {
        case MessageType::kKitchenArrived:
        {
            owner->getFSM()->changeState(BBiBBiCookFood::getInstance());
            return true;
        }
        default:
        {
            return false;
        }
    }
}


//
// BBiBBiCookFood
//
BBiBBiCookFood* BBiBBiCookFood::getInstance()
{
    static BBiBBiCookFood instance;
    return &instance;
}

void BBiBBiCookFood::enter(BBiBBi* owner)
{
    PushLogDataBundle extraMsg(Entity::kBBiBBi, "삐삐: 밥 지을 준비 완료.");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
    Dispatch->pushMessage(3.0, owner, owner, MessageType::kFoodCompleted, nullptr);
}

void BBiBBiCookFood::execute(BBiBBi* owner)
{
    PushLogDataBundle extraMsg(Entity::kBBiBBi, "삐삐: 밥 만드는 중 ...");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

void BBiBBiCookFood::exit(BBiBBi* owner)
{
    PushLogDataBundle extraMsg(Entity::kBBiBBi, "삐삐: 밥 다 만듬.");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

bool BBiBBiCookFood::onMessage(BBiBBi* owner, const Telegram& msg)
{
    switch (msg.msg)
    {
        case MessageType::kFoodCompleted:
        {
            owner->getFSM()->changeState(BBiBBiGoToHomeWithFood::getInstance());
            return true;
        }
        default:
        {
            return false;
        }
    }
}



//
// BBiBBiGoToHomeWithFood
//
BBiBBiGoToHomeWithFood* BBiBBiGoToHomeWithFood::getInstance()
{
    static BBiBBiGoToHomeWithFood instance;
    return &instance;
}

void BBiBBiGoToHomeWithFood::enter(BBiBBi* owner)
{
    PushLogDataBundle extraMsg(Entity::kBBiBBi, "삐삐: 밥 옮기기 준비 완료.");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
    
    MoveEntityDataBundle extra(Entity::kBBiBBi, Location::kHome, 1.0f);
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kMoveEntity, &extra);
    Dispatch->pushMessage(1.0, owner, owner, MessageType::kHomeArrived, nullptr);
}

void BBiBBiGoToHomeWithFood::execute(BBiBBi* owner)
{
    PushLogDataBundle extraMsg(Entity::kBBiBBi, "삐삐: 밥 옮기는 중 ...");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

void BBiBBiGoToHomeWithFood::exit(BBiBBi* owner)
{
    PushLogDataBundle extraMsg(Entity::kBBiBBi, "삐삐: 식사 여기요.");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
    
    Dispatch->pushMessage(1.0, EntMgr->getEntityFromID((int)Entity::kMuscleMan), owner, MessageType::kFoodCompleted, nullptr);
}

bool BBiBBiGoToHomeWithFood::onMessage(BBiBBi* owner, const Telegram& msg)
{
    switch (msg.msg)
    {
        case MessageType::kHomeArrived:
        {
            owner->getFSM()->changeState(BBiBBiWorkAtHome::getInstance());
            return true;
        }
        default:
        {
            return false;
        }
    }
}





