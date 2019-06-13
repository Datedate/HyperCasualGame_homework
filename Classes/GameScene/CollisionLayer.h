#ifndef __PROJ_COLLISIONLAYER_H_
#define __PROJ_COLLISIONLAYER_H_

#include "cocos2d.h"

USING_NS_CC;

class CollisionLayer : public Layer {
public:
	virtual bool init();
	void update(float _dt);
	CREATE_FUNC(CollisionLayer);
	bool onContactBegin(PhysicsContact& _data);
private:
};

#endif // !
