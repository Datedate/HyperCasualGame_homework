#ifndef __PROJ_TOUCHLAYER_H_
#define __PROJ_TOUCHLAYER_H_

#include "cocos2d.h"

USING_NS_CC;

enum ETouchEventDispatch : long;
enum EEventDispatch : long;

class TouchLayer : public Layer {
public:
	TouchLayer::TouchLayer() {};
	TouchLayer::~TouchLayer();

	bool init();
	//void update(float _dt);

	CREATE_FUNC(TouchLayer);
// Touchイベント
	bool onTouchBegan(Touch* _touch, Event* _event);	// タッチした時呼ばれる関数
	void onTouchEnded(Touch* _touch, Event* _event);	// タッチが離れた時呼ばれる関数
	void onTouchMoved(Touch* _touch, Event* _event);	// タッチしながら移動中呼ばれる関数
private:
	void initEventDispatch();		// イベント発行準備
	void initEventReceive();		// イベント受け取り準備
	bool eventDisptcher(ETouchEventDispatch _eTouchType , EEventDispatch _eEventType);	// イベント発行処理
private:
// タッチ情報を渡すイベント
	EventCustom m_playerOnTriggerEvent;
	EventCustom m_playerOnReleaseEvent;
	EventCustom m_titleOnTriggerEvent;
	EventCustom m_titleOnReleaseEvent;
	EventCustom m_holdOnTriggerEvent;
	EventCustom m_holdOnReleaseEvent;
};

#endif
