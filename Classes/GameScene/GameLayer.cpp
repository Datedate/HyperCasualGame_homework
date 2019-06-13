#include "GameLayer.h"
#include "Player.h"
#include "Wall.h"
#include "VerticalScroll.h"
#include "Rock.h"
bool GameLayer::init() {
	if (!Layer::init()) {
		return false;
	}


	// 画面サイズ取得
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	// プレイヤー生成
	m_player = Player::create();
	this->addChild(m_player);
	// 壁生成
	m_wall = Wall::create();
	this->addChild(m_wall);

	// 画面スクロール対象の設定
	this->runAction(VerticalScroll::create(m_player));

	this->scheduleUpdate();

	

	// お試し
	auto box = Node::create();
	box->setPhysicsBody(PhysicsBody::createBox(
		Size(50,50), PhysicsMaterial(1.0f, 0.3f, 0.5f)));

	// 岩生成こんな感じ
	auto rock = Rock::create("", Rock::TYPE::TYPE_1, Rect(0, 0, 50, 50));
	this->addChild(rock);
	
	box->getPhysicsBody()->setDynamic(false);
	box->getPhysicsBody()->setRotationEnable(false);
	box->setPosition(origin.x + visibleSize.width / 2.0f, origin.y + visibleSize.height);
	this->addChild(box);



	return true;
}

void GameLayer::update(float _dt) {
	m_wall->updatePos(m_player->getPosition());
}

