#ifndef __PROJ_OBSTACLE_H_
#define __PROJ_OBSTACLE_H_

#include "cocos2d.h"
#include <string>

USING_NS_CC;

enum Collision;

// 障害物クラス
class Obstacle : public Sprite {
private:
	// 画像パス、矩形の大きさ、タイプの引数を用いて生成させる
	static Obstacle* create(const std::string& _path);
	static Obstacle* create(const std::string& _path, const Rect& _rect) ;
	//static Obstacle* create(const std::string& _path, TYPE _type);
public:
	static Obstacle* create(const std::string& _path, const Rect& _rect);
	static Obstacle* create(const std::string& _path, const Rect& _rect, Vec2 _pos);
	static Obstacle* create(const std::string& _path, const Rect& _rect, Vec2 _pos, float _rota);
public:
	virtual bool init();
private:
	virtual bool generate();	// 画像に合わせたPhysicsLineを生成
protected:
	// createPhysicsから先に行ってください
	virtual void createPhysics(const Vec2* _point, int _count, const PhysicsMaterial& _mat = PHYSICSBODY_MATERIAL_DEFAULT);
	virtual void setPhysicsMask(Collision _myBitMask, Collision _colBitMask, int _contactBitMask = -1);
	// 継承先のクラスでonCollision関数を入れる
	template < class T>
	void setOnCollision(bool(T::*_func)(PhysicsContact&) ,int _priority);
protected:
	PhysicsBody*  m_edge;
	const Vec2*	  m_points;
	int			  m_count;
};

#endif