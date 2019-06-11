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
	// プレイヤー初期化

	// イベント発行
	initEventDispatch();
	// イベント受け取り処理登録
	initEventReceive();

	// スケジューラにUpdate回してもらう
	this->scheduleUpdate();
	return true;
}

void Player::initEventDispatch() {
	// イベント発行準備
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


	// それぞれのレイヤーにイベント発行
	if (!eventDisptcher(EEventDispatch::DEBUG_EVENT)) {
		// イベント種類を追加してください
	}
	if (!eventDisptcher(EEventDispatch::UI_EVENT)) {
		// イベント種類を追加してください
	}
	if (!eventDisptcher(EEventDispatch::BACKGROUND_EVENT)) {
		// イベント種類を追加してください
	}
}

bool Player::eventDisptcher(EEventDispatch _eEventType) {
	// 送るデータ形式
	auto data = stEventSendPlayerData();

	switch (_eEventType)
	{
		// TODO:setUserDataに座標だけ渡す
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
	// ビュー座標に変換
	return Vec2::ZERO;
}

void Player::moveStop(EventCustom* _event) {
	if (!eventDisptcher(EEventDispatch::HOLD_EVENT)) {
		// イベント種類を追加してください
	}

	// 重力軽減処理
}

void Player::moveStart(EventCustom* _event) {
	// 吹っ飛ばす処理
	// 
	auto fastenVec = (stEventSendTouchData*)_event->getUserData();
}