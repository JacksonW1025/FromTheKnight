#include "Knight.h"
#include "weapon.h"
#include"BattleScene.h"
#include "measureProp.h"
#include "beast.h"
#include "BOSS.h"
#include "SafeMapScene.h"
#define schedule_selector(_SELECTOR) static_cast<cocos2d::SEL_SCHEDULE>(&_SELECTOR)
cocos2d::Scene* Knight::createScene()
{
	auto scene = Scene::create();
	auto layerKnight = Knight::create();
	auto layerShot = createShot::create();
	auto layerSaber = createSaber::create();
	auto layerBigKnife = createBigKnife::create();
	auto layerTry = createTry::create();
	auto layermeasure = createMeasure::create();

	layerShot->mp = &layerKnight->MP;
	layerTry->mp = &layerKnight->MP;

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
	layermeasure->startx = &layerKnight->_Knight->getPosition().x;
	layermeasure->starty = &layerKnight->_Knight->getPosition().y;

	auto layerHP = createHP::create();
	layerHP->startx = &layerKnight->_Knight->getPosition().x;
	layerHP->starty = &layerKnight->_Knight->getPosition().y;
	layerHP->knighthp = &layerKnight->HP;
	scene->addChild(layerHP);

	auto layerMP = createMP::create();
	layerMP->startx = &layerKnight->_Knight->getPosition().x;
	layerMP->starty = &layerKnight->_Knight->getPosition().y;
	layerMP->knightmp = &layerKnight->MP;
	scene->addChild(layerMP);

	auto layerbeast = besat1::create();
	layerbeast->weapon = &layerKnight->weapon;
	layerbeast->startx = &layerKnight->_Knight->getPosition().x;
	layerbeast->starty = &layerKnight->_Knight->getPosition().y;
	layerbeast->knightHP = &layerKnight->HP;
	layerbeast->knightARMOR = &layerKnight->ARMOR;
	layerbeast->direct = &layerShot->direct;
	layerKnight->isbeast01 = &layerbeast->isbeast;
	layerbeast->longwayx = 200;
	layerbeast->longwayy = 200;
	layerbeast->kinds = 1;
	scene->addChild(layerbeast);

	auto layerBOSS = BOSS1::create();
	layerBOSS->weapon = &layerKnight->weapon;
	layerBOSS->startx = &layerKnight->_Knight->getPosition().x;
	layerBOSS->starty = &layerKnight->_Knight->getPosition().y;
	layerBOSS->knightHP = &layerKnight->HP;
	layerBOSS->knightARMOR = &layerKnight->ARMOR;
	layerBOSS->longwayx = 0;
	layerBOSS->longwayy = -200;
	scene->addChild(layerBOSS);

	auto layerbeast02 = besat2::create();
	layerbeast02->weapon = &layerKnight->weapon;
	layerbeast02->startx = &layerKnight->_Knight->getPosition().x;
	layerbeast02->starty = &layerKnight->_Knight->getPosition().y; 
	layerbeast02->knightARMOR = &layerKnight->ARMOR;
	layerbeast02->knightHP = &layerKnight->HP;
	layerbeast02->direct = &layerShot->direct;
	layerKnight->isbeast02 = &layerbeast02->isbeast;
	layerbeast02->longwayx = -200;
	layerbeast02->longwayy = 200;
	layerbeast02->kinds = 1;
	scene->addChild(layerbeast02);

	scene->addChild(layerKnight);
	scene->addChild(layerShot);
	scene->addChild(layerSaber);
	scene->addChild(layerBigKnife);
	scene->addChild(layerTry);
	scene->addChild(layermeasure);

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

	schedule(schedule_selector(Knight::knightMove), 0.2f);//定时器执行动画
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

	Animation* animation = Animation::createWithSpriteFrames(images, 0.2 / images.size());
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

	Animation* animation = Animation::createWithSpriteFrames(images, 0.2 / images.size());
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
	CD++;
	ARMORCD++;
	if (MP < 200&& MP>10)
	{
		MP++;
	}
	else if (MP <= 10)
	{
		MP=MP+3;
	}
	if (ARMORCD >= 12)
	{
		if (ARMOR < 10)
		{
			ARMOR++;
			ARMORCD = 0;
		}
	}
	if (iswar == 1)
	{
		if (*isbeast00 == -1)
		{
			if (_Knight->getPosition().y < 750)
			{
				*isbeast00 = 0;
			}
		}
		if (*isbeast01 == -1)
		{
			if (_Knight->getPosition().y < 750)
			{
				*isbeast01 = 0;
			}
		}
		if (*isbeast02 == -1)
		{
			if (_Knight->getPosition().y <750)
			{
				*isbeast02 = 0;
			}
		}
		if (*isbeast03 == -1)
		{
			if (_Knight->getPosition().y < 750)
			{
				*isbeast03 = 0;
			}
		}
		if (*isbeast04 == -1)
		{
			if (_Knight->getPosition().x > 1200)
			{
				*isbeast04 = 0;
			}
		}
		if (*isbeast05 == -1)
		{
			if (_Knight->getPosition().x > 1200)
			{
				*isbeast05 = 0;
			}
		}
		if (*isbeast06 == -1)
		{
			if (_Knight->getPosition().x > 1200)
			{
				*isbeast06 = 0;
			}
		}
		if (*isbeast07 == -1)
		{
			if (_Knight->getPosition().x > 1200)
			{
				*isbeast07 = 0;
			}
		}
	}
	log("1");
	auto w = EventKeyboard::KeyCode::KEY_W;
	auto s = EventKeyboard::KeyCode::KEY_S;
	auto a = EventKeyboard::KeyCode::KEY_A;
	auto d = EventKeyboard::KeyCode::KEY_D;
	auto k = EventKeyboard::KeyCode::KEY_K;
	int offsetx = 0;
	int offsety = 0;
	if (Limit == 0)
	{
		if (_Knight->getPosition().x < 1280 && _Knight->getPosition().x > 0 && _Knight->getPosition().y < 720 && _Knight->getPosition().y > 0 && iswar == 0 || iswar == 1)
		{
			if (keyMap[a])
			{
				offsetx = -32;
				direction = 1;
				theLastMove = 1;
			}
			else if (keyMap[d])
			{
				offsetx = 32;
				direction = 0;
				theLastMove = 2;
			}
			else if (keyMap[w])
			{
				offsety = 32;
				theLastMove = 3;
			}
			else if (keyMap[s])
			{
				offsety = -32;
				theLastMove = 4;
			}
		}
		if (_Knight->getPosition().y > 700 && iswar == 0)
		{
			auto p = Vec2(_Knight->getPosition().x , _Knight->getPosition().y-64);
			auto moveto = MoveTo::create(0.25, p);
			_Knight->runAction(moveto);
		}
		if (_Knight->getPosition().y <20 && iswar == 0)
		{
			auto p = Vec2(_Knight->getPosition().x, _Knight->getPosition().y + 64);
			auto moveto = MoveTo::create(0.25, p);
			_Knight->runAction(moveto);
		}
		if (_Knight->getPosition().x > 1260 && iswar == 0)
		{
			auto p = Vec2(_Knight->getPosition().x-64, _Knight->getPosition().y );
			auto moveto = MoveTo::create(0.25, p);
			_Knight->runAction(moveto);
		}
		if (_Knight->getPosition().x<20 && iswar == 0)
		{
			auto p = Vec2(_Knight->getPosition().x+64, _Knight->getPosition().y );
			auto moveto = MoveTo::create(0.25, p);
			_Knight->runAction(moveto);
		}
		if (keyMap[k])
		{
			if (CD > 16 && HP < 5)
			{
				auto cache = SpriteFrameCache::getInstance();
				cache->addSpriteFramesWithFile("Knight_khp.plist");
				Vector<SpriteFrame*>images;
				images.pushBack(cache->getSpriteFrameByName("Knight_khp2.png"));
				images.pushBack(cache->getSpriteFrameByName("Knight_khp3.png"));
				Animation* animation = Animation::createWithSpriteFrames(images, 0.6 / images.size());
				Animate* animate = Animate::create(animation);
				_Knight->runAction(animate);
				HP++;
				CD = 0;
			}
		}
	}
	else if (Limit == 1)
	{
		if (theLastMove == 1)
		{
			offsetx = 32;
		}
		if (theLastMove == 2)
		{
			offsetx = -32;
		}
		if (theLastMove == 3)
		{
			offsety = -32;
		}
		if (theLastMove == 4)
		{
			offsety = 32;
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
	if (HP <= 0)
	{
		Director::getInstance()->replaceScene(TransitionSlideInT::create(2.0f, SafeMap::createScene()));
	}
	if (portal == nullptr)
		return;
	else if (isinPortal(this->portal))
	{
		Director::getInstance()->replaceScene(TransitionSlideInT::create(2.0f, BattleScene::create()));
	}
}
void Knight::bindSprite(Sprite* sprite)
{
	this->portal = sprite;
}
Knight::~Knight()
{
}

