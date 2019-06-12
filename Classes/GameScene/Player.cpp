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
	// ビュー情報取得
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	// プレイヤー初期化
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

	// イベント受け取り処理登録
	initEventReceive();

	// スケジューラにUpdate回してもらう
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


	// それぞれのレイヤーにイベント発行
	if (!eventDisptcher(EEventDispatch::DEBUG_DISPLAY_EVENT)) {
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
	// ビュー座標に変換
	return Vec2::ZERO;
}

void Player::moveStop(EventCustom* _event) {
	if (!eventDisptcher(EEventDispatch::HOLD_EVENT)) {
		// イベント種類を追加してください
	}

	// 重力軽減処理
	this->getPhysicsBody()->setVelocity(Vec2(0, 0));
	this->getPhysicsBody()->setDynamic(false);

}

void Player::moveStart(EventCustom* _event) {
	// 吹っ飛ばす処理
	auto data = (stEventSendTouchData*)_event->getUserData();
	Point began = data->touchBegan;
	Point ended = data->touchRealse;

//	Vect force = Vect(ended.x - began.x, ended.y - began.y) * m_vecPower;
	Vect force = Vect(began.x - ended.x, began.y - ended.y) * m_vecPower;
	this->getPhysicsBody()->setDynamic(true);
	this->getPhysicsBody()->applyImpulse(force);
}