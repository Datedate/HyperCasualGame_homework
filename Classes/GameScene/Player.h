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

	Vec2 getViewPos() const;		// ��ʓ��ł̃v���C���[���W�擾
// TouchLayer����̃C�x���g����
	void moveStop(EventCustom* _event);
	void moveStart(EventCustom* _event);
private:
	void initEventDispatch();		// �C�x���g���s����
	void initEventReceive();		// �C�x���g�󂯎�菀��
	bool eventDisptcher(EEventDispatch _eEventType);	// �C�x���g���s����
private:
	float m_vecPower;				//	�v���C���[������΂��x�N�g���̋��� 
// �v���C���[���W��n���C�x���g
	EventCustom m_debugEvent;
	EventCustom m_holdEvent;
	EventCustom m_uiEvent;
	EventCustom m_backGroundEvent;
};

#endif