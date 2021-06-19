#pragma once
#include "cocos2d.h"
USING_NS_CC;

class besat1 :public cocos2d::Layer
{
public:
	int longwayx;
	int longwayy;
	CREATE_FUNC(besat1);
	const float* startx;
	const float* starty;
	void onKeyPressed(EventKeyboard::KeyCode Code, Event* events);
	void onKeyReleased(EventKeyboard::KeyCode Code, Event* event);
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keyMap;//≈–∂œ «∑Ò—π‘⁄º¸≈Ã…œ
	virtual bool init();
	Sprite* besat01;
	Sprite* bullt01;
	int* weapon;
	void createbesat01(float dt);
	void movebeast01(float dt);
	void hpbeast01(float dt);
	void deadbeast01(float dt);
	void bulltbeast01(float dt);
	void attackbeast01(float dt);
	int isbeast = -1;
	int isbullt = 0;
	int HP = 5;
	int* knightHP;
	int* knightARMOR;
	int* direct;
	int kinds = 0;
	int movequickly = 0;
	~besat1();
	Animate* getAnimatebeast01();
private:
};

class besat2 :public cocos2d::Layer
{
public:
	int longwayx;
	int longwayy;
	CREATE_FUNC(besat2);
	const float* startx;
	const float* starty;
	void onKeyPressed(EventKeyboard::KeyCode Code, Event* events);
	void onKeyReleased(EventKeyboard::KeyCode Code, Event* event);
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keyMap;//≈–∂œ «∑Ò—π‘⁄º¸≈Ã…œ
	virtual bool init();
	Sprite* besat02;
	int* weapon;
	void createbesat02(float dt);
	void movebeast02(float dt);
	void hpbeast02(float dt);
	void deadbeast02(float dt);
	void attackbeast02(float dt);
	int isbeast = -1;
	int HP = 9;
	int* knightHP;
	int* knightARMOR;
	int* direct;
	int kinds = 0;
	int movequickly = 0;
	~besat2();
	Animate* getAnimatebeast02();
private:
};
