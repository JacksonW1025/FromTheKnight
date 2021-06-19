#pragma once
#include "editor-support/cocostudio/CCSGUIReader.h"
#include"ui/CocosGUI.h"

#include "cocos2d.h"
using namespace cocos2d::ui;
using namespace cocostudio;
USING_NS_CC;

/*Õ½¶·³¡¾°*/

class Boss_map: public Layer
{
public:
	CREATE_FUNC(Boss_map) ;
	virtual bool init() ;
	void update(float delta);
	static cocos2d::Scene* createScene();
	void Boss_map::menuCloseCallbackSet(Ref* pSender);
	int* armor;
	int* Enemy_Num;
	int* hp_MAX;
	int* hp;
	int* mp;
	int corn=10000;
	Text* HPlable;
	Text* AMlable;
	Text* MPlable;
	Text* label_corn;
	LoadingBar* HPbar;
	LoadingBar* AMbar;
	LoadingBar* MPbar;
	LoadingBar* Boss_HPbar;
	Sprite* Boss_HPbarBG;
	int* boss_hp;
};