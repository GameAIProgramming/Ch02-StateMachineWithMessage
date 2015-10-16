//
//  MuscleManOwnedStates.cpp
//  Ai001_StateMachine
//
//  Created by 남준현 on 2015. 10. 8..
//  Copyright © 2015년 남준현. All rights reserved.
//

#include "MuscleManOwnedStates.hpp"
#include "Telegram.hpp"
#include "MessageDispatcher.hpp"
#include "EntityManager.hpp"
#include <iostream>
#include "SceneListener.hpp"

//
// MuscleManGlobalState
//

void MuscleManGlobalState::execute(MuscleMan* owner)
{

}

MuscleManGlobalState* MuscleManGlobalState::getInstance()
{
    static MuscleManGlobalState instance;
    return &instance;
}


bool MuscleManGlobalState::onMessage(MuscleMan* owner, const Telegram& msg)
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
// MuscleManMineGold
//
MuscleManMineGold* MuscleManMineGold::getInstance()
{
	static MuscleManMineGold instance;
    return &instance;
}

void MuscleManMineGold::enter(MuscleMan* owner)
{
    PushLogDataBundle extraMsg(Entity::kMuscleMan, "근육맨: 일 하기 전 준비운동!");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
	owner->setLocation(Location::kMine);
}

void MuscleManMineGold::execute(MuscleMan* owner)
{
	if (owner->getTiredness() < kMuscleManMaxTiredness)
	{
		owner->setTiredness(owner->getTiredness() + 10);
        PushLogDataBundle extraMsg(Entity::kMuscleMan, "근육맨: 으쌰! 으쌰!");
        Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
	}
	else
	{
		owner->getFSM()->changeState(MuscleManGoToHome::getInstance());
	}

	if (owner->getOwnedGold() < kMaxOwnedGold)
	{
        owner->setOwnedGold(owner->getOwnedGold() + 7000);
	}
    else
    {
        owner->getFSM()->changeState(MuscleManGoToBank::getInstance());
    }
}

void MuscleManMineGold::exit(MuscleMan* owner)
{
    PushLogDataBundle extraMsg(Entity::kMuscleMan, "근육맨: 그만 가야겠군!");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

bool MuscleManMineGold::onMessage(MuscleMan* owner, const Telegram& msg)
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
// MuscleManGoToHome
//
MuscleManGoToHome* MuscleManGoToHome::getInstance()
{
	static MuscleManGoToHome instance;
	return &instance;
}

void MuscleManGoToHome::enter(MuscleMan* owner)
{
    MoveEntityDataBundle extra(Entity::kMuscleMan, Location::kHome, 3.0f);
	Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kMoveEntity, &extra);
	Dispatch->pushMessage(3.0, owner, owner, MessageType::kHomeArrived, nullptr);
    
    PushLogDataBundle extraMsg(Entity::kMuscleMan, "근육맨: 집에 갈 준비!");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

void MuscleManGoToHome::execute(MuscleMan* owner)
{
    PushLogDataBundle extraMsg(Entity::kMuscleMan, "근육맨: 뚜벅 뚜벅 ... 집으로 향하는 중 ...");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

void MuscleManGoToHome::exit(MuscleMan* owner)
{
    PushLogDataBundle extraMsg(Entity::kMuscleMan, "근육맨: 집에 도착 후, 신발 텀.");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

bool MuscleManGoToHome::onMessage(MuscleMan* owner, const Telegram& msg)
{
	switch (msg.msg)
	{
	case MessageType::kHomeArrived:
	{
		owner->getFSM()->changeState(MuscleManWaitFood::getInstance());
		return true;
	}
	default:
	{
		return false;
	}

	}
}



//
// MuscleManWaitFood
//
MuscleManWaitFood* MuscleManWaitFood::getInstance()
{
	static MuscleManWaitFood instance;
	return &instance;
}

void MuscleManWaitFood::enter(MuscleMan* owner)
{
    PushLogDataBundle extraMsg(Entity::kMuscleMan, "근육맨: 삐삐! 나 왔어요. 밥 주세요.");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
    
	owner->setLocation(Location::kHome);
	Dispatch->pushMessage(0.0, EntMgr->getEntityFromID((int)Entity::kBBiBBi), owner, MessageType::kHiHoneyGiveMeFood, nullptr);
}

void MuscleManWaitFood::execute(MuscleMan* owner)
{
    PushLogDataBundle extraMsg(Entity::kMuscleMan, "근육맨: 오늘은 어떤 메뉴가 나올까나? (밥 기다리는 중...)");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

void MuscleManWaitFood::exit(MuscleMan* owner)
{
    PushLogDataBundle extraMsg(Entity::kMuscleMan, "근육맨: 맛잇겠군!");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

bool MuscleManWaitFood::onMessage(MuscleMan* owner, const Telegram& msg)
{
	switch (msg.msg)
	{
		case MessageType::kFoodCompleted:
		{
			owner->getFSM()->changeState(MuscleManEatFood::getInstance());
			return true;
		}
		default:
		{
			return false;
		}
	}
}


//
// MuscleManEatFood
//
MuscleManEatFood* MuscleManEatFood::getInstance()
{
	static MuscleManEatFood instance;
	return &instance;
}

void MuscleManEatFood::enter(MuscleMan* owner)
{
    PushLogDataBundle extraMsg(Entity::kMuscleMan, "근육맨: 포크를 집어 들었다.");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
    
	Dispatch->pushMessage(3.0, owner, owner, MessageType::kEatCompleted, nullptr);
}

void MuscleManEatFood::execute(MuscleMan* owner)
{
    PushLogDataBundle extraMsg(Entity::kMuscleMan, "근육맨: 밥을 맛있게 먹는 중 ...");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

void MuscleManEatFood::exit(MuscleMan* owner)
{
    PushLogDataBundle extraMsg(Entity::kMuscleMan, "근육맨: 밥 다 먹음.");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

bool MuscleManEatFood::onMessage(MuscleMan* owner, const Telegram& msg)
{
	switch (msg.msg)
	{
		case MessageType::kEatCompleted:
		{
			owner->getFSM()->changeState(MuscleManGoToBed::getInstance());
			return true;
		}
		default:
		{
			return false;
		}
	}
}


//
// MuscleManGoToBed
//
MuscleManGoToBed* MuscleManGoToBed::getInstance()
{
	static MuscleManGoToBed instance;
	return &instance;
}

void MuscleManGoToBed::enter(MuscleMan* owner)
{
    PushLogDataBundle extraMsg(Entity::kMuscleMan, "근육맨: 쉬러 갈 준비.");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
    
    MoveEntityDataBundle extra(Entity::kMuscleMan, Location::kBed, 1.0f);
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kMoveEntity, &extra);
	Dispatch->pushMessage(1.0, owner, owner, MessageType::kBedArrived, nullptr);
}

void MuscleManGoToBed::execute(MuscleMan* owner)
{
    PushLogDataBundle extraMsg(Entity::kMuscleMan, "근육맨: 침대로 향하는 중...");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

void MuscleManGoToBed::exit(MuscleMan* owner)
{
    PushLogDataBundle extraMsg(Entity::kMuscleMan, "근육맨: 침대 도착.");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

bool MuscleManGoToBed::onMessage(MuscleMan* owner, const Telegram& msg)
{
	switch (msg.msg)
	{
		case MessageType::kBedArrived:
		{
			owner->getFSM()->changeState(MuscleManSleep::getInstance());
			return true;
		}
		default:
		{
			return false;
		}

	}
}


//
// MuscleManSleep
//
MuscleManSleep* MuscleManSleep::getInstance()
{
	static MuscleManSleep instance;
	return &instance;
}

void MuscleManSleep::enter(MuscleMan* owner)
{
	owner->setLocation(Location::kBed);
    PushLogDataBundle extraMsg(Entity::kMuscleMan, "근육맨: 바닥에 이불 깔음.");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

void MuscleManSleep::execute(MuscleMan* owner)
{
	if (owner->getTiredness() > 0)
	{
		owner->setTiredness(owner->getTiredness() - 10);
	}
	else
	{
		owner->getFSM()->changeState(MuscleManGoToMine::getInstance());
	}
    
    PushLogDataBundle extraMsg(Entity::kMuscleMan, "근육맨: zZZ ...");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

void MuscleManSleep::exit(MuscleMan* owner)
{
    PushLogDataBundle extraMsg(Entity::kMuscleMan, "근육맨: 시간이 벌써! (벌떡 일어남)");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

bool MuscleManSleep::onMessage(MuscleMan* owner, const Telegram& msg)
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
// MuscleManGoToMine
//
MuscleManGoToMine* MuscleManGoToMine::getInstance()
{
	static MuscleManGoToMine instance;
	return &instance;
}

void MuscleManGoToMine::enter(MuscleMan* owner)
{
    MoveEntityDataBundle extra(Entity::kMuscleMan, Location::kMine, 3.0f);
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kMoveEntity, &extra);
	Dispatch->pushMessage(3.0, owner, owner, MessageType::kMineArrived, nullptr);
    
    PushLogDataBundle extraMsg(Entity::kMuscleMan, "근육맨: 광산을 향해 출발!");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

void MuscleManGoToMine::execute(MuscleMan* owner)
{
    PushLogDataBundle extraMsg(Entity::kMuscleMan, "근육맨: 광산으로 향하는 중...");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

void MuscleManGoToMine::exit(MuscleMan* owner)
{
    PushLogDataBundle extraMsg(Entity::kMuscleMan, "근육맨: 광산 도착!");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

bool MuscleManGoToMine::onMessage(MuscleMan* owner, const Telegram& msg)
{
	switch (msg.msg)
	{
		case MessageType::kMineArrived:
		{
			owner->getFSM()->changeState(MuscleManMineGold::getInstance());
			return true;
		}
		default:
		{
			return false;
		}
	}
}


//
// MuscleManGoToBank
//
MuscleManGoToBank* MuscleManGoToBank::getInstance()
{
	static MuscleManGoToBank instance;
	return &instance;
}

void MuscleManGoToBank::enter(MuscleMan* owner)
{
    MoveEntityDataBundle extra(Entity::kMuscleMan, Location::kBank, 3.0f);
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kMoveEntity, &extra);
	Dispatch->pushMessage(3.0, owner, owner, MessageType::kBankArrived, nullptr);
	
    PushLogDataBundle extraMsg(Entity::kMuscleMan, "근육맨: 은행으로 돈을 맡기러 가볼까?");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

void MuscleManGoToBank::execute(MuscleMan* owner)
{
    PushLogDataBundle extraMsg(Entity::kMuscleMan, "근육맨: 은행으로 향하는 중...");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

void MuscleManGoToBank::exit(MuscleMan* owner)
{
    PushLogDataBundle extraMsg(Entity::kMuscleMan, "근육맨: 은행 도착.");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

bool MuscleManGoToBank::onMessage(MuscleMan* owner, const Telegram& msg)
{
	switch (msg.msg)
	{
		case MessageType::kBankArrived:
		{
			owner->setOwnedGold(0);
			owner->getFSM()->changeState(MuscleManGoToMine::getInstance());
            return true;
		}
		default:
		{
			return false;
		}
	}
}










