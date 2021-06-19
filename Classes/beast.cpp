#include "beast.h"
#define schedule_selector(_SELECTOR) static_cast<cocos2d::SEL_SCHEDULE>(&_SELECTOR)

void besat1::onKeyPressed(EventKeyboard::KeyCode Code, Event* events)
{
	keyMap[Code] = true;
}

void besat1::onKeyReleased(EventKeyboard::KeyCode Code, Event* event)
{
	keyMap[Code] = false;
}

bool besat1::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto keyListener = EventListenerKeyboard::create();//¼üÅÌ¼àÌý
	keyListener->onKeyPressed = CC_CALLBACK_2(besat1::onKeyPressed, this);
	keyListener->onKeyReleased = CC_CALLBACK_2(besat1::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

	schedule(schedule_selector(besat1::createbesat01), 0.25f);
	schedule(schedule_selector(besat1::movebeast01), 0.25f);
	schedule(schedule_selector(besat1::hpbeast01), 0.25f);
	schedule(schedule_selector(besat1::deadbeast01), 0.25f);
	schedule(schedule_selector(besat1::bulltbeast01), 5.0f);
	schedule(schedule_selector(besat1::attackbeast01), 0.1f);
	return true;
}

void besat1::createbesat01(float dt)
{
	int dx = *startx;
	int dy = *starty;
	if (isbeast == 0)
	{
		if (kinds == 0)
		{
			isbeast = 1;
			besat01 = Sprite::create("foreigen1.png");
			besat01->setPosition(Vec2(*startx - longwayx, *starty - longwayy));
			this->addChild(besat01);
		}
		else if (kinds == 1)
		{
			isbeast = 1;
			besat01 = Sprite::create("UFO1.png");
			besat01->setPosition(Vec2(*startx - longwayx, *starty - longwayy));
			this->addChild(besat01);

		}
	}
}

void besat1::movebeast01(float dt)
{
	if (isbeast == 1)
	{
		auto target = Vec2(*startx, *starty);
		Vec2 offset = target - besat01->getPosition();

		offset.normalize();
		auto shootAmount = offset * (10 + movequickly);
		auto realDest = shootAmount + besat01->getPosition();

		auto actionMove = MoveTo::create(0.5f, realDest);
		besat01->runAction(Sequence::create(actionMove, nullptr));
	}
}

void besat1::hpbeast01(float dt)
{
	log("1");
	auto j = EventKeyboard::KeyCode::KEY_J;
	if (isbeast == 1)
	{
		if (keyMap[j])
		{
			int dx = *startx - besat01->getPosition().x;
			int dy = *starty - besat01->getPosition().y;
			if (*weapon == 4)
			{
				if (-25 <= dy && dy <= 25)
				{
					besat01->runAction(getAnimatebeast01());
					HP = HP - 3;
				}
			}
			else if (*weapon == 2 || *weapon == 3)
			{
				if (-50 <= dy && dy <= 50 && -50 <= dx && dx <= 50)
				{
					besat01->runAction(getAnimatebeast01());
					HP = HP - 3;
				}
			}
			else if (*weapon == 1)
			{
				if (*direct == 1)
				{
					if (-30 <= dy && dy <= 30 && 0 <= dx)
					{
						besat01->runAction(getAnimatebeast01());
						HP = HP - 2;
					}
				}
				else if (*direct == 2)
				{
					if (-30 <= dy && dy <= 30 && dx <= 0)
					{
						besat01->runAction(getAnimatebeast01());
						HP = HP - 1;
					}
				}
				else if (*direct == 3)
				{
					if (-30 <= dx && dx <= 30 && dy <= 0)
					{
						besat01->runAction(getAnimatebeast01());
						HP = HP - 1;
					}
				}
				else if (*direct == 4)
				{
					if (-30 <= dx && dx <= 30 && 0 <= dy)
					{
						besat01->runAction(getAnimatebeast01());
						HP = HP - 1;
					}
				}
			}
		}
	}
}

void besat1::deadbeast01(float dt)
{
	if (isbeast == 1)
	{
		if (HP <= 0)
		{
			isbeast = 2;
			auto actionRemove = RemoveSelf::create();
			besat01->runAction(Sequence::create(getAnimatebeast01(), actionRemove, nullptr));
		}
	}
}

void besat1::bulltbeast01(float dt)
{
	if (isbeast == 1)
	{
		if (isbullt == 0)
		{
			bullt01 = Sprite::create("Bullet0.png");
			bullt01->setPosition(besat01->getPosition());
			this->addChild(bullt01);
			auto target = Vec2(*startx, *starty);
			Vec2 offset = target - besat01->getPosition();
			bullt01->setPosition(besat01->getPosition());

			offset.normalize();
			auto shootAmount = offset * 2048;
			auto realDest = shootAmount + bullt01->getPosition();

			auto actionMove = MoveTo::create(5.0f, realDest);
			bullt01->runAction(Sequence::create(actionMove, nullptr));

			isbullt = 1;
		}
		else
		{
			auto target = Vec2(*startx, *starty);
			Vec2 offset = target - besat01->getPosition();
			bullt01->setPosition(besat01->getPosition());

			offset.normalize();
			auto shootAmount = offset * 2048;
			auto realDest = shootAmount + bullt01->getPosition();

			auto actionMove = MoveTo::create(5.0f, realDest);
			bullt01->runAction(Sequence::create(actionMove, nullptr));
		}
	}
}

void besat1::attackbeast01(float dt)
{
	if (isbullt == 1)
	{
		int dx = *startx - bullt01->getPosition().x;
		int dy = *starty - bullt01->getPosition().y;
		if (-30 <= dx && dx <= 30 && -30 <= dy && dy <= 30)
		{
			if (*knightARMOR > 0)
			{
				*knightARMOR = *knightARMOR - 1;
			}
			else if (*knightHP > 0)
			{
				*knightHP = *knightHP - 1;
			}
		}
	}
}

besat1::~besat1()
{

}

Animate* besat1::getAnimatebeast01()
{
	if (kinds == 0)
	{
		auto cache = SpriteFrameCache::getInstance();
		cache->addSpriteFramesWithFile("foreign.plist");

		Vector<SpriteFrame*>images;
		images.pushBack(cache->getSpriteFrameByName("foreigen1.png"));
		images.pushBack(cache->getSpriteFrameByName("foreigen2.png"));
		images.pushBack(cache->getSpriteFrameByName("foreigen3.png"));

		Animation* animation = Animation::createWithSpriteFrames(images, 0.48 / images.size());
		Animate* animate = Animate::create(animation);
		return animate;
	}
	else if (kinds == 1)
	{
		auto cache = SpriteFrameCache::getInstance();
		cache->addSpriteFramesWithFile("UFO.plist");

		Vector<SpriteFrame*>images;
		images.pushBack(cache->getSpriteFrameByName("UFO1.png"));
		images.pushBack(cache->getSpriteFrameByName("UFO2.png"));
		images.pushBack(cache->getSpriteFrameByName("UFO3.png"));

		Animation* animation = Animation::createWithSpriteFrames(images, 0.48 / images.size());
		Animate* animate = Animate::create(animation);
		return animate;
	}
}




void besat2::onKeyPressed(EventKeyboard::KeyCode Code, Event* events)
{
	keyMap[Code] = true;
}

void besat2::onKeyReleased(EventKeyboard::KeyCode Code, Event* event)
{
	keyMap[Code] = false;
}

bool besat2::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto keyListener = EventListenerKeyboard::create();//¼üÅÌ¼àÌý
	keyListener->onKeyPressed = CC_CALLBACK_2(besat2::onKeyPressed, this);
	keyListener->onKeyReleased = CC_CALLBACK_2(besat2::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

	schedule(schedule_selector(besat2::createbesat02), 0.25f);
	schedule(schedule_selector(besat2::movebeast02), 0.25f);
	schedule(schedule_selector(besat2::hpbeast02), 0.25f);
	schedule(schedule_selector(besat2::deadbeast02), 0.25f);
	schedule(schedule_selector(besat2::attackbeast02), 0.5f);
	return true;
}

void besat2::createbesat02(float dt)
{
	int dx = *startx;
	int dy = *starty;
	if (isbeast == 0)
	{
		if (kinds == 0)
		{
			isbeast = 1;
			besat02 = Sprite::create("enemy1.png");
			besat02->setPosition(Vec2(*startx - longwayx, *starty - longwayy));
			this->addChild(besat02);
		}
		if (kinds == 1)
		{
			isbeast = 1;
			besat02 = Sprite::create("foe1.png");
			besat02->setPosition(Vec2(*startx - longwayx, *starty - longwayy));
			this->addChild(besat02);
		}
	}
}

void besat2::movebeast02(float dt)
{
	if (isbeast == 1)
	{
		auto target = Vec2(*startx, *starty);
		Vec2 offset = target - besat02->getPosition();

		offset.normalize();
		auto shootAmount = offset * (30 + movequickly);
		auto realDest = shootAmount + besat02->getPosition();

		auto actionMove = MoveTo::create(0.5f, realDest);
		besat02->runAction(Sequence::create(actionMove, nullptr));
	}
}

void besat2::hpbeast02(float dt)
{
	log("1");
	auto j = EventKeyboard::KeyCode::KEY_J;
	if (isbeast == 1)
	{
		if (keyMap[j])
		{
			int dx = *startx - besat02->getPosition().x;
			int dy = *starty - besat02->getPosition().y;
			if (*weapon == 4)
			{
				if (-25 <= dy && dy <= 25)
				{
					besat02->runAction(getAnimatebeast02());
					HP = HP - 3;
				}
			}
			else if (*weapon == 2 || *weapon == 3)
			{
				if (-50 <= dy && dy <= 50 && -50 <= dx && dx <= 50)
				{
					besat02->runAction(getAnimatebeast02());
					HP = HP - 3;
				}
			}
			else if (*weapon == 1)
			{
				if (*direct == 1)
				{
					if (-30 <= dy && dy <= 30 && 0 <= dx)
					{
						besat02->runAction(getAnimatebeast02());
						HP = HP - 2;
					}
				}
				else if (*direct == 2)
				{
					if (-30 <= dy && dy <= 30 && dx <= 0)
					{
						besat02->runAction(getAnimatebeast02());
						HP = HP - 1;
					}
				}
				else if (*direct == 3)
				{
					if (-30 <= dx && dx <= 30 && dy <= 0)
					{
						besat02->runAction(getAnimatebeast02());
						HP = HP - 1;
					}
				}
				else if (*direct == 4)
				{
					if (-30 <= dx && dx <= 30 && 0 <= dy)
					{
						besat02->runAction(getAnimatebeast02());
						HP = HP - 1;
					}
				}
			}
		}
	}
}

void besat2::deadbeast02(float dt)
{
	if (isbeast == 1)
	{
		if (HP <= 0)
		{
			isbeast = 2;
			auto actionRemove = RemoveSelf::create();
			besat02->runAction(Sequence::create(getAnimatebeast02(), actionRemove, nullptr));
		}
	}
}

void besat2::attackbeast02(float dt)
{
	if (isbeast == 1)
	{
		int dx = *startx - besat02->getPosition().x;
		int dy = *starty - besat02->getPosition().y;
		if (-40 <= dx && dx <= 40 && -40 <= dy && dy <= 40)
		{
			if (*knightARMOR > 0)
			{
				*knightARMOR = *knightARMOR - 1;
			}
			else if (*knightHP > 0)
			{
				*knightHP = *knightHP - 1;
			}
		}
	}
}

besat2::~besat2()
{

}

Animate* besat2::getAnimatebeast02()
{
	if (kinds == 0)
	{
		auto cache = SpriteFrameCache::getInstance();
		cache->addSpriteFramesWithFile("enemy.plist");

		Vector<SpriteFrame*>images;
		images.pushBack(cache->getSpriteFrameByName("enemy1.png"));
		images.pushBack(cache->getSpriteFrameByName("enemy2.png"));
		images.pushBack(cache->getSpriteFrameByName("enemy3.png"));

		Animation* animation = Animation::createWithSpriteFrames(images, 0.48 / images.size());
		Animate* animate = Animate::create(animation);
		return animate;
	}
	else if (kinds == 1)
	{
		auto cache = SpriteFrameCache::getInstance();
		cache->addSpriteFramesWithFile("foe.plist");

		Vector<SpriteFrame*>images;
		images.pushBack(cache->getSpriteFrameByName("foe1.png"));
		images.pushBack(cache->getSpriteFrameByName("foe2.png"));
		images.pushBack(cache->getSpriteFrameByName("foe3.png"));

		Animation* animation = Animation::createWithSpriteFrames(images, 0.48 / images.size());
		Animate* animate = Animate::create(animation);
		return animate;
	}
}