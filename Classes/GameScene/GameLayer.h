#ifndef __PROJ_GAMELAYER_H_
#define __PROJ_GAMELAYER_H_

#include "cocos2d.h"
#include "SceneLayer.h"

USING_NS_CC;

class Player;
class Wall;

class GameLayer : public SceneLayer {
public:
	GameLayer() {};
	~GameLayer() {
		m_player;
	};
	virtual bool init();
	void update(float _dt);
	CREATE_FUNC(GameLayer);
	bool onContactBegin(PhysicsContact& _data);

	// SceneLayer‚ÌŽÀ‘•
	bool changeRequest();
private:

	Player* m_player;
	Wall* m_wall;
};

#endif