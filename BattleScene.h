#pragma once
#define MAP_SIZE 1600
#include "cocos2d.h"
#include "Knight.h"
#include "editor-support/cocostudio/CCSGUIReader.h"
#include"ui/CocosGUI.h"
using namespace cocos2d::ui;
using namespace cocostudio;
USING_NS_CC;

/*Õ½¶·³¡¾°*/

class BattleScene : public Scene
{
public:
	CREATE_FUNC(BattleScene);
	virtual bool init();
	bool isCanReach(const float* x, const float* y);
	bool NextPass(const float* x, const float* y);
	TMXTiledMap* map = TMXTiledMap::create("First.tmx");
	const float* startx;
	const float* starty;
	int* limit;
	void update(float tmd);
	void BattleScene::setPointOfViwe();
	bool isCanPass(const float* x, const float* y);
	bool BattleScene::isdeath();
	void BattleScene::menuCloseCallbackSet(Ref* pSender);
	int* armor;
	int* Enemy_Num;
	int* hp_MAX;
	int* hp;
	int* mp;
	Text* HPlable;
	Text* AMlable;
	Text* MPlable;
	LoadingBar* HPbar;
	LoadingBar* AMbar;
	LoadingBar* MPbar;
	int* isdeath1;
	int* isdeath2;
	int* isdeath3;
	int* isdeath4;
	int* isdeath5;
	int* isdeath6;
	int* isdeath7;
	int* isdeath8;
	int ismap1 = 1;
	int ismap2 = 1;
};