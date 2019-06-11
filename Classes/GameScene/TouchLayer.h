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
// Touch�C�x���g
	bool onTouchBegan(Touch* _touch, Event* _event);	// �^�b�`�������Ă΂��֐�
	void onTouchEnded(Touch* _touch, Event* _event);	// �^�b�`�����ꂽ���Ă΂��֐�
	void onTouchMoved(Touch* _touch, Event* _event);	// �^�b�`���Ȃ���ړ����Ă΂��֐�
private:
	void initEventDispatch();		// �C�x���g���s����
	void initEventReceive();		// �C�x���g�󂯎�菀��
	bool eventDisptcher(ETouchEventDispatch _eTouchType , EEventDispatch _eEventType);	// �C�x���g���s����
private:
// �^�b�`����n���C�x���g
	EventCustom m_playerOnTriggerEvent;
	EventCustom m_playerOnReleaseEvent;
	EventCustom m_titleOnTriggerEvent;
	EventCustom m_titleOnReleaseEvent;
	EventCustom m_holdOnTriggerEvent;
	EventCustom m_holdOnReleaseEvent;
};

#endif
