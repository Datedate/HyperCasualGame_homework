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
	void updatePos(Vec2 _pos);		// プレイヤー座標を取得

	CREATE_FUNC(Wall);
private:
	Node* m_edges[EDGE_NUM];		// 両壁
	Vec2  m_oldPlayerPos;			// 前回のupdateのプレイヤー座標
};


#endif