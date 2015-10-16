//
//  KidStoneOwnedStates.cpp
//  Ai001_StateMachine
//
//  Created by 남준현 on 2015. 10. 8..
//  Copyright © 2015년 남준현. All rights reserved.
//

#include "KidStoneOwnedStates.hpp"
#include "Telegram.hpp"
#include "MessageDispatcher.hpp"
#include "EntityManager.hpp"
#include "SceneListener.hpp"
#include <random>
#include <ctime>

//
// KidStoneGlobalState
//
KidStoneGlobalState* KidStoneGlobalState::getInstance()
{
	static KidStoneGlobalState instance;
	return &instance;
}

bool KidStoneGlobalState::onMessage(KidStone* owner, const Telegram& msg)
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
// KidStonePlayInRoom
//
KidStonePlayInRoom* KidStonePlayInRoom::getInstance()
{
	static KidStonePlayInRoom instance;
	return &instance;
}

void KidStonePlayInRoom::enter(KidStone* owner)
{
    PushLogDataBundle extraMsg(Entity::kKidStone, "꼬마돌: TV전원을 킴.");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
    
    Dispatch->pushMessage(3.0, owner, owner, MessageType::kWatchTVCompleted, nullptr);
    owner->setLocation(Location::kHome);
}

void KidStonePlayInRoom::execute(KidStone* owner)
{
    PushLogDataBundle extraMsg(Entity::kKidStone, "꼬마돌: TV 시청 중 ...");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

void KidStonePlayInRoom::exit(KidStone* owner)
{
    PushLogDataBundle extraMsg(Entity::kKidStone, "꼬마돌: TV 끔.");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

bool KidStonePlayInRoom::onMessage(KidStone* owner, const Telegram& msg)
{
	switch (msg.msg)
	{
        case MessageType::kWatchTVCompleted:
        {
            std::mt19937 seed((unsigned int)time(nullptr));
            std::uniform_int_distribution<int> dre(0, 100);
            int ret = dre(seed);
            if(ret >= 0 && ret <= 30)
            {
                owner->getFSM()->changeState(KidStoneGoToBed::getInstance());
            }
            else if(ret > 30 && ret <= 60)
            {
                owner->getFSM()->changeState(KidStoneGoToSchool::getInstance());
            }
            else
            {
                owner->getFSM()->changeState(KidStoneGoToToilet::getInstance());
            }
            return true;
        }
        default:
        {
            return false;
        }

	}
}


//
// KidStoneGoToBed
//
KidStoneGoToBed* KidStoneGoToBed::getInstance()
{
    static KidStoneGoToBed instance;
    return &instance;
}

void KidStoneGoToBed::enter(KidStone* owner)
{
    PushLogDataBundle extraMsg(Entity::kKidStone, "꼬마돌: 방으로 향하기 위해 일어남.");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
    
    Dispatch->pushMessage(1.0, owner, owner, MessageType::kBedArrived, nullptr);
    
    MoveEntityDataBundle extra(Entity::kKidStone, Location::kBed, 1.0);
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kMoveEntity, &extra);
}

void KidStoneGoToBed::execute(KidStone* owner)
{
    PushLogDataBundle extraMsg(Entity::kKidStone, "꼬마돌: 방으로 향하는 중...");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

void KidStoneGoToBed::exit(KidStone* owner)
{
    PushLogDataBundle extraMsg(Entity::kKidStone, "꼬마돌: 방에 도착함.");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

bool KidStoneGoToBed::onMessage(KidStone* owner, const Telegram& msg)
{
    switch (msg.msg)
    {
        case MessageType::kBedArrived:
        {
            owner->getFSM()->changeState(KidStoneSleep::getInstance());
            return true;
        }
        default:
        {
            return false;
        }
            
    }
}



//
// KidStoneGoToSchool
//
KidStoneGoToSchool* KidStoneGoToSchool::getInstance()
{
    static KidStoneGoToSchool instance;
    return &instance;
}

void KidStoneGoToSchool::enter(KidStone* owner)
{
    PushLogDataBundle extraMsg(Entity::kKidStone, "꼬마돌: 학교가기 위해 신발을 신음.");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
    
    Dispatch->pushMessage(3.0, owner, owner, MessageType::kSchoolArrived, nullptr);
    
    MoveEntityDataBundle extra(Entity::kKidStone, Location::kSchool, 3.0);
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kMoveEntity, &extra);
}

void KidStoneGoToSchool::execute(KidStone* owner)
{
    PushLogDataBundle extraMsg(Entity::kKidStone, "꼬마돌: 학교로 향하는 중 ...");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

void KidStoneGoToSchool::exit(KidStone* owner)
{
    PushLogDataBundle extraMsg(Entity::kKidStone, "꼬마돌: 학교 도착!");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

bool KidStoneGoToSchool::onMessage(KidStone* owner, const Telegram& msg)
{
    switch (msg.msg)
    {
        case MessageType::kSchoolArrived:
        {
            owner->getFSM()->changeState(KidStoneStudyInSchool::getInstance());
            return true;
        }
        default:
        {
            return false;
        }
            
    }
}



//
// KidStoneStudyInSchool
//
KidStoneStudyInSchool* KidStoneStudyInSchool::getInstance()
{
    static KidStoneStudyInSchool instance;
    return &instance;
}

void KidStoneStudyInSchool::enter(KidStone* owner)
{
    PushLogDataBundle extraMsg(Entity::kKidStone, "꼬마돌: 책상에 앉았다.");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
    
    Dispatch->pushMessage(3.0, owner, owner, MessageType::kStudyCompleted, nullptr);
    owner->setLocation(Location::kSchool);
}

void KidStoneStudyInSchool::execute(KidStone* owner)
{
    PushLogDataBundle extraMsg(Entity::kKidStone, "꼬마돌: 수업 듣는 중 ...");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

void KidStoneStudyInSchool::exit(KidStone* owner)
{
    PushLogDataBundle extraMsg(Entity::kKidStone, "꼬마돌: 수업 끝!");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

bool KidStoneStudyInSchool::onMessage(KidStone* owner, const Telegram& msg)
{
    switch (msg.msg)
    {
        case MessageType::kStudyCompleted:
        {
            owner->getFSM()->changeState(KidStoneGoToHome::getInstance());
            return true;
        }
        default:
        {
            return false;
        }
            
    }
}



//
// KidStoneGoToHome
//
KidStoneGoToHome* KidStoneGoToHome::getInstance()
{
    static KidStoneGoToHome instance;
    return &instance;
}

void KidStoneGoToHome::enter(KidStone* owner)
{
    PushLogDataBundle extraMsg(Entity::kKidStone, "꼬마돌: 집으로 향하려고 준비 함.");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
    
    Dispatch->pushMessage(3.0, owner, owner, MessageType::kHomeArrived, nullptr);
    
    MoveEntityDataBundle extra(Entity::kKidStone, Location::kHome, 3.0);
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kMoveEntity, &extra);
}

void KidStoneGoToHome::execute(KidStone* owner)
{
    PushLogDataBundle extraMsg(Entity::kKidStone, "꼬마돌: 집 가는 중 ...");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

void KidStoneGoToHome::exit(KidStone* owner)
{
    PushLogDataBundle extraMsg(Entity::kKidStone, "꼬마돌: 집 도착.");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

bool KidStoneGoToHome::onMessage(KidStone* owner, const Telegram& msg)
{
    switch (msg.msg)
    {
        case MessageType::kHomeArrived:
        {
            owner->getFSM()->changeState(KidStonePlayInRoom::getInstance());
            return true;
        }
        default:
        {
            return false;
        }
    }
}



//
// KidStoneGoToToilet
//
KidStoneGoToToilet* KidStoneGoToToilet::getInstance()
{
    static KidStoneGoToToilet instance;
    return &instance;
}

void KidStoneGoToToilet::enter(KidStone* owner)
{
    PushLogDataBundle extraMsg(Entity::kKidStone, "꼬마돌: 화장실이 가고 싶어짐.");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
    
    Dispatch->pushMessage(1.0, owner, owner, MessageType::kToiletArrived, nullptr);
    
    MoveEntityDataBundle extra(Entity::kKidStone, Location::kToilet, 1.0);
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kMoveEntity, &extra);
}

void KidStoneGoToToilet::execute(KidStone* owner)
{
    PushLogDataBundle extraMsg(Entity::kKidStone, "꼬마돌: 화장실 가는 중 ...");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

void KidStoneGoToToilet::exit(KidStone* owner)
{
    PushLogDataBundle extraMsg(Entity::kKidStone, "꼬마돌: 화장실 도착!");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

bool KidStoneGoToToilet::onMessage(KidStone* owner, const Telegram& msg)
{
    switch (msg.msg)
    {
        case MessageType::kToiletArrived:
        {
            owner->getFSM()->changeState(KidStoneUseToilet::getInstance());
            return true;
        }
        default:
        {
            return false;
        }
            
    }
}



//
// KidStoneUseToilet
//
KidStoneUseToilet* KidStoneUseToilet::getInstance()
{
    static KidStoneUseToilet instance;
    return &instance;
}

void KidStoneUseToilet::enter(KidStone* owner)
{
    PushLogDataBundle extraMsg(Entity::kKidStone, "꼬마돌: 화장실에 들어옴.");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
    Dispatch->pushMessage(3.0, owner, owner, MessageType::kToiletUseCompleted, nullptr);
    owner->setLocation(Location::kBed);
}

void KidStoneUseToilet::execute(KidStone* owner)
{
    PushLogDataBundle extraMsg(Entity::kKidStone, "꼬마돌: 소변 보는 중 ...");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

void KidStoneUseToilet::exit(KidStone* owner)
{
    PushLogDataBundle extraMsg(Entity::kKidStone, "꼬마돌: 소변 다 봄.");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

bool KidStoneUseToilet::onMessage(KidStone* owner, const Telegram& msg)
{
    switch (msg.msg)
    {
        case MessageType::kToiletUseCompleted:
        {
            owner->getFSM()->changeState(KidStoneGoToHome::getInstance());
            return true;
        }
        default:
        {
            return false;
        }
            
    }
}



//
// KidStoneSleep
//
KidStoneSleep* KidStoneSleep::getInstance()
{
    static KidStoneSleep instance;
    return &instance;
}

void KidStoneSleep::enter(KidStone* owner)
{
    PushLogDataBundle extraMsg(Entity::kKidStone, "꼬마돌: 졸려서 눈이 감김.");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
    Dispatch->pushMessage(5.0, owner, owner, MessageType::kSleepCompleted, nullptr);
    owner->setLocation(Location::kToilet);
}

void KidStoneSleep::execute(KidStone* owner)
{
    PushLogDataBundle extraMsg(Entity::kKidStone, "꼬마돌: zZZ...");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

void KidStoneSleep::exit(KidStone* owner)
{
    PushLogDataBundle extraMsg(Entity::kKidStone, "꼬마돌: 번뜩! 눈을 뜸.");
    Dispatch->pushMessage(0.0, SceneLisner, owner, MessageType::kPushLog, &extraMsg);
}

bool KidStoneSleep::onMessage(KidStone* owner, const Telegram& msg)
{
    switch (msg.msg)
    {
        case MessageType::kSleepCompleted:
        {
            owner->getFSM()->changeState(KidStoneGoToHome::getInstance());
            return true;
        }
        default:
        {
            return false;
        }
            
    }
}








