//
//  KidStone.hpp
//  Ai001_StateMachine
//
//  Created by 남준현 on 2015. 10. 11..
//  Copyright © 2015년 남준현. All rights reserved.
//

#pragma once

#include "BaseEntity.hpp"
#include "StateMachine.hpp"

class KidStone : public BaseEntity
{

private:

    int                                         _waterInBody;
	StateMachine<KidStone>*                     _FSM;

	KidStone() = delete;
	KidStone(const KidStone&) = delete;
	KidStone& operator=(const KidStone&) = delete;


public:

	KidStone(int id);

	virtual ~KidStone()
	{}

    virtual bool handleMessage(const Telegram& msg);
	virtual void update(float dt);

    StateMachine<KidStone>* getFSM() const		{ return _FSM; }

};





