//
//  BBiBBiOwnedStates.hpp
//  Ai001_StateMachine
//
//  Created by 남준현 on 2015. 10. 11..
//  Copyright © 2015년 남준현. All rights reserved.
//

#pragma once

#include "State.hpp"
#include "BBiBBi.hpp"

class Telegram;

//
// BBiBBiGlobalState
//
class BBiBBiGlobalState : public State<BBiBBi>
{

private:

	BBiBBiGlobalState() {};
	BBiBBiGlobalState& operator=(const BBiBBiGlobalState&) = delete;
	BBiBBiGlobalState(const BBiBBiGlobalState&) = delete;

public:

	static BBiBBiGlobalState* getInstance();
	virtual void enter(BBiBBi* owner) {};
	virtual void execute(BBiBBi* owner);
	virtual void exit(BBiBBi* owner) {};
	virtual bool onMessage(BBiBBi* owner, const Telegram& msg);

};

//
// BBiBBiWorkAtHome
//
class BBiBBiWorkAtHome : public State<BBiBBi>
{

private:

	BBiBBiWorkAtHome() {};
	BBiBBiWorkAtHome& operator=(const BBiBBiWorkAtHome&) = delete;
	BBiBBiWorkAtHome(const BBiBBiWorkAtHome&) = delete;

public:

	static BBiBBiWorkAtHome* getInstance();
	virtual void enter(BBiBBi* owner);
	virtual void execute(BBiBBi* owner);
	virtual void exit(BBiBBi* owner);
	virtual bool onMessage(BBiBBi* owner, const Telegram& msg);

};

//
// BBiBBiGoToToilet
//
class BBiBBiGoToToilet : public State<BBiBBi>
{
    
private:
    
    BBiBBiGoToToilet() {};
    BBiBBiGoToToilet& operator=(const BBiBBiGoToToilet&) = delete;
    BBiBBiGoToToilet(const BBiBBiGoToToilet&) = delete;
    
public:
    
    static BBiBBiGoToToilet* getInstance();
    virtual void enter(BBiBBi* owner);
    virtual void execute(BBiBBi* owner);
    virtual void exit(BBiBBi* owner);
    virtual bool onMessage(BBiBBi* owner, const Telegram& msg);
    
};

//
// BBiBBiUseToilet
//
class BBiBBiUseToilet : public State<BBiBBi>
{
    
private:
    
    BBiBBiUseToilet() {};
    BBiBBiUseToilet& operator=(const BBiBBiUseToilet&) = delete;
    BBiBBiUseToilet(const BBiBBiUseToilet&) = delete;
    
public:
    
    static BBiBBiUseToilet* getInstance();
    virtual void enter(BBiBBi* owner);
    virtual void execute(BBiBBi* owner);
    virtual void exit(BBiBBi* owner);
    virtual bool onMessage(BBiBBi* owner, const Telegram& msg);
    
};


//
// BBiBBiGoToHome
//
class BBiBBiGoToHome : public State<BBiBBi>
{
    
private:
    
    BBiBBiGoToHome() {};
    BBiBBiGoToHome& operator=(const BBiBBiGoToHome&) = delete;
    BBiBBiGoToHome(const BBiBBiGoToHome&) = delete;
    
public:
    
    static BBiBBiGoToHome* getInstance();
    virtual void enter(BBiBBi* owner);
    virtual void execute(BBiBBi* owner);
    virtual void exit(BBiBBi* owner);
    virtual bool onMessage(BBiBBi* owner, const Telegram& msg);
    
};


//
// BBiBBiGoToKitchen
//
class BBiBBiGoToKitchen : public State<BBiBBi>
{
    
private:
    
    BBiBBiGoToKitchen() {};
    BBiBBiGoToKitchen& operator=(const BBiBBiGoToKitchen&) = delete;
    BBiBBiGoToKitchen(const BBiBBiGoToKitchen&) = delete;
    
public:
    
    static BBiBBiGoToKitchen* getInstance();
    virtual void enter(BBiBBi* owner);
    virtual void execute(BBiBBi* owner);
    virtual void exit(BBiBBi* owner);
    virtual bool onMessage(BBiBBi* owner, const Telegram& msg);
    
};


//
// BBiBBiCookFood
//
class BBiBBiCookFood : public State<BBiBBi>
{
    
private:
    
    BBiBBiCookFood() {};
    BBiBBiCookFood& operator=(const BBiBBiCookFood&) = delete;
    BBiBBiCookFood(const BBiBBiCookFood&) = delete;
    
public:
    
    static BBiBBiCookFood* getInstance();
    virtual void enter(BBiBBi* owner);
    virtual void execute(BBiBBi* owner);
    virtual void exit(BBiBBi* owner);
    virtual bool onMessage(BBiBBi* owner, const Telegram& msg);
    
};


//
// BBiBBiGoToHomeWithFood
//
class BBiBBiGoToHomeWithFood : public State<BBiBBi>
{
    
private:
    
    BBiBBiGoToHomeWithFood() {};
    BBiBBiGoToHomeWithFood& operator=(const BBiBBiGoToHomeWithFood&) = delete;
    BBiBBiGoToHomeWithFood(const BBiBBiGoToHomeWithFood&) = delete;
    
public:
    
    static BBiBBiGoToHomeWithFood* getInstance();
    virtual void enter(BBiBBi* owner);
    virtual void execute(BBiBBi* owner);
    virtual void exit(BBiBBi* owner);
    virtual bool onMessage(BBiBBi* owner, const Telegram& msg);
    
};


//
// BBiBBiDummyState
//
class BBiBBiDummyState : public State<BBiBBi>
{
    
private:
    
    BBiBBiDummyState() {};
    BBiBBiDummyState& operator=(const BBiBBiDummyState&) = delete;
    BBiBBiDummyState(const BBiBBiDummyState&) = delete;
    
public:
    
    static BBiBBiDummyState* getInstance()
    {
        static BBiBBiDummyState instance;
        return &instance;
    }
    virtual void enter(BBiBBi* owner) {}
    virtual void execute(BBiBBi* owner) {}
    virtual void exit(BBiBBi* owner) {}
    virtual bool onMessage(BBiBBi* owner, const Telegram& msg) { return false; }
    
};




