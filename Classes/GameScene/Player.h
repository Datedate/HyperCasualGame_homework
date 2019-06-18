#ifndef __PROJ_PLAYER_H_
#define __PROJ_PLAYER_H_

#include "cocos2d.h"
#include "Lerp.h"

USING_NS_CC;

enum EEventDispatch : long;

class Player : public Sprite {
public:
	enum STATE {
		ALIVE,
		DEAD,
		BOOST,
	};
public:
	static Player* create(const std::string& _filename, const Rect& _rect);
public:
	Player::Player() {};
	Player::~Player();
	bool initWithFile(const std::string& _filename, const Rect& _rect);
	void update(float _dt);

//	CREATE_FUNC(Player);

	Vec2 getViewPos() const;		// 画面内でのプレイヤー座標取得
	bool isDead() const;			// プレイヤー死亡フラグ取得関数
	bool isBoost() const;			// プレイヤーブースト状態取得
	
	// TouchLayerからのイベント処理
	void moveStop(EventCustom* _event);
	void moveStart(EventCustom* _event);
	
	// HoldLayerからのイベント処理
	void deadHoldOver(EventCustom* _event);
	
	// Crystal衝突判定処理
	void deadCrystal();
	
	// アイテム取得時ブースト
	void boostStart(float _distance,float _time);
private:
	void initEventReceive();		// イベント受け取り準備
	bool eventDisptcher(EEventDispatch _eEventType);	// イベント発行処理

	void deadUnder();				// プレイヤーがレイヤーより下かチェック
	void boostUpdate(float _dt);				// ブースト処理
	void velocityUpdate();			// ベクトル処理
private:
	STATE m_state;					// プレイヤー状態
	float m_vecPower;				// プレイヤー吹き飛ばしベクトルの強さ 
	Vec2  m_alwaysVecPower;			// プレイヤーが常に加わるベクトルの力
	Lerp  m_lerp;					// 線形補間処理
// プレイヤー座標を渡すイベント
	EventCustom m_debugEvent = EventCustom("player_debug_event");
	EventCustom m_holdEvent = EventCustom("player_hold_event");
	EventCustom m_uiEvent = EventCustom("player_ui_event");
	EventCustom m_backGroundEvent = EventCustom("player_scroll_event");
};

#endif