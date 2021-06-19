#include "BattleScene.h"
#include "Knight.h"
#include "Boss_map.h"
#include "weapon.h"
#include "measureProp.h"
#include "StopScene.h"
#include "beast.h"
#include "editor-support/cocostudio/CCSGUIReader.h"
#include"ui/CocosGUI.h"
#include "AudioEngine.h"
#include "SetScene.h"

using namespace cocos2d::ui;
using namespace cocostudio;
bool BattleScene::init()
{
	if (!Scene::init())
		return false;
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	map->setAnchorPoint(Vec2(0, 0));
	map->setPosition(Vec2::ZERO);
	map->setScale(1, 1);
	addChild(map);
	auto layer0 = Knight::create();
	auto layerShot = createShot::create();
	auto layerSaber = createSaber::create();
	auto layerBigKnife = createBigKnife::create();
	auto box1 = createMeasure::create();
	auto box2 = createMeasure::create();
	auto box3 = createMeasure::create();
	auto box4 = createMeasure::create();
	auto hp1 = createHP::create();
	auto mp1 = createMP::create();
	Vec2 position = Vec2(layer0->_Knight->getPosition().x, layer0->_Knight->getPosition().y);
	layerShot->_Shot->setPosition(position);
	layerSaber->_Saber->setPosition(Vec2(220, 980));
	layerBigKnife->_BigKnife->setPosition(Vec2(800, 500));
	box1->_measure->setScale(1.3, 1.3);
	box2->_measure->setScale(1.5, 1.5);
	box1->_measure->setPosition(Vec2(220, 980));
	box2->_measure->setPosition(Vec2(800, 500));
	box3->_measure->setPosition(Vec2(1000, 1450));
	box4->_measure->setPosition(Vec2(1000, 1200));
	hp1->_HP->setPosition(Vec2(1000, 1450));
	mp1->_MP->setPosition(Vec2(1000, 1200));
	layerShot->weapon = &layer0->weapon;
	layerShot->isweapon = &layer0->isweapon;
	layerShot->startx = &layer0->_Knight->getPosition().x;
	layerShot->starty = &layer0->_Knight->getPosition().y;
	layerShot->mp = &layer0->MP;
	layerSaber->weapon = &layer0->weapon;
	layerSaber->isweapon = &layer0->isweapon;
	layerSaber->startx = &layer0->_Knight->getPosition().x;
	layerSaber->starty = &layer0->_Knight->getPosition().y;
	layerBigKnife->weapon = &layer0->weapon;
	layerBigKnife->isweapon = &layer0->isweapon;
	layerBigKnife->startx = &layer0->_Knight->getPosition().x;
	layerBigKnife->starty = &layer0->_Knight->getPosition().y;
	box1->startx = &layer0->_Knight->getPosition().x;
	box1->starty = &layer0->_Knight->getPosition().y;
	box2->startx = &layer0->_Knight->getPosition().x;
	box2->starty = &layer0->_Knight->getPosition().y;
	box3->startx = &layer0->_Knight->getPosition().x;
	box3->starty = &layer0->_Knight->getPosition().y;
	box4->startx = &layer0->_Knight->getPosition().x;
	box4->starty = &layer0->_Knight->getPosition().y;
	hp1->startx = &layer0->_Knight->getPosition().x;
	hp1->starty = &layer0->_Knight->getPosition().y;
	hp1->knighthp = &layer0->HP;
	mp1->knightmp = &layer0->MP;
	mp1->startx = &layer0->_Knight->getPosition().x;
	mp1->starty = &layer0->_Knight->getPosition().y;
	map->addChild(hp1);
	map->addChild(mp1);
	auto layerbeast = besat1::create();
	layerbeast->kinds = 1;
	layerbeast->weapon = &layer0->weapon;
	layerbeast->startx = &layer0->_Knight->getPosition().x;
	layerbeast->starty = &layer0->_Knight->getPosition().y;
	layerbeast->knightHP = &layer0->HP;
	layerbeast->direct = &layerShot->direct;
	layer0->isbeast00 = &layerbeast->isbeast;
	layerbeast->longwayx = 100;
	layerbeast->longwayy = 200;
	layer0->iswar = 1;
	layerbeast->knightARMOR = &layer0->ARMOR;
	isdeath3 = &layerbeast->isbeast;
	map->addChild(layerbeast);

	auto layerbeast0 = besat1::create();
	layerbeast0->kinds = 1;
	layerbeast0->weapon = &layer0->weapon;
	layerbeast0->startx = &layer0->_Knight->getPosition().x;
	layerbeast0->starty = &layer0->_Knight->getPosition().y;
	layerbeast0->knightHP = &layer0->HP;
	layerbeast0->direct = &layerShot->direct;
	layer0->isbeast01 = &layerbeast0->isbeast;
	layerbeast0->longwayx = -100;
	layerbeast0->longwayy = 200;
	layerbeast0->knightARMOR = &layer0->ARMOR;
	layerbeast0->movequickly = 5;
	isdeath4 = &layerbeast0->isbeast;
	map->addChild(layerbeast0);

	auto layerbeast1 = besat1::create();
	layerbeast1->weapon = &layer0->weapon;
	layerbeast1->startx = &layer0->_Knight->getPosition().x;
	layerbeast1->starty = &layer0->_Knight->getPosition().y;
	layerbeast1->knightHP = &layer0->HP;
	layerbeast1->direct = &layerShot->direct;
	layer0->isbeast02 = &layerbeast1->isbeast;
	layerbeast1->longwayx = -100;
	layerbeast1->longwayy = 100;
	layerbeast1->knightARMOR = &layer0->ARMOR;
	layerbeast1->movequickly = 10;
	isdeath1 = &layerbeast1->isbeast;
	map->addChild(layerbeast1);

	auto layerbeast2 = besat1::create();
	layerbeast2->weapon = &layer0->weapon;
	layerbeast2->startx = &layer0->_Knight->getPosition().x;
	layerbeast2->starty = &layer0->_Knight->getPosition().y;
	layerbeast2->knightHP = &layer0->HP;
	layerbeast2->direct = &layerShot->direct;
	layer0->isbeast03 = &layerbeast2->isbeast;
	layerbeast2->longwayx = 100;
	layerbeast2->longwayy = 100;
	layerbeast2->knightARMOR = &layer0->ARMOR;
	layerbeast2->movequickly = 15;
	isdeath2 = &layerbeast2->isbeast;
	map->addChild(layerbeast2);

	auto layerbeast3 = besat2::create();
	layerbeast3->weapon = &layer0->weapon;
	layerbeast3->startx = &layer0->_Knight->getPosition().x;
	layerbeast3->starty = &layer0->_Knight->getPosition().y;
	layerbeast3->knightHP = &layer0->HP;
	layerbeast3->direct = &layerShot->direct;
	layer0->isbeast04 = &layerbeast3->isbeast;
	layerbeast3->longwayx = -100;
	layerbeast3->longwayy = -100;
	layerbeast3->knightARMOR = &layer0->ARMOR;
	layerbeast3->movequickly = 0;
	isdeath5 = &layerbeast3->isbeast;
	map->addChild(layerbeast3);

	auto layerbeast4 = besat2::create();
	layerbeast4->weapon = &layer0->weapon;
	layerbeast4->startx = &layer0->_Knight->getPosition().x;
	layerbeast4->starty = &layer0->_Knight->getPosition().y;
	layerbeast4->knightHP = &layer0->HP;
	layerbeast4->direct = &layerShot->direct;
	layer0->isbeast05 = &layerbeast4->isbeast;
	layerbeast4->longwayx = -100;
	layerbeast4->longwayy = 100;
	layerbeast4->knightARMOR = &layer0->ARMOR;
	layerbeast4->movequickly = 5;
	isdeath6 = &layerbeast4->isbeast;
	map->addChild(layerbeast4);

	auto layerbeast5 = besat2::create();
	layerbeast5->weapon = &layer0->weapon;
	layerbeast5->startx = &layer0->_Knight->getPosition().x;
	layerbeast5->starty = &layer0->_Knight->getPosition().y;
	layerbeast5->knightHP = &layer0->HP;
	layerbeast5->direct = &layerShot->direct;
	layer0->isbeast06 = &layerbeast5->isbeast;
	layerbeast5->longwayx = -200;
	layerbeast5->knightARMOR = &layer0->ARMOR;
	layerbeast5->movequickly = 10;
	layerbeast5->kinds = 1;
	isdeath7 = &layerbeast5->isbeast;
	map->addChild(layerbeast5);

	auto layerbeast6 = besat2::create();
	layerbeast6->weapon = &layer0->weapon;
	layerbeast6->startx = &layer0->_Knight->getPosition().x;
	layerbeast6->starty = &layer0->_Knight->getPosition().y;
	layerbeast6->knightHP = &layer0->HP;
	layerbeast6->direct = &layerShot->direct;
	layer0->isbeast07 = &layerbeast6->isbeast;
	layerbeast6->longwayx = -200;
	layerbeast6->longwayy = 100;
	layerbeast6->knightARMOR = &layer0->ARMOR;
	layerbeast6->movequickly = 15;
	layerbeast6->kinds = 1;
	isdeath8 = &layerbeast6->isbeast;
	map->addChild(layerbeast6);

	map->addChild(box1, 1);
	map->addChild(box2, 1);
	map->addChild(box3, 1);
	map->addChild(box4, 1);
	map->addChild(layer0, 0);
	map->addChild(layerShot, 0);
	map->addChild(layerSaber, 0);
	map->addChild(layerBigKnife, 0);
	startx = &layer0->_Knight->getPosition().x;
	starty = &layer0->_Knight->getPosition().y;
	layer0->Limit = 0;
	limit = &layer0->Limit;
	hp = &layer0->HP;
	armor = &layer0->ARMOR;
	hp_MAX = &layer0->HP_MAX;
	mp = &layer0->MP;
	auto UI_status = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("UI_status.ExportJson");
	UI_status->setAnchorPoint(Vec2(0, 0.5));
	UI_status->setPosition(Vec2(0, visibleSize.height * 0.8));
	this->addChild(UI_status);

	Sprite* micro_map1 = Sprite::create("micro_map1.png");
	micro_map1->setPosition(Vec2(visibleSize.width * 0.95, visibleSize.height * 0.8));
	micro_map1->setScale(0.1, 0.1);
	this->addChild(micro_map1);

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

	HPbar->setPercent((*hp + 0.0) / *hp_MAX * 100);
	AMbar->setPercent((*armor + 0.0) / 10 * 100);
	MPbar->setPercent((*mp + 0.0) / 200 * 100);

	auto setImg = MenuItemImage::create(
		"set.png",
		"set.png",
		CC_CALLBACK_1(BattleScene::menuCloseCallbackSet, this));
	auto Menu02 = Menu::create(setImg, NULL);
	Menu02->setPosition(100, 100);
	this->addChild(Menu02, 1);
	this->scheduleUpdate();
	return true;
}

bool BattleScene::isCanReach(const float* x, const float* y)
{
	int mapX, mapY;
	mapX = (int)((*x - 16) / 32);
	mapY = (int)(49 - (*y - 16) / 32);
	auto layer2 = map->getLayer("layer2");
	int tileGid = layer2->getTileGIDAt(Vec2(mapX, mapY));
	if (tileGid == 0)
		return true;
	else
		return false;
}

bool BattleScene::NextPass(const float* x, const float* y)
{
	int mapX, mapY;
	mapX = (int)((*x - 16) / 32);
	mapY = (int)(49 - (*y - 16) / 32);
	auto layer3 = map->getLayer("layer3");
	int tileGid = layer3->getTileGIDAt(Vec2(mapX, mapY));
	if (tileGid != 0)
		return true;
	else
		return false;
}

void BattleScene::update(float tmd)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	if (ismap1 == 1 && *starty <= 750)
	{
		Sprite* micro_map2 = Sprite::create("micro_map2.png");
		micro_map2->setPosition(Vec2(visibleSize.width * 0.95, visibleSize.height * 0.8));
		micro_map2->setScale(0.1, 0.1);
		this->addChild(micro_map2);
		ismap1--;
	}
	if (ismap2 == 1 && *startx >= 1200&&ismap1==0)
	{
		Sprite* micro_map3 = Sprite::create("micro_map3.png");
		micro_map3->setPosition(Vec2(visibleSize.width * 0.95, visibleSize.height * 0.8));
		micro_map3->setScale(0.1, 0.1);
		this->addChild(micro_map3);
		ismap2--;
	}
	if (!isCanReach(startx, starty) || (!isCanPass(startx, starty) && !isdeath()))
	{
		*limit = 1;
	}
	if (NextPass(startx, starty))
	{
		Director::getInstance()->replaceScene(TransitionSlideInT::create(3.0f, Boss_map::createScene()));
	}

	HPlable->setString(Value(*hp).asString());
	AMlable->setString(Value(*armor).asString());
	MPlable->setString(Value(*mp).asString());

	HPbar->setPercent((*hp + 0.0) / *hp_MAX * 100);
	AMbar->setPercent((*armor + 0.0) / 10 * 100);
	MPbar->setPercent((*mp + 0.0) / 200 * 100);
	setPointOfViwe();
}



void BattleScene::setPointOfViwe()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Size mapTiledNum = map->getTileSize();
	Size tiledSize = map->getMapSize();
	Size mapSize = Size(mapTiledNum.width * tiledSize.width, mapTiledNum.height * tiledSize.height);
	float x = MAX(*startx, visibleSize.width / 2);
	float y = MAX(*starty, visibleSize.height / 2);
	x = MIN(x, mapSize.width - visibleSize.width / 2);
	y = MIN(y, mapSize.height - visibleSize.height / 2);
	Vec2 destPos = Vec2(x, y);
	Vec2 centerPos = Vec2(visibleSize.width / 2, visibleSize.height / 2);
	Vec2 viewPos = centerPos - destPos;
	map->setPosition(viewPos);
}

bool BattleScene::isdeath()
{
	if (*isdeath1 != 1 && *isdeath2 != 1 && *isdeath3 != 1 && *isdeath4 != 1 && *isdeath5!=1 && *isdeath6 != 1 && *isdeath7 != 1 & *isdeath8 != 1)
		return true;
	else
		return false;
}

bool BattleScene::isCanPass(const float* x, const float* y)
{
	int mapX, mapY;
	mapX = (int)((*x - 16) / 32);
	mapY = (int)(49 - (*y - 16) / 32);
	auto layer2 = map->getLayer("layer4");
	int tileGid = layer2->getTileGIDAt(Vec2(mapX, mapY));
	if (tileGid == 0)
		return true;
	else
		return false;
}

void BattleScene::menuCloseCallbackSet(Ref* pSender)
{
	Director::getInstance()->pushScene(TransitionFade::create(1.0f, SetScene::createScene()));
}
