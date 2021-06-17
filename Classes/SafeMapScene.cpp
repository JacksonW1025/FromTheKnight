#include "SafeMapScene.h"
#include "Knight.h"
#include "AudioEngine.h"
#include "BattleScene.h"
#include "StopScene.h"
USING_NS_CC;

Scene* SafeMap::createScene()
{
	auto scene = Scene::create();
	auto layer = SafeMap::create();
	scene->addChild(layer);
	return scene;
}

bool SafeMap::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	//create the first layer for the move_area
	auto* layer_move = Layer::create();
	auto* move_pic = Sprite::create("Scene//move_area.png");
	Size bg_pic_size = move_pic->getBoundingBox().size;
	move_pic->setScale(visibleSize.width / bg_pic_size.width, visibleSize.height / bg_pic_size.height);
	move_pic->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	layer_move->addChild(move_pic);

	//create the second layer for the background picture
	auto* layer_bg = Layer::create();
	auto* bg_pic = Sprite::create("Scene//SafeScene.png");
	//set the scale
	bg_pic->setScale(visibleSize.width / bg_pic_size.width, visibleSize.height / bg_pic_size.height);
	// position the sprite on the center of the screen
	bg_pic->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	layer_bg->addChild(bg_pic);
	auto* lable = Label::createWithTTF("&The Safe Map&", "fonts/Marker Felt.ttf", 24);
	lable->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + lable->getContentSize().height));
	lable->enableGlow(Color4B::GREEN);
	layer_bg->addChild(lable);

	//create the third layer for the knight and the portal
	auto* portal_pic = Sprite::create("portal3.png");
	auto layer_Knight = Knight::create();
	layer_Knight->set_status();
	layer_Knight->_Knight->setPosition(visibleSize.width / 2, visibleSize.height / 2-180);
	portal_pic->setPosition(visibleSize.width / 2, visibleSize.height - 150);
	layer_Knight->bindSprite(portal_pic);
	layer_Knight->addChild(portal_pic);

	this->addChild(layer_move);
	this->addChild(layer_bg);
	this->addChild(layer_Knight);
	
	return true;
}
/*问题：
1 骑士类的update函数不停调用加载ui且没有内存释放导致越来越卡
2 战斗场景内ui的位置应如何设置为窗口固定位置
3 在战斗过程中的受攻击函数，能量消耗，护盾自动回复函数能否进行适配*/

