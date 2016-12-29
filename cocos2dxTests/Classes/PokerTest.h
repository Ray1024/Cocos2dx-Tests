#ifndef __POKER_TEST_H__
#define __POKER_TEST_H__

#include "cocos2d.h"
#include "PokerManager.h"

class PokerTest : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
	// »Øµ÷
    void menuBackCallback(cocos2d::Ref* pSender);
    void menuDealCallback(cocos2d::Ref* pSender);

	void updateCustom(float dt);

    CREATE_FUNC(PokerTest);

protected:
	PokerManager* _pokerManager;
};

#endif // __POKER_TEST_H__
