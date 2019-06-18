#include "VerticalScroll.h"
#include "Player.h"

VerticalScroll::VerticalScroll() {
	m_margin = Rect::ZERO;
}

VerticalScroll::~VerticalScroll() {
	CC_SAFE_RELEASE_NULL(_followedNode);
}

VerticalScroll* VerticalScroll::create(Node* followNode) {
	VerticalScroll *follow = new VerticalScroll();
	if (follow && follow->initWithTarget(followNode, Rect::ZERO))
	{
		follow->autorelease();
		return follow;
	}
	if (follow) {
		delete follow;
		follow = nullptr;
	}

	return nullptr;
}

void VerticalScroll::step(float dt)
{
	CC_UNUSED_PARAM(dt);

	if (_boundarySet) {

		if (_boundaryFullyCovered) {
			return;
		}

		Point t = _halfScreenSize - _followedNode->getPosition();

		float x = _target->getPositionX();
		float y = clampf(t.y, _bottomBoundary, _topBoundary);

		_target->setPosition(Point(x, y));

	}
	else {
		Point p = _target->convertToWorldSpace(_followedNode->getPosition());

		if (m_margin.containsPoint(p)) {
			return;
		}

		float x = _target->getPositionX();
		float y = _target->getPositionY();
		// �����F �@�@�v���C���[��Y�x�N�g���� 0 ���傫��
		//      �@�@�@���C���[����̃v���C���[���W����ʔ������傫����	
		// �������e�F�@��ʔ�������ɍs���Ƃ����C���[��������
		//
		auto physicsNode = _followedNode->getPhysicsBody();
		if(((physicsNode->getVelocity().y) > 0 || !physicsNode->isDynamic())
			&& _followedNode->getPositionY() + _target->getPositionY()  > _halfScreenSize.y)
			y = _halfScreenSize.y - _followedNode->getPositionY();

	
		_target->setPosition(Point(x, y));
	}
}