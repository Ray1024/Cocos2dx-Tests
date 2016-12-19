#include "CoordinateTest.h"
#include "TestController.h"

USING_NS_CC;

Scene* CoordinateTest::createScene()
{
    auto scene = Scene::create();
    
    auto layer = CoordinateTest::create();

    scene->addChild(layer);

    return scene;
}

bool CoordinateTest::init()
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
		CC_CALLBACK_1(CoordinateTest::menuBackCallback, this));
	itemBack->setPosition(visibleSize.width-itemBack->getContentSize().width,
		itemBack->getContentSize().height);
    auto menu = Menu::create(itemBack, NULL);
	menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

	//添加精灵---------------------------------------------------------------
	auto block = Sprite::create("icon.png");
	this->addChild(block, 1);
	this->setPosition(-100,100);
	//this->runAction(MoveBy::create(5, Vec2(480, 320)));
    this->runAction(RotateBy::create(5, 360));

    return true;
}

void CoordinateTest::menuBackCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(TestController::createScene());
}
