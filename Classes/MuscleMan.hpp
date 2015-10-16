//
//  MuscleMan.hpp
//  Ai001_StateMachine
//
//  Created by 남준현 on 2015. 9. 24..
//  Copyright © 2015년 남준현. All rights reserved.
//

#pragma once

#include "BaseEntity.hpp"
#include "StateMachine.hpp"

class Telegram;

const int kMuscleManMaxTiredness    = 100;
const int kMaxOwnedGold             = 200000;

class MuscleMan : public BaseEntity
{
    
private:
    
	int									_tiredness;
	int									_ownedGold;

	StateMachine<MuscleMan>*			 _FSM;
    
	MuscleMan() = delete;
	MuscleMan(const MuscleMan&) = delete;
	MuscleMan& operator=(const MuscleMan&) = delete;
    
    
public:
    
	MuscleMan(int id);
    
	virtual ~MuscleMan()
    {}
    
    virtual bool handleMessage(const Telegram& msg);
    virtual void update(float dt);

	StateMachine<MuscleMan>* getFSM() const		{ return _FSM; }
	int getTiredness() const					{ return _tiredness; }
	int getOwnedGold() const					{ return _ownedGold; }

	void setTiredness(int newValue)				{ _tiredness = newValue; }
	void setOwnedGold(int newValue)				{ _ownedGold = newValue; }


    
};




