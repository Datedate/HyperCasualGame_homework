
#include "GameScene.h"
#include "GameLayer.h"
#include "SimpleAudioEngine.h"
#include "TouchLayer.h"
#include "SceneLayer.h"
#include "SceneType.h"

USING_NS_CC;

GameScene* GameScene::createScene() {
	GameScene *ret = new (std::nothrow) GameScene();
	if (ret && ret->initWithPhysics())
	{
		ret->autorelease();
		return ret;
	}
	else
	{
		CC_SAFE_DELETE(ret);
		return nullptr;
	}
}


bool GameScene::initWithPhysics() {
	if (!Scene::initWithPhysics()) {
		return false;
	}
	// ������Ԃ����o��
	auto world = this->getPhysicsWorld();

	// �d�̓Z�b�g
	Vect gravity;
	gravity.setPoint(0, -20);
	world->setGravity(gravity);
	world->setSpeed(6.0f);
	world->setSubsteps(5);

	// �����I�u�W�F�N�g�̑Ώ۔͈͂���������f�o�b�O�@�\
	world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	
	// �^�b�`���C���[�ǉ�
	m_touchLayer = TouchLayer::create();
	this->addChild(m_touchLayer);
	
	// SceneType���烌�C���[�ǉ�
	m_oldSceneType = m_sceneType = EScene::GAME;
	newScene(m_sceneType);

	this->scheduleUpdate();

	return true;
}

void GameScene::update(float _dt) {
	if (m_mainLayer == nullptr) return;
	if (!m_mainLayer->changeRequest()) return;

	setScene(m_sceneType);
	deleteScene(m_oldSceneType);
	newScene(m_sceneType);
}

void GameScene::setScene(EScene _sceneType) {
	switch (_sceneType)
	{
	case EScene::TITLE:
		m_oldSceneType = m_sceneType;
		m_sceneType = EScene::GAME;
		break;
	case EScene::GAME:
		m_oldSceneType = m_sceneType;
		m_sceneType = EScene::RESULT;
		break;
	case EScene::RESULT:
		m_oldSceneType = m_sceneType;
		m_sceneType = EScene::TITLE;
		break;
	default:
		break;
	}
}

void GameScene::newScene(EScene _newSceneType) {
	m_touchLayer->setCurrentScene(_newSceneType);
	switch (_newSceneType)
	{
	case EScene::TITLE:
//TODO:�R�����g�͂���
//		m_mainLayer = TitleLayer::create();
		break;
	case EScene::GAME:
		m_mainLayer = GameLayer::create();
		this->addChild(m_mainLayer);
		break;
	case EScene::RESULT:
//TODO:�R�����g�͂���
//		m_mainLayer = ResultLayer::create();
		break;
	default:
		break;
	}
}

void GameScene::deleteScene(EScene _oldSceneType) {
	// Title,Game,Result ���ꂼ���Layer��j��
	this->removeChild(m_mainLayer);
	m_mainLayer = nullptr;
	switch (_oldSceneType)
	{
	case EScene::TITLE:
		break;
	case EScene::GAME:
		//this->removeChild(m_effectLayer);
		//this->removeChild(m_holdLayer);
		//m_effectLayer = nullptr;
		//m_holdLayer = nullptr;
		break;
	case EScene::RESULT:
		break;
	default:
		break;
	}
}