#pragma once
#include "cocos2d.h"
USING_NS_CC;

class createMeasure :public cocos2d::Layer
{
public:
	CREATE_FUNC(createMeasure);
	virtual bool init();
	void MeasureCreate(int x, int y);
	void Measurebegan(float dt);
	int islife = 0;
	int ison = 0;
	const float* startx;
	const float* starty;
	Sprite* _measure;
	Animate* getAnimateMeasure();
	~createMeasure();
private:

};

class createHP :public cocos2d::Layer
{
public:
	CREATE_FUNC(createHP);
	virtual bool init();
	void HPCreate(int x, int y);
	Sprite* _HP;//精灵
	Animate* getAnimateHP();
	void onKeyPressed(EventKeyboard::KeyCode Code, Event* events);
	void onKeyReleased(EventKeyboard::KeyCode Code, Event* event);
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keyMap;//判断是否压在键盘上
	void beganHP(float dt);
	const float* startx;
	const float* starty;
	int* knighthp;
	int isHP = 0;
	~createHP();
private:

};

class createMP :public cocos2d::Layer
{
public:
	CREATE_FUNC(createMP);
	virtual bool init();
	void MPCreate(int x, int y);
	Sprite* _MP;//精灵
	Animate* getAnimateMP();
	void onKeyPressed(EventKeyboard::KeyCode Code, Event* events);
	void onKeyReleased(EventKeyboard::KeyCode Code, Event* event);
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keyMap;//判断是否压在键盘上
	void beganMP(float dt);
	const float* startx;
	const float* starty;
	int* knightmp;
	int isMP = 0;
	~createMP();
private:

};