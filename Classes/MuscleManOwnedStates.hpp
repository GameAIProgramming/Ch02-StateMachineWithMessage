//
//  MuscleManOwnedStates.hpp
//  Ai001_StateMachine
//
//  Created by 남준현 on 2015. 10. 8..
//  Copyright © 2015년 남준현. All rights reserved.
//

#pragma once

#include "State.hpp"
#include "MuscleMan.hpp"

class Telegram;

//
// MuscleManGlobalState
//
class MuscleManGlobalState : public State<MuscleMan>
{
    
private:
    
	MuscleManGlobalState() {};
	MuscleManGlobalState& operator=(const MuscleManGlobalState&) = delete;
	MuscleManGlobalState(const MuscleManGlobalState&) = delete;
    
public:
    
	static MuscleManGlobalState* getInstance();
	virtual void enter(MuscleMan* owner) {};
	virtual void execute(MuscleMan* owner);
	virtual void exit(MuscleMan* owner) {};
	virtual bool onMessage(MuscleMan* owner, const Telegram& msg);
    
};

//
// MuscleManMineGold
//
class MuscleManMineGold : public State<MuscleMan>
{
    
private:
    
	MuscleManMineGold() {};
	MuscleManMineGold& operator=(const MuscleManMineGold&) = delete;
	MuscleManMineGold(const MuscleManMineGold&) = delete;
    
public:
    
	static MuscleManMineGold* getInstance();
    virtual void enter(MuscleMan* owner);
    virtual void execute(MuscleMan* owner);
    virtual void exit(MuscleMan* owner);
    virtual bool onMessage(MuscleMan* owner, const Telegram& msg);
    
};



//
// MuscleManWaitFood
//
class MuscleManWaitFood : public State<MuscleMan>
{

private:

	MuscleManWaitFood() {};
	MuscleManWaitFood& operator=(const MuscleManWaitFood&) = delete;
	MuscleManWaitFood(const MuscleManWaitFood&) = delete;

public:

	static MuscleManWaitFood* getInstance();
	virtual void enter(MuscleMan* owner);
	virtual void execute(MuscleMan* owner);
	virtual void exit(MuscleMan* owner);
	virtual bool onMessage(MuscleMan* owner, const Telegram& msg);

};


//
// MuscleManEatFood
//
class MuscleManEatFood : public State<MuscleMan>
{

private:

	MuscleManEatFood() {};
	MuscleManEatFood& operator=(const MuscleManEatFood&) = delete;
	MuscleManEatFood(const MuscleManEatFood&) = delete;

public:

	static MuscleManEatFood* getInstance();
	virtual void enter(MuscleMan* owner);
	virtual void execute(MuscleMan* owner);
	virtual void exit(MuscleMan* owner);
	virtual bool onMessage(MuscleMan* owner, const Telegram& msg);

};


//
// MuscleManGoToBed
//
class MuscleManGoToBed : public State<MuscleMan>
{

private:

	MuscleManGoToBed() {};
	MuscleManGoToBed& operator=(const MuscleManGoToBed&) = delete;
	MuscleManGoToBed(const MuscleManGoToBed&) = delete;

public:

	static MuscleManGoToBed* getInstance();
	virtual void enter(MuscleMan* owner);
	virtual void execute(MuscleMan* owner);
	virtual void exit(MuscleMan* owner);
	virtual bool onMessage(MuscleMan* owner, const Telegram& msg);

};


//
// MuscleManSleep
//
class MuscleManSleep : public State<MuscleMan>
{

private:

	MuscleManSleep() {};
	MuscleManSleep& operator=(const MuscleManSleep&) = delete;
	MuscleManSleep(const MuscleManSleep&) = delete;

public:

	static MuscleManSleep* getInstance();
	virtual void enter(MuscleMan* owner);
	virtual void execute(MuscleMan* owner);
	virtual void exit(MuscleMan* owner);
	virtual bool onMessage(MuscleMan* owner, const Telegram& msg);

};


//
// MuscleManGoToMine
//
class MuscleManGoToMine : public State<MuscleMan>
{

private:

	MuscleManGoToMine() {};
	MuscleManGoToMine& operator=(const MuscleManGoToMine&) = delete;
	MuscleManGoToMine(const MuscleManGoToMine&) = delete;

public:

	static MuscleManGoToMine* getInstance();
	virtual void enter(MuscleMan* owner);
	virtual void execute(MuscleMan* owner);
	virtual void exit(MuscleMan* owner);
	virtual bool onMessage(MuscleMan* owner, const Telegram& msg);

};


//
// MuscleManGoToBank
//
class MuscleManGoToBank : public State<MuscleMan>
{

private:

	MuscleManGoToBank() {};
	MuscleManGoToBank& operator=(const MuscleManGoToBank&) = delete;
	MuscleManGoToBank(const MuscleManGoToBank&) = delete;

public:

	static MuscleManGoToBank* getInstance();
	virtual void enter(MuscleMan* owner);
	virtual void execute(MuscleMan* owner);
	virtual void exit(MuscleMan* owner);
	virtual bool onMessage(MuscleMan* owner, const Telegram& msg);

};


//
// MuscleManGoToHome
//
class MuscleManGoToHome : public State<MuscleMan>
{

private:

	MuscleManGoToHome() {};
	MuscleManGoToHome& operator=(const MuscleManGoToHome&) = delete;
	MuscleManGoToHome(const MuscleManGoToHome&) = delete;

public:

	static MuscleManGoToHome* getInstance();
	virtual void enter(MuscleMan* owner);
	virtual void execute(MuscleMan* owner);
	virtual void exit(MuscleMan* owner);
	virtual bool onMessage(MuscleMan* owner, const Telegram& msg);

};


//
// MuscleManDummyState
//
class MuscleManDummyState : public State<MuscleMan>
{
    
private:
    
    MuscleManDummyState() {};
    MuscleManDummyState& operator=(const MuscleManDummyState&) = delete;
    MuscleManDummyState(const MuscleManDummyState&) = delete;
    
public:
    
    static MuscleManDummyState* getInstance()
    {
        static MuscleManDummyState instance;
        return &instance;
    }
    virtual void enter(MuscleMan* owner) {}
    virtual void execute(MuscleMan* owner) {}
    virtual void exit(MuscleMan* owner) {}
    virtual bool onMessage(MuscleMan* owner, const Telegram& msg) { return false; }
    
};


