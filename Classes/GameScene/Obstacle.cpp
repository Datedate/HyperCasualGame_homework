#include "Obstacle.h"
#include "Collision.h"

Obstacle* Obstacle::create(const std::string& _path) {
	auto node = Obstacle::create(_path);
	return node;
}

Obstacle* Obstacle::create(const std::string& _path, const Rect& _rect) {
	auto node = Obstacle::create(_path, _rect);
	return node;
}
/*
Obstacle* Obstacle::create(const std::string& _path, TYPE _type) {
	auto node = Obstacle::create(_path);
	node->setType(_type);
	return node;
}
*/
Obstacle* Obstacle::create(const std::string& _path, const Rect& _rect) {
	auto node = Obstacle::create(_path , _rect);
	return node;
}

Obstacle* Obstacle::create(const std::string& _path, const Rect& _rect, Vec2 _pos) {
	auto node = Obstacle::create(_path, _rect);
	node->setPosition(_pos);
	return node;
}

Obstacle* Obstacle::create(const std::string& _path, const Rect& _rect, Vec2 _pos, float _rota) {
	auto node = Obstacle::create(_path, _rect, _pos);
	node->setRotation(_rota);
	return node;
}

bool Obstacle::init() {
	if (!Sprite::init()) {
		return false;
	}

	if (generate()) {
		return false;
	}

	return true;
}


bool Obstacle::generate() {

}

void Obstacle::createPhysics(const Vec2* _point, int _count, const PhysicsMaterial& _mat) {
	m_edge = PhysicsBody::createEdgeChain(_point, _count,_mat);
	this->setPhysicsBody(m_edge);
	m_edge->setDynamic(false);
	m_edge->setRotationEnable(false);
}


void Obstacle::setPhysicsMask(Collision _myBitMask, Collision _colBitMask, int _contactBitMask) {
	if (m_edge == nullptr) {
		// 初期値
		Vec2 p[] = { Vec2(0,0),Vec2(100,100) };
		m_edge = PhysicsBody::createEdgeChain(p, 2);
		m_edge->setName("No_createPhysics");
	}
	// 衝突判定のマスク設定
	m_edge->setCategoryBitmask(static_cast<int>(_myBitMask));
	m_edge->setCollisionBitmask(static_cast<int>(_colBitMask));
	if (_contactBitMask == -1)
		_contactBitMask = _colBitMask;
	m_edge->setContactTestBitmask(_contactBitMask);
}

template < class T>
void Obstacle::setOnCollision(bool (T::*_func)(PhysicsContact&), int _priority) {
	
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(_func, T);
	this->getEventDispatcher()->addEventListenerWithFixedPriority(contactListener, _priority);
}