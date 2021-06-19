#include "winScene.h"
#include "SafeMapScene.h"
#include "Knight.h"
#include "AudioEngine.h"
#include "BattleScene.h"
USING_NS_CC;

Scene* winSC::createScene()
{
    auto scene = Scene::create();
    auto layer = winSC::create();
    scene->addChild(layer);
    return scene;
}


bool winSC::init()
{
    if (!Layer::init())
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto* layer_pause = Layer::create();
    auto* lable = Label::createWithTTF("You WIN!!!!!!!!!!!", "fonts/Marker Felt.ttf", 48);
    lable->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + lable->getContentSize().height));
    lable->enableGlow(Color4B::BLUE);
    layer_pause->addChild(lable);

    MenuItemImage* pCloseItem = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(winSC::popScene, this));
    pCloseItem->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.width / 2 - 30));

    Menu* pMenu = Menu::create(pCloseItem, NULL);
    pMenu->setPosition(Point(0, 0));
    layer_pause->addChild(pMenu, 1);
    this->addChild(layer_pause);

    auto cornImg = Sprite::create("portal3.png");
    cornImg->setPosition(Vec2(origin.x + visibleSize.width / 2 , visibleSize.height/2));
    this->addChild(cornImg);

    return true;
}

void winSC::popScene(Ref* pSender)
{
    Director::getInstance()->replaceScene(TransitionSlideInT::create(2.0f, SafeMap::createScene()));
}