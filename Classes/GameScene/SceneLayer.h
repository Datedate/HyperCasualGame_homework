#ifndef __PROJ_SCENELAYER_H_
#define __PROJ_SCENELAYER_H_

#include "cocos2d.h"

USING_NS_CC;

class SceneLayer : public Layer{
public:
	virtual bool changeRequest() { return false; };
};

#endif // !
