
#include "GameScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* GameScene::createScene() {
	//return GameScene::create();
	// 物理演算を使うためのメソッド
	auto scene = Scene::createWithPhysics();

	// 重力セット
	Vect gravity;
	gravity.setPoint(0, -20);
	scene->getPhysicsWorld()->setGravity(gravity);
	scene->getPhysicsWorld()->setSpeed(6.0f);

	// 物理オブジェクトの対象範囲を可視化するデバッグ機能
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	auto layer = GameScene::create();
	scene->addChild(layer);

	return scene;
}

static void problemLoading(const char* filename) {
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool GameScene::init() {
	if (!Layer::init()) {
		return false;
	}

	/*
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto closeItem = MenuItemImage::create(
		"CloseNoraml.png",
		"CloseSelected.png",
		CC_CALLBACK_1(GameScene::menuCloseCallback, this));

	if (closeItem == nullptr || 
		closeItem->getContentSize().width <= 0 ||
		closeItem->getContentSize().height <= 0) 
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else {
		float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
		float y = origin.y + closeItem->getContentSize().height / 2;
		closeItem->setPosition(Vec2(x, y));
	}

	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	auto label = Label::createWithTTF("Game Start", "fonts/Marker Felt.ttf", 24);
	if (label == nullptr) {
		problemLoading("'fonts/Marker Felt.ttf'");
	}
	else {
		label->setPosition(Vec2(origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height - label->getContentSize().height));

		this->addChild(label, 1);
	}

	auto sprite = Sprite::create("HelloWorld.png");
	if (sprite == nullptr) {
		problemLoading("'HelloWorld.png'");
	}
	else {
		sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

		this->addChild(sprite, 0);
	}
	*/

	// 画面サイズ取得
	auto window_size = Director::getInstance()->getWinSize();

	// 床
	auto wall = Sprite::create();
	wall->setPosition(150, 0);
	wall->setTextureRect(Rect(0, 0, window_size.width, 100));
	wall->setColor(Color3B(255, 255, 255));
	wall->setRotation(2.0f);

	// 反発係数と摩擦係数
	auto material = PHYSICSBODY_MATERIAL_DEFAULT;
	material.restitution = 1.0f;
	material.friction = 1.0f;

	auto pWall = PhysicsBody::createBox(wall->getContentSize(), material);
	// 重力干渉をうけるか
	pWall->setDynamic(false);
	// 回転させるか
	pWall->setRotationEnable(false);
	wall->setPhysicsBody(pWall);
	this->addChild(wall);

	// 丸いボール
	auto ball = Sprite::create();
	ball->setPosition(20, 300);
	ball->setColor(Color3B(255, 255, 255));
	auto ballMat = PHYSICSBODY_MATERIAL_DEFAULT;
	ballMat.restitution = 0.5f;
	ballMat.friction = 0.4f;
	auto pBall = PhysicsBody::createCircle(10.0f,ballMat);
	pBall->setDynamic(true);
	pBall->setRotationEnable(true);
	pBall->setMass(1.0f);
	pBall->setMoment(1.0f);
	pBall->setVelocity(Vec2(0, 200));
	ball->setPhysicsBody(pBall);
	this->addChild(ball);


	return true;
}

void GameScene::menuCloseCallback(Ref* pSender) {
	Director::getInstance()->end();
}