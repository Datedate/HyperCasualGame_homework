#include "GameLayer.h"
#include "Player.h"
#include "Wall.h"

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

	this->scheduleUpdate();

	return true;
}

void GameLayer::update(float _dt) {
	m_wall->updatePos(m_player->getPosition());
}