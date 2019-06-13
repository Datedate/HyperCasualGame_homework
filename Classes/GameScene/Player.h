#ifndef __PROJ_PLAYER_H_
#define __PROJ_PLAYER_H_

#include "cocos2d.h"

USING_NS_CC;

enum EEventDispatch : long;

class Player : public Sprite {
public:
	Player::Player() {};
	Player::~Player();
	bool init();
	void update(float _dt);

	CREATE_FUNC(Player);

	Vec2 getViewPos() const;		// 画面内でのプレイヤー座標取得


// TouchLayerからのイベント処理
	void moveStop(EventCustom* _event);
	void moveStart(EventCustom* _event);
private:
	void initEventReceive();		// イベント受け取り準備
	bool eventDisptcher(EEventDispatch _eEventType);	// イベント発行処理
	bool onContactBegin(PhysicsContact& _data);
private:
	float m_vecPower;				//	プレイヤー吹き飛ばしベクトルの強さ 
// プレイヤー座標を渡すイベント
	EventCustom m_debugEvent = EventCustom("player_debug_event");
	EventCustom m_holdEvent = EventCustom("player_hold_event");
	EventCustom m_uiEvent = EventCustom("player_ui_event");
	EventCustom m_backGroundEvent = EventCustom("player_scroll_event");
};

#endif