#include "PokerManager.h"
#include "Poker.h"
#include <algorithm>

USING_NS_CC;

bool nodeComparisonLess(Node* n1, Node* n2)
{
	return( n1->getLocalZOrder() < n2->getLocalZOrder() ||
		( n1->getLocalZOrder() == n2->getLocalZOrder() && n1->getOrderOfArrival() < n2->getOrderOfArrival() )
		);
}

PokerManager* PokerManager::create()
{
	PokerManager *sprite = new (std::nothrow) PokerManager();
	if (sprite && sprite->init())
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

bool PokerManager::init()
{
	// 初始化基类--------------------------------------------------------------
    if ( !Sprite::init() )
    {
        return false;
    }

    return true;
}

void PokerManager::dealer()
{
	if (_children.size()>=17)
	{
		return;
	}

	int index;
	while (1)
	{
		index = rand()%54;
		auto iter = std::find(_pokersIndex.begin(), _pokersIndex.end(), index);
		if (_pokersIndex.size()==0)
		{
			break;
		} else if (iter == _pokersIndex.end()) //原先不存在
		{
			break;
		}
	}
	_pokersIndex.push_back(index);

	//添加精灵
	auto block = Poker::create(index);
	this->addChild(block, 100-(index%13));

	sortAllChildren();

	updatePokers();
}

void PokerManager::updatePokers()
{
	int count = _children.size();
	int zeroPoint = count/2;
	for (int i=0; i<_children.size(); i++)
	{
		Sprite* poker = (Sprite*)_children.at(i);
		if (poker != NULL)
		{
			poker->setPosition((i-zeroPoint)*30, 0);
		}
	}
}