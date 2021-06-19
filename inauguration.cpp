#include "inauguration.h"
#include "SafeMapScene.h"
#include"cocos2d.h"
#include "AudioEngine.h"
#include "SetScene.h"
using namespace std;
USING_NS_CC;


Scene* inauguration::createScene()
{
	return inauguration::create();
}

bool inauguration::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto closeItem = MenuItemImage::create(
		"exit_up.png",
		"exit_down.png",
		CC_CALLBACK_1(inauguration::menuCloseCallback, this));
	auto start = MenuItemFont::create("Start", CC_CALLBACK_1(inauguration::menuStartCallback, this));//按开始游戏后的动作，可修改
	start->setColor(Color3B::RED);
	start->setFontSizeObj(100);
	float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
	float y = origin.y + closeItem->getContentSize().height / 2;
	start->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	closeItem->setPosition(Vec2(x, y));
	Vec2 start_V = Director::getInstance()->getVisibleSize() / 2;

	//关闭按钮创建，开始游戏按钮
	auto menu = Menu::create(closeItem, NULL);
	menu->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
	menu_s = Menu::create(start, NULL);
	menu_s->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	menu_s->setPosition(start_V.x, start_V.y - 20);
	this->addChild(menu_s, 1);

	string p_content = StringUtils::format("Welcome to our ");
	p_content.append("Soul Knight!");
	label = Label::createWithTTF(p_content, "fonts/Marker Felt.ttf", 48);
	label->setColor(Color3B::GREEN);
	label->enableOutline(Color4B::RED, 1);
	label->enableBold();         //黑体
	static int opacity = 0;
	label->setOpacity(0);
	menu_s->setOpacity(0);
	this->schedule([&](float dlt)
		{
			if (opacity >= 255)
			{
				this->unschedule("schedule");
				return;
			}
			opacity += 1;
			label->setOpacity(opacity);
			menu_s->setOpacity(opacity);
		}, 0.02f, "schedule");

	backgroundAudioID = AudioEngine::play2d("bkMusic.mp3", true);  //play music

	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height - 220));
	this->addChild(label, 1);

	auto setImg = MenuItemImage::create(
		"set.png",
		"set.png",
		CC_CALLBACK_1(inauguration::menuCloseCallbackSet, this));
	auto Menu02 = Menu::create(setImg, NULL);
	Menu02->setPosition(closeItem->getPositionX() - 110, closeItem->getPositionY());
	this->addChild(Menu02, 1);
	/* 背景创建*/
	auto sprite = Sprite::create("pic.png");
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);

	
	return true;
}

void inauguration::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();
}
void inauguration::menuStartCallback(Ref* pSender)
{
	//replace scene after beginning;
	Director::getInstance()->replaceScene(TransitionSlideInT::create(1.0f, SafeMap::createScene()));
}
void inauguration::menuCloseCallbackSet(Ref* pSender)
{
	Director::getInstance()->pushScene(TransitionFade::create(1.0f, SetScene::createScene()));
}
