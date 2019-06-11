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
	// �v���C���[������

	// �C�x���g���s
	initEventDispatch();
	// �C�x���g�󂯎�菈���o�^
	initEventReceive();

	// �X�P�W���[����Update�񂵂Ă��炤
	this->scheduleUpdate();
	return true;
}

void Player::initEventDispatch() {
	// �C�x���g���s����
	m_debugEvent	  = EventCustom("player_debug_event");
	m_holdEvent		  = EventCustom("player_hold_event");
	m_uiEvent		  = EventCustom("player_ui_event");
	m_backGroundEvent = EventCustom("player_scroll_event");
}

void Player::initEventReceive() {
	Director::getInstance()->getEventDispatcher()->addCustomEventListener("touchTrigger_player_event",
		CC_CALLBACK_1(Player::moveStop, this));
	Director::getInstance()->getEventDispatcher()->addCustomEventListener("touchRelease_player_event",
		CC_CALLBACK_1(Player::moveStart, this));
}

void Player::update(float _dt) {


	// ���ꂼ��̃��C���[�ɃC�x���g���s
	if (!eventDisptcher(EEventDispatch::DEBUG_EVENT)) {
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

	switch (_eEventType)
	{
		// TODO:setUserData�ɍ��W�����n��
	case DEBUG_EVENT:
		data.pos = this->getPosition();
		m_debugEvent.setUserData(&data);
		Director::getInstance()->getEventDispatcher()->dispatchEvent(&m_debugEvent);
		break;
	case HOLD_EVENT:
		data.pos = this->getPosition();
		m_holdEvent.setUserData(&data);
		Director::getInstance()->getEventDispatcher()->dispatchEvent(&m_holdEvent);
		break;
	case UI_EVENT:
		data.pos = this->getPosition();
		m_holdEvent.setUserData(&data);
		Director::getInstance()->getEventDispatcher()->dispatchEvent(&m_holdEvent);
		break;
	case BACKGROUND_EVENT:
		data.pos = this->getPosition();
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
}

void Player::moveStart(EventCustom* _event) {
	// ������΂�����
	// 
	auto fastenVec = (stEventSendTouchData*)_event->getUserData();
}