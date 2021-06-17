#include "Knight.h"
#include "weapon.h"
#include"BattleScene.h"
#define schedule_selector(_SELECTOR) static_cast<cocos2d::SEL_SCHEDULE>(&_SELECTOR)
cocos2d::Scene* Knight::createScene()
{
	auto scene = Scene::create();
	auto layerKnight = Knight::create();
	auto layerShot = createShot::create();
	auto layerSaber = createSaber::create();
	auto layerBigKnife = createBigKnife::create();
	auto layerTry = createTry::create();
	auto layerd = d::create();

	layerShot->weapon = &layerKnight->weapon;
	layerShot->isweapon = &layerKnight->isweapon;
	layerSaber->weapon = &layerKnight->weapon;
	layerSaber->isweapon = &layerKnight->isweapon;
	layerBigKnife->weapon = &layerKnight->weapon;
	layerBigKnife->isweapon = &layerKnight->isweapon;
	layerTry->weapon = &layerKnight->weapon;
	layerTry->isweapon = &layerKnight->isweapon;

	layerKnight->_Knight->setPosition(Vec2(512, 374));
	layerShot->startx = &layerKnight->_Knight->getPosition().x;
	layerShot->starty = &layerKnight->_Knight->getPosition().y;
	layerSaber->startx = &layerKnight->_Knight->getPosition().x;
	layerSaber->starty = &layerKnight->_Knight->getPosition().y;
	layerBigKnife->startx = &layerKnight->_Knight->getPosition().x;
	layerBigKnife->starty = &layerKnight->_Knight->getPosition().y;
	layerTry->startx = &layerKnight->_Knight->getPosition().x;
	layerTry->starty = &layerKnight->_Knight->getPosition().y;

	scene->addChild(layerKnight);
	scene->addChild(layerShot);
	scene->addChild(layerSaber);
	scene->addChild(layerBigKnife);
	scene->addChild(layerTry);
	scene->addChild(layerd);

	return scene;
}
bool Knight::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();//居中坐标
	Vec2 position = Vec2(0.25 * visibleSize.width, 1.8 * visibleSize.height);

	_Knight = Sprite::create("Knight1.png");//创建精灵
	_Knight->setPosition(position);//初始坐标
	this->addChild(_Knight);

	auto keyListener = EventListenerKeyboard::create();//键盘监听
	keyListener->onKeyPressed = CC_CALLBACK_2(Knight::onKeyPressed, this);
	keyListener->onKeyReleased = CC_CALLBACK_2(Knight::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

	schedule(schedule_selector(Knight::knightMove), 0.25f);//定时器执行动画

	/*add the UI of Knight's status and the exit button*/
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

	this->scheduleUpdate();

	return true;
}

Animate* Knight::getAnimateRight()//右移动画
{
	auto cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Knight.plist");

	Vector<SpriteFrame*>images;
	images.pushBack(cache->getSpriteFrameByName("Knight1.png"));
	images.pushBack(cache->getSpriteFrameByName("Knight2.png"));
	images.pushBack(cache->getSpriteFrameByName("Knight3.png"));
	images.pushBack(cache->getSpriteFrameByName("Knight4.png"));

	Animation* animation = Animation::createWithSpriteFrames(images, 0.25 / images.size());
	Animate* animate = Animate::create(animation);
	return animate;
}

Animate* Knight::getAnimateLeft() //左移动画
{
	auto cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("KnightLeft.plist");

	Vector<SpriteFrame*>images;
	images.pushBack(cache->getSpriteFrameByName("KnightLeft1.png"));
	images.pushBack(cache->getSpriteFrameByName("KnightLeft2.png"));
	images.pushBack(cache->getSpriteFrameByName("KnightLeft3.png"));
	images.pushBack(cache->getSpriteFrameByName("KnightLeft4.png"));

	Animation* animation = Animation::createWithSpriteFrames(images, 0.25 / images.size());
	Animate* animate = Animate::create(animation);
	return animate;
}

void Knight::onKeyPressed(EventKeyboard::KeyCode Code, Event* events)
{
	keyMap[Code] = true;
}

void Knight::onKeyReleased(EventKeyboard::KeyCode Code, Event* event)
{
	keyMap[Code] = false;
}

void Knight::knightMove(float dt)
{
	log("1");
	auto w = EventKeyboard::KeyCode::KEY_W;
	auto s = EventKeyboard::KeyCode::KEY_S;
	auto a = EventKeyboard::KeyCode::KEY_A;
	auto d = EventKeyboard::KeyCode::KEY_D;
	int offsetx = 0;
	int offsety = 0;
	if (Limit == 0)
	{
		if (keyMap[a])
		{
			offsetx = -40;
			direction = 1;
			theLastMove = 1;
		}
		else if (keyMap[d])
		{
			offsetx = 40;
			direction = 0;
			theLastMove = 2;
		}
		else if (keyMap[w])
		{
			offsety = 40;
			theLastMove = 3;
		}
		else if (keyMap[s])
		{
			offsety = -40;
			theLastMove = 4;
		}
	}
	else if (Limit == 1)
	{
		if (theLastMove == 1)
		{
			offsetx = 40;
		}
		if (theLastMove == 2)
		{
			offsetx = -40;
		}
		if (theLastMove == 3)
		{
			offsety = -40;
		}
		if (theLastMove == 4)
		{
			offsety = 40;
		}
		Limit = 0;
	}
	if (offsetx == 0 && offsety == 0)
	{
		return;
	}
	if (direction == 0)
	{
		_Knight->runAction(getAnimateRight());
	}
	else
	{
		_Knight->runAction(getAnimateLeft());
	}
	auto moveto = MoveTo::create(0.25, Vec2(_Knight->getPosition().x + offsetx, _Knight->getPosition().y + offsety));
	_Knight->runAction(moveto);
}
bool Knight::isinPortal(Sprite* portal)
{
	Rect entityRect = this->_Knight->getBoundingBox();
	Point PortalPos = portal->getPosition();
	//judge if the boundingbox of the knight has touched the portal center.
	return entityRect.containsPoint(PortalPos);
}

void Knight::update(float dt)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	if (portal == nullptr)
		return;
	else if (isinPortal(this->portal))
	{
		Director::getInstance()->replaceScene(TransitionSlideInT::create(0.5f, BattleScene::create()));
	}

	/*add the UI of Knight's status and the exit button*/
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

	HPlable->setString(Value(Knight::HP).asString());
	AMlable->setString(Value(Knight::ARMOR).asString());
	MPlable->setString(Value(Knight::MP).asString());

	HPbar->setPercent(HP / 5 * 100);
	AMbar->setPercent(ARMOR / 10 * 100);
	MPbar->setPercent(MP / 100 * 100);
}
void Knight::bindSprite(Sprite* sprite)
{
	this->portal = sprite;
}
void Knight::set_status()
{
	Knight::HP = 5;
	Knight::ARMOR = 10;
	Knight::MP = 100;
}
Knight::~Knight()
{
}

