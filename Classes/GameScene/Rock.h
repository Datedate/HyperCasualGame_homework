#ifndef __PROJ_ROCK_H_
#define __PROJ_ROCK_H_

#include "cocos2d.h"
#include "Obstacle.h"

USING_NS_CC;

class Rock : public Obstacle
{
public:
	enum TYPE
	{
		TYPE_1,
		TYPE_2,
		TYPE_3,
		TYPE_4,
		TYPE_5,
		TYPE_6,
		TYPE_7,
		TYPE_8,
		TYPE_9,
		TYPE_10,
	};
private:
	// 画像パス、矩形の大きさ、タイプの引数を用いて生成させる
	static Rock* create(const std::string& _path);
	static Rock* create(const std::string& _path, const Rect& _rect);
	static Rock* create(const std::string& _path, Rock::TYPE _type);
public:
	static Rock* create(const std::string& _path, Rock::TYPE _type, const Rect& _rect);
	static Rock* create(const std::string& _path, Rock::TYPE _type, const Rect& _rect, Vec2 _pos);
	static Rock* create(const std::string& _path, Rock::TYPE _type, const Rect& _rect, Vec2 _pos, float _rota);
public:
	Rock();
	~Rock();
	bool init();
	bool onCollision(PhysicsContact& _contact);
private:
	virtual bool generate();
	// 画像に合わせたエッジ関数
	void createEdge_01();
	void createEdge_02();
	void createEdge_03();
	void createEdge_04();
	void createEdge_05();
	void createEdge_06();
	void createEdge_07();
	void createEdge_08();
	void createEdge_09();
	void createEdge_10();
private:
	Rock::TYPE m_type;
};



#endif