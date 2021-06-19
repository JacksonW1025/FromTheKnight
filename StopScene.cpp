#include "StopScene.h"
#include "SafeMapScene.h"
#include "Knight.h"
#include "AudioEngine.h"
#include "BattleScene.h"
USING_NS_CC;

Scene* StopSC::createScene()
{
	auto scene = Scene::create();
	auto layer = StopSC::create();
	scene->addChild(layer);
	return scene;
}


bool StopSC::init()
{
    if (!Layer::init())
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto* layer_pause = Layer::create();
    auto* lable = Label::createWithTTF("&Pause!!&", "fonts/Marker Felt.ttf", 48);
    lable->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y+visibleSize.width / 2 + lable->getContentSize().height));
    lable->enableGlow(Color4B::GREEN);
    layer_pause->addChild(lable);

    MenuItemImage* pCloseItem = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(StopSC::popScene, this));
    pCloseItem->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.width / 2 - 30));

    Menu* pMenu = Menu::create(pCloseItem, NULL);
    pMenu->setPosition(Point(0, 0));
    layer_pause->addChild(pMenu, 1);
    this->addChild(layer_pause);
    return true;
}

void StopSC::popScene(Ref* pSender)
{
    Director::getInstance()->popScene();
}