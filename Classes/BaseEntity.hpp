//
//  BaseEntity.hpp
//  Ai001_StateMachine
//
//  Created by 남준현 on 2015. 9. 24..
//  Copyright © 2015년 남준현. All rights reserved.
//

#pragma once

#include "Locations.hpp"

class Telegram;

class BaseEntity
{
    
private:
    
    int         _id;
	Location	_location;
    
    BaseEntity() = delete;
    BaseEntity(const BaseEntity&) = delete;
    BaseEntity& operator=(const BaseEntity&) = delete;
    
public:
    
    BaseEntity(int id) : _id(id)
    {
		_location = Location::kHome;
	}
    
    virtual ~BaseEntity()
    {}
    
    int getID() const						{ return _id; }
	Location getLocation() const			{ return _location; }

	void setLocation(Location newLocation)	{ _location = newLocation; }

    virtual bool handleMessage(const Telegram& msg) = 0;
    virtual void update(float dt) = 0;
    
};