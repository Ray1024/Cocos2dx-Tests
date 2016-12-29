#include "TestController.h"
#include "CocosStudioTest.h"
#include "CoordinateTest.h"
#include "PokerTest.h"

USING_NS_CC;

Scene* TestController::createScene()
{
    auto scene = Scene::create();
    
    auto layer = TestController::create();

    scene->addChild(layer);

    return scene;
}

bool TestController::init()
{
	// 初始化基类--------------------------------------------------------------
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //菜单----------------------------------------------------------------------
    auto itemCocosStudio = MenuItemFont::create("CocosStudioTest",
		CC_CALLBACK_1(TestController::menuCocosStudioCallback, this));
	itemCocosStudio->setPosition(0, 50);
	auto itemCoordinate = MenuItemFont::create("CoordinateTest",
		CC_CALLBACK_1(TestController::menuCoordinateTestCallback, this));
	itemCoordinate->setPosition(0, 0);

	auto itemPoker = MenuItemFont::create("PokerTest",
		CC_CALLBACK_1(TestController::menuPokerTestCallback, this));
	itemPoker->setPosition(0, -50);

    auto menu = Menu::create(itemCocosStudio, itemCoordinate, itemPoker, NULL);
    this->addChild(menu, 1);
    
    return true;
}


void TestController::menuCocosStudioCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(CocosStudioTest::createScene());
}

void TestController::menuCoordinateTestCallback(Ref* pSender)
{
	Director::getInstance()->replaceScene(CoordinateTest::createScene());
}

void TestController::menuPokerTestCallback(Ref* pSender)
{
	Director::getInstance()->replaceScene(PokerTest::createScene());
}