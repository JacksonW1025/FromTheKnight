#include "weapon.h"
#include <windows.h>
#define schedule_selector(_SELECTOR) static_cast<cocos2d::SEL_SCHEDULE>(&_SELECTOR)


bool createShot::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();//居中坐标
	Vec2 position = Vec2(visibleSize / 2);

	ShotCreate(512, 374);//创建精灵
	this->addChild(_Shot);

	auto keyListener = EventListenerKeyboard::create();//键盘监听
	keyListener->onKeyPressed = CC_CALLBACK_2(createShot::onKeyPressed, this);
	keyListener->onKeyReleased = CC_CALLBACK_2(createShot::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

	schedule(schedule_selector(createShot::ShotMove), 0.05f);//定时器执行动画
	schedule(schedule_selector(createShot::ShotQJ), 0.25f);
	this->scheduleUpdate();

	return true;
}

void createShot::ShotCreate(int x, int y)
{
	_Shot = Sprite::create("baseShot1.png");//创建精灵
	_Shot->setPosition(Vec2(x, y));//初始坐标
}

void createShot::onKeyPressed(EventKeyboard::KeyCode Code, Event* events)
{
	keyMap[Code] = true;
}

void createShot::onKeyReleased(EventKeyboard::KeyCode Code, Event* event)
{
	keyMap[Code] = false;
}

bool createShot::onTouchBegan()
{
	Vec2 target = Vec2(_Shot->getPosition().x - 40, _Shot->getPosition().y);
	if (direct == 1)
	{
		target = Vec2(_Shot->getPosition().x - 40, _Shot->getPosition().y);
	}
	else if (direct == 2)
	{
		target = Vec2(_Shot->getPosition().x + 40, _Shot->getPosition().y);
	}
	else if (direct == 3)
	{
		target = Vec2(_Shot->getPosition().x, _Shot->getPosition().y + 40);
	}
	else if (direct == 4)
	{
		target = Vec2(_Shot->getPosition().x, _Shot->getPosition().y - 40);
	}
	Vec2 offset = target - _Shot->getPosition();

	auto bullt = Sprite::create("Bullet0.png");
	bullt->setPosition(_Shot->getPosition());

	this->addChild(bullt);
	offset.normalize();
	auto shootAmount = offset * 1024;
	auto realDest = shootAmount + bullt->getPosition();

	auto actionMove = MoveTo::create(0.5f, realDest);
	auto actionRemove = RemoveSelf::create();
	bullt->runAction(Sequence::create(actionMove, actionRemove, nullptr));
	return true;
}

void createShot::ShotMove(float dt)
{
	if (createShotLive == 1)
	{
		auto moveto = MoveTo::create(0.05, Vec2(*startx, *starty));
		_Shot->runAction(moveto);
	}
}

void createShot::ShotQJ(float dt)
{
	log("1");
	auto q = EventKeyboard::KeyCode::KEY_Q;
	auto e = EventKeyboard::KeyCode::KEY_E;
	auto j = EventKeyboard::KeyCode::KEY_J;
	auto a = EventKeyboard::KeyCode::KEY_A;
	auto d = EventKeyboard::KeyCode::KEY_D;
	auto w = EventKeyboard::KeyCode::KEY_W;
	auto s = EventKeyboard::KeyCode::KEY_S;
	if (keyMap[q])
	{
		if (createShotLive == 1);
		{
			createShotLive = 0;
			*isweapon = 0;
		}
	}
	if (*isweapon == 0)
	{
		if (keyMap[e])
		{
			int dx = _Shot->getPosition().x - *startx;
			int dy = _Shot->getPosition().y - *starty;
			if (dx <= 40 && dx >= -40 && dy <= 40 && dy >= -40)
			{
				if (createShotLive == 0);
				{
					createShotLive = 1;
					*isweapon = 1;
					*weapon = 1;
				}
			}
		}
	}
	if (createShotLive == 1)
	{
		if (keyMap[j])
		{
			if (*mp > 0)
			{
				*mp = *mp - 2;
				createShot::onTouchBegan();
			}
		}
		else if (keyMap[a])
		{
			direct = 1;
		}
		else if (keyMap[d])
		{
			direct = 2;
		}
		else if (keyMap[w])
		{
			direct = 3;
		}
		else if (keyMap[s])
		{
			direct = 4;
		}
	}
}

createShot::~createShot()
{
}




bool createSaber::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();//居中坐标
	Vec2 position = Vec2(visibleSize / 2);

	SaberCreate(612, 374);//创建精灵
	this->addChild(_Saber);

	auto keyListener = EventListenerKeyboard::create();//键盘监听
	keyListener->onKeyPressed = CC_CALLBACK_2(createSaber::onKeyPressed, this);
	keyListener->onKeyReleased = CC_CALLBACK_2(createSaber::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

	schedule(schedule_selector(createSaber::SaberMove), 0.05f);//定时器执行动画
	schedule(schedule_selector(createSaber::SaberQJ), 0.25f);
	this->scheduleUpdate();
	return true;
}

Animate* createSaber::getAnimateSaber()
{
	auto cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("saber.plist");

	Vector<SpriteFrame*>images;
	images.pushBack(cache->getSpriteFrameByName("saber1.png"));
	images.pushBack(cache->getSpriteFrameByName("saber2.png"));
	images.pushBack(cache->getSpriteFrameByName("saber3.png"));
	images.pushBack(cache->getSpriteFrameByName("saber4.png"));
	images.pushBack(cache->getSpriteFrameByName("saber1.png"));

	Animation* animation = Animation::createWithSpriteFrames(images, 0.25 / images.size());
	Animate* animate = Animate::create(animation);
	return animate;
}

void createSaber::SaberCreate(int x, int y)
{
	_Saber = Sprite::create("saber1.png");//创建精灵
	_Saber->setPosition(Vec2(x, y));//初始坐标
}

void createSaber::onKeyPressed(EventKeyboard::KeyCode Code, Event* events)
{
	keyMap[Code] = true;
}

void createSaber::onKeyReleased(EventKeyboard::KeyCode Code, Event* event)
{
	keyMap[Code] = false;
}

bool createSaber::onTouchBegan()
{
	_Saber->runAction(getAnimateSaber());
	return true;
}

void createSaber::SaberMove(float dt)
{
	if (createSaberLive == 1)
	{
		auto moveto = MoveTo::create(0.05, Vec2(*startx, *starty));
		_Saber->runAction(moveto);
	}
}

void createSaber::SaberQJ(float dt)
{
	log("1");
	auto q = EventKeyboard::KeyCode::KEY_Q;
	auto e = EventKeyboard::KeyCode::KEY_E;
	auto j = EventKeyboard::KeyCode::KEY_J;
	auto a = EventKeyboard::KeyCode::KEY_A;
	auto d = EventKeyboard::KeyCode::KEY_D;
	auto w = EventKeyboard::KeyCode::KEY_W;
	auto s = EventKeyboard::KeyCode::KEY_S;
	if (keyMap[q])
	{
		if (createSaberLive == 1);
		{
			createSaberLive = 0;
			*isweapon = 0;
		}
	}
	if (*isweapon == 0)
	{
		if (keyMap[e])
		{
			int dx = _Saber->getPosition().x - *startx;
			int dy = _Saber->getPosition().y - *starty;
			if (dx <= 40 && dx >= -40 && dy <= 40 && dy >= -40)
			{
				if (createSaberLive == 0);
				{
					createSaberLive = 1;
					*isweapon = 1;
					*weapon = 2;
				}
			}
		}
	}
	if (createSaberLive == 1)
	{
		if (keyMap[j])
		{
			onTouchBegan();
		}
		else if (keyMap[a])
		{
			direct = 1;
		}
		else if (keyMap[d])
		{
			direct = 2;
		}
		else if (keyMap[w])
		{
			direct = 3;
		}
		else if (keyMap[s])
		{
			direct = 4;
		}
	}
}

createSaber::~createSaber()
{
}




bool createBigKnife::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();//居中坐标
	Vec2 position = Vec2(visibleSize / 2);

	BigKnifeCreate(712, 374);//创建精灵
	this->addChild(_BigKnife);

	auto keyListener = EventListenerKeyboard::create();//键盘监听
	keyListener->onKeyPressed = CC_CALLBACK_2(createBigKnife::onKeyPressed, this);
	keyListener->onKeyReleased = CC_CALLBACK_2(createBigKnife::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

	schedule(schedule_selector(createBigKnife::BigKnifeMove), 0.05f);//定时器执行动画
	schedule(schedule_selector(createBigKnife::BigKnifeQJ), 0.25f);
	this->scheduleUpdate();
	return true;
}

Animate* createBigKnife::getAnimateBigKnife()
{
	auto cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("BigKnife.plist");

	Vector<SpriteFrame*>images;
	images.pushBack(cache->getSpriteFrameByName("BigKnife1.png"));
	images.pushBack(cache->getSpriteFrameByName("BigKnife2.png"));
	images.pushBack(cache->getSpriteFrameByName("BigKnife3.png"));
	images.pushBack(cache->getSpriteFrameByName("BigKnife4.png"));
	images.pushBack(cache->getSpriteFrameByName("BigKnife5.png"));
	images.pushBack(cache->getSpriteFrameByName("BigKnife1.png"));

	Animation* animation = Animation::createWithSpriteFrames(images, 0.25 / images.size());
	Animate* animate = Animate::create(animation);
	return animate;
}

void createBigKnife::BigKnifeCreate(int x, int y)
{
	_BigKnife = Sprite::create("BigKnife1.png");//创建精灵
	_BigKnife->setPosition(Vec2(x, y));//初始坐标
}

void createBigKnife::onKeyPressed(EventKeyboard::KeyCode Code, Event* events)
{
	keyMap[Code] = true;
}

void createBigKnife::onKeyReleased(EventKeyboard::KeyCode Code, Event* event)
{
	keyMap[Code] = false;
}

bool createBigKnife::onTouchBegan()
{
	_BigKnife->runAction(getAnimateBigKnife());
	return true;
}

void createBigKnife::BigKnifeMove(float dt)
{
	if (createBigKnifeLive == 1)
	{
		auto moveto = MoveTo::create(0.05, Vec2(*startx, *starty));
		_BigKnife->runAction(moveto);
	}
}

void createBigKnife::BigKnifeQJ(float dt)
{
	log("1");
	auto q = EventKeyboard::KeyCode::KEY_Q;
	auto e = EventKeyboard::KeyCode::KEY_E;
	auto j = EventKeyboard::KeyCode::KEY_J;
	auto a = EventKeyboard::KeyCode::KEY_A;
	auto d = EventKeyboard::KeyCode::KEY_D;
	auto w = EventKeyboard::KeyCode::KEY_W;
	auto s = EventKeyboard::KeyCode::KEY_S;
	if (keyMap[q])
	{
		if (createBigKnifeLive == 1);
		{
			createBigKnifeLive = 0;
			*isweapon = 0;
		}
	}
	if (*isweapon == 0)
	{
		if (keyMap[e])
		{
			int dx = _BigKnife->getPosition().x - *startx;
			int dy = _BigKnife->getPosition().y - *starty;
			if (dx <= 40 && dx >= -40 && dy <= 40 && dy >= -40)
			{
				if (createBigKnifeLive == 0);
				{
					createBigKnifeLive = 1;
					*isweapon = 1;
					*weapon = 3;
				}
			}
		}
	}
	if (createBigKnifeLive == 1)
	{
		if (keyMap[j])
		{
			onTouchBegan();
		}
		else if (keyMap[a])
		{
			direct = 1;
		}
		else if (keyMap[d])
		{
			direct = 2;
		}
		else if (keyMap[w])
		{
			direct = 3;
		}
		else if (keyMap[s])
		{
			direct = 4;
		}
	}
}

createBigKnife::~createBigKnife()
{
}




bool createTry::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();//居中坐标
	Vec2 position = Vec2(visibleSize / 2);

	TryCreate(812, 374);//创建精灵
	this->addChild(_Try);

	auto keyListener = EventListenerKeyboard::create();//键盘监听
	keyListener->onKeyPressed = CC_CALLBACK_2(createTry::onKeyPressed, this);
	keyListener->onKeyReleased = CC_CALLBACK_2(createTry::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

	schedule(schedule_selector(createTry::TryMove), 0.05f);//定时器执行动画
	schedule(schedule_selector(createTry::TryQJ), 0.25f);
	this->scheduleUpdate();
	return true;
}

void createTry::TryCreate(int x, int y)
{
	_Try = Sprite::create("tryright.png");//创建精灵
	_Try->setPosition(Vec2(x, y));//初始坐标
}

void createTry::onKeyPressed(EventKeyboard::KeyCode Code, Event* events)
{
	keyMap[Code] = true;
}

void createTry::onKeyReleased(EventKeyboard::KeyCode Code, Event* event)
{
	keyMap[Code] = false;
}

bool createTry::onTouchBegan()
{
	auto bullt = Sprite::create("laser.png");
	bullt->setPosition(_Try->getPosition());
	this->addChild(bullt);
	auto actionRemove = RemoveSelf::create();
	auto moveto = MoveTo::create(0.25, bullt->getPosition());
	bullt->runAction(moveto);

	bullt->runAction(Sequence::create(actionRemove, nullptr));
	return true;
}

void createTry::TryMove(float dt)
{
	if (createTryLive == 1)
	{
		auto moveto = MoveTo::create(0.05, Vec2(*startx, *starty));
		_Try->runAction(moveto);
	}
}

void createTry::TryQJ(float dt)
{
	log("1");
	auto q = EventKeyboard::KeyCode::KEY_Q;
	auto e = EventKeyboard::KeyCode::KEY_E;
	auto j = EventKeyboard::KeyCode::KEY_J;
	auto a = EventKeyboard::KeyCode::KEY_A;
	auto d = EventKeyboard::KeyCode::KEY_D;
	auto w = EventKeyboard::KeyCode::KEY_W;
	auto s = EventKeyboard::KeyCode::KEY_S;
	if (keyMap[q])
	{
		if (createTryLive == 1);
		{
			createTryLive = 0;
			*isweapon = 0;
		}
	}
	if (*isweapon == 0)
	{
		if (keyMap[e])
		{
			int dx = _Try->getPosition().x - *startx;
			int dy = _Try->getPosition().y - *starty;
			if (dx <= 40 && dx >= -40 && dy <= 40 && dy >= -40)
			{
				if (createTryLive == 0);
				{
					createTryLive = 1;
					*isweapon = 1;
					*weapon = 4;
				}
			}
		}
	}
	if (createTryLive == 1)
	{
		if (keyMap[j])
		{
			if (*mp > 1)
			{
				*mp = *mp - 3;
				onTouchBegan();
			}
		}
		else if (keyMap[a])
		{
			direct = 1;
		}
		else if (keyMap[d])
		{
			direct = 2;
		}
		else if (keyMap[w])
		{
			direct = 3;
		}
		else if (keyMap[s])
		{
			direct = 4;
		}
	}
}

createTry::~createTry()
{
}



void d::onKeyPressed(EventKeyboard::KeyCode Code, Event* events)
{
	keyMap[Code] = true;
}

void d::onKeyReleased(EventKeyboard::KeyCode Code, Event* event)
{
	keyMap[Code] = false;
}

bool d::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto keyListener = EventListenerKeyboard::create();//键盘监听
	keyListener->onKeyPressed = CC_CALLBACK_2(d::onKeyPressed, this);
	keyListener->onKeyReleased = CC_CALLBACK_2(d::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

	schedule(schedule_selector(d::ddd), 0.25f);
	schedule(schedule_selector(d::ddc), 0.25f);
	schedule(schedule_selector(d::ddb), 0.25f);
	schedule(schedule_selector(d::dda), 0.25f);
	schedule(schedule_selector(d::dde), 5.0f);
	schedule(schedule_selector(d::ddf), 0.1f);
	return true;
}

void d::ddd(float dt)
{
	int dx = *startx;
	int dy = *starty;
	if (dddd == 0)
	{
		if (*startx >= 600)
		{
			dddd = 1;
			pl = Sprite::create("Knight1.png");
			pl->setPosition(Vec2(100, 100));
			this->addChild(pl);
			auto b = MoveTo::create(10, Vec2(pl->getPosition().x + 900, pl->getPosition().y));
			pl->runAction(b);
		}
	}
}

void d::ddc(float dt)
{
	if (dddd == 1)
	{
		auto target = Vec2(*startx, *starty);
		Vec2 offset = target - pl->getPosition();

		offset.normalize();
		auto shootAmount = offset * 10;
		auto realDest = shootAmount + pl->getPosition();

		auto actionMove = MoveTo::create(0.5f, realDest);
		pl->runAction(Sequence::create(actionMove, nullptr));
	}
}

void d::ddb(float dt)
{
	log("1");
	auto j = EventKeyboard::KeyCode::KEY_J;
	if (dddd == 1)
	{
		if (keyMap[j])
		{
			int dx = *startx - pl->getPosition().x;
			int dy = *starty - pl->getPosition().y;
			if (*weapon == 4)
			{
				if (-20 <= dy && dy <= 20)
				{
					HP--;
				}
			}
			else if (*weapon == 2 || *weapon == 3)
			{
				if (-50 <= dy && dy <= 50 && -50 <= dx && dx <= 50)
				{
					HP = HP - 3;
				}
			}
		}
	}
}

void d::dda(float dt)
{
	if (dddd == 1)
	{
		if (HP <= 0)
		{
			dddd = 2;
			auto actionRemove = RemoveSelf::create();
			pl->runAction(Sequence::create(actionRemove, nullptr));
		}
	}
}

void d::dde(float dt)
{
	if (dddd == 1)
	{
		if (da == 0)
		{
			bullt = Sprite::create("Bullet0.png");
			bullt->setPosition(pl->getPosition());
			this->addChild(bullt);
			auto target = Vec2(*startx, *starty);
			Vec2 offset = target - pl->getPosition();
			bullt->setPosition(pl->getPosition());

			offset.normalize();
			auto shootAmount = offset * 2048;
			auto realDest = shootAmount + bullt->getPosition();

			auto actionMove = MoveTo::create(5.0f, realDest);
			bullt->runAction(Sequence::create(actionMove, nullptr));

			da = 1;
		}
		else
		{
			auto target = Vec2(*startx, *starty);
			Vec2 offset = target - pl->getPosition();
			bullt->setPosition(pl->getPosition());

			offset.normalize();
			auto shootAmount = offset * 2048;
			auto realDest = shootAmount + bullt->getPosition();

			auto actionMove = MoveTo::create(5.0f, realDest);
			bullt->runAction(Sequence::create(actionMove, nullptr));
		}
	}
}

void d::ddf(float dt)
{
	if (da == 1)
	{
		int dx = *startx - bullt->getPosition().x;
		int dy = *starty - bullt->getPosition().y;
		if (-20 <= dx && dx <= 20 && -20 <= dy && dy <= 20)
		{
			*knightHP = *knightHP - 1;
		}
	}
}


d::~d()
{
}