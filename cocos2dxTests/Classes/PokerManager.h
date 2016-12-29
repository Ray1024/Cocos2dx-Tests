#ifndef __POKER_MANAGER_H__
#define __POKER_MANAGER_H__

#include "cocos2d.h"

class PokerManager : public cocos2d::Sprite
{

public:

	static PokerManager* create();

    virtual bool init();

	void dealer();

	void updatePokers();

	std::vector<int> _pokersIndex;
};

#endif // __POKER_MANAGER_H__
