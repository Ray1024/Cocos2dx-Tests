#include "PokerTest.h"
#include "TestController.h"

USING_NS_CC;

Scene* PokerTest::createScene()
{
    auto scene = Scene::create();
    
    auto layer = PokerTest::create();

    scene->addChild(layer);

    return scene;
}

bool PokerTest::init()
{
	// 初始化基类--------------------------------------------------------------
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //菜单----------------------------------------------------------------------
    auto itemBack = MenuItemFont::create("Back",
		CC_CALLBACK_1(PokerTest::menuBackCallback, this));
	itemBack->setPosition(visibleSize.width-itemBack->getContentSize().width,
		itemBack->getContentSize().height);

	auto itemDeal = MenuItemFont::create("Deal",
		CC_CALLBACK_1(PokerTest::menuDealCallback, this));
	itemDeal->setPosition(visibleSize.width-itemBack->getContentSize().width,
		itemBack->getContentSize().height + 100);

    auto menu = Menu::create(itemBack, itemDeal, NULL);
	menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

	_pokerManager = PokerManager::create();
	_pokerManager->setPosition(visibleSize.width/2,visibleSize.height/2);
	this->addChild(_pokerManager, 1);

	schedule(CC_SCHEDULE_SELECTOR(PokerTest::updateCustom), 0.2);

    return true;
}

void PokerTest::menuBackCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(TestController::createScene());
}

void PokerTest::menuDealCallback(Ref* pSender)
{
	_pokerManager->dealer();
}

void PokerTest::updateCustom(float dt)
{
	_pokerManager->dealer();
};