//
//  KidStone.cpp
//  Ai001_StateMachine
//
//  Created by 남준현 on 2015. 10. 11..
//  Copyright © 2015년 남준현. All rights reserved.
//


#include "KidStone.hpp"
#include "KidStoneOwnedStates.hpp"
#include "Telegram.hpp"

KidStone::KidStone(int id) : BaseEntity(id)
{
	_FSM = new StateMachine<KidStone>(this);
	_FSM->setCurrState(KidStoneDummyState::getInstance());
    _FSM->changeState(KidStoneStudyInSchool::getInstance());
	_FSM->setGlobalState(KidStoneGlobalState::getInstance());
	_waterInBody = 0;
}

bool KidStone::handleMessage(const Telegram& msg)
{
    int flag {};
    if (_FSM->getGlobalState())
    {
        if(_FSM->getGlobalState()->onMessage(this, msg))
        {
            flag ++;
        }
    }
    
    if (_FSM->getCurrState())
    {
        if(_FSM->getCurrState()->onMessage(this, msg))
        {
            flag++;
        }
    }
    
    if( flag > 0)
        return true;
    
    return false;
}

void KidStone::update(float dt)
{
	_FSM->update(dt);
}





