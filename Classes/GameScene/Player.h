#ifndef __PROJ_PLAYER_H_
#define __PROJ_PLAYER_H_

#include "cocos2d.h"

USING_NS_CC;

enum EEventDispatch : long;

class Player : public Sprite {
public:
	static Player* create(const std::string& _filename, const Rect& _rect);
public:
	Player::Player() {};
	Player::~Player();
	bool initWithFile(const std::string& _filename, const Rect& _rect);
	void update(float _dt);

//	CREATE_FUNC(Player);

	Vec2 getViewPos() const;		// ��ʓ��ł̃v���C���[���W�擾
	bool isDead() const;			// �v���C���[���S�t���O�擾�֐�
// TouchLayer����̃C�x���g����
	void moveStop(EventCustom* _event);
	void moveStart(EventCustom* _event);
// HoldLayer����̃C�x���g����
	void deadHoldOver(EventCustom* _event);
// Crystal�Փ˔��菈��
	void deadCrystal();
private:
	void initEventReceive();		// �C�x���g�󂯎�菀��
	bool eventDisptcher(EEventDispatch _eEventType);	// �C�x���g���s����
private:
	float m_vecPower;				// �v���C���[������΂��x�N�g���̋��� 
	bool  m_isDeadFlg;				// �v���C���[���S�t���O
	Vec2  m_alwaysVecPower;			// �v���C���[����ɉ����x�N�g���̗�
// �v���C���[���W��n���C�x���g
	EventCustom m_debugEvent = EventCustom("player_debug_event");
	EventCustom m_holdEvent = EventCustom("player_hold_event");
	EventCustom m_uiEvent = EventCustom("player_ui_event");
	EventCustom m_backGroundEvent = EventCustom("player_scroll_event");
};

#endif