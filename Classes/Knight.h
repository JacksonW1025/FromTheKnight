#pragma once
#include "cocos2d.h"
USING_NS_CC;
#include "editor-support/cocostudio/CCSGUIReader.h"
#include"ui/CocosGUI.h"
using namespace cocos2d::ui;
using namespace cocostudio;

class Knight :public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	CREATE_FUNC(Knight);
	virtual bool init();
	Animate* getAnimateRight();//右移动画
	Animate* getAnimateLeft();//左移动画
	void onKeyPressed(EventKeyboard::KeyCode Code, Event* events);
	void onKeyReleased(EventKeyboard::KeyCode Code, Event* event);
	Sprite* _Knight;//骑士精灵
	int Limit = 0;
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keyMap;//判断是否压在键盘上
	void knightMove(float dt);
	bool Knight::isinPortal(Sprite* portal);
	void Knight::update(float dt);
	void Knight::bindSprite(Sprite* sprite);
	int theLastMove = 0;//记录上一个移动动作
	int weapon = 1;//记录武器装备状态
	int isweapon = 1;//记录是否装备武器
	int direction;//判断左右朝向
	void set_status();
	~Knight();
private:
	Sprite* portal;
	INT HP=5;
	INT ARMOR=10;
	INT MP=100;
	Text* HPlable;
	Text* AMlable;
	Text* MPlable;
	LoadingBar* HPbar;
	LoadingBar* AMbar;
	LoadingBar* MPbar;
};

