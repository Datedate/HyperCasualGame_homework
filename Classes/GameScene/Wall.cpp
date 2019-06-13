#include "Wall.h"
#include "Collision.h"

Wall::Wall()
{
}

Wall ::~Wall()
{
}

bool Wall::init() {
	if (!Node::init()) {
		return false;
	}

	// ビュー情報取得
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	// 壁ライン座標
	Vec2 vec[EDGE_NUM][EDGE_NUM * 2] = {
		// 左側
		{   Vec2(origin.x,origin.y - visibleSize.height / 4),
			Vec2(origin.x,origin.y + visibleSize.height / 4),},
		// 右側
		{	Vec2(origin.x + visibleSize.width , origin.y - visibleSize.height / 4),
			Vec2(origin.x + visibleSize.width , origin.y + visibleSize.height / 4),}
	};

	// 壁生成
	for (int i = 0; i < EDGE_NUM; ++i) {
		m_edges[i] = Node::create();
		m_edges[i]->setPhysicsBody(PhysicsBody::createEdgeChain(
			vec[i], 2, PhysicsMaterial(1.0f, 0.3f, 0.5f)));
		auto phyWall = m_edges[i]->getPhysicsBody();
		phyWall->setDynamic(false);
		phyWall->setRotationEnable(false);
		// 衝突判定のマスク設定
		phyWall->setCategoryBitmask(static_cast<int>(Collision::CRYSTAL));
		phyWall->setCollisionBitmask(static_cast<int>(Collision::PLAYER));
		phyWall->setContactTestBitmask(INT_MAX);

		this->addChild(m_edges[i]);
	}

	return true;
}

void Wall::updatePos(Vec2 _pos) {
	for each (auto edge in m_edges)
	{
		edge->setPosition(edge->getPositionX(), _pos.y);
	}
}
