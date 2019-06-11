#ifndef __PROJ_GAMELAYER_H_
#define __PROJ_GAMELAYER_H_

#include "cocos2d.h"

USING_NS_CC;

const int EDGE_NUM = 2;

class GameLayer : public Layer {
public:
	virtual bool init();

	CREATE_FUNC(GameLayer);

private:

	Sprite* m_player;
	Node* edges[EDGE_NUM];
};

#endif