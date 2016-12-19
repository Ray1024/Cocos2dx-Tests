#ifndef __CORRDINATE_TEST_H__
#define __CORRDINATE_TEST_H__

#include "cocos2d.h"

class CoordinateTest : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
	// »Øµ÷
    void menuBackCallback(cocos2d::Ref* pSender);
    
    CREATE_FUNC(CoordinateTest);
};

#endif // __CORRDINATE_TEST_H__
