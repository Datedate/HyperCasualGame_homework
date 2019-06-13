#ifndef __PROJ_OBSTACLE_H_
#define __PROJ_OBSTACLE_H_

#include "cocos2d.h"
#include <string>

USING_NS_CC;

enum Collision;

// ��Q���N���X
class Obstacle : public Sprite {
private:
	// �摜�p�X�A��`�̑傫���A�^�C�v�̈�����p���Đ���������
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
	virtual bool generate();	// �摜�ɍ��킹��PhysicsLine�𐶐�
protected:
	// createPhysics�����ɍs���Ă�������
	virtual void createPhysics(const Vec2* _point, int _count, const PhysicsMaterial& _mat = PHYSICSBODY_MATERIAL_DEFAULT);
	virtual void setPhysicsMask(Collision _myBitMask, Collision _colBitMask, int _contactBitMask = -1);
	// �p����̃N���X��onCollision�֐�������
	template < class T>
	void setOnCollision(bool(T::*_func)(PhysicsContact&) ,int _priority);
protected:
	PhysicsBody*  m_edge;
	const Vec2*	  m_points;
	int			  m_count;
};

#endif