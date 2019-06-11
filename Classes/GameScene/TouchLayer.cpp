#include "TouchLayer.h"
#include "EventData.h"

TouchLayer::~TouchLayer() {
	// �C�x���g�폜

}

bool TouchLayer::init() {
	if (!Layer::init()) {
		return false;
	}


	// �C�x���g���s
	initEventDispatch();
	// �C�x���g�󂯎�菈���o�^
	initEventReceive();

	return true;
}

void TouchLayer::initEventDispatch() {
	// �C�x���g���s����
	m_playerOnTriggerEvent = EventCustom("touchTrigger_player_event");
	m_playerOnReleaseEvent = EventCustom("touchRelease_player_event");
	m_titleOnTriggerEvent  = EventCustom("touchTrigger_title_event");
	m_titleOnReleaseEvent  = EventCustom("touchRelease_title_event");
	m_holdOnTriggerEvent   = EventCustom("touchTrigger_hold_event");
	m_holdOnReleaseEvent   = EventCustom("touchRelease_hold_event");
}

void TouchLayer::initEventReceive() {
	//�^�b�`�������󂯕t����
	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = CC_CALLBACK_2(TouchLayer::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(TouchLayer::onTouchEnded, this);
	listener->onTouchMoved = CC_CALLBACK_2(TouchLayer::onTouchMoved, this);

	//�C�x���g�o�^
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

bool TouchLayer::eventDisptcher(ETouchEventDispatch _eTouchType, EEventDispatch _eEventType) {

}

bool TouchLayer::onTouchBegan(Touch* _touch, Event* _event) {
	return true;
}

void TouchLayer::onTouchEnded(Touch* _touch, Event* _event) {

}

void TouchLayer::onTouchMoved(Touch* _touch, Event* _event) {
	
}