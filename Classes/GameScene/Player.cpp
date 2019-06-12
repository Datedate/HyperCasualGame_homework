#include "Player.h"
#include "EventData.h"

Player::~Player() {
	Director::getInstance()->getEventDispatcher()->removeCustomEventListeners("touchStart_player_event");
	Director::getInstance()->getEventDispatcher()->removeCustomEventListeners("touchRelease_player_event");
}

bool Player::init() {
	if (!Sprite::init()) {
		return false;
	}
	// �r���[���擾
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	// �v���C���[������
	this->setPosition(origin.x + visibleSize.width / 2.0f, origin.y + visibleSize.height / 2.0f);
	this->setColor(Color3B(255, 255, 255));
	auto playerMat = PHYSICSBODY_MATERIAL_DEFAULT;
	playerMat.restitution = 0.5f;
	playerMat.friction = 0.4f;
	auto phyPlayer = PhysicsBody::createCircle(10.0f, playerMat);
	phyPlayer->setDynamic(true);
	phyPlayer->setRotationEnable(false);
	phyPlayer->setMass(1.0f);
	phyPlayer->setMoment(1.0f);
	this->setPhysicsBody(phyPlayer);

	m_vecPower = 0.5f;

	// �C�x���g�󂯎�菈���o�^
	initEventReceive();

	// �X�P�W���[����Update�񂵂Ă��炤
	this->scheduleUpdate();
	return true;
}

void Player::initEventReceive() {
	Director::getInstance()->getEventDispatcher()->addCustomEventListener("touchTrigger_player_event",
		CC_CALLBACK_1(Player::moveStop, this));
	Director::getInstance()->getEventDispatcher()->addCustomEventListener("touchRelease_player_event",
		CC_CALLBACK_1(Player::moveStart, this));
}

void Player::update(float _dt) {


	// ���ꂼ��̃��C���[�ɃC�x���g���s
	if (!eventDisptcher(EEventDispatch::DEBUG_DISPLAY_EVENT)) {
		// �C�x���g��ނ�ǉ����Ă�������
	}
	if (!eventDisptcher(EEventDispatch::UI_EVENT)) {
		// �C�x���g��ނ�ǉ����Ă�������
	}
	if (!eventDisptcher(EEventDispatch::BACKGROUND_EVENT)) {
		// �C�x���g��ނ�ǉ����Ă�������
	}
}

bool Player::eventDisptcher(EEventDispatch _eEventType) {
	// ����f�[�^�`��
	auto data = stEventSendPlayerData();
	data.pos = this->getPosition();
	switch (_eEventType)
	{
	case EEventDispatch::DEBUG_DISPLAY_EVENT:
		m_debugEvent.setUserData(&data);
		Director::getInstance()->getEventDispatcher()->dispatchEvent(&m_debugEvent);
		break;
	case EEventDispatch::HOLD_EVENT:
		m_holdEvent.setUserData(&data);
		Director::getInstance()->getEventDispatcher()->dispatchEvent(&m_holdEvent);
		break;
	case EEventDispatch::UI_EVENT:
		m_holdEvent.setUserData(&data);
		Director::getInstance()->getEventDispatcher()->dispatchEvent(&m_holdEvent);
		break;
	case EEventDispatch::BACKGROUND_EVENT:
		m_holdEvent.setUserData(&data);
		Director::getInstance()->getEventDispatcher()->dispatchEvent(&m_holdEvent);
		break;
	default:
		return false;
	}
	return true;
}

Vec2 Player::getViewPos() const {
	// �r���[���W�ɕϊ�
	return Vec2::ZERO;
}

void Player::moveStop(EventCustom* _event) {
	if (!eventDisptcher(EEventDispatch::HOLD_EVENT)) {
		// �C�x���g��ނ�ǉ����Ă�������
	}

	// �d�͌y������
	this->getPhysicsBody()->setVelocity(Vec2(0, 0));
	this->getPhysicsBody()->setDynamic(false);

}

void Player::moveStart(EventCustom* _event) {
	// ������΂�����
	auto data = (stEventSendTouchData*)_event->getUserData();
	Point began = data->touchBegan;
	Point ended = data->touchRealse;

//	Vect force = Vect(ended.x - began.x, ended.y - began.y) * m_vecPower;
	Vect force = Vect(began.x - ended.x, began.y - ended.y) * m_vecPower;
	this->getPhysicsBody()->setDynamic(true);
	this->getPhysicsBody()->applyImpulse(force);
}