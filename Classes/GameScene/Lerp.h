#ifndef __PROJ_LERP_H_
#define __PROJ_LERP_H_

#include "cocos2d.h"

USING_NS_CC;

class Lerp {
public:
	enum STATE {
		START,
		CONTINUE,
		STOP
	};
public:
	void set(Vec2 _begin, Vec2 _end, float _time);
	Vec2 pos(float _dt);
	bool isComplete() const;
	bool isAction() const;
private:
	STATE m_state = STATE::STOP;
	float m_deltaTime;
	float m_time;
	Vec2  m_beginPoint;
	Vec2  m_endPoint;
};

#endif
