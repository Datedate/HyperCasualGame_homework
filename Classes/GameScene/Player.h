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
	void initEventDispatch();		// イベント発行準備
	void initEventReceive();		// イベント受け取り準備
	bool eventDisptcher(EEventDispatch _eEventType);	// イベント発行処理
private:
	float m_vecPower;				//	プレイヤー吹き飛ばしベクトルの強さ 
// プレイヤー座標を渡すイベント
	EventCustom m_debugEvent;
	EventCustom m_holdEvent;
	EventCustom m_uiEvent;
	EventCustom m_backGroundEvent;
};

#endif