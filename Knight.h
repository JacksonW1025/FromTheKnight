#pragma once
#include "cocos2d.h"
USING_NS_CC;

class Knight :public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	CREATE_FUNC(Knight);
	virtual bool init();
	Animate* getAnimateRight();//���ƶ���
	Animate* getAnimateLeft();//���ƶ���
	void onKeyPressed(EventKeyboard::KeyCode Code, Event* events);
	void onKeyReleased(EventKeyboard::KeyCode Code, Event* event);
	Sprite* _Knight;//��ʿ����
	int Limit = 0;
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keyMap;//�ж��Ƿ�ѹ�ڼ�����
	void knightMove(float dt);
	bool Knight::isinPortal(Sprite* portal);
	void Knight::update(float dt);
	void Knight::bindSprite(Sprite* sprite);
	int* isbeast00;
	int* isbeast01;
	int* isbeast02;
	int* isbeast03;
	int* isbeast04;
	int* isbeast05;
	int* isbeast06;
	int* isbeast07;
	int theLastMove = 0;//��¼��һ���ƶ�����
	int weapon = 1;//��¼����װ��״̬
	int isweapon = 1;//��¼�Ƿ�װ������
	int HP_MAX = 5;
	int HP = HP_MAX;
	int MP = 200;
	int CD = 16;
	int ARMORCD = 0;
	int ARMOR = 10;
	int iswar = 0;
	int direction;//�ж����ҳ���
	~Knight();
private:
	Sprite* portal;
};

