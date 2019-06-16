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
// Touch�C�x���g
	bool onTouchBegan(Touch* _touch, Event* _event);	// �^�b�`�������Ă΂��֐�
	void onTouchEnded(Touch* _touch, Event* _event);	// �^�b�`�����ꂽ���Ă΂��֐�
private:
	void initEventReceive();		// �C�x���g�󂯎�菀��
	void eventOnTriggerDispatch(EEventDispatch _eEventType, Touch* _touch);
	void eventOnReleaseDispatch(EEventDispatch _eEventType, Touch* _touch);
private:
// �^�b�`����n���C�x���g
	EventCustom m_playerOnTriggerEvent = EventCustom("touchTrigger_player_event");
	EventCustom m_playerOnReleaseEvent = EventCustom("touchRelease_player_event");
	EventCustom m_titleOnTriggerEvent = EventCustom("touchTrigger_title_event");
	EventCustom m_titleOnReleaseEvent = EventCustom("touchRelease_title_event");
	EventCustom m_holdOnTriggerEvent = EventCustom("touchTrigger_hold_event");
	EventCustom m_holdOnReleaseEvent = EventCustom("touchRelease_hold_event");
// �ۑ��p�^�b�`���W
	Vec2 m_beganPos;
	Vec2 m_endedPos;
// Scene�ɂ���ăC�x���g��؂�ւ���
	EScene m_sceneType;
};

#endif
