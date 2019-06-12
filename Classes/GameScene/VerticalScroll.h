#ifndef __PROJ_VERTICAL_H_
#define __PROJ_VERTICAL_H_

#include "cocos2d.h"

USING_NS_CC;

class VerticalScroll : public Follow
{
public:
	static VerticalScroll* create(Node *followedNode);
	void step(float dt) override;

private:
	VerticalScroll();
	virtual ~VerticalScroll();
	Rect m_margin;

};

#endif
