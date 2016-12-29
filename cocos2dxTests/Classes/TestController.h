#ifndef __TEST_CONTROLLER_H__
#define __TEST_CONTROLLER_H__

#include "cocos2d.h"

class TestController : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
	// »Øµ÷
    void menuCocosStudioCallback(cocos2d::Ref* pSender);
	void menuCoordinateTestCallback(cocos2d::Ref* pSender);
    void menuPokerTestCallback(cocos2d::Ref* pSender);

    CREATE_FUNC(TestController);
};

#endif // __TEST_CONTROLLER_H__
