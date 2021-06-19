#pragma once
#include "cocos2d.h"
USING_NS_CC;


class BOSS1 :public cocos2d::Layer
{
public:
	int longwayx;
	int longwayy;
	CREATE_FUNC(BOSS1);
	const float* startx;
	const float* starty;
	void onKeyPressed(EventKeyboard::KeyCode Code, Event* events);
	void onKeyReleased(EventKeyboard::KeyCode Code, Event* event);
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keyMap;//≈–∂œ «∑Ò—π‘⁄º¸≈Ã…œ
	virtual bool init();
	Sprite* BOSS01;
	Sprite* bullt01;
	int* weapon;
	void createBOSS01(float dt);
	void moveBOSS01(float dt);
	void hpBOSS01(float dt);
	void deadBOSS01(float dt);
	void bulltBOSS01(float dt);
	void attackBOSS01(float dt);
	int isBOSS = 0;
	int isbullt = 0;
	int HP = 150;
	int* knightHP;
	int* knightARMOR;
	int movequickly = 0;
	~BOSS1();
	Animate* getAnimateBOSS01();
private:
};


