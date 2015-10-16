//
//  State.hpp
//  Ai001_StateMachine
//
//  Created by 남준현 on 2015. 9. 24..
//  Copyright © 2015년 남준현. All rights reserved.
//

#pragma once

class Telegram;

template <class entityType>
class State
{
    
public:
    
    virtual ~State(){}
    virtual void enter(entityType*) = 0;
    virtual void execute(entityType*) = 0;
    virtual void exit(entityType*) = 0;
    virtual bool onMessage(entityType*, const Telegram&) = 0;
    
};