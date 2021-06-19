#pragma once
#ifndef __SAFEMAP_SCENE_H__
#define __SAFEMAP_SCENE_H__
#include "cocos2d.h"

#include "editor-support/cocostudio/CCSGUIReader.h"
#include"ui/CocosGUI.h"
using namespace cocos2d::ui;
using namespace cocostudio;

class SafeMap : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void menuCloseCallback_close(cocos2d::Ref* pSender);
	void update(float delta);
	void loadUI();
	void SafeMap::menuCloseCallbackSet(Ref* pSender);
	//ImageView* m_exitBtnImg;
	CREATE_FUNC(SafeMap);
private:
	INT HP;
	INT ARMOR;
	INT MP;
	Text* HPlable;
	Text* AMlable;
	Text* MPlable;
	LoadingBar* HPbar;
	LoadingBar* AMbar;
	LoadingBar* MPbar;
};


#endif // __HELLOWORLD_SCENE_H__