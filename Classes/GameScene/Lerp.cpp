#include "Lerp.h"

void Lerp::set(Vec2 _begin, Vec2 _end, float _time) {
	m_state = STATE::START;
	m_beginPoint = _begin;
	m_endPoint = _end;
	m_time = _time;
	m_deltaTime = 0.0f;
	m_state = STATE::CONTINUE;
}

Vec2 Lerp::pos(float _dt) {
	if (m_state != STATE::CONTINUE) return Vec2::ZERO;
	m_deltaTime += _dt;

	if (m_deltaTime > m_time) {
		m_state = STATE::STOP;
	}

	Vec2 p;
	p.x = m_beginPoint.x + (m_endPoint.x - m_beginPoint.x) * m_deltaTime / m_time;
	p.y = m_beginPoint.y + (m_endPoint.y - m_beginPoint.y) * m_deltaTime / m_time;

	return p;
}

bool Lerp::isComplete() const{
	if (m_state == STATE::STOP) return true;
	return false;
}

bool Lerp::isAction() const{
	if (m_state == STATE::CONTINUE) return true;
	return false;
}