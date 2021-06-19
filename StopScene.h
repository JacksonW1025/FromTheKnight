#pragma once
#ifndef __STOP_SCENE_H__
#define __STOP_SCENE_H__

#include "cocos2d.h"

class StopSC : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    void menuCloseCallback(cocos2d::Ref* pSender);
    void popScene(cocos2d::Ref* pSender);
    // implement the "static create()" method manually
    CREATE_FUNC(StopSC);
};

#endif