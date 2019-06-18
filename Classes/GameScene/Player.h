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

	Vec2 getViewPos() const;		// ��ʓ��ł̃v���C���[���W�擾
	bool isDead() const;			// �v���C���[���S�t���O�擾�֐�
	bool isBoost() const;			// �v���C���[�u�[�X�g��Ԏ擾
	
	// TouchLayer����̃C�x���g����
	void moveStop(EventCustom* _event);
	void moveStart(EventCustom* _event);
	
	// HoldLayer����̃C�x���g����
	void deadHoldOver(EventCustom* _event);
	
	// Crystal�Փ˔��菈��
	void deadCrystal();
	
	// �A�C�e���擾���u�[�X�g
	void boostStart(float _distance,float _time);
private:
	void initEventReceive();		// �C�x���g�󂯎�菀��
	bool eventDisptcher(EEventDispatch _eEventType);	// �C�x���g���s����

	void deadUnder();				// �v���C���[�����C���[��艺���`�F�b�N
	void boostUpdate(float _dt);				// �u�[�X�g����
	void velocityUpdate();			// �x�N�g������
private:
	STATE m_state;					// �v���C���[���
	float m_vecPower;				// �v���C���[������΂��x�N�g���̋��� 
	Vec2  m_alwaysVecPower;			// �v���C���[����ɉ����x�N�g���̗�
	Lerp  m_lerp;					// ���`��ԏ���
// �v���C���[���W��n���C�x���g
	EventCustom m_debugEvent = EventCustom("player_debug_event");
	EventCustom m_holdEvent = EventCustom("player_hold_event");
	EventCustom m_uiEvent = EventCustom("player_ui_event");
	EventCustom m_backGroundEvent = EventCustom("player_scroll_event");
};

#endif