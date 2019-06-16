#ifndef __PROJ_GAMESCENE_H_
#define __PROJ_GAMESCENE_H_

#include "cocos2d.h"

USING_NS_CC;

class TouchLayer;
class DebugLayer;
class UILayer;
class HoldLayer;
class BackGroundLayer;
class EffectLayer;
class SceneLayer;

enum EScene :long;

class GameScene : public cocos2d::Scene
{
public:
//static Scene* createScene();
static GameScene* createScene();
	bool initWithPhysics();
	void update(float _dt);

	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);

private:
	void setScene(EScene _currentSceneType);
	void newScene(EScene _newSceneType);
	void deleteScene(EScene _oldSceneType);
private:
	Scene*     m_physicsScene;
	EScene	   m_sceneType;
	EScene	   m_oldSceneType;

	SceneLayer*			m_mainLayer;
	TouchLayer*			m_touchLayer;
	DebugLayer*			m_debugLayer;
	UILayer*			m_uiLayer;
	HoldLayer*			m_holdLayer;
	BackGroundLayer*	m_backGroundLayer;
	EffectLayer*		m_effectLayer;
};

#endif