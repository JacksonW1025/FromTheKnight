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
	void update(float dt);
	bool isinPortal(Sprite* sprite);
	void bindSprite(Sprite* sprite);
	Sprite* _Knight;//��ʿ����
	int Limit = 0;
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keyMap;//�ж��Ƿ�ѹ�ڼ�����
	void knightMove(float dt);
	~Knight();
	int k = 0;
private:
	int direction;//�ж����ҳ���
	Sprite* portal;
};




