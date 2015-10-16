//
//  SceneListener.cpp
//  Ai001_StateMachine
//
//  Created by 남준현 on 2015. 10. 12..
//  Copyright © 2015년 남준현. All rights reserved.
//


#include "SceneListener.hpp"
#include "Telegram.hpp"
#include <numeric>

SceneListener::SceneListener(int id) : BaseEntity(id)
{
}

SceneListener* SceneListener::getInstance()
{
    static SceneListener instance(std::numeric_limits<int>::max());
	return &instance;
}

bool SceneListener::handleMessage(const Telegram& msg)
{
	switch (msg.msg)
	{
		case MessageType::kMoveEntity:
		{
            MoveEntityDataBundle* extra = (MoveEntityDataBundle*)msg.extraInfo;
			_scene->moveEntity(extra->entity, extra->dest, extra->spendTime);
			return true;
		}
        case MessageType::kPushLog:
        {
            PushLogDataBundle* extra = (PushLogDataBundle*)msg.extraInfo;
            _scene->pushLabelToConsoleView(extra->entity, extra->text);
            return true;
        }
		default:
		{
			return false;
		}
	}
}