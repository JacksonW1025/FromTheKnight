#include "measureProp.h"
#define schedule_selector(_SELECTOR) static_cast<cocos2d::SEL_SCHEDULE>(&_SELECTOR)

bool createMeasure::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();//居中坐标
	Vec2 position = Vec2(visibleSize / 2);
	MeasureCreate(100, 100);
	if (ison == 0)
	{
		schedule(schedule_selector(createMeasure::Measurebegan), 0.5f);
	}
	return true;
}

Animate* createMeasure::getAnimateMeasure()
{
	auto cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("box.plist");
	Vector<SpriteFrame*>images;
	images.pushBack(cache->getSpriteFrameByName("box1.png"));
	images.pushBack(cache->getSpriteFrameByName("box2.png"));
	Animation* animation = Animation::createWithSpriteFrames(images, 0.4 / images.size());
	Animate* animate = Animate::create(animation);

	return animate;
}

createMeasure::~createMeasure()
{
}

void createMeasure::MeasureCreate(int x, int y)
{
	_measure = Sprite::create("box1.png");//创建精灵
	_measure->setPosition(Vec2(x, y));//初始坐标
	this->addChild(_measure);
}

void createMeasure::Measurebegan(float dt)
{
	if (ison == 0)
	{
		int dx = _measure->getPosition().x - *startx;
		int dy = _measure->getPosition().y - *starty;
		if (dx <= 60 && dx >= -60 && dy <= 60 && dy >= -60)
		{
			ison = 1;
			auto actionRemove = RemoveSelf::create();
			_measure->runAction(Sequence::create(getAnimateMeasure(), actionRemove, nullptr));
		}
	}
}

bool createHP::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();//居中坐标
	Vec2 position = Vec2(visibleSize / 2);

	HPCreate(100, 100);//创建精灵
	this->addChild(_HP);

	auto keyListener = EventListenerKeyboard::create();//键盘监听
	keyListener->onKeyPressed = CC_CALLBACK_2(createHP::onKeyPressed, this);
	keyListener->onKeyReleased = CC_CALLBACK_2(createHP::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

	schedule(schedule_selector(createHP::beganHP), 0.4f);
	this->scheduleUpdate();

	return true;
}

void createHP::HPCreate(int x, int y)
{
	_HP = Sprite::create("add_HP.png");//创建精灵
	_HP->setPosition(Vec2(x, y));//初始坐标
}

Animate* createHP::getAnimateHP()
{
	auto cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("HP.plist");
	Vector<SpriteFrame*>images;
	images.pushBack(cache->getSpriteFrameByName("HP1.png"));
	images.pushBack(cache->getSpriteFrameByName("HP2.png"));
	Animation* animation = Animation::createWithSpriteFrames(images, 0.4 / images.size());
	Animate* animate = Animate::create(animation);

	return animate;
	return nullptr;
}

void createHP::onKeyPressed(EventKeyboard::KeyCode Code, Event* events)
{
	keyMap[Code] = true;
}

void createHP::onKeyReleased(EventKeyboard::KeyCode Code, Event* event)
{
	keyMap[Code] = false;
}

void createHP::beganHP(float dt)
{
	log("1");
	auto j = EventKeyboard::KeyCode::KEY_J;
	if (isHP == 0)
	{
		int dx = _HP->getPosition().x - *startx;
		int dy = _HP->getPosition().y - *starty;
		if (dx <= 60 && dx >= -60 && dy <= 60 && dy >= -60)
		{
			if (keyMap[j])
			{
				isHP = 1;
				*knighthp = 5;
				_HP->runAction(Sequence::create(getAnimateHP(), nullptr));
			}
		}
	}
}

createHP::~createHP()
{
}

bool createMP::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();//居中坐标
	Vec2 position = Vec2(visibleSize / 2);

	MPCreate(200, 100);//创建精灵
	this->addChild(_MP);

	auto keyListener = EventListenerKeyboard::create();//键盘监听
	keyListener->onKeyPressed = CC_CALLBACK_2(createMP::onKeyPressed, this);
	keyListener->onKeyReleased = CC_CALLBACK_2(createMP::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

	schedule(schedule_selector(createMP::beganMP), 0.4f);
	this->scheduleUpdate();

	return true;
}

void createMP::MPCreate(int x, int y)
{
	_MP = Sprite::create("add_MP.png");//创建精灵
	_MP->setPosition(Vec2(x, y));//初始坐标
}

Animate* createMP::getAnimateMP()
{
	auto cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("MP.plist");
	Vector<SpriteFrame*>images;
	images.pushBack(cache->getSpriteFrameByName("MP1.png"));
	images.pushBack(cache->getSpriteFrameByName("MP2.png"));
	Animation* animation = Animation::createWithSpriteFrames(images, 0.4 / images.size());
	Animate* animate = Animate::create(animation);

	return animate;
	return nullptr;
}

void createMP::onKeyPressed(EventKeyboard::KeyCode Code, Event* events)
{
	keyMap[Code] = true;
}

void createMP::onKeyReleased(EventKeyboard::KeyCode Code, Event* event)
{
	keyMap[Code] = false;
}

void createMP::beganMP(float dt)
{
	log("1");
	auto j = EventKeyboard::KeyCode::KEY_J;
	if (isMP == 0)
	{
		int dx = _MP->getPosition().x - *startx;
		int dy = _MP->getPosition().y - *starty;
		if (dx <= 60 && dx >= -60 && dy <= 60 && dy >= -60)
		{
			if (keyMap[j])
			{
				*knightmp = 200;
				isMP = 1;
				_MP->runAction(Sequence::create(getAnimateMP(), nullptr));
			}
		}
	}
}

createMP::~createMP()
{
}