#include "Rock.h"
#include "Collision.h"

Rock* Rock::create(const std::string& _path) {
	auto node = Rock::create(_path);
	node->init();
	return node;
}

Rock* Rock::create(const std::string& _path, const Rect& _rect) {
	auto node = Rock::create(_path);
	node->_rect = _rect;
	return node;
}

Rock* Rock::create(const std::string& _path, Rock::TYPE _type) {
	auto node = Rock::create(_path);
	node->m_type = _type;
	return node;
}

Rock* Rock::create(const std::string& _path, Rock::TYPE _type, const Rect& _rect) {
	auto node = Rock::create(_path, _rect);
	node->m_type = _type;
	return node;
}

Rock* Rock::create(const std::string& _path, Rock::TYPE _type, const Rect& _rect, Vec2 _pos) {
	auto node = Rock::create(_path, _type, _rect);
	node->setPosition(_pos);
	return node;
}

Rock* Rock::create(const std::string& _path, Rock::TYPE _type, const Rect& _rect, Vec2 _pos, float _rota) {
	auto node = Rock::create(_path, _type,_rect, _pos);
	node->setRotation(_rota);
	return node;
}

Rock::Rock()
{
}

Rock::~Rock()
{
}

bool Rock::init() {
	if (!Obstacle::init()) {
		return false;
	}

;	// PhysicsBody����
	createPhysics(m_points, m_count, PhysicsMaterial(1.0f, 0.3f, 0.5f));
	// �Փ˃r�b�g�}�X�N�ݒ�
	setPhysicsMask(Collision::ROCK, Collision::PLAYER);
	// �Փˎ��̊֐��o�^
	setOnCollision(Rock::onCollision,10);


	return true;
}

bool Rock::onCollision(PhysicsContact& _contact) {
	return true;
}

bool Rock::generate() {
	switch (m_type)
	{
	case Rock::TYPE_1:
		createEdge_01();
		break;
	case Rock::TYPE_2:
		createEdge_02();
		break;
	case Rock::TYPE_3:
		createEdge_03();
		break;
	case Rock::TYPE_4:
		createEdge_04();
		break;
	case Rock::TYPE_5:
		createEdge_05();
		break;
	case Rock::TYPE_6:
		createEdge_06();
		break;
	case Rock::TYPE_7:
		createEdge_07();
		break;
	case Rock::TYPE_8:
		createEdge_08();
		break;
	case Rock::TYPE_9:
		createEdge_09();
		break;
	case Rock::TYPE_10:
		createEdge_10();
		break;
	default:
		return false;
	}
	return true;
}



// =============================================================================
//
// TODO:�]�؊֐��Q
//
// =============================================================================
void Rock::createEdge_01() {
	// �G�b�W�̐�
	const int count = 2;
	// �G�b�W�̍��W
	Vec2 points[count] = {
		Vec2(0,0),
		Vec2(0,0),
	};

	// �����o�ϐ��ɑ��
	m_points = points;
	m_count = count;
}

void Rock::createEdge_02() {
	// �G�b�W�̐�
	const int count = 2;
	// �G�b�W�̍��W
	Vec2 points[count] = {
		Vec2(0,0),
		Vec2(0,0),
	};

	// �����o�ϐ��ɑ��
	m_points = points;
	m_count = count;
}

void Rock::createEdge_03() {
	// �G�b�W�̐�
	const int count = 2;
	// �G�b�W�̍��W
	Vec2 points[count] = {
		Vec2(0,0),
		Vec2(0,0),
	};

	// �����o�ϐ��ɑ��
	m_points = points;
	m_count = count;
}

void Rock::createEdge_04() {
	// �G�b�W�̐�
	const int count = 2;
	// �G�b�W�̍��W
	Vec2 points[count] = {
		Vec2(0,0),
		Vec2(0,0),
	};

	// �����o�ϐ��ɑ��
	m_points = points;
	m_count = count;
}

void Rock::createEdge_05() {
	// �G�b�W�̐�
	const int count = 2;
	// �G�b�W�̍��W
	Vec2 points[count] = {
		Vec2(0,0),
		Vec2(0,0),
	};

	// �����o�ϐ��ɑ��
	m_points = points;
	m_count = count;
}

void Rock::createEdge_06() {
	// �G�b�W�̐�
	const int count = 2;
	// �G�b�W�̍��W
	Vec2 points[count] = {
		Vec2(0,0),
		Vec2(0,0),
	};

	// �����o�ϐ��ɑ��
	m_points = points;
	m_count = count;
}

void Rock::createEdge_07() {
	// �G�b�W�̐�
	const int count = 2;
	// �G�b�W�̍��W
	Vec2 points[count] = {
		Vec2(0,0),
		Vec2(0,0),
	};

	// �����o�ϐ��ɑ��
	m_points = points;
	m_count = count;
}

void Rock::createEdge_08() {
	// �G�b�W�̐�
	const int count = 2;
	// �G�b�W�̍��W
	Vec2 points[count] = {
		Vec2(0,0),
		Vec2(0,0),
	};

	// �����o�ϐ��ɑ��
	m_points = points;
	m_count = count;
}

void Rock::createEdge_09() {
	// �G�b�W�̐�
	const int count = 2;
	// �G�b�W�̍��W
	Vec2 points[count] = {
		Vec2(0,0),
		Vec2(0,0),
	};

	// �����o�ϐ��ɑ��
	m_points = points;
	m_count = count;
}

void Rock::createEdge_10() {
	// �G�b�W�̐�
	const int count = 2;
	// �G�b�W�̍��W
	Vec2 points[count] = {
		Vec2(0,0),
		Vec2(0,0),
	};

	// �����o�ϐ��ɑ��
	m_points = points;
	m_count = count;
}
// =============================================================================

