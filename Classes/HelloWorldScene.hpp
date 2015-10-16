//
//  HelloWorldScene.hpp
//  Ai001_StateMachine
//
//  Created by 남준현 on 2015. 9. 24..
//  Copyright © 2015년 남준현. All rights reserved.
//

#pragma once

#include "cocos2d.h"
#include "Entities.hpp"
#include "Locations.hpp"
#include "ui/CocosGUI.h"

#define kGameViewWidth          500
#define kGameViewHeight         400

#define kConsoleViewWidth       530
#define kConsoleViewHeight      400

#define kInfoViewWidth          1030
#define kInfoViewHeight         210

#define kHomePos                Vec2(200, 230)
#define kKitchenPos             Vec2(200, 170)
#define kToiletPos              Vec2(300, 230)
#define kBedPos                 Vec2(300, 170)
#define kBankPos                Vec2(370, 300)
#define kMinePos                Vec2(70, 300)
#define kSchoolPos              Vec2(370, 50)

class HelloWorldScene : public cocos2d::LayerColor
{
    
private:
    
    cocos2d::Sprite*					_muscleMan;
    cocos2d::Sprite*					_BBiBBi;
    cocos2d::Sprite*					_kidStone;
    
    cocos2d::Size						_winSize;
    
    cocos2d::Sprite*                    _gameView;
    cocos2d::Sprite*                    _consoleView;
    cocos2d::Sprite*                    _infoView;
    
    cocos2d::Label*                     _consoleViewTitle;
    
    cocos2d::ui::ScrollView*            _entryConsoleScrollView;
    cocos2d::ui::ScrollView*            _muscleManConsoleScrollView;
    cocos2d::ui::ScrollView*            _bbibbiConsoleScrollView;
    cocos2d::ui::ScrollView*            _kidStoneConsoleScrollView;
    cocos2d::ui::ScrollView*            _messageQueueScrollView;
    
    cocos2d::Sprite*                    _pause;
    
    int                                 _numOfEntryConsoleViewLabels = 0;
    int                                 _numOfMuscleManConsoleViewLabels = 0;
    int                                 _numOfBBiBBiConsoleViewLabels = 0;
    int                                 _numOfKidStoneConsoleViewLabels = 0;
    float								_updateDelay = 0.0f;
    Entity                              _currConsoleEntity;
    bool                                _isPlayGame = true;
    
    void _pushLabelToEntryConsoleView(std::string text);
    void _changeConsoleViewTarget(Entity who);
    void _updateMessageQueueScrollView();
    
public:
    
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(HelloWorldScene);
    
    void update(float dt);
    void moveEntity(Entity who, Location dest, float spendTime);
    void pushLabelToConsoleView(Entity who, std::string text);
    
};
