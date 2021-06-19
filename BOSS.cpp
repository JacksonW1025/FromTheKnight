#include "BOSS.h"
#define schedule_selector(_SELECTOR) static_cast<cocos2d::SEL_SCHEDULE>(&_SELECTOR)

void BOSS1::onKeyPressed(EventKeyboard::KeyCode Code, Event* events)
{
	keyMap[Code] = true;
}

void BOSS1::onKeyReleased(EventKeyboard::KeyCode Code, Event* event)
{
	keyMap[Code] = false;
}

bool BOSS1::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto keyListener = EventListenerKeyboard::create();//¼üÅÌ¼àÌý
	keyListener->onKeyPressed = CC_CALLBACK_2(BOSS1::onKeyPressed, this);
	keyListener->onKeyReleased = CC_CALLBACK_2(BOSS1::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

	schedule(schedule_selector(BOSS1::createBOSS01), 0.25f);
	schedule(schedule_selector(BOSS1::moveBOSS01), 0.25f);
	schedule(schedule_selector(BOSS1::hpBOSS01), 0.25f);
	schedule(schedule_selector(BOSS1::deadBOSS01), 0.25f);
	schedule(schedule_selector(BOSS1::bulltBOSS01), 5.0f);
	schedule(schedule_selector(BOSS1::attackBOSS01), 0.1f);
	return true;
}

void BOSS1::createBOSS01(float dt)
{
	int dx = *startx;
	int dy = *starty;
	if (isBOSS == 0)
	{
		isBOSS = 1;
		BOSS01 = Sprite::create("BOSS1.png");
		BOSS01->setPosition(Vec2(512-longwayx, 384 - longwayy));
		this->addChild(BOSS01);
	}
}

void BOSS1::moveBOSS01(float dt)
{
	if (isBOSS == 1)
	{
		auto target = Vec2(*startx, *starty);
		Vec2 offset = target - BOSS01->getPosition();

		offset.normalize();
		auto shootAmount = offset * (10 + movequickly);
		auto realDest = shootAmount + BOSS01->getPosition();

		auto actionMove = MoveTo::create(0.5f, realDest);
		BOSS01->runAction(Sequence::create(actionMove, nullptr));
	}
}

void BOSS1::hpBOSS01(float dt)
{
	log("1");
	auto j = EventKeyboard::KeyCode::KEY_J;
	if (isBOSS == 1)
	{
		if (keyMap[j])
		{
			int dx = *startx - BOSS01->getPosition().x;
			int dy = *starty - BOSS01->getPosition().y;
			if (*weapon == 4)
			{
				if (-40 <= dy && dy <= 40)
				{
					BOSS01->runAction(getAnimateBOSS01());
					HP = HP - 3;
				}
			}
		}
	}
}

void BOSS1::deadBOSS01(float dt)
{
	if (isBOSS == 1)
	{
		if (HP <= 0)
		{
			isBOSS = 2;
			auto actionRemove = RemoveSelf::create();
			BOSS01->runAction(Sequence::create(getAnimateBOSS01(), actionRemove, nullptr));
		}
	}
}

void BOSS1::bulltBOSS01(float dt)
{
	if (isBOSS == 1)
	{
		if (isbullt == 0)
		{
			bullt01 = Sprite::create("bossbullet0.png");
			bullt01->setPosition(BOSS01->getPosition());
			this->addChild(bullt01);
			auto target = Vec2(*startx, *starty);
			Vec2 offset = target - BOSS01->getPosition();
			bullt01->setPosition(BOSS01->getPosition());

			offset.normalize();
			auto shootAmount = offset * 2048;
			auto realDest = shootAmount + bullt01->getPosition();

			auto actionMove = MoveTo::create(5.0f, realDest);
			bullt01->runAction(Sequence::create(actionMove, nullptr));

			auto cache = SpriteFrameCache::getInstance();
			cache->addSpriteFramesWithFile("bossbullet1.plist");
			Vector<SpriteFrame*>images;
			images.pushBack(cache->getSpriteFrameByName("bossbullet1.png"));
			images.pushBack(cache->getSpriteFrameByName("bossbullet2.png"));
			images.pushBack(cache->getSpriteFrameByName("bossbullet3.png"));
			images.pushBack(cache->getSpriteFrameByName("bossbullet4.png"));
			images.pushBack(cache->getSpriteFrameByName("bossbullet5.png"));
			images.pushBack(cache->getSpriteFrameByName("bossbullet6.png"));
			images.pushBack(cache->getSpriteFrameByName("bossbullet7.png"));
			images.pushBack(cache->getSpriteFrameByName("bossbullet8.png"));
			images.pushBack(cache->getSpriteFrameByName("bossbullet9.png"));
			images.pushBack(cache->getSpriteFrameByName("bossbullet10.png"));
			images.pushBack(cache->getSpriteFrameByName("bossbullet11.png"));
			images.pushBack(cache->getSpriteFrameByName("bossbullet12.png"));
			images.pushBack(cache->getSpriteFrameByName("bossbullet13.png"));
			images.pushBack(cache->getSpriteFrameByName("bossbullet14.png"));
			images.pushBack(cache->getSpriteFrameByName("bossbullet15.png"));
			images.pushBack(cache->getSpriteFrameByName("bossbullet16.png"));
			images.pushBack(cache->getSpriteFrameByName("bossbullet17.png"));
			Animation* animation = Animation::createWithSpriteFrames(images, 5.0 / images.size());
			Animate* animate = Animate::create(animation);
			bullt01->runAction(Sequence::create(animate, nullptr));

			isbullt = 1;
		}
		else
		{
			auto target = Vec2(*startx, *starty);
			Vec2 offset = target - BOSS01->getPosition();
			bullt01->setPosition(BOSS01->getPosition());

			offset.normalize();
			auto shootAmount = offset * 2048;
			auto realDest = shootAmount + bullt01->getPosition();

			auto actionMove = MoveTo::create(5.0f, realDest);
			bullt01->runAction(Sequence::create(actionMove, nullptr));

			auto cache = SpriteFrameCache::getInstance();
			cache->addSpriteFramesWithFile("bossbullet1.plist");
			Vector<SpriteFrame*>images;
			images.pushBack(cache->getSpriteFrameByName("bossbullet1.png"));
			images.pushBack(cache->getSpriteFrameByName("bossbullet2.png"));
			images.pushBack(cache->getSpriteFrameByName("bossbullet3.png"));
			images.pushBack(cache->getSpriteFrameByName("bossbullet4.png"));
			images.pushBack(cache->getSpriteFrameByName("bossbullet5.png"));
			images.pushBack(cache->getSpriteFrameByName("bossbullet6.png"));
			images.pushBack(cache->getSpriteFrameByName("bossbullet7.png"));
			images.pushBack(cache->getSpriteFrameByName("bossbullet8.png"));
			images.pushBack(cache->getSpriteFrameByName("bossbullet9.png"));
			images.pushBack(cache->getSpriteFrameByName("bossbullet10.png"));
			images.pushBack(cache->getSpriteFrameByName("bossbullet11.png"));
			images.pushBack(cache->getSpriteFrameByName("bossbullet12.png"));
			images.pushBack(cache->getSpriteFrameByName("bossbullet13.png"));
			images.pushBack(cache->getSpriteFrameByName("bossbullet14.png"));
			images.pushBack(cache->getSpriteFrameByName("bossbullet15.png"));
			images.pushBack(cache->getSpriteFrameByName("bossbullet16.png"));
			images.pushBack(cache->getSpriteFrameByName("bossbullet17.png"));
			Animation* animation = Animation::createWithSpriteFrames(images, 5.0 / images.size());
			Animate* animate = Animate::create(animation);
			bullt01->runAction(Sequence::create(animate, nullptr));
		}
	}
}

void BOSS1::attackBOSS01(float dt)
{
	if (isbullt == 1)
	{
		int dx = *startx - bullt01->getPosition().x;
		int dy = *starty - bullt01->getPosition().y;
		if (-60 <= dx && dx <= 60 && -60 <= dy && dy <= 60)
		{
			if (*knightARMOR > 2)
			{
				*knightARMOR = *knightARMOR - 3;
			}
			else if (*knightARMOR < 3 && *knightARMOR > 0)
			{
				*knightHP = *knightHP - *knightARMOR;
				*knightARMOR = 0;
			}
			else if (*knightHP > 0)
			{
				*knightHP = *knightHP - 1;
			}
		}
	}
}

BOSS1::~BOSS1()
{

}

Animate* BOSS1::getAnimateBOSS01()
{
	auto cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("BOSS.plist");

	Vector<SpriteFrame*>images;
	images.pushBack(cache->getSpriteFrameByName("BOSS1.png"));
	images.pushBack(cache->getSpriteFrameByName("BOSS2.png"));
	images.pushBack(cache->getSpriteFrameByName("BOSS3.png"));

	Animation* animation = Animation::createWithSpriteFrames(images, 0.48 / images.size());
	Animate* animate = Animate::create(animation);
	return animate;
}

