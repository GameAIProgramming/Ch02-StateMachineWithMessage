//
//  BBiBBi.cpp
//  Ai001_StateMachine
//
//  Created by 남준현 on 2015. 10. 11..
//  Copyright © 2015년 남준현. All rights reserved.
//


#include "BBiBBi.hpp"
#include "BBiBBiOwnedStates.hpp"
#include "Telegram.hpp"

BBiBBi::BBiBBi(int id) : BaseEntity(id)
{
	_FSM = new StateMachine<BBiBBi>(this);
    _FSM->setCurrState(BBiBBiDummyState::getInstance());
	_FSM->changeState(BBiBBiWorkAtHome::getInstance());
	_FSM->setGlobalState(BBiBBiGlobalState::getInstance());
    
    _waterInBody = 0;
	_tiredness = 0;
}

bool BBiBBi::handleMessage(const Telegram& msg)
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
    
    if( flag > 0 )
    {
        return true;
    }
    
    return false;
}

void BBiBBi::update(float dt)
{
	_FSM->update(dt);
}





