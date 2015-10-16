//
//  BBiBBi.cpp
//  Ai001_StateMachine
//
//  Created by 남준현 on 2015. 9. 24..
//  Copyright © 2015년 남준현. All rights reserved.
//

#include "MuscleMan.hpp"
#include "MuscleManOwnedStates.hpp"
#include "Telegram.hpp"
#include <iostream>

MuscleMan::MuscleMan(int id) : BaseEntity(id)
{
	_FSM = new StateMachine<MuscleMan>(this);
    _FSM->setCurrState(MuscleManDummyState::getInstance());
	_FSM->changeState(MuscleManMineGold::getInstance());
	_FSM->setGlobalState(MuscleManGlobalState::getInstance());
    _tiredness = 0;
    _ownedGold = 0;
}

bool MuscleMan::handleMessage(const Telegram& msg)
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

void MuscleMan::update(float dt)
{
    _FSM->update(dt);
}





