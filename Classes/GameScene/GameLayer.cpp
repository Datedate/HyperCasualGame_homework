#include "GameLayer.h"

bool GameLayer::init() {
	if (!Layer::init()) {
		return false;
	}


	// ��ʃT�C�Y�擾
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	// ��
	const int edgeNum = 2;

	Vec2 vec[edgeNum][edgeNum * 2] = {
		// ����
		{   Vec2(origin.x,origin.y),
			Vec2(origin.x,origin.y + visibleSize.height * 2),},
			// �E��
			{	Vec2(origin.x + visibleSize.width , origin.y),
				Vec2(origin.x + visibleSize.width , origin.y + visibleSize.height * 2),}
	};

	Node* edges[edgeNum] = {
		Node::create(),
		Node::create(),
	};

	for (int i = 0; i < edgeNum; ++i) {
		edges[i]->setPhysicsBody(PhysicsBody::createEdgeChain(
			vec[i], 2, PhysicsMaterial(1.0f, 0.3f, 0.5f)));
		edges[i]->getPhysicsBody()->setDynamic(false);
		this->addChild(edges[i]);
	}

	// �ۂ��{�[��
	m_player = Sprite::create();
	m_player->setPosition(origin.x + visibleSize.width / 2.0f, origin.y + visibleSize.height / 2.0f);
	m_player->setColor(Color3B(255, 255, 255));
	auto playerMat = PHYSICSBODY_MATERIAL_DEFAULT;
	playerMat.restitution = 0.5f;
	playerMat.friction = 0.4f;
	auto phyPlayer = PhysicsBody::createCircle(10.0f, playerMat);
	phyPlayer->setDynamic(true);
	phyPlayer->setRotationEnable(true);
	phyPlayer->setMass(1.0f);
	phyPlayer->setMoment(1.0f);
	phyPlayer->setVelocity(Vec2(0, 200));
	m_player->setPhysicsBody(phyPlayer);
	this->addChild(m_player);

	return true;
}