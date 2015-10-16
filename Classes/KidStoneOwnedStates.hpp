//
//  KidStoneOwnedStates.hpp
//  Ai001_StateMachine
//
//  Created by 남준현 on 2015. 10. 11..
//  Copyright © 2015년 남준현. All rights reserved.
//

#pragma once

#include "State.hpp"
#include "KidStone.hpp"

class Telegram;

//
// KidStoneGlobalState
//
class KidStoneGlobalState : public State<KidStone>
{

private:

	KidStoneGlobalState() {};
	KidStoneGlobalState& operator=(const KidStoneGlobalState&) = delete;
	KidStoneGlobalState(const KidStoneGlobalState&) = delete;

public:

	static KidStoneGlobalState* getInstance();
	virtual void enter(KidStone* owner) {};
	virtual void execute(KidStone* owner) {};
	virtual void exit(KidStone* owner) {};
	virtual bool onMessage(KidStone* owner, const Telegram& msg);

};

//
// KidStonePlayInRoom
//
class KidStonePlayInRoom : public State<KidStone>
{

private:

	KidStonePlayInRoom() {};
	KidStonePlayInRoom& operator=(const KidStonePlayInRoom&) = delete;
	KidStonePlayInRoom(const KidStonePlayInRoom&) = delete;

public:

	static KidStonePlayInRoom* getInstance();
	virtual void enter(KidStone* owner);
	virtual void execute(KidStone* owner);
	virtual void exit(KidStone* owner);
	virtual bool onMessage(KidStone* owner, const Telegram& msg);

};


//
// KidStoneGoToSchool
//
class KidStoneGoToSchool : public State<KidStone>
{
    
private:
    
    KidStoneGoToSchool() {};
    KidStoneGoToSchool& operator=(const KidStoneGoToSchool&) = delete;
    KidStoneGoToSchool(const KidStoneGoToSchool&) = delete;
    
public:
    
    static KidStoneGoToSchool* getInstance();
    virtual void enter(KidStone* owner);
    virtual void execute(KidStone* owner);
    virtual void exit(KidStone* owner);
    virtual bool onMessage(KidStone* owner, const Telegram& msg);
    
};




//
// KidStoneStudyInSchool
//
class KidStoneStudyInSchool : public State<KidStone>
{
    
private:
    
    KidStoneStudyInSchool() {};
    KidStoneStudyInSchool& operator=(const KidStoneStudyInSchool&) = delete;
    KidStoneStudyInSchool(const KidStoneStudyInSchool&) = delete;
    
public:
    
    static KidStoneStudyInSchool* getInstance();
    virtual void enter(KidStone* owner);
    virtual void execute(KidStone* owner);
    virtual void exit(KidStone* owner);
    virtual bool onMessage(KidStone* owner, const Telegram& msg);
    
};



//
// KidStoneGoToHome
//
class KidStoneGoToHome : public State<KidStone>
{
    
private:
    
    KidStoneGoToHome() {};
    KidStoneGoToHome& operator=(const KidStoneGoToHome&) = delete;
    KidStoneGoToHome(const KidStoneGoToHome&) = delete;
    
public:
    
    static KidStoneGoToHome* getInstance();
    virtual void enter(KidStone* owner);
    virtual void execute(KidStone* owner);
    virtual void exit(KidStone* owner);
    virtual bool onMessage(KidStone* owner, const Telegram& msg);
    
};



//
// KidStoneGoToToilet
//
class KidStoneGoToToilet : public State<KidStone>
{
    
private:
    
    KidStoneGoToToilet() {};
    KidStoneGoToToilet& operator=(const KidStoneGoToToilet&) = delete;
    KidStoneGoToToilet(const KidStoneGoToToilet&) = delete;
    
public:
    
    static KidStoneGoToToilet* getInstance();
    virtual void enter(KidStone* owner);
    virtual void execute(KidStone* owner);
    virtual void exit(KidStone* owner);
    virtual bool onMessage(KidStone* owner, const Telegram& msg);
    
};


//
// KidStoneUseToilet
//
class KidStoneUseToilet : public State<KidStone>
{
    
private:
    
    KidStoneUseToilet() {};
    KidStoneUseToilet& operator=(const KidStoneUseToilet&) = delete;
    KidStoneUseToilet(const KidStoneUseToilet&) = delete;
    
public:
    
    static KidStoneUseToilet* getInstance();
    virtual void enter(KidStone* owner);
    virtual void execute(KidStone* owner);
    virtual void exit(KidStone* owner);
    virtual bool onMessage(KidStone* owner, const Telegram& msg);
    
};


//
// KidStoneGoToBed
//
class KidStoneGoToBed : public State<KidStone>
{
    
private:
    
    KidStoneGoToBed() {};
    KidStoneGoToBed& operator=(const KidStoneGoToBed&) = delete;
    KidStoneGoToBed(const KidStoneGoToBed&) = delete;
    
public:
    
    static KidStoneGoToBed* getInstance();
    virtual void enter(KidStone* owner);
    virtual void execute(KidStone* owner);
    virtual void exit(KidStone* owner);
    virtual bool onMessage(KidStone* owner, const Telegram& msg);
    
};



//
// KidStoneSleep
//
class KidStoneSleep : public State<KidStone>
{
    
private:
    
    KidStoneSleep() {};
    KidStoneSleep& operator=(const KidStoneSleep&) = delete;
    KidStoneSleep(const KidStoneSleep&) = delete;
    
public:
    
    static KidStoneSleep* getInstance();
    virtual void enter(KidStone* owner);
    virtual void execute(KidStone* owner);
    virtual void exit(KidStone* owner);
    virtual bool onMessage(KidStone* owner, const Telegram& msg);
    
};


//
// KidStoneDummyState
//
class KidStoneDummyState : public State<KidStone>
{
    
private:
    
    KidStoneDummyState() {};
    KidStoneDummyState& operator=(const KidStoneDummyState&) = delete;
    KidStoneDummyState(const KidStoneDummyState&) = delete;
    
public:
    
    static KidStoneDummyState* getInstance()
    {
        static KidStoneDummyState instance;
        return &instance;
    }
    virtual void enter(KidStone* owner) {}
    virtual void execute(KidStone* owner) {}
    virtual void exit(KidStone* owner) {}
    virtual bool onMessage(KidStone* owner, const Telegram& msg) { return false; }
    
};










