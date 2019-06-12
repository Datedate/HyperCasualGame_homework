#include "TouchLayer.h"
#include "EventData.h"

TouchLayer::~TouchLayer() {
	// イベント削除

}

bool TouchLayer::init() {
	if (!Layer::init()) {
		return false;
	}


	// イベント受け取り処理登録
	initEventReceive();

	return true;
}

void TouchLayer::initEventReceive() {
	//タッチ処理を受け付ける
	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = CC_CALLBACK_2(TouchLayer::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(TouchLayer::onTouchEnded, this);
	listener->onTouchMoved = CC_CALLBACK_2(TouchLayer::onTouchMoved, this);

	//イベント登録
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void TouchLayer::eventOnTriggerDispatch(EEventDispatch _eEventType, Touch* _touch) {
	auto data = stEventSendTouchData();
	data.touchBegan = _touch->getLocation();
	data.touchRealse = m_endedPos;
	switch (_eEventType)
	{
	case EEventDispatch::PLAYER_EVENT:
		m_playerOnTriggerEvent.setUserData(&data);
		Director::getInstance()->getEventDispatcher()->dispatchEvent(&m_playerOnTriggerEvent);
		break;
	case EEventDispatch::TITLE_EVENT:
		m_titleOnTriggerEvent.setUserData(&data);
		Director::getInstance()->getEventDispatcher()->dispatchEvent(&m_titleOnTriggerEvent);
		break;
	case EEventDispatch::HOLD_EVENT:
		m_holdOnTriggerEvent.setUserData(&data);
		Director::getInstance()->getEventDispatcher()->dispatchEvent(&m_holdOnTriggerEvent);
		break;
	default:
		break;
	}
}

void TouchLayer::eventOnReleaseDispatch(EEventDispatch _eEventType, Touch* _touch) {
	auto data = stEventSendTouchData();
	data.touchBegan = m_beganPos;
	data.touchRealse = _touch->getLocation();
	switch (_eEventType)
	{
	case EEventDispatch::PLAYER_EVENT:
		m_playerOnReleaseEvent.setUserData(&data);
		Director::getInstance()->getEventDispatcher()->dispatchEvent(&m_playerOnReleaseEvent);
		break;
	case EEventDispatch::TITLE_EVENT:
		m_titleOnReleaseEvent.setUserData(&data);
		Director::getInstance()->getEventDispatcher()->dispatchEvent(&m_titleOnReleaseEvent);
		break;
	case EEventDispatch::HOLD_EVENT:
		m_holdOnReleaseEvent.setUserData(&data);
		Director::getInstance()->getEventDispatcher()->dispatchEvent(&m_holdOnReleaseEvent);
		break;
	default:
		break;
	}
}

bool TouchLayer::onTouchBegan(Touch* _touch, Event* _event) {
	eventOnTriggerDispatch(EEventDispatch::PLAYER_EVENT, _touch);
	eventOnTriggerDispatch(EEventDispatch::TITLE_EVENT, _touch);
	eventOnTriggerDispatch(EEventDispatch::HOLD_EVENT, _touch);

	m_beganPos = _touch->getLocation();
	return true;
}

void TouchLayer::onTouchEnded(Touch* _touch, Event* _event) {
	eventOnReleaseDispatch(EEventDispatch::PLAYER_EVENT, _touch);
	eventOnReleaseDispatch(EEventDispatch::TITLE_EVENT, _touch);
	eventOnReleaseDispatch(EEventDispatch::HOLD_EVENT, _touch);

	m_endedPos = _touch->getLocation();
}