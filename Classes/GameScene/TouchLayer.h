#ifndef __PROJ_TOUCHLAYER_H_
#define __PROJ_TOUCHLAYER_H_

#include "cocos2d.h"

USING_NS_CC;

enum ETouchEventDispatch : long;
enum EEventDispatch : long;
enum EScene : long;

class TouchLayer : public Layer {
public:
	TouchLayer::TouchLayer() {};
	TouchLayer::~TouchLayer();

	bool init();
	//void update(float _dt);
	void setCurrentScene(EScene _sceneType);

	CREATE_FUNC(TouchLayer);
// Touchイベント
	bool onTouchBegan(Touch* _touch, Event* _event);	// タッチした時呼ばれる関数
	void onTouchEnded(Touch* _touch, Event* _event);	// タッチが離れた時呼ばれる関数
private:
	void initEventReceive();		// イベント受け取り準備
	void eventOnTriggerDispatch(EEventDispatch _eEventType, Touch* _touch);
	void eventOnReleaseDispatch(EEventDispatch _eEventType, Touch* _touch);
private:
// タッチ情報を渡すイベント
	EventCustom m_playerOnTriggerEvent = EventCustom("touchTrigger_player_event");
	EventCustom m_playerOnReleaseEvent = EventCustom("touchRelease_player_event");
	EventCustom m_titleOnTriggerEvent = EventCustom("touchTrigger_title_event");
	EventCustom m_titleOnReleaseEvent = EventCustom("touchRelease_title_event");
	EventCustom m_holdOnTriggerEvent = EventCustom("touchTrigger_hold_event");
	EventCustom m_holdOnReleaseEvent = EventCustom("touchRelease_hold_event");
// 保存用タッチ座標
	Vec2 m_beganPos;
	Vec2 m_endedPos;
// Sceneによってイベントを切り替える
	EScene m_sceneType;
};

#endif
