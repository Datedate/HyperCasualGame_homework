#ifndef __PROJ_CRYSTAL_H_
#define __PROJ_CRYSTAL_H_

#include "cocos2d.h"
#include "Obstacle.h"

USING_NS_CC;

class Crystal : public Obstacle {
public:
	enum TYPE {
		TYPE_1,
		TYPE_2,
		TYPE_3,
		TYPE_4,
		TYPE_5,
	};
private:
	// 画像パス、矩形の大きさ、タイプの引数を用いて生成させる
	static Crystal* create(const std::string& _path);
	static Crystal* create(const std::string& _path, const Rect& _rect);
	static Crystal* create(const std::string& _path, Crystal::TYPE _type);
public:
	static Crystal* create(const std::string& _path, Crystal::TYPE _type, const Rect& _rect);
	static Crystal* create(const std::string& _path, Crystal::TYPE _type, const Rect& _rect, Vec2 _pos);
	static Crystal* create(const std::string& _path, Crystal::TYPE _type, const Rect& _rect, float _rota);
	static Crystal* create(const std::string& _path, Crystal::TYPE _type, const Rect& _rect, Vec2 _pos, float _rota);
public:
	Crystal();
	~Crystal();
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
private:
	Crystal::TYPE m_type;
};

#endif