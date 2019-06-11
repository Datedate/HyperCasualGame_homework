
#include "GameScene.h"
#include "GameLayer.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;


bool GameScene::init() {
	if (!Scene::init()) {
		return false;
	}

	// 重力セット
	Vect gravity;
	gravity.setPoint(0, -20);
	this->getPhysicsWorld()->setGravity(gravity);
	this->getPhysicsWorld()->setSpeed(6.0f);
	this->getPhysicsWorld()->setSubsteps(5);

	// 物理オブジェクトの対象範囲を可視化するデバッグ機能
	this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);


	m_gamelayer = GameLayer::create();
	this->addChild(m_gamelayer);

	return true;
}
