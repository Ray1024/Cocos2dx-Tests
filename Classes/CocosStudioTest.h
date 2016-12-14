#ifndef __COCOSSTUDIO_TEST_H__
#define __COCOSSTUDIO_TEST_H__

#include "cocos2d.h"

class CocosStudioTest : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
	// »Øµ÷
    void menuBackCallback(cocos2d::Ref* pSender);
    
    CREATE_FUNC(CocosStudioTest);
};

#endif // __COCOSSTUDIO_TEST_H__
