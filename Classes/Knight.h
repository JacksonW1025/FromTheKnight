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
	int theLastMove = 0;//��¼��һ���ƶ�����
	int weapon = 1;//��¼����װ��״̬
	int isweapon = 1;//��¼�Ƿ�װ������
	int direction;//�ж����ҳ���
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

