#ifndef __PROJ_EVENTDATA_H_
#define __PROJ_EVENTDATA_H_

#include "cocos2d.h"

USING_NS_CC;

// �C�x���g�ʒm���
enum EEventDispatch : long{
	PLAYER_EVENT,
	DEBUG_EVENT,
	HOLD_EVENT,
	UI_EVENT,
	BACKGROUND_EVENT
};

// �^�b�`�C�x���g���
enum ETouchEventDispatch : long {
	TRIGGER,
	RELEASE,
	MOVE
};

// �󂯓n���f�[�^�F�v���C���[��񃂃f��
struct stEventSendPlayerData {
	Vec2 pos;
};

// �󂯓n���f�[�^�F�^�b�`��񃂃f��
struct stEventSendTouchData {
	Vec2 touchBegan;
	Vec2 touchRealse;
};

#endif
