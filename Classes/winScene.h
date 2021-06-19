#pragma once
#pragma once
#ifndef __WIN_SCENE_H__
#define __WIN_SCENE_H__

#include "cocos2d.h"

class winSC : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    void menuCloseCallback(cocos2d::Ref* pSender);
    void popScene(cocos2d::Ref* pSender);
    // implement the "static create()" method manually
    CREATE_FUNC(winSC);
};

#endif