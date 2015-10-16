//
//  BBiBBi.hpp
//  Ai001_StateMachine
//
//  Created by 남준현 on 2015. 10. 11..
//  Copyright © 2015년 남준현. All rights reserved.
//

#pragma once

#include "BaseEntity.hpp"
#include "StateMachine.hpp"

const int kMaxWaterInBody                   = 100;
const int kBBiBBiMaxTiredness               = 100;


class BBiBBi : public BaseEntity
{

private:

	int                                         _tiredness;
    int                                         _waterInBody;
	StateMachine<BBiBBi>*                       _FSM;

	BBiBBi() = delete;
	BBiBBi(const BBiBBi&) = delete;
	BBiBBi& operator=(const BBiBBi&) = delete;

public:

	BBiBBi(int id);

	virtual ~BBiBBi()
	{}

    virtual bool handleMessage(const Telegram& msg);
	virtual void update(float dt);

    StateMachine<BBiBBi>* getFSM() const		{ return _FSM; }
    int getTiredness() const					{ return _tiredness; }
    int getWaterInBody() const                  { return _waterInBody; }
    
    void setTiredness(int newValue)				{ _tiredness = newValue; }
    void setWaterInBody(int newValue)           { _waterInBody = newValue; }

};