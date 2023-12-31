#include "TowerManager.h"
#include "FlyScene.h"
#include"cocos2d.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

bool TowerManager::init()
{
    //初始化，在初始场景中无炮塔放置
    if (!Node::init())
    {
        return false;
    }

    selectedTowerType = Tower::Type::None;
    options.build = nullptr;
    options.up = nullptr;
    options.remove = nullptr;

    return true;
}

void TowerManager::showTowerOptions(const Vec2& position)
{
    if (!options.build) {
        createOptions(position);
    }
    cocos2d::Vec2 newPosition = cocos2d::Vec2(position.x, position.y + 50);

    // 设置选项的位置
    options.build->setPosition(newPosition);
    addChild(options.build, 1);
    selectedTowerType = Tower::Type::None;  // 重置为 None，以便下一次点击重新选择
}

void TowerManager::showUP_BOTTLEOptions(const Vec2& position, const int& time)
{
    cocos2d::Vec2 newPosition = cocos2d::Vec2(position.x, position.y + 50);
    /////////////////////////////////
    if (options.up) {
        removeTowerOptions();
    }
    createUP_BOTTLEOptions(position, time);//显示升级选项
    // 设置选项的位置
    options.up->setPosition(newPosition);
    addChild(options.up, 1);
    selectedTowerType = Tower::Type::None;  // 重置为 None，以便下一次点击重新选择
}

void TowerManager::showUP_SHITOptions(const Vec2& position, const int& time)//flyScene中传递进来time
{
    cocos2d::Vec2 newPosition = cocos2d::Vec2(position.x, position.y + 50);
    /////////////////////////////////
    if (options.up) {
        removeTowerOptions();
    }
    createUP_SHITOptions(position, time);//显示升级选项

    // 设置选项的位置
    options.up->setPosition(newPosition);
    addChild(options.up, 1);
    selectedTowerType = Tower::Type::None;  // 重置为 None，以便下一次点击重新选择
}

void TowerManager::noTower() {

    // 创建精灵
    auto sprite = Sprite::create("noTower.png");

    sprite->setPosition(Vec2(1024 / 2, 576 / 2));
    addChild(sprite, 1);

    // 创建动画
    auto fadeOut = FadeOut::create(1.0f);  // 1秒内淡出
    // 创建动作序列，淡入后延迟1秒，然后淡出
    auto sequence = Sequence::create(DelayTime::create(1.0f), fadeOut, nullptr);
    // 运行动作
    sprite->runAction(sequence);
}

void TowerManager::createbottleTower(const Vec2& position, const int& time)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("3.mp3");
    // 播放背景音乐
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("3.mp3", false);
    auto flyScene = dynamic_cast<FlyScene*>(this->getScene());

    // 创建并添加炮塔

    if (time == 0)
    {
        if (flyScene->wealth >= 100) {
            selectedTowerType = Tower::Type::BasicBottle;
            auto tower = Tower::create(Tower::Type::BasicBottle);
            tower->setPosition(position);
            getParent()->addChild(tower, 1);  // 添加到FlyScene中
            tower->tower_locx = position.x;
            tower->tower_locy = position.y;
            tower->distance = 150;
            tower->hurt = 3;
            tower->level = 1;
            tower->type = 1;
            flyScene->wealth -= 100;
            flyScene->tower_change(flyScene->loc_return(position.x, position.y), 1, 1);
            flyScene->towerList.push_back(tower);
        }
        else {
            noTower();
        }
    }
    
        //第一次升级
        if (time == 1)
        {
            if (flyScene->wealth >= 180) {
                // 删除点击位置的炮塔
                removeTowerAtPosition(position);
                selectedTowerType = Tower::Type::BetterBottle;
                auto tower = Tower::create(Tower::Type::BetterBottle);
                tower->setPosition(position);
                getParent()->addChild(tower, 1);  // 添加到FlyScene中   
                tower->tower_locx = position.x;
                tower->tower_locy = position.y;
                tower->distance = 150;
                tower->hurt = 5;
                tower->level = 2;
                tower->type = 1;
                flyScene->wealth -= 180;
                flyScene->tower_change(flyScene->loc_return(position.x, position.y), 2, 1);
                flyScene->towerList.push_back(tower);
            }
            else
                noTower();
        }
        //第二次升级
        if (time == 2)
        {
            if (flyScene->wealth >= 180) {
                // 删除点击位置的炮塔
                removeTowerAtPosition(position);
                selectedTowerType = Tower::Type::BestBottle;
                auto tower = Tower::create(Tower::Type::BestBottle);
                tower->setPosition(position);
                getParent()->addChild(tower, 1);  // 添加到FlyScene中
                tower->tower_locx = position.x;
                tower->tower_locy = position.y;
                tower->distance = 200;
                tower->hurt = 7;
                tower->level = 3;
                tower->type = 1;
                flyScene->wealth -= 180;
                flyScene->tower_change(flyScene->loc_return(position.x, position.y), 3, 1);
                flyScene->towerList.push_back(tower);
            }
            else
                noTower();
        }
    
   
}

void TowerManager::createshitTower(const Vec2& position, const int& time)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("3.mp3");
    // 播放背景音乐
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("3.mp3", false);
    auto flyScene = dynamic_cast<FlyScene*>(this->getScene());

    // 创建并添加炮塔
    if (time == 0 && selectedTowerType != Tower::Type::None)
    {
        if (flyScene->wealth >= 120) {
            selectedTowerType = Tower::Type::BasicShit;
            auto tower = Tower::create(Tower::Type::BasicShit);
            tower->setPosition(position);
            tower->tower_locx = position.x;
            tower->tower_locy = position.y;
            tower->distance = 150;
            tower->hurt = 3;
            tower->level = 1;
            tower->type = 2;
            getParent()->addChild(tower, 1);  // 添加到FlyScene中
            flyScene->wealth -= 120;
            flyScene->tower_change(flyScene->loc_return(position.x, position.y), 1, 2);
            flyScene->towerList.push_back(tower);
        }
        else
            noTower();
    }
   
        //第一次升级
        if (time == 1 && selectedTowerType != Tower::Type::None)
        {
            if (flyScene->wealth >= 220) {
                // 删除点击位置的炮塔
                removeTowerAtPosition(position);
                selectedTowerType = Tower::Type::BetterShit;
                auto tower = Tower::create(Tower::Type::BetterShit);
                tower->setPosition(position);
                tower->tower_locx = position.x;
                tower->tower_locy = position.y;
                tower->distance = 150;
                tower->hurt = 5;
                tower->level = 2;
                tower->type = 2;
                getParent()->addChild(tower, 1);// 添加到FlyScene中
                flyScene->tower_change(flyScene->loc_return(position.x, position.y), 2, 2);
                flyScene->wealth -= 220;
                flyScene->towerList.push_back(tower);
            }
            else
                noTower();
        }
        //第二次升级
        if (time == 2 && selectedTowerType != Tower::Type::None)
        {
            if (flyScene->wealth >= 220) {
                // 删除点击位置的炮塔
                removeTowerAtPosition(position);
                selectedTowerType = Tower::Type::BestShit;
                auto tower = Tower::create(Tower::Type::BestShit);
                tower->setPosition(position);
                tower->tower_locx = position.x;
                tower->tower_locy = position.y;
                tower->distance = 200;
                tower->hurt = 7;
                tower->level = 3;
                tower->type = 2;
                getParent()->addChild(tower, 1);  // 添加到FlyScene中
                flyScene->wealth -= 220;
                flyScene->tower_change(flyScene->loc_return(position.x, position.y), 3, 2);
                flyScene->towerList.push_back(tower);
            }
            else
                noTower();
        }
    
    
}

bool TowerManager::onTouchBegan(const Touch* touch, const Event* event)//这里有问题，出现升级选项时
{
    // 获取点击位置
    Vec2 touchPos = touch->getLocation();

    // 判断点击位置是否在炮塔选项范围内
    if (options.build) {//如果此时出现的是放置选项
        if (!options.build->getBoundingBox().containsPoint(touchPos)) {//如果点击不在放置选项上
            // 关闭炮塔选项
            removeTowerOptions();
            return true;  // 处理触摸事件
        }
        else //如果点击在选项上
            return false;  // 则不处理触摸事件
    }
    if (options.up) {//如果此时出现的是升级选项
        if (!options.up->getBoundingBox().containsPoint(touchPos)) {//如果点击不在放置选项上
            // 关闭炮塔选项
            removeTowerOptions();
            return false;  // 处理触摸事件
        }
        else //如果点击在选项上
            return false;  // 则不处理触摸事件
    }
    if (options.remove) {//如果此时出现的是删除选项
        if (!options.remove->getBoundingBox().containsPoint(touchPos)) {//如果点击不在放置选项上
            // 关闭炮塔选项
            removeTowerOptions();
            return true;  // 处理触摸事件
        }
        else //如果点击在选项上
            return false;  // 则不处理触摸事件
    }
    else//如果此时无选项
        return false;
}

void TowerManager::createOptions(const Vec2& position)
{
    if (options.build) {
        options.build->removeFromParentAndCleanup(true);
    }
    // 创建炮塔选项的菜单
    options.build = Menu::create();
    // 创建两个不同种类的炮塔选项
    auto option1 = MenuItemImage::create(
        "shit0build.png",
        "buildA.png",
        [=](Ref* sender) {
            selectedTowerType = Tower::Type::BasicShit;
            createshitTower(position, 0);  // 选择炮塔后直接创建
            removeTowerOptions();
        });
    option1->setLocalZOrder(3);
    auto option2 = MenuItemImage::create(
        "bottle0build.png",
        "buildA.png",
        [=](Ref* sender) {
            selectedTowerType = Tower::Type::BasicBottle;
            createbottleTower(position, 0);  // 选择炮塔后直接创建
            removeTowerOptions();

        });
    option2->setLocalZOrder(3);
    // 设置选项的位置
    option2->setPosition(Vec2(-50, 0));
    option1->setPosition(Vec2(50, 0));

    // 将选项添加到菜单中
    options.build->addChild(option1, 2);
    options.build->addChild(option2, 2);

    // 注册触摸事件
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(TowerManager::onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
}

void TowerManager::createUP_BOTTLEOptions(const Vec2& position, const int& time)
{
    if (options.up) {/////
        options.up->removeFromParentAndCleanup(true);
    }
    // 创建炮塔选项的菜单
    options.up = Menu::create();

    // 创建2个不同种类的炮塔选项
    auto option1 = MenuItemImage::create(
        "bottle2build.png",
        "buildA.png",
        [=](Ref* sender) {
            //selectedTowerType = Tower::Type::BetterBottle;
            createbottleTower(position, time);  // 选择炮塔后直接创建
            removeTowerOptions();
        });
    option1->setLocalZOrder(3);
    auto option2 = MenuItemImage::create(
        "cancel.png",
        "cancel.png",
        [=](Ref* sender) {
            selectedTowerType = Tower::Type::None;  // 清除之前的选择
            removeTowerAtPosition(position);
            auto flyScene = dynamic_cast<FlyScene*>(this->getScene());
            flyScene->tower_change(flyScene->loc_return(position.x, position.y), 0, 0);
            flyScene->wealth += 100;
            removeTowerOptions();
        });
    option2->setLocalZOrder(3);
    // 设置选项的位置
    option1->setPosition(Vec2(-40, 0));
    option2->setPosition(Vec2(40, 0));

    // 将选项添加到菜单中
    options.up->addChild(option1, 1);
    options.up->addChild(option2, 1);

    // 注册触摸事件
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(TowerManager::onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
}

void TowerManager::createUP_SHITOptions(const Vec2& position, const int& time)
{
    if (options.up) {
        options.up->removeFromParentAndCleanup(true);
    }
    // 创建炮塔选项的菜单
    options.up = Menu::create();

    // 创建两个不同种类的炮塔选项
    auto option1 = MenuItemImage::create(
        "shit2build.png",
        "buildA.png",
        [=](Ref* sender) {
            selectedTowerType = Tower::Type::BetterShit;
            createshitTower(position, time);  // 选择炮塔后直接创建   
            removeTowerOptions();
        });
    option1->setLocalZOrder(3);
    auto option2 = MenuItemImage::create(
        "cancel.png",
        "cancel.png",
        [=](Ref* sender) {
            selectedTowerType = Tower::Type::None;  // 清除之前的选择
            removeTowerAtPosition(position);
            auto flyScene = dynamic_cast<FlyScene*>(this->getScene());
            flyScene->wealth += 120;
            flyScene->tower_change(flyScene->loc_return(position.x, position.y), 0, 0);
            removeTowerOptions();
        });
    option2->setLocalZOrder(3);
    // 设置选项的位置
    option1->setPosition(Vec2(-40, 0));
    option2->setPosition(Vec2(40, 0));

    // 将选项添加到菜单中
    options.up->addChild(option1, 1);
    options.up->addChild(option2, 1);
    // 注册触摸事件
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(TowerManager::onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
}

void TowerManager::DELETETOptions(const Vec2& position) {

    if (!options.remove) {
        options.remove = Menu::create();
        auto option0 = MenuItemImage::create(
            "cancel.png",
            "cancel.png",
            [=](Ref* sender) {
                selectedTowerType = Tower::Type::None;  // 清除之前的选择
                removeTowerAtPosition(position);
                auto flyScene = dynamic_cast<FlyScene*>(this->getScene());
                flyScene->tower_change(flyScene->loc_return(position.x, position.y), 0, 0);
                removeTowerOptions();
            });

        // 设置选项的位置
        option0->setPosition(Vec2(0, 0));
        option0->setLocalZOrder(1);
        // 将选项添加到菜单中
        options.remove->addChild(option0, 1);

        // 注册触摸事件
        auto touchListener = EventListenerTouchOneByOne::create();
        touchListener->setSwallowTouches(true);
        touchListener->onTouchBegan = CC_CALLBACK_2(TowerManager::onTouchBegan, this);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    }

    cocos2d::Vec2 newPosition = cocos2d::Vec2(position.x, position.y + 50);

    // 设置选项的位置
    options.remove->setPosition(newPosition);
    addChild(options.remove, 4);
}

void TowerManager::removeTowerOptions()
{

    auto fadeOutAction = FadeOut::create(0.1f);  // 淡出效果
    auto removeSelfAction = RemoveSelf::create();  // 移除自身节点
    auto callback = CallFunc::create([&]() {
        auto flyScene = dynamic_cast<FlyScene*>(this->getScene());
        if (flyScene) {
            flyScene->tower = false;
        }
        });
    auto sequence = Sequence::create(
        Spawn::create(fadeOutAction, nullptr),  // 同时进行淡出
        DelayTime::create(0.1f),
        removeSelfAction,
        callback,
        nullptr
    );
    if (options.up) {// 移除升级选项
        options.up->removeAllChildren();
        options.up->runAction(sequence);  // 运行动作序列
        options.up = nullptr;
        //return;
    }
    if (options.build) {// 移除炮塔选项
        options.build->removeAllChildren();
        options.build->runAction(sequence);  // 运行动作序列
        options.build = nullptr;
        //return;
    }
    if (options.remove) {// 移除炮塔选项
        options.remove->removeAllChildren();
        options.remove->runAction(sequence);  // 运行动作序列
        options.remove = nullptr;
        //return;
    }
}

void TowerManager::removeTowerAtPosition(const Vec2& position)
{
    auto flyScene = dynamic_cast<FlyScene*>(this->getScene());
    if (flyScene)
    {
        for (auto child : flyScene->getChildren())
        {
            auto tower = dynamic_cast<Tower*>(child);
            if (tower && tower->getBoundingBox().containsPoint(position))
            {
                for (auto it = flyScene->towerList.begin(); it != flyScene->towerList.end(); ) {
                    Tower* towers = *it;

                    // 检查怪物的生存状态
                    if (towers == tower) {
                        // 移除怪物
                        it = flyScene->towerList.erase(it);
                    }
                    else {
                        // 更新活着的怪物
                        ++it;
                    }
                }
                tower->removeFromParent();
                break;  // 假设每个位置最多只有一个炮塔，找到并移除后就退出循环
            }
        }
    }
}


