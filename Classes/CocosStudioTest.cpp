#include "CocosStudioTest.h"
#include "TestController.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio;
using namespace ui;

Scene* CocosStudioTest::createScene()
{
    auto scene = Scene::create();
    
    auto layer = CocosStudioTest::create();

    scene->addChild(layer);

    return scene;
}

bool CocosStudioTest::init()
{
	// 初始化基类--------------------------------------------------------------
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //菜单----------------------------------------------------------------------
    auto itemCocosStudio = MenuItemFont::create("Back",
		CC_CALLBACK_1(CocosStudioTest::menuBackCallback, this));
	itemCocosStudio->setPosition(visibleSize.width-itemCocosStudio->getContentSize().width,
		itemCocosStudio->getContentSize().height);
    auto menu = Menu::create(itemCocosStudio, NULL);
	menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

	//加载.csb文件---------------------------------------------------------------
// 	FileUtils::getInstance()->addSearchPath("ccs-res/Setting");
// 	auto node = CSLoader::createNode("ccs-res/Setting/Setting.csb");
// 	node->setPosition(0,-200);
// 	this->addChild(node, 1);

// 	FileUtils::getInstance()->addSearchPath("ccs-res/BackgroundComponentTest/");
// 	auto nodeScene = SceneReader::getInstance()->createNodeWithSceneFile("ccs-res/BackgroundComponentTest/BackgroundComponentTest.json");
// 	ActionManagerEx::getInstance()->playActionByName("startMenu_1.json", "Animation1");
// 	this->addChild(nodeScene, 1);

	FileUtils::getInstance()->addSearchPath("ccs-res/ParticleComponentTest/");
	auto rootNode = SceneReader::getInstance()->createNodeWithSceneFile("ccs-res/ParticleComponentTest/ParticleComponentTest.json");
	this->addChild(rootNode, 1);
	ComRender* Particle = static_cast<ComRender*>(rootNode->getChildByTag(10020)->getComponent("CCParticleSystemQuad"));
	ActionInterval*  jump = CCJumpBy::create(5, Point(-500,0), 50, 4);
	FiniteTimeAction*  action = CCSequence::create( jump, jump->reverse(), nullptr);
	Particle->getNode()->runAction(action);
    
    return true;
}

void CocosStudioTest::menuBackCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(TestController::createScene());
}
