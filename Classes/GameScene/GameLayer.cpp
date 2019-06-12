#include "GameLayer.h"
#include "Player.h"
#include "Wall.h"

bool GameLayer::init() {
	if (!Layer::init()) {
		return false;
	}


	// ��ʃT�C�Y�擾
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	// �v���C���[����
	m_player = Player::create();
	this->addChild(m_player);
	// �ǐ���
	m_wall = Wall::create();
	this->addChild(m_wall);

	this->scheduleUpdate();

	return true;
}

void GameLayer::update(float _dt) {
	m_wall->updatePos(m_player->getPosition());
}