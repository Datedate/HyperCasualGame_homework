#include "Player.h"
#include "EventData.h"
#include "VerticalScroll.h"
#include "Collision.h"


Player* Player::create(const std::string& _filename, const Rect& _rect) {
	Player *sprite = new (std::nothrow) Player();
	if (sprite && sprite->initWithFile(_filename, _rect))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

Player::~Player() {
	Director::getInstance()->getEventDispatcher()->removeCustomEventListeners("touchStart_player_event");
	Director::getInstance()->getEventDispatcher()->removeCustomEventListeners("touchRelease_player_event");
}

bool Player::initWithFile(const std::string& _filename, const Rect& _rect) {
	if (!Sprite::initWithFile(_filename,_rect)) {
		return false;
	}
	// �r���[���擾
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	// �v���C���[������
	this->setPosition(origin.x + visibleSize.width / 2.0f, origin.y + visibleSize.height / 2.0f);
	this->setColor(Color3B(255, 255, 255));
	auto playerMat = PHYSICSBODY_MATERIAL_DEFAULT;
	playerMat.restitution = 0.5f;
	playerMat.friction = 0.4f;
	auto phyPlayer = PhysicsBody::createCircle(_rect.getMidX(), playerMat);
	phyPlayer->setDynamic(true);
	phyPlayer->setRotationEnable(false);
	phyPlayer->setMass(1.0f);
	phyPlayer->setMoment(1.0f);

	// �Փ˔���̃}�X�N�ݒ�
	phyPlayer->setCategoryBitmask(static_cast<int>(ECollision::PLAYER));
	//phyPlayer->setCollisionBitmask(static_cast<int>(ECollision::Wall));
	phyPlayer->setContactTestBitmask(INT_MAX);
	this->setPhysicsBody(phyPlayer);

	// �Փ˃^�O�ݒ�
	this->setTag(ECollision::PLAYER);

	// ������ї�
	m_vecPower = 0.5f;

	// ���S�t���O
	m_isDeadFlg = false;

	// �v���C���[����ɉ����x�N�g���̋���
	m_alwaysVecPower = Vec2(1, 1);

	// �C�x���g�󂯎�菈���o�^
	initEventReceive();

	// �X�P�W���[����Update�񂵂Ă��炤
	this->scheduleUpdate();

	return true;
}


void Player::update(float _dt) {
	auto posY = getViewPos().y;
	// �v���C���[���W��Layer��艺��ʂɗ�������Scene�J��
	if (posY < -20) {
		// TODO:���S�A�j���[�V�����Ńt���O�Z�b�g
		m_isDeadFlg = true;
	}

	auto vec = this->getPhysicsBody()->getVelocity();
	this->getPhysicsBody()->setVelocity(Vec2(vec.x ,
											 vec.y * m_alwaysVecPower.y));

	// ���ꂼ��̃��C���[�ɃC�x���g���s
	if (!eventDisptcher(EEventDispatch::DEBUG_DISPLAY_EVENT)) {
		// �C�x���g��ނ�ǉ����Ă�������
	}
	if (!eventDisptcher(EEventDispatch::UI_EVENT)) {
		// �C�x���g��ނ�ǉ����Ă�������
	}
	if (!eventDisptcher(EEventDispatch::BACKGROUND_EVENT)) {
		// �C�x���g��ނ�ǉ����Ă�������
	}
}

Vec2 Player::getViewPos() const {
	// �r���[���W�ɕϊ�
	auto layerPos = this->_parent->getPosition();
	auto playerPos = this->getPosition();
	return (layerPos + playerPos);
}

bool Player::isDead() const {
	return m_isDeadFlg;
}

void Player::moveStop(EventCustom* _event) {
	if (!eventDisptcher(EEventDispatch::HOLD_EVENT)) {
		// �C�x���g��ނ�ǉ����Ă�������
	}

	// �x�N�g���y������
	m_alwaysVecPower.x *= 0.05f;
	m_alwaysVecPower.y *= 0.2f;
	auto vec = this->getPhysicsBody()->getVelocity();
	this->getPhysicsBody()->setVelocity(Vec2(vec.x * m_alwaysVecPower.x, vec.y));
	//this->getPhysicsBody()->setDynamic(false);

}

void Player::moveStart(EventCustom* _event) {
	// �x�N�g�������߂�
	m_alwaysVecPower = Vec2(1, 1);

	// ������΂�����
	auto data = (stEventSendTouchData*)_event->getUserData();
	Point began = data->touchBegan;
	Point ended = data->touchRealse;

	Vect force = Vect(began.x - ended.x, began.y - ended.y) * m_vecPower;
	this->getPhysicsBody()->setDynamic(true);
	this->getPhysicsBody()->applyImpulse(force);
}

void Player::deadHoldOver(EventCustom* _event) {
	// TODO:�z�[���h�I�[�o�[�����o
	m_isDeadFlg = true;
}

void Player::deadCrystal() {
	// TODO:�N���X�^���Փˎ����o
	m_isDeadFlg = true;
}

void Player::initEventReceive() {
	Director::getInstance()->getEventDispatcher()->addCustomEventListener("touchTrigger_player_event",
		CC_CALLBACK_1(Player::moveStop, this));
	Director::getInstance()->getEventDispatcher()->addCustomEventListener("touchRelease_player_event",
		CC_CALLBACK_1(Player::moveStart, this));
}

bool Player::eventDisptcher(EEventDispatch _eEventType) {
	// ����f�[�^�`��
	auto data = stEventSendPlayerData();
	data.pos = this->getPosition();
	switch (_eEventType)
	{
	case EEventDispatch::DEBUG_DISPLAY_EVENT:
		m_debugEvent.setUserData(&data);
		Director::getInstance()->getEventDispatcher()->dispatchEvent(&m_debugEvent);
		break;
	case EEventDispatch::HOLD_EVENT:
		m_holdEvent.setUserData(&data);
		Director::getInstance()->getEventDispatcher()->dispatchEvent(&m_holdEvent);
		break;
	case EEventDispatch::UI_EVENT:
		m_holdEvent.setUserData(&data);
		Director::getInstance()->getEventDispatcher()->dispatchEvent(&m_holdEvent);
		break;
	case EEventDispatch::BACKGROUND_EVENT:
		m_holdEvent.setUserData(&data);
		Director::getInstance()->getEventDispatcher()->dispatchEvent(&m_holdEvent);
		break;
	default:
		return false;
	}
	return true;
}
