#include "GameLayer.h"
#include "Player.h"
#include "Wall.h"
#include "VerticalScroll.h"
#include "Rock.h"
#include "Crystal.h"

bool GameLayer::init() {
	if (!Layer::init()) {
		return false;
	}

	// 画面サイズ取得
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	// プレイヤー生成
	m_player = Player::create("white.jpeg",Rect(0,0,20,20));
	this->addChild(m_player);
	// 壁生成
	m_wall = Wall::create();
	this->addChild(m_wall);

	// 画面スクロール対象の設定
	this->runAction(VerticalScroll::create(m_player));

	// 岩生成こんな感じ
	auto rock = Rock::create("white.jpeg", Rock::TYPE::TYPE_1, Rect(0, 0, 50, 50));
	rock->setPosition(origin.x + visibleSize.width / 4.0f, origin.y + visibleSize.height );
	this->addChild(rock);
	auto rock2 = Rock::create("white.jpeg", Rock::TYPE::TYPE_1, Rect(0, 0, 50, 100));
	rock2->setPosition(origin.x + visibleSize.width / 3.0f * 2.0f, origin.y + visibleSize.height * 1.5f);
	this->addChild(rock2);
	// クリスタル生成こんな感じ
	auto crystal = Crystal::create("blue.png", Crystal::TYPE::TYPE_1, Rect(0, 0, 40, 40),20.0f);
	crystal->setPosition(origin.x + visibleSize.width / 2.0f, origin.y + visibleSize.height * 2.0f);
	this->addChild(crystal);

	this->scheduleUpdate();

	return true;
}

void GameLayer::update(float _dt) {
	m_wall->updatePos(m_player->getPosition());
}

bool GameLayer::changeRequest() {
	// 死亡フラグが立っているならScene遷移
	if (m_player->isDead()) return true;

	return false;
}