
#include "GameScene.h"
#include "GameLayer.h"
#include "SimpleAudioEngine.h"
#include "TouchLayer.h"

USING_NS_CC;


Scene* GameScene::createScene() {
	// �����G���W����L���ɂ����V�[�����쐬����
	auto scene = GameScene::createWithPhysics();

	// ������Ԃ����o��
	auto world = scene->getPhysicsWorld();

	// �d�̓Z�b�g
	Vect gravity;
	gravity.setPoint(0, -20);
	world->setGravity(gravity);
	world->setSpeed(6.0f);
	world->setSubsteps(5);

	// �����I�u�W�F�N�g�̑Ώ۔͈͂���������f�o�b�O�@�\
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
