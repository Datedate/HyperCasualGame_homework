#ifndef __PROJ_GAMELAYER_H_
#define __PROJ_GAMELAYER_H_

#include "cocos2d.h"

USING_NS_CC;

class Player;
class Wall;

class GameLayer : public Layer {
public:
	virtual bool init();
	void update(float _dt);
	CREATE_FUNC(GameLayer);

private:

	Player* m_player;
	Wall* m_wall;
};

#endif