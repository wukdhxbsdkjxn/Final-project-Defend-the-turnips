#include "LoginScene.h"
#include "SimpleAudioEngine.h"
#include "FlyScene.h"
USING_NS_CC;
Scene* LoginScene::createLoginScene()
{
    return LoginScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}


bool LoginScene::init()
{

    if (!Scene::init())
    {
        return false;
    }


    // 加载背景音乐文件
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("1.mp3");
    // 播放背景音乐
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("1.mp3", true);


    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //创建一个按钮
    auto closeItem = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(LoginScene::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
        float y = origin.y + closeItem->getContentSize().height / 2;
        closeItem->setPosition(Vec2(x, y));
    }
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);



    //开始按钮
    auto  startButton = MenuItemImage::create(
        "4.png",
        "5.png",
        CC_CALLBACK_1(LoginScene::menuStartCallback, this));
    if (startButton == nullptr ||
        startButton->getContentSize().width <= 0 ||
        startButton->getContentSize().height <= 0)
    {
        problemLoading("'startButton' and 'startButton'");
    }
    else
    {
        float x = origin.x + visibleSize.width/2;
        float y = origin.y + visibleSize.height / 2- startButton->getContentSize().height*2 ;
        startButton->setPosition(Vec2(x, y));
    }

    // create menu, it's an autorelease object
    auto menu_start = Menu::create(startButton, NULL);
    menu_start->setPosition(Vec2::ONE);
    this->addChild(menu_start, 1);
   


    //创建一个字
    auto label = Label::createWithTTF("Carrot Fantasy", "fonts/Marker Felt.ttf", 100);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }



    //创建一个精灵
    auto sprite = Sprite::create("3.png");
    if (sprite == nullptr)
    {
        problemLoading("'1.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }
   
    return true;
}


void LoginScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}
void LoginScene::menuStartCallback(Ref* pSender)
{
    auto newScene = LoginChoiceScene::createChoiceLoginScene();
    Director::getInstance()->replaceScene(newScene);
}
Scene* LoginChoiceScene::createChoiceLoginScene()
{
    return LoginChoiceScene::create();
}
bool LoginChoiceScene::init()
{

    if (!Scene::init())
    {
        return false;
    }

    auto choice_visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 choice_origin = Director::getInstance()->getVisibleOrigin();

    //创建一个按钮
    auto choice_closeItem = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(LoginChoiceScene::menuCloseCallback, this));

    if (choice_closeItem == nullptr ||
        choice_closeItem->getContentSize().width <= 0 ||
        choice_closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = choice_origin.x + choice_visibleSize.width - choice_closeItem->getContentSize().width / 2;
        float y = choice_origin.y + choice_closeItem->getContentSize().height / 2;
        choice_closeItem->setPosition(Vec2(x, y));
    }
    auto choice_menu = Menu::create(choice_closeItem, NULL);
    choice_menu->setPosition(Vec2::ZERO);
    this->addChild(choice_menu, 1);





    //sky关卡按钮
    auto  sky_startButton = MenuItemImage::create(
        "8.png",
        "10.png",
        CC_CALLBACK_1(LoginChoiceScene::menu_fly, this));
    if (sky_startButton == nullptr ||
        sky_startButton->getContentSize().width <= 0 ||
        sky_startButton->getContentSize().height <= 0)
    {
        problemLoading("'startButton' and 'startButton'");
    }
    else
    {
        float x = choice_origin.x + choice_visibleSize.width / 4;
        float y = choice_origin.y + choice_visibleSize.height / 2 ;
        sky_startButton->setPosition(Vec2(x, y));
    }
    auto sky_menu_start = Menu::create(sky_startButton, NULL);
    sky_menu_start->setPosition(Vec2::ONE);
    this->addChild(sky_menu_start, 1);





    //Forest关卡按钮
    auto  for_startButton = MenuItemImage::create(
        "9.png",
        "11.png",
        CC_CALLBACK_1(LoginChoiceScene::menuCloseCallback, this));
    if (for_startButton == nullptr ||
        for_startButton->getContentSize().width <= 0 ||
        for_startButton->getContentSize().height <= 0)
    {
        problemLoading("'startButton' and 'startButton'");
    }
    else
    {
        float x = choice_origin.x + 3*choice_visibleSize.width / 4;
        float y = choice_origin.y + choice_visibleSize.height / 2;
        for_startButton->setPosition(Vec2(x, y));
    }

    // create menu, it's an autorelease object
    auto for_menu_start = Menu::create(for_startButton, NULL);
    for_menu_start->setPosition(Vec2(2,2));
    this->addChild(for_menu_start, 1);
    ////////////////////////
    // add "HelloWorld" splash screen"
    auto back_sprite = Sprite::create("7.png");
    if (back_sprite == nullptr)
    {
        problemLoading("'1.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        back_sprite->setPosition(Vec2(choice_visibleSize.width / 2 + choice_origin.x, choice_visibleSize.height / 2 + choice_origin.y));
        // add the sprite as a child to this layer
        this->addChild(back_sprite, 0);
    }

    auto sign_sprite = Sprite::create("6.png");
    if (sign_sprite == nullptr)
    {
        problemLoading("'1.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sign_sprite->setPosition(Vec2(choice_visibleSize.width / 2 + choice_origin.x, choice_visibleSize.height  + choice_origin.y-20));
        // add the sprite as a child to this layer
        this->addChild(sign_sprite, 0);
    }
    return true;
}
void LoginChoiceScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
void LoginChoiceScene::menu_fly(Ref* pSender)
{
    auto newScene = FlyScene::createFlyScene();
    Director::getInstance()->replaceScene(newScene);
}

