//
//  SceneListener.hpp
//  Ai001_StateMachine
//
//  Created by 남준현 on 2015. 10. 12..
//  Copyright © 2015년 남준현. All rights reserved.
//


#pragma once

#include "BaseEntity.hpp"
#include "HelloWorldScene.hpp"

#define SceneLisner SceneListener::getInstance()

class Telegram;

class SceneListener : public BaseEntity
{

private:

	HelloWorldScene*			_scene;

	SceneListener(int id);
	SceneListener() = delete;
	SceneListener& operator=(const SceneListener&) = delete;
	SceneListener(const SceneListener&) = delete;

public:

	static SceneListener* getInstance();

	void registScene(HelloWorldScene* scene)	{ _scene = scene; }
	bool handleMessage(const Telegram& msg);
	void update(float dt) {}

};