#ifndef __PROJ_GAMESCENE_H_
#define __PROJ_GAMESCENE_H_

#include "cocos2d.h"

USING_NS_CC;

class GameLayer;
class TouchLayer;
class TitleLayer;
class ResultLayer;
class DebugLayer;
class UILayer;
class HoldLayer;
class BackGroundLayer;
class EffectLayer;


class GameScene : public cocos2d::Scene
{
public:
static Scene* createScene();
	bool init();


	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);

private:
	Scene*     m_physicsScene;
	GameLayer* m_gamelayer;
};

#endif