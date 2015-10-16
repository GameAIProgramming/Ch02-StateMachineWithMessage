//
//  HelloWorldScene.cpp
//  Ai001_StateMachine
//
//  Created by 남준현 on 2015. 9. 24..
//  Copyright © 2015년 남준현. All rights reserved.
//


#include "HelloWorldScene.hpp"
#include "MessageDispatcher.hpp"
#include "EntityManager.hpp"
#include "BBiBBi.hpp"
#include "MuscleMan.hpp"
#include "KidStone.hpp"
#include "Entities.hpp"
#include "SceneListener.hpp"
#include "MessageTypes.hpp"

USING_NS_CC;

Scene* HelloWorldScene::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorldScene::create();
    scene->addChild(layer);
    return scene;
}

bool HelloWorldScene::init()
{
    if (!LayerColor::initWithColor(Color4B::BLACK))
        return false;
    
    this->scheduleUpdate();
    _winSize = Director::getInstance()->getVisibleSize();
    SceneLisner->registScene(this);

    
    //
    // Game View Init
    //
    _gameView = Sprite::create();
    _gameView->setPosition(Vec2(30, 230));
    addChild(_gameView);
    
    DrawNode* gameViewNode = DrawNode::create();

    // box
    gameViewNode->drawSegment(Vec2(0,0), Vec2(500, 0), 1, Color4F::GRAY);
    gameViewNode->drawSegment(Vec2(500,0), Vec2(500, 400), 1, Color4F::GRAY);
    gameViewNode->drawSegment(Vec2(500,400), Vec2(0, 400), 1, Color4F::GRAY);
    gameViewNode->drawSegment(Vec2(0,400), Vec2(0, 0), 1, Color4F::GRAY);
    
    // tap
    gameViewNode->drawSolidRect(Vec2(-1, 370), Vec2(501, 401), Color4F::GRAY);
    
    // red circle
    gameViewNode->drawCircle(Vec2(435,385), 8.0f, 360.0f, 30, false, 1.0f, 1.0f, Color4F(0.7f, 0.0f, 0.0f, 1.0f));
    gameViewNode->drawDot(Vec2(435, 385), 8.0f, Color4F(0.9f,0.0f,0.0f,1.0f));
    
    // yellow circle
    gameViewNode->drawCircle(Vec2(460,385), 8.0f, 360.0f, 30, false, 1.0f, 1.0f, Color4F(0.5f, 0.5f, 0.0f, 1.0f));
    gameViewNode->drawDot(Vec2(460, 385), 8.0f, Color4F(0.7f, 0.7f, 0.0f, 1.0f));
    
    // green circle
    gameViewNode->drawCircle(Vec2(485,385), 8.0f, 360.0f, 30, false, 1.0f, 1.0f, Color4F(0.0f, 0.5f, 0.0f, 1.0f));
    gameViewNode->drawDot(Vec2(485, 385), 8.0f, Color4F(0.0f, 0.7f, 0.0f, 1.0f));
    
    gameViewNode->drawSolidRect(Vec2(0,0), Vec2(500,370), Color4F(0.0f, 0.5f, 0.0f, 1.0f));
    
    gameViewNode->drawSegment(Vec2(150, 150), Vec2(350, 150), 1, Color4F::BLACK);
    gameViewNode->drawSegment(Vec2(350, 150), Vec2(350, 250), 1, Color4F::BLACK);
    gameViewNode->drawSegment(Vec2(350, 250), Vec2(150, 250), 1, Color4F::BLACK);
    gameViewNode->drawSegment(Vec2(150, 250), Vec2(150, 150), 1, Color4F::BLACK);

    
    _gameView->addChild(gameViewNode);
    
    Label* gameViewTitle = Label::createWithSystemFont("Game View", "", 20);
    gameViewTitle->setPosition(Vec2(10, 375));
    gameViewTitle->setAnchorPoint(Vec2(0.0f, 0.0f));
    gameViewTitle->setColor(Color3B::BLACK);
    _gameView->addChild(gameViewTitle);
    
    Label* home = Label::createWithSystemFont("Room", "", 20);
    home->setPosition(kHomePos);
    home->setColor(Color3B::BLACK);
    _gameView->addChild(home);
    
    Label* kitchen = Label::createWithSystemFont("Kitchen", "", 20);
    kitchen->setPosition(kKitchenPos);
    kitchen->setColor(Color3B::BLACK);
    _gameView->addChild(kitchen);
    
    Label* bed = Label::createWithSystemFont("Bed", "", 20);
    bed->setPosition(kBedPos);
    bed->setColor(Color3B::BLACK);
    _gameView->addChild(bed);
    
    Label* toilet = Label::createWithSystemFont("Toilet", "", 20);
    toilet->setPosition(kToiletPos);
    toilet->setColor(Color3B::BLACK);
    _gameView->addChild(toilet);
    
    Label* bank = Label::createWithSystemFont("Bank", "", 20);
    bank->setPosition(kBankPos);
    bank->setColor(Color3B::BLACK);
    _gameView->addChild(bank);
    
    Label* school = Label::createWithSystemFont("School", "", 20);
    school->setPosition(kSchoolPos);
    school->setColor(Color3B::BLACK);
    _gameView->addChild(school);
    
    Label* mine = Label::createWithSystemFont("Mine", "", 20);
    mine->setPosition(kMinePos);
    mine->setColor(Color3B::BLACK);
    _gameView->addChild(mine);
    
    //
    // Console View Init
    //
    _consoleView = Sprite::create();
    _consoleView->setPosition(Vec2(576,230));
    addChild(_consoleView);
    
    DrawNode* consoleViewNode = DrawNode::create();
    // box
    consoleViewNode->drawSegment(Vec2(0,0), Vec2(530, 0), 1, Color4F::GRAY);
    consoleViewNode->drawSegment(Vec2(530,0), Vec2(530, 400), 1, Color4F::GRAY);
    consoleViewNode->drawSegment(Vec2(530,400), Vec2(0, 400), 1, Color4F::GRAY);
    consoleViewNode->drawSegment(Vec2(0,400), Vec2(0, 0), 1, Color4F::GRAY);
    
    // tap
    consoleViewNode->drawSolidRect(Vec2(-1, 370), Vec2(531, 401), Color4F::GRAY);
    
    // red circle
    consoleViewNode->drawCircle(Vec2(465,385), 8.0f, 360.0f, 30, false, 1.0f, 1.0f, Color4F(0.7f, 0.0f, 0.0f, 1.0f));
    consoleViewNode->drawDot(Vec2(465, 385), 8.0f, Color4F(0.9f,0.0f,0.0f,1.0f));
    
    // yellow circle
    consoleViewNode->drawCircle(Vec2(490,385), 8.0f, 360.0f, 30, false, 1.0f, 1.0f, Color4F(0.5f, 0.5f, 0.0f, 1.0f));
    consoleViewNode->drawDot(Vec2(490, 385), 8.0f, Color4F(0.7f, 0.7f, 0.0f, 1.0f));
    
    // green circle
    consoleViewNode->drawCircle(Vec2(515,385), 8.0f, 360.0f, 30, false, 1.0f, 1.0f, Color4F(0.0f, 0.5f, 0.0f, 1.0f));
    consoleViewNode->drawDot(Vec2(515, 385), 8.0f, Color4F(0.0f, 0.7f, 0.0f, 1.0f));
    _consoleView->addChild(consoleViewNode , 100);
    
    _consoleViewTitle = Label::createWithSystemFont("MuscleMan Output", "", 20);
    _consoleViewTitle->setPosition(Vec2(10, 375));
    _consoleViewTitle->setAnchorPoint(Vec2(0.0f, 0.0f));
    _consoleViewTitle->setColor(Color3B::BLACK);
    _consoleView->addChild(_consoleViewTitle , 101);
    
    ui::Button* rightBtn = ui::Button::create("right.png", "right.png");
    rightBtn->setPosition(Vec2(487, 10));
    rightBtn->setAnchorPoint(Vec2::ZERO);
    rightBtn->addTouchEventListener([&, this](Ref* ref, ui::Widget::TouchEventType type){
        
        switch (type)
        {
            case ui::Widget::TouchEventType::ENDED:
            {
                if(_currConsoleEntity == Entity::kMuscleMan)
                {
                    _currConsoleEntity = Entity::kBBiBBi;
                }
                else if(_currConsoleEntity == Entity::kBBiBBi)
                {
                    _currConsoleEntity = Entity::kKidStone;
                }
                else if(_currConsoleEntity == Entity::kKidStone)
                {
                    _currConsoleEntity = Entity::kDefault;
                }
                else if(_currConsoleEntity == Entity::kDefault)
                {
                    _currConsoleEntity = Entity::kMuscleMan;
                }
                
                _changeConsoleViewTarget(_currConsoleEntity);
                
                break;
            }
            default:
            {
                break;
            }
        }
        
    });
    
    _consoleView->addChild(rightBtn, 101);
    
    _pause = Sprite::create("pause.png");
    _pause->setPosition(Vec2(487, 320));
    _pause->setAnchorPoint(Vec2::ZERO);
    _pause->setVisible(false);
    _consoleView->addChild(_pause, 103);
    
    ui::Button* playBtn = ui::Button::create("play.png", "play.png");
    playBtn->setPosition(Vec2(487, 320));
    playBtn->setAnchorPoint(Vec2::ZERO);
    playBtn->addTouchEventListener([&, this](Ref* ref, ui::Widget::TouchEventType type){
        
        switch (type)
        {
            case ui::Widget::TouchEventType::ENDED:
            {
                if(_isPlayGame)
                {
                    _isPlayGame = false;
                    _pause->setVisible(true);
                    
                }
                else
                {
                    _isPlayGame = true;
                    _pause->setVisible(false);
                }
                break;
            }
            default:
            {
                break;
            }
        }
        
    });
    
    _consoleView->addChild(playBtn, 102);
    
    _entryConsoleScrollView= ui::ScrollView::create();
    _entryConsoleScrollView->setSize(Size(530.0f, 370.0f));
    _entryConsoleScrollView->setAnchorPoint(Vec2(0.0f, 1.0f));
    _entryConsoleScrollView->setPosition(Vec2(0.0f, 370.0f));
    _entryConsoleScrollView->setInnerContainerSize(Size(530, 370.0f));
    _entryConsoleScrollView->setDirection(ui::ScrollView::Direction::VERTICAL);
    _entryConsoleScrollView->setBounceEnabled(true);
    _entryConsoleScrollView->setVisible(false);
    _consoleView->addChild(_entryConsoleScrollView , 99);

    
    _muscleManConsoleScrollView= ui::ScrollView::create();
    _muscleManConsoleScrollView->setSize(Size(530.0f, 370.0f));
    _muscleManConsoleScrollView->setAnchorPoint(Vec2(0.0f, 1.0f));
    _muscleManConsoleScrollView->setPosition(Vec2(0.0f, 370.0f));
    _muscleManConsoleScrollView->setInnerContainerSize(Size(530, 370.0f));
    _muscleManConsoleScrollView->setDirection(ui::ScrollView::Direction::VERTICAL);
    _muscleManConsoleScrollView->setBounceEnabled(true);
    _muscleManConsoleScrollView->setVisible(false);
    _consoleView->addChild(_muscleManConsoleScrollView , 99);
    
    _bbibbiConsoleScrollView= ui::ScrollView::create();
    _bbibbiConsoleScrollView->setSize(Size(530.0f, 370.0f));
    _bbibbiConsoleScrollView->setAnchorPoint(Vec2(0.0f, 1.0f));
    _bbibbiConsoleScrollView->setPosition(Vec2(0.0f, 370.0f));
    _bbibbiConsoleScrollView->setInnerContainerSize(Size(530, 370.0f));
    _bbibbiConsoleScrollView->setDirection(ui::ScrollView::Direction::VERTICAL);
    _bbibbiConsoleScrollView->setBounceEnabled(true);
    _bbibbiConsoleScrollView->setVisible(false);
    _consoleView->addChild(_bbibbiConsoleScrollView , 99);
    
    _kidStoneConsoleScrollView= ui::ScrollView::create();
    _kidStoneConsoleScrollView->setSize(Size(530.0f, 370.0f));
    _kidStoneConsoleScrollView->setAnchorPoint(Vec2(0.0f, 1.0f));
    _kidStoneConsoleScrollView->setPosition(Vec2(0.0f, 370.0f));
    _kidStoneConsoleScrollView->setInnerContainerSize(Size(530, 370.0f));
    _kidStoneConsoleScrollView->setDirection(ui::ScrollView::Direction::VERTICAL);
    _kidStoneConsoleScrollView->setBounceEnabled(true);
    _kidStoneConsoleScrollView->setVisible(false);
    _consoleView->addChild(_kidStoneConsoleScrollView , 99);
    
    
    //
    // Info View Init
    //
    _infoView = Sprite::create();
    _infoView->setPosition(Vec2(30, 10));
    addChild(_infoView);
    
    DrawNode* infoViewNode = DrawNode::create();
    // box
    infoViewNode->drawSegment(Vec2(0,0), Vec2(1076, 0), 1, Color4F::GRAY);
    infoViewNode->drawSegment(Vec2(1076,0), Vec2(1076, 200), 1, Color4F::GRAY);
    infoViewNode->drawSegment(Vec2(1076,200), Vec2(0, 200), 1, Color4F::GRAY);
    infoViewNode->drawSegment(Vec2(0,200), Vec2(0, 0), 1, Color4F::GRAY);
    
    // tap
    infoViewNode->drawSolidRect(Vec2(-1, 170), Vec2(1077, 201), Color4F::GRAY);
    
    // red circle
    infoViewNode->drawCircle(Vec2(1011,185), 8.0f, 360.0f, 30, false, 1.0f, 1.0f, Color4F(0.7f, 0.0f, 0.0f, 1.0f));
    infoViewNode->drawDot(Vec2(1011, 185), 8.0f, Color4F(0.9f,0.0f,0.0f,1.0f));
    
    // yellow circle
    infoViewNode->drawCircle(Vec2(1036,185), 8.0f, 360.0f, 30, false, 1.0f, 1.0f, Color4F(0.5f, 0.5f, 0.0f, 1.0f));
    infoViewNode->drawDot(Vec2(1036, 185), 8.0f, Color4F(0.7f, 0.7f, 0.0f, 1.0f));
    
    // green circle
    infoViewNode->drawCircle(Vec2(1061,185), 8.0f, 360.0f, 30, false, 1.0f, 1.0f, Color4F(0.0f, 0.5f, 0.0f, 1.0f));
    infoViewNode->drawDot(Vec2(1061, 185), 8.0f, Color4F(0.0f, 0.7f, 0.0f, 1.0f));
    _infoView->addChild(infoViewNode);
    
    Label* infoViewTitle = Label::createWithSystemFont("Message Queue", "", 20);
    infoViewTitle->setPosition(Vec2(10, 175));
    infoViewTitle->setAnchorPoint(Vec2(0.0f, 0.0f));
    infoViewTitle->setColor(Color3B::BLACK);
    _infoView->addChild(infoViewTitle);
    
    _messageQueueScrollView = ui::ScrollView::create();
    _messageQueueScrollView->setSize(Size(1076, 170));
    _messageQueueScrollView->setAnchorPoint(Vec2(0.0f, 1.0f));
    _messageQueueScrollView->setPosition(Vec2(0.0f, 170.0f));
    _messageQueueScrollView->setInnerContainerSize(Size(1076, 170));
    _messageQueueScrollView->setDirection(ui::ScrollView::Direction::VERTICAL);
    _messageQueueScrollView->setBounceEnabled(true);
    _infoView->addChild(_messageQueueScrollView);

    Label* test = Label::createWithSystemFont("test", "", 20);
    test->setPosition(Vec2(10.0f, 170.0f));
    test->setAnchorPoint(Vec2(0.0f, 1.0f));
    _messageQueueScrollView->addChild(test);

    
#pragma region addEntitis
    
    _muscleMan = Sprite::create("muscle1.png");
    _muscleMan->setPosition(kMinePos);
    _gameView->addChild(_muscleMan);
    
    auto muscleAnimation = Animation::create();
    muscleAnimation->setDelayPerUnit(0.3f);
    
    muscleAnimation->addSpriteFrameWithFile("muscle1.png");
    muscleAnimation->addSpriteFrameWithFile("muscle2.png");
    
    auto muscleAnimate = Animate::create(muscleAnimation);
    _muscleMan->runAction(RepeatForever::create(muscleAnimate));
    
    
    _BBiBBi = Sprite::create("bbibbi1.png");
    _BBiBBi->setPosition(kHomePos);
    _gameView->addChild(_BBiBBi);
    
    auto bbibbiAnimation = Animation::create();
    bbibbiAnimation->setDelayPerUnit(0.3f);
    
    bbibbiAnimation->addSpriteFrameWithFile("bbibbi1.png");
    bbibbiAnimation->addSpriteFrameWithFile("bbibbi2.png");
    
    auto bbibbiAnimate = Animate::create(bbibbiAnimation);
    _BBiBBi->runAction(RepeatForever::create(bbibbiAnimate));
    
    
    _kidStone = Sprite::create("stone1.png");
    _kidStone->setPosition(kSchoolPos);
    _gameView->addChild(_kidStone);
    
    auto kidAnimation = Animation::create();
    kidAnimation->setDelayPerUnit(0.3f);
    
    kidAnimation->addSpriteFrameWithFile("stone1.png");
    kidAnimation->addSpriteFrameWithFile("stone2.png");
    
    auto kidAnimate = Animate::create(kidAnimation);
    _kidStone->runAction(RepeatForever::create(kidAnimate));
    
#pragma endregion
    
    _currConsoleEntity = Entity::kMuscleMan;
    _changeConsoleViewTarget(_currConsoleEntity);
    
    EntMgr->registEntity(new MuscleMan((int)Entity::kMuscleMan));
    EntMgr->registEntity(new BBiBBi((int)Entity::kBBiBBi));
    EntMgr->registEntity(new KidStone((int)Entity::kKidStone));
    
    return true;
}

void HelloWorldScene::update(float dt)
{
    if(_isPlayGame)
    {
        if (_updateDelay < 1.0f)
        {
            _updateDelay += dt;
        }
        else
        {
            EntMgr->updateEntities(1.0f);
            Dispatch->dispatchDelayedMessages();
            
            _updateDelay = 0.0f;
        }
        
        _updateMessageQueueScrollView();
    }
}

void HelloWorldScene::moveEntity(Entity who, Location dest, float spendTime)
{
    Sprite* finWho;
    Vec2 finDest;
    
    // set entity
    if( who == Entity::kMuscleMan)
    {
        finWho = _muscleMan;
    }
    else if( who == Entity::kBBiBBi)
    {
        finWho = _BBiBBi;
    }
    else if(who == Entity::kKidStone)
    {
        finWho = _kidStone;
    }
    
    
    // set location, spend time.
    if( dest == Location::kBank)
    {
        finDest = kBankPos;
    }
    else if ( dest == Location::kBed)
    {
        finDest = kBedPos;
    }
    else if (dest == Location::kHome)
    {
        finDest = kHomePos;
    }
    else if ( dest == Location::kKitchen)
    {
        finDest = kKitchenPos;
    }
    else if( dest == Location::kMine)
    {
        finDest = kMinePos;
    }
    else if ( dest == Location::kSchool)
    {
        finDest = kSchoolPos;
    }
    else if(dest == Location::kToilet)
    {
        finDest = kToiletPos;
    }
    
    finWho->runAction(MoveTo::create(spendTime, finDest));
}

void HelloWorldScene::_updateMessageQueueScrollView()
{
    _messageQueueScrollView->removeAllChildren();
    std::vector<PushMessageQueueDataBundle> v = Dispatch->getUseableMessages();
    
    long numOfMessages = v.size();
    float scrollViewHeight {};
    if(numOfMessages < 10)
    {
        scrollViewHeight = 170.0f;
    }
    else
    {
        scrollViewHeight = 170.0f + (numOfMessages - 9) * 20.0f;
    }
    _messageQueueScrollView->setInnerContainerSize(Size(1076, scrollViewHeight));
    
    for(int i = 0 ; i < numOfMessages; ++ i)
    {
        std::string messageStr;
        if(v[i].messageType == MessageType::kBankArrived)
        {
            messageStr = "'kBankArrived'";
        }
        else if(v[i].messageType == MessageType::kBedArrived)
        {
            messageStr = "'kBedArrived'";
        }
        else if(v[i].messageType == MessageType::kEatCompleted)
        {
            messageStr = "'kEatCompleted'";
        }
        else if(v[i].messageType == MessageType::kFoodCompleted)
        {
            messageStr = "'kFoodCompleted'";
        }
        else if(v[i].messageType == MessageType::kHiHoneyGiveMeFood)
        {
            messageStr = "'kHiHoneyGiveMeFood'";
        }
        else if(v[i].messageType == MessageType::kHomeArrived)
        {
            messageStr = "'kHomeArrived'";
        }
        else if(v[i].messageType == MessageType::kKitchenArrived)
        {
            messageStr = "'kKitchenArrived'";
        }
        else if(v[i].messageType == MessageType::kMineArrived)
        {
            messageStr = "'kMineArrived'";
        }
        else if(v[i].messageType == MessageType::kSchoolArrived)
        {
            messageStr = "'kSchoolArrived'";
        }
        else if(v[i].messageType == MessageType::kSleepCompleted)
        {
            messageStr = "'kSleepCompleted'";
        }
        else if(v[i].messageType == MessageType::kStudyCompleted)
        {
            messageStr = "'kStudyCompleted'";
        }
        else if(v[i].messageType == MessageType::kToiletArrived)
        {
            messageStr = "'kToiletArrived'";
        }
        else if(v[i].messageType == MessageType::kToiletUseCompleted)
        {
            messageStr = "'kToiletUseCompleted'";
        }
        else if(v[i].messageType == MessageType::kWatchTVCompleted)
        {
            messageStr = "'kWatchTVCompleted'";
        }
        
        std::string rst = v[i].sender + "가 " + v[i].receiver + "에게 " + std::to_string(v[i].remainSeconds) + "초 뒤 도착하는 메세지(" + messageStr + ").";
        Label* label = Label::createWithSystemFont(rst, "", 20);
        label->setAnchorPoint(Vec2(0.0f, 1.0f));
        label->setPosition(Vec2(10.0f, scrollViewHeight - (i * 20.0f)));
        _messageQueueScrollView->addChild(label);
    }
    
}

void HelloWorldScene::pushLabelToConsoleView(Entity who, std::string text)
{
    ui::ScrollView* tempView = nullptr;
    int whoNumOfLabel = 0;
    if(who == Entity::kMuscleMan)
    {
        tempView = _muscleManConsoleScrollView;
        whoNumOfLabel = _numOfMuscleManConsoleViewLabels;
    }
    else if(who == Entity::kBBiBBi)
    {
        tempView = _bbibbiConsoleScrollView;
        whoNumOfLabel = _numOfBBiBBiConsoleViewLabels;
    }
    else if(who == Entity::kKidStone)
    {
        tempView = _kidStoneConsoleScrollView;
        whoNumOfLabel = _numOfKidStoneConsoleViewLabels;
    }
    
    Label* newLabel = Label::createWithSystemFont(text, "", 20);
    newLabel->setTag(whoNumOfLabel);
    newLabel->setAnchorPoint(Vec2(0.0f, 1.0f));
    float scrollViewHeight {};
    if(whoNumOfLabel < 20)
    {
        scrollViewHeight = 370.0f;
    }
    else
    {
        scrollViewHeight = 370.0f + (whoNumOfLabel - 19) * 20.0f;
    }
    
    tempView->setInnerContainerSize(Size(530, scrollViewHeight));
    tempView->addChild(newLabel);
    
    Vector<Node*> node = tempView->getChildren();
    for(auto &d : node)
    {
        d->setPosition(Vec2(10.0f, scrollViewHeight - (d->getTag() * 20.0f)));
    }
    

    if(who == Entity::kMuscleMan)
    {
        _numOfMuscleManConsoleViewLabels ++;
    }
    else if(who == Entity::kBBiBBi)
    {
        _numOfBBiBBiConsoleViewLabels ++;
    }
    else if(who == Entity::kKidStone)
    {
        _numOfKidStoneConsoleViewLabels ++;
    }
    
    _pushLabelToEntryConsoleView(text);
    
}

void HelloWorldScene::_pushLabelToEntryConsoleView(std::string text)
{
    Label* newLabel = Label::createWithSystemFont(text, "", 20);
    newLabel->setTag(_numOfEntryConsoleViewLabels);
    newLabel->setAnchorPoint(Vec2(0.0f, 1.0f));
    float scrollViewHeight {};
    if(_numOfEntryConsoleViewLabels < 20)
    {
        scrollViewHeight = 370.0f;
    }
    else
    {
        scrollViewHeight = 370.0f + (_numOfEntryConsoleViewLabels - 19) * 20.0f;
    }
    
    _entryConsoleScrollView->setInnerContainerSize(Size(530, scrollViewHeight));
    _entryConsoleScrollView->addChild(newLabel);
    
    Vector<Node*> node = _entryConsoleScrollView->getChildren();
    for(auto &d : node)
    {
        d->setPosition(Vec2(10.0f, scrollViewHeight - (d->getTag() * 20.0f)));
    }
    
    _numOfEntryConsoleViewLabels ++;
    
}

void HelloWorldScene::_changeConsoleViewTarget(Entity who)
{
    if( who == Entity::kMuscleMan)
    {
        _consoleViewTitle->setString("MuscleMan Output");
        _muscleManConsoleScrollView->setVisible(true);
        _bbibbiConsoleScrollView->setVisible(false);
        _kidStoneConsoleScrollView->setVisible(false);
        _entryConsoleScrollView->setVisible(false);
    }
    else if( who == Entity::kBBiBBi)
    {
         _consoleViewTitle->setString("BBi-BBi Output");
        _muscleManConsoleScrollView->setVisible(false);
        _bbibbiConsoleScrollView->setVisible(true);
        _kidStoneConsoleScrollView->setVisible(false);
        _entryConsoleScrollView->setVisible(false);
    }
    else if( who == Entity::kKidStone)
    {
         _consoleViewTitle->setString("KidStone Output");
        _muscleManConsoleScrollView->setVisible(false);
        _bbibbiConsoleScrollView->setVisible(false);
        _kidStoneConsoleScrollView->setVisible(true);
        _entryConsoleScrollView->setVisible(false);
    }
    else if( who == Entity::kDefault)
    {
         _consoleViewTitle->setString("All Output");
        _muscleManConsoleScrollView->setVisible(false);
        _bbibbiConsoleScrollView->setVisible(false);
        _kidStoneConsoleScrollView->setVisible(false);
        _entryConsoleScrollView->setVisible(true);
    }
}












