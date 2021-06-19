#pragma once
#include "cocos2d.h"
USING_NS_CC;

class createShot :public cocos2d::Layer
{
public:
	CREATE_FUNC(createShot);
	virtual bool init();
	Sprite* _Shot;//精灵
	void ShotCreate(int x, int y);
	void onKeyPressed(EventKeyboard::KeyCode Code, Event* events);
	void onKeyReleased(EventKeyboard::KeyCode Code, Event* event);
	bool onTouchBegan();
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keyMap;//判断是否压在键盘上
	void ShotMove(float dt);
	void ShotQJ(float dt);
	const float* startx;
	const float* starty;
	int createShotLive = 1;
	int direct = 1;
	int* weapon;
	int* isweapon;
	int* mp;
	~createShot();
private:

};


class createSaber :public cocos2d::Layer
{
public:
	CREATE_FUNC(createSaber);
	virtual bool init();
	Sprite* _Saber;//精灵
	Animate* getAnimateSaber();
	void SaberCreate(int x, int y);
	void onKeyPressed(EventKeyboard::KeyCode Code, Event* events);
	void onKeyReleased(EventKeyboard::KeyCode Code, Event* event);
	bool onTouchBegan();
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keyMap;//判断是否压在键盘上
	void SaberMove(float dt);
	void SaberQJ(float dt);
	const float* startx;
	const float* starty;
	int createSaberLive = 0;
	int direct = 0;
	int* weapon;
	int* isweapon;
	~createSaber();
private:

};



class createBigKnife :public cocos2d::Layer
{
public:
	CREATE_FUNC(createBigKnife);
	virtual bool init();
	Sprite* _BigKnife;//精灵
	Animate* getAnimateBigKnife();
	void BigKnifeCreate(int x, int y);
	void onKeyPressed(EventKeyboard::KeyCode Code, Event* events);
	void onKeyReleased(EventKeyboard::KeyCode Code, Event* event);
	bool onTouchBegan();
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keyMap;//判断是否压在键盘上
	void BigKnifeMove(float dt);
	void BigKnifeQJ(float dt);
	const float* startx;
	const float* starty;
	int createBigKnifeLive = 0;
	int direct = 0;
	int* weapon;
	int* isweapon;
	~createBigKnife();
private:

};


class createTry :public cocos2d::Layer
{
public:
	CREATE_FUNC(createTry);
	virtual bool init();
	Sprite* _Try;//精灵
	void TryCreate(int x, int y);
	void onKeyPressed(EventKeyboard::KeyCode Code, Event* events);
	void onKeyReleased(EventKeyboard::KeyCode Code, Event* event);
	bool onTouchBegan();
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keyMap;//判断是否压在键盘上
	void TryMove(float dt);
	void TryQJ(float dt);
	const float* startx;
	const float* starty;
	int createTryLive = 0;
	int direct = 0;
	int* weapon;
	int* isweapon;
	int* mp;
	~createTry();
private:

};

class d :public cocos2d::Layer
{
public:
	CREATE_FUNC(d);
	const float* startx;
	const float* starty;
	void onKeyPressed(EventKeyboard::KeyCode Code, Event* events);
	void onKeyReleased(EventKeyboard::KeyCode Code, Event* event);
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keyMap;//判断是否压在键盘上
	virtual bool init();
	Sprite* pl;
	Sprite* bullt;
	int* weapon;
	void ddd(float dt);
	void ddc(float dt);
	void ddb(float dt);
	void dda(float dt);
	void dde(float dt);
	void ddf(float dt);
	int dddd = 0;
	int da = 0;
	int HP = 3;
	int* knightHP;
	~d();
private:
};