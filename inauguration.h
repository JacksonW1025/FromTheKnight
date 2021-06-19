#pragma once
#include "AppDelegate.h"
#include "SafeMapScene.h"
#include"cocos2d.h"
#include<string.h>
#include "AudioEngine.h"
#include "ui/CocosGUI.h"
USING_NS_CC;

class inauguration : public Scene
{
public:
	static cocos2d::Scene* createScene();
	CREATE_FUNC(inauguration);
	virtual bool init();
	void menuStartCallback(Ref* pSender);
	void menuCloseCallback(Ref* pSender);
	void menuCloseCallbackSet(Ref* pSender);
	void popScene(Ref* pSender);

	int backgroundAudioID;   //开始界面背景音乐
	//CREATE_FUNC(inauguration);

private:
	Label* label;
	Menu* menu_s;


};

