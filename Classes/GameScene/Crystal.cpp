#include "Crystal.h"
#include "Collision.h"
#include "Player.h"

// ================================================================================
//	�N���X�^�������֐�
// ================================================================================

Crystal* Crystal::create(const std::string& _path) {
	Crystal* sprite = new (std::nothrow) Crystal();
	if (sprite && sprite->initWithFile(_path))
	{
		sprite->init();
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;

	//auto node = Crystal::create(_path);
	//node->init();
	//return node;
}

Crystal* Crystal::create(const std::string& _path, const Rect& _rect) {
	Crystal* sprite = new (std::nothrow) Crystal();
	if (sprite && sprite->initWithFile(_path, _rect))
	{
		sprite->init();
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

Crystal* Crystal::create(const std::string& _path, Crystal::TYPE _type) {
	Crystal* sprite = new (std::nothrow) Crystal();
	if (sprite && sprite->initWithFile(_path))
	{
		sprite->m_type = _type;
		sprite->init();
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

Crystal* Crystal::create(const std::string& _path, Crystal::TYPE _type, const Rect& _rect) {
	Crystal* sprite = new (std::nothrow) Crystal();
	if (sprite && sprite->initWithFile(_path, _rect))
	{
		sprite->m_type = _type;
		sprite->init();
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

Crystal* Crystal::create(const std::string& _path, Crystal::TYPE _type, const Rect& _rect, Vec2 _pos) {
	auto node = Crystal::create(_path, _type, _rect);
	node->setPosition(_pos);
	return node;
}

Crystal* Crystal::create(const std::string& _path, Crystal::TYPE _type, const Rect& _rect, float _rota) {
	auto node = Crystal::create(_path, _type, _rect);
	node->setRotation(_rota);
	return node;
}

Crystal* Crystal::create(const std::string& _path, Crystal::TYPE _type, const Rect& _rect, Vec2 _pos, float _rota) {
	auto node = Crystal::create(_path, _type, _rect, _pos);
	node->setRotation(_rota);
	return node;
}

// ================================================================================

Crystal::Crystal()
{
}

Crystal::~Crystal()
{
}

bool Crystal::init() {
	// �Փ˃^�O�ݒ�
	this->setTag(ECollision::CRYSTAL);

	generate();
	;	// PhysicsBody����
	createPhysics(m_points.data(), m_count, PhysicsMaterial(1.0f, 0.3f, 0.5f));
	// �Փ˃r�b�g�}�X�N�ݒ�
	setPhysicsMask(ECollision::CRYSTAL, ECollision::PLAYER);
	// �Փˎ��̊֐��o�^
	//setOnCollision(Crystal::onCollision,10);
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(Crystal::onCollision, this);
	this->getEventDispatcher()->addEventListenerWithFixedPriority(contactListener, 10);

	return true;
}
// TODO:�S�Ă̏Փˎ����̊֐����Ă΂��̂ŕʃN���X�ɕ�����
// ���R�G�N���X�^���̃����o�֐����S�Ă̓����蔻����Ǘ�����̂͂�����������
bool Crystal::onCollision(PhysicsContact& _contact) {
	auto obstacle = _contact.getShapeB()->getBody()->getNode();
	if (obstacle->getTag() == ECollision::CRYSTAL) {
		auto player = static_cast<Player*>(_contact.getShapeA()->getBody()->getNode());
		player->deadCrystal();
	}
	else if (obstacle->getTag() == ECollision::FOAM) {

	}
	return true;
}

bool Crystal::generate() {
	switch (m_type)
	{
	case Crystal::TYPE_1:
		createEdge_01();
		break;
	case Crystal::TYPE_2:
		createEdge_02();
		break;
	case Crystal::TYPE_3:
		createEdge_03();
		break;
	case Crystal::TYPE_4:
		createEdge_04();
		break;
	case Crystal::TYPE_5:
		createEdge_05();
		break;
	default:
		return false;
	}
	return true;
}



// =============================================================================
//
// TODO:�]�؊֐��Q �G�b�W���͍쐬�֐�
//
// =============================================================================
void Crystal::createEdge_01() {
	// ��ʃT�C�Y�擾
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	// �G�b�W�̐�
	const int count = 5;
	// �G�b�W�̍��W
	Vec2 points[count] = {
		Vec2(origin.x - _rect.getMaxX() / 2.0f,origin.y - _rect.getMaxY() / 2.0f),
		Vec2(origin.x + _rect.getMaxX() / 2.0f,origin.y - _rect.getMaxY() / 2.0f),
		Vec2(origin.x + _rect.getMaxX() / 2.0f,origin.y + _rect.getMaxY() / 2.0f),
		Vec2(origin.x - _rect.getMaxX() / 2.0f,origin.y + _rect.getMaxY() / 2.0f),
		Vec2(origin.x - _rect.getMaxX() / 2.0f,origin.y - _rect.getMaxY() / 2.0f),
	};

	// �����o�ϐ��ɑ��
	for (int i = 0; i < count; ++i) {
		m_points.push_back(points[i]);
	}
	m_count = count;
}

void Crystal::createEdge_02() {
	// �G�b�W�̐�
	const int count = 2;
	// �G�b�W�̍��W
	Vec2 points[count] = {
		Vec2(0,0),
		Vec2(0,0),
	};

	// �����o�ϐ��ɑ��
	for (int i = 0; i < count; ++i) {
		m_points.push_back(points[i]);
	}
	m_count = count;
}

void Crystal::createEdge_03() {
	// �G�b�W�̐�
	const int count = 2;
	// �G�b�W�̍��W
	Vec2 points[count] = {
		Vec2(0,0),
		Vec2(0,0),
	};

	// �����o�ϐ��ɑ��
	for (int i = 0; i < count; ++i) {
		m_points.push_back(points[i]);
	}
	m_count = count;
}

void Crystal::createEdge_04() {
	// �G�b�W�̐�
	const int count = 2;
	// �G�b�W�̍��W
	Vec2 points[count] = {
		Vec2(0,0),
		Vec2(0,0),
	};

	// �����o�ϐ��ɑ��
	for (int i = 0; i < count; ++i) {
		m_points.push_back(points[i]);
	}
	m_count = count;
}

void Crystal::createEdge_05() {
	// �G�b�W�̐�
	const int count = 2;
	// �G�b�W�̍��W
	Vec2 points[count] = {
		Vec2(0,0),
		Vec2(0,0),
	};

	// �����o�ϐ��ɑ��
	for (int i = 0; i < count; ++i) {
		m_points.push_back(points[i]);
	}
	m_count = count;
}
// =============================================================================
