#include "CollisionLayer.h"

bool CollisionLayer::init() {
	if (!Layer::init()) {
		return false;
	}

	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(CollisionLayer::onContactBegin, this);
	this->getEventDispatcher()->addEventListenerWithFixedPriority(contactListener, 10);

	return true;
}

bool CollisionLayer::onContactBegin(PhysicsContact& _data) {
	//_data.getCurrentTarget()->getName();
	return true;
}