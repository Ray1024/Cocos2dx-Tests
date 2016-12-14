#include "TestController.h"
#include "CocosStudioTest.h"

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

    auto menu = Menu::create(itemCocosStudio, NULL);
    this->addChild(menu, 1);
    
    return true;
}


void TestController::menuCocosStudioCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(CocosStudioTest::createScene());
}
