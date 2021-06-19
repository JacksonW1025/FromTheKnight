#include "Boss_map.h"
#include "Knight.h"
#include "weapon.h"
#include "StopScene.h"
#include "BOSS.h"
#include "AudioEngine.h"
#include "SetScene.h"
#include "winScene.h"
Scene* Boss_map::createScene()
{
	auto scene = Scene::create();
	auto layer = Boss_map::create();
	scene->addChild(layer);
	return scene;
}
bool Boss_map::init()
{
	if (!Layer::init())
		return false;
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto* layer1 = Layer::create();
	auto* BG = Sprite::create("second.png");
	BG->setAnchorPoint(Vec2(0, 0));
	BG->setScale(1, 0.9);
	layer1->addChild(BG, 0);
	auto layer_Knight = Knight::create();
	layer_Knight->_Knight->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	auto layerTry = createTry::create();
	layerTry->_Try->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	layerTry->weapon = &layer_Knight->weapon;
	layerTry->createTryLive = 1;
	layer_Knight->weapon = 4;
	layerTry->isweapon = &layer_Knight->isweapon;
	layerTry->startx = &layer_Knight->_Knight->getPosition().x;
	layerTry->starty = &layer_Knight->_Knight->getPosition().y;
	layerTry->mp = &layer_Knight->MP;
	layer1->addChild(layer_Knight, 0);
	layer1->addChild(layerTry, 0);
	this->addChild(layer1);

	auto layerBOSS = BOSS1::create();
	layerBOSS->weapon = &layer_Knight->weapon;
	layerBOSS->startx = &layer_Knight->_Knight->getPosition().x;
	layerBOSS->starty = &layer_Knight->_Knight->getPosition().y;
	layerBOSS->knightHP = &layer_Knight->HP;
	layerBOSS->knightARMOR = &layer_Knight->ARMOR;
	layerBOSS->longwayx = 0;
	layerBOSS->longwayy = -200;
	boss_hp = &layerBOSS->HP;
	this->addChild(layerBOSS);

	hp = &layer_Knight->HP;
	armor = &layer_Knight->ARMOR;
	hp_MAX = &layer_Knight->HP_MAX;
	mp = &layer_Knight->MP;
	auto UI_status = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("UI_status.ExportJson");
	UI_status->setAnchorPoint(Vec2(0, 0.5));
	UI_status->setPosition(Vec2(0, visibleSize.height * 0.8));
	this->addChild(UI_status);

	/*load the UI*/
	Button* exitBtn = (Button*)Helper::seekWidgetByName(UI_status, "exitBtn");
	exitBtn->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
		switch (type)
		{
			case ui::Widget::TouchEventType::BEGAN:
				break;
			case ui::Widget::TouchEventType::ENDED:
				Director::getInstance()->end();
				break;
			default:
				break;
		}
		});
	Button* pauseBtn = (Button*)Helper::seekWidgetByName(UI_status, "pauseBtn");
	pauseBtn->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
		switch (type)
		{
			case ui::Widget::TouchEventType::BEGAN:
				break;
			case ui::Widget::TouchEventType::ENDED:
				Director::getInstance()->pushScene(StopSC::createScene());
				break;
			default:
				break;
		}
		});

	
	HPlable = (Text*)Helper::seekWidgetByName(UI_status, "HPlable");
	AMlable = (Text*)Helper::seekWidgetByName(UI_status, "AMlable");
	MPlable = (Text*)Helper::seekWidgetByName(UI_status, "MPlable");
	HPbar = (LoadingBar*)Helper::seekWidgetByName(UI_status, "HPbarImg");
	AMbar = (LoadingBar*)Helper::seekWidgetByName(UI_status, "ARMORbarImg");
	MPbar = (LoadingBar*)Helper::seekWidgetByName(UI_status, "MPbarImg");

	HPlable->setString(Value(*hp).asString());
	AMlable->setString(Value(*armor).asString());
	MPlable->setString(Value(*mp).asString());

	HPbar->setPercent((*hp+0.0) / *hp_MAX * 100);
	AMbar->setPercent((*armor+0.0) / 10 * 100);
	MPbar->setPercent((*mp+0.0) / 200 * 100);

	auto label = Label::createWithTTF("Your corn is decreasing...", "fonts/Marker Felt.ttf", 24);
	label->setPosition(Vec2(origin.x + visibleSize.width / 2, visibleSize.height - label->getContentSize().height));
	label->enableGlow(Color4B::BLUE);
	
	label_corn = Text::create();
	label_corn->setPosition(Vec2(origin.x + visibleSize.width / 2, visibleSize.height - 2*label->getContentSize().height));
	label_corn->enableGlow(Color4B::BLUE);

	auto cornImg = Sprite::create("add_gold.png");
	cornImg->setPosition(Vec2(origin.x + visibleSize.width / 2 - label_corn->getContentSize().width / 2, visibleSize.height - 2 * label->getContentSize().height));
	this->addChild(cornImg);
	this->addChild(label);
	this->addChild(label_corn);
	this->scheduleUpdate();


	auto setImg = MenuItemImage::create(
		"set.png",
		"set.png",
		CC_CALLBACK_1(Boss_map::menuCloseCallbackSet, this));
	auto Menu02 = Menu::create(setImg, NULL);
	Menu02->setPosition(100, 100);
	this->addChild(Menu02, 1);

	Boss_HPbar = LoadingBar::create("bossBlood.png");
	Boss_HPbarBG = Sprite::create("bossBloodBg.png");
	Boss_HPbar->setScale(1, 1);
	Boss_HPbarBG->setScale(1, 1);
	Boss_HPbar->setAnchorPoint(Vec2(0.5, 0));
	Boss_HPbarBG->setAnchorPoint(Vec2(0.5, 0));
	Boss_HPbar->setPosition(Vec2(visibleSize.width/2, visibleSize.height/6));
	Boss_HPbarBG->setPosition(Vec2(visibleSize.width/2, visibleSize.height/6));
	this->addChild(Boss_HPbarBG, 3);
	this->addChild(Boss_HPbar, 3);
	return true;
}
void Boss_map::update(float tmd)
{
	HPlable->setString(Value(*hp).asString());
	AMlable->setString(Value(*armor).asString());
	MPlable->setString(Value(*mp).asString());
	label_corn->setString(Value(corn).asString());
	if (corn > 0)
	{
		corn-=1;
	}
	if (*boss_hp <= 0)
	{
		Director::getInstance()->replaceScene(TransitionSlideInT::create(1.0f, winSC::createScene()));
	}
	HPbar->setPercent((*hp + 0.0) / *hp_MAX * 100);
	AMbar->setPercent((*armor + 0.0) / 10 * 100);
	MPbar->setPercent((*mp + 0.0) / 200 * 100);
	Boss_HPbar->setPercent((*boss_hp + 0.0) / 150 * 100);

}

void Boss_map::menuCloseCallbackSet(Ref* pSender)
{
	Director::getInstance()->pushScene(TransitionFade::create(1.0f, SetScene::createScene()));
}