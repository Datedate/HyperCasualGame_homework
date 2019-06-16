#include "Crystal.h"
#include "Collision.h"
#include "Player.h"

// ================================================================================
//	クリスタル生成関数
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
	// 衝突タグ設定
	this->setTag(ECollision::CRYSTAL);

	generate();
	;	// PhysicsBody生成
	createPhysics(m_points.data(), m_count, PhysicsMaterial(1.0f, 0.3f, 0.5f));
	// 衝突ビットマスク設定
	setPhysicsMask(ECollision::CRYSTAL, ECollision::PLAYER);
	// 衝突時の関数登録
	//setOnCollision(Crystal::onCollision,10);
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(Crystal::onCollision, this);
	this->getEventDispatcher()->addEventListenerWithFixedPriority(contactListener, 10);

	return true;
}
// TODO:全ての衝突時この関数が呼ばれるので別クラスに分ける
// 理由；クリスタルのメンバ関数が全ての当たり判定を管理するのはおかしいから
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
// TODO:脳筋関数群 エッジ自力作成関数
//
// =============================================================================
void Crystal::createEdge_01() {
	// 画面サイズ取得
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	// エッジの数
	const int count = 5;
	// エッジの座標
	Vec2 points[count] = {
		Vec2(origin.x - _rect.getMaxX() / 2.0f,origin.y - _rect.getMaxY() / 2.0f),
		Vec2(origin.x + _rect.getMaxX() / 2.0f,origin.y - _rect.getMaxY() / 2.0f),
		Vec2(origin.x + _rect.getMaxX() / 2.0f,origin.y + _rect.getMaxY() / 2.0f),
		Vec2(origin.x - _rect.getMaxX() / 2.0f,origin.y + _rect.getMaxY() / 2.0f),
		Vec2(origin.x - _rect.getMaxX() / 2.0f,origin.y - _rect.getMaxY() / 2.0f),
	};

	// メンバ変数に代入
	for (int i = 0; i < count; ++i) {
		m_points.push_back(points[i]);
	}
	m_count = count;
}

void Crystal::createEdge_02() {
	// エッジの数
	const int count = 2;
	// エッジの座標
	Vec2 points[count] = {
		Vec2(0,0),
		Vec2(0,0),
	};

	// メンバ変数に代入
	for (int i = 0; i < count; ++i) {
		m_points.push_back(points[i]);
	}
	m_count = count;
}

void Crystal::createEdge_03() {
	// エッジの数
	const int count = 2;
	// エッジの座標
	Vec2 points[count] = {
		Vec2(0,0),
		Vec2(0,0),
	};

	// メンバ変数に代入
	for (int i = 0; i < count; ++i) {
		m_points.push_back(points[i]);
	}
	m_count = count;
}

void Crystal::createEdge_04() {
	// エッジの数
	const int count = 2;
	// エッジの座標
	Vec2 points[count] = {
		Vec2(0,0),
		Vec2(0,0),
	};

	// メンバ変数に代入
	for (int i = 0; i < count; ++i) {
		m_points.push_back(points[i]);
	}
	m_count = count;
}

void Crystal::createEdge_05() {
	// エッジの数
	const int count = 2;
	// エッジの座標
	Vec2 points[count] = {
		Vec2(0,0),
		Vec2(0,0),
	};

	// メンバ変数に代入
	for (int i = 0; i < count; ++i) {
		m_points.push_back(points[i]);
	}
	m_count = count;
}
// =============================================================================
