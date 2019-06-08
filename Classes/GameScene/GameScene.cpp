
#include "GameScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* GameScene::createScene() {
	return GameScene::create();
}

static void problemLoading(const char* filename) {
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool GameScene::init() {
	if (!Scene::init()) {
		return false;
	}

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

	return true;
}

void GameScene::menuCloseCallback(Ref* pSender) {
	Director::getInstance()->end();
}