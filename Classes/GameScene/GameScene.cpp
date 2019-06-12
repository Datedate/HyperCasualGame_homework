
#include "GameScene.h"
#include "GameLayer.h"
#include "SimpleAudioEngine.h"
#include "TouchLayer.h"

USING_NS_CC;


Scene* GameScene::createScene() {
	// 物理エンジンを有効にしたシーンを作成する
	auto scene = GameScene::createWithPhysics();

	// 物理空間を取り出す
	auto world = scene->getPhysicsWorld();

	// 重力セット
	Vect gravity;
	gravity.setPoint(0, -20);
	world->setGravity(gravity);
	world->setSpeed(6.0f);
	world->setSubsteps(5);

	// 物理オブジェクトの対象範囲を可視化するデバッグ機能
	world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	auto touchlayer = TouchLayer::create();
	scene->addChild(touchlayer);
	auto gameLayer = GameLayer::create();
	scene->addChild(gameLayer);

	return scene;
}

bool GameScene::init() {
	if (!Scene::init()) {
		return false;
	}


	return true;
}
