#ifndef __PROJ_WALL_H_
#define __PROJ_WALL_H_

#include "cocos2d.h"

USING_NS_CC;

const int EDGE_NUM = 2;

class Wall : public Node
{
public:
	Wall ();
	~Wall ();
	bool init();
	void updatePos(Vec2 _pos);		// �v���C���[���W���擾

	CREATE_FUNC(Wall);
private:
	Node* m_edges[EDGE_NUM];		// ����
	Vec2  m_oldPlayerPos;			// �O���update�̃v���C���[���W
};


#endif