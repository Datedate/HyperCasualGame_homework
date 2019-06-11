#ifndef __PROJ_EVENTDATA_H_
#define __PROJ_EVENTDATA_H_

#include "cocos2d.h"

USING_NS_CC;

// イベント通知種類
enum EEventDispatch : long{
	PLAYER_EVENT,
	DEBUG_EVENT,
	HOLD_EVENT,
	UI_EVENT,
	BACKGROUND_EVENT
};

// タッチイベント種類
enum ETouchEventDispatch : long {
	TRIGGER,
	RELEASE,
	MOVE
};

// 受け渡しデータ：プレイヤー情報モデル
struct stEventSendPlayerData {
	Vec2 pos;
};

// 受け渡しデータ：タッチ情報モデル
struct stEventSendTouchData {
	Vec2 touchBegan;
	Vec2 touchRealse;
};

#endif
