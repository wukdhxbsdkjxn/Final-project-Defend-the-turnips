#include "TowerManager.h"
#include "FlyScene.h"
#include"cocos2d.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

bool TowerManager::init()
{
    //��ʼ�����ڳ�ʼ����������������
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

    // ����ѡ���λ��
    options.build->setPosition(newPosition);
    addChild(options.build, 1);
    selectedTowerType = Tower::Type::None;  // ����Ϊ None���Ա���һ�ε������ѡ��
}

void TowerManager::showUP_BOTTLEOptions(const Vec2& position, const int& time)
{
    cocos2d::Vec2 newPosition = cocos2d::Vec2(position.x, position.y + 50);
    /////////////////////////////////
    if (options.up) {
        removeTowerOptions();
    }
    createUP_BOTTLEOptions(position, time);//��ʾ����ѡ��
    // ����ѡ���λ��
    options.up->setPosition(newPosition);
    addChild(options.up, 1);
    selectedTowerType = Tower::Type::None;  // ����Ϊ None���Ա���һ�ε������ѡ��
}

void TowerManager::showUP_SHITOptions(const Vec2& position, const int& time)//flyScene�д��ݽ���time
{
    cocos2d::Vec2 newPosition = cocos2d::Vec2(position.x, position.y + 50);
    /////////////////////////////////
    if (options.up) {
        removeTowerOptions();
    }
    createUP_SHITOptions(position, time);//��ʾ����ѡ��

    // ����ѡ���λ��
    options.up->setPosition(newPosition);
    addChild(options.up, 1);
    selectedTowerType = Tower::Type::None;  // ����Ϊ None���Ա���һ�ε������ѡ��
}

void TowerManager::noTower() {

    // ��������
    auto sprite = Sprite::create("noTower.png");

    sprite->setPosition(Vec2(1024 / 2, 576 / 2));
    addChild(sprite, 1);

    // ��������
    auto fadeOut = FadeOut::create(1.0f);  // 1���ڵ���
    // �����������У�������ӳ�1�룬Ȼ�󵭳�
    auto sequence = Sequence::create(DelayTime::create(1.0f), fadeOut, nullptr);
    // ���ж���
    sprite->runAction(sequence);
}

void TowerManager::createbottleTower(const Vec2& position, const int& time)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("3.mp3");
    // ���ű�������
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("3.mp3", false);
    auto flyScene = dynamic_cast<FlyScene*>(this->getScene());

    // �������������

    if (time == 0)
    {
        if (flyScene->wealth >= 100) {
            selectedTowerType = Tower::Type::BasicBottle;
            auto tower = Tower::create(Tower::Type::BasicBottle);
            tower->setPosition(position);
            getParent()->addChild(tower, 1);  // ��ӵ�FlyScene��
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
    
        //��һ������
        if (time == 1)
        {
            if (flyScene->wealth >= 180) {
                // ɾ�����λ�õ�����
                removeTowerAtPosition(position);
                selectedTowerType = Tower::Type::BetterBottle;
                auto tower = Tower::create(Tower::Type::BetterBottle);
                tower->setPosition(position);
                getParent()->addChild(tower, 1);  // ��ӵ�FlyScene��   
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
        //�ڶ�������
        if (time == 2)
        {
            if (flyScene->wealth >= 180) {
                // ɾ�����λ�õ�����
                removeTowerAtPosition(position);
                selectedTowerType = Tower::Type::BestBottle;
                auto tower = Tower::create(Tower::Type::BestBottle);
                tower->setPosition(position);
                getParent()->addChild(tower, 1);  // ��ӵ�FlyScene��
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
    // ���ű�������
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("3.mp3", false);
    auto flyScene = dynamic_cast<FlyScene*>(this->getScene());

    // �������������
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
            getParent()->addChild(tower, 1);  // ��ӵ�FlyScene��
            flyScene->wealth -= 120;
            flyScene->tower_change(flyScene->loc_return(position.x, position.y), 1, 2);
            flyScene->towerList.push_back(tower);
        }
        else
            noTower();
    }
   
        //��һ������
        if (time == 1 && selectedTowerType != Tower::Type::None)
        {
            if (flyScene->wealth >= 220) {
                // ɾ�����λ�õ�����
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
                getParent()->addChild(tower, 1);// ��ӵ�FlyScene��
                flyScene->tower_change(flyScene->loc_return(position.x, position.y), 2, 2);
                flyScene->wealth -= 220;
                flyScene->towerList.push_back(tower);
            }
            else
                noTower();
        }
        //�ڶ�������
        if (time == 2 && selectedTowerType != Tower::Type::None)
        {
            if (flyScene->wealth >= 220) {
                // ɾ�����λ�õ�����
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
                getParent()->addChild(tower, 1);  // ��ӵ�FlyScene��
                flyScene->wealth -= 220;
                flyScene->tower_change(flyScene->loc_return(position.x, position.y), 3, 2);
                flyScene->towerList.push_back(tower);
            }
            else
                noTower();
        }
    
    
}

bool TowerManager::onTouchBegan(const Touch* touch, const Event* event)//���������⣬��������ѡ��ʱ
{
    // ��ȡ���λ��
    Vec2 touchPos = touch->getLocation();

    // �жϵ��λ���Ƿ�������ѡ�Χ��
    if (options.build) {//�����ʱ���ֵ��Ƿ���ѡ��
        if (!options.build->getBoundingBox().containsPoint(touchPos)) {//���������ڷ���ѡ����
            // �ر�����ѡ��
            removeTowerOptions();
            return true;  // �������¼�
        }
        else //��������ѡ����
            return false;  // �򲻴������¼�
    }
    if (options.up) {//�����ʱ���ֵ�������ѡ��
        if (!options.up->getBoundingBox().containsPoint(touchPos)) {//���������ڷ���ѡ����
            // �ر�����ѡ��
            removeTowerOptions();
            return false;  // �������¼�
        }
        else //��������ѡ����
            return false;  // �򲻴������¼�
    }
    if (options.remove) {//�����ʱ���ֵ���ɾ��ѡ��
        if (!options.remove->getBoundingBox().containsPoint(touchPos)) {//���������ڷ���ѡ����
            // �ر�����ѡ��
            removeTowerOptions();
            return true;  // �������¼�
        }
        else //��������ѡ����
            return false;  // �򲻴������¼�
    }
    else//�����ʱ��ѡ��
        return false;
}

void TowerManager::createOptions(const Vec2& position)
{
    if (options.build) {
        options.build->removeFromParentAndCleanup(true);
    }
    // ��������ѡ��Ĳ˵�
    options.build = Menu::create();
    // ����������ͬ���������ѡ��
    auto option1 = MenuItemImage::create(
        "shit0build.png",
        "buildA.png",
        [=](Ref* sender) {
            selectedTowerType = Tower::Type::BasicShit;
            createshitTower(position, 0);  // ѡ��������ֱ�Ӵ���
            removeTowerOptions();
        });
    option1->setLocalZOrder(3);
    auto option2 = MenuItemImage::create(
        "bottle0build.png",
        "buildA.png",
        [=](Ref* sender) {
            selectedTowerType = Tower::Type::BasicBottle;
            createbottleTower(position, 0);  // ѡ��������ֱ�Ӵ���
            removeTowerOptions();

        });
    option2->setLocalZOrder(3);
    // ����ѡ���λ��
    option2->setPosition(Vec2(-50, 0));
    option1->setPosition(Vec2(50, 0));

    // ��ѡ����ӵ��˵���
    options.build->addChild(option1, 2);
    options.build->addChild(option2, 2);

    // ע�ᴥ���¼�
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
    // ��������ѡ��Ĳ˵�
    options.up = Menu::create();

    // ����2����ͬ���������ѡ��
    auto option1 = MenuItemImage::create(
        "bottle2build.png",
        "buildA.png",
        [=](Ref* sender) {
            //selectedTowerType = Tower::Type::BetterBottle;
            createbottleTower(position, time);  // ѡ��������ֱ�Ӵ���
            removeTowerOptions();
        });
    option1->setLocalZOrder(3);
    auto option2 = MenuItemImage::create(
        "cancel.png",
        "cancel.png",
        [=](Ref* sender) {
            selectedTowerType = Tower::Type::None;  // ���֮ǰ��ѡ��
            removeTowerAtPosition(position);
            auto flyScene = dynamic_cast<FlyScene*>(this->getScene());
            flyScene->tower_change(flyScene->loc_return(position.x, position.y), 0, 0);
            flyScene->wealth += 100;
            removeTowerOptions();
        });
    option2->setLocalZOrder(3);
    // ����ѡ���λ��
    option1->setPosition(Vec2(-40, 0));
    option2->setPosition(Vec2(40, 0));

    // ��ѡ����ӵ��˵���
    options.up->addChild(option1, 1);
    options.up->addChild(option2, 1);

    // ע�ᴥ���¼�
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
    // ��������ѡ��Ĳ˵�
    options.up = Menu::create();

    // ����������ͬ���������ѡ��
    auto option1 = MenuItemImage::create(
        "shit2build.png",
        "buildA.png",
        [=](Ref* sender) {
            selectedTowerType = Tower::Type::BetterShit;
            createshitTower(position, time);  // ѡ��������ֱ�Ӵ���   
            removeTowerOptions();
        });
    option1->setLocalZOrder(3);
    auto option2 = MenuItemImage::create(
        "cancel.png",
        "cancel.png",
        [=](Ref* sender) {
            selectedTowerType = Tower::Type::None;  // ���֮ǰ��ѡ��
            removeTowerAtPosition(position);
            auto flyScene = dynamic_cast<FlyScene*>(this->getScene());
            flyScene->wealth += 120;
            flyScene->tower_change(flyScene->loc_return(position.x, position.y), 0, 0);
            removeTowerOptions();
        });
    option2->setLocalZOrder(3);
    // ����ѡ���λ��
    option1->setPosition(Vec2(-40, 0));
    option2->setPosition(Vec2(40, 0));

    // ��ѡ����ӵ��˵���
    options.up->addChild(option1, 1);
    options.up->addChild(option2, 1);
    // ע�ᴥ���¼�
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
                selectedTowerType = Tower::Type::None;  // ���֮ǰ��ѡ��
                removeTowerAtPosition(position);
                auto flyScene = dynamic_cast<FlyScene*>(this->getScene());
                flyScene->tower_change(flyScene->loc_return(position.x, position.y), 0, 0);
                removeTowerOptions();
            });

        // ����ѡ���λ��
        option0->setPosition(Vec2(0, 0));
        option0->setLocalZOrder(1);
        // ��ѡ����ӵ��˵���
        options.remove->addChild(option0, 1);

        // ע�ᴥ���¼�
        auto touchListener = EventListenerTouchOneByOne::create();
        touchListener->setSwallowTouches(true);
        touchListener->onTouchBegan = CC_CALLBACK_2(TowerManager::onTouchBegan, this);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    }

    cocos2d::Vec2 newPosition = cocos2d::Vec2(position.x, position.y + 50);

    // ����ѡ���λ��
    options.remove->setPosition(newPosition);
    addChild(options.remove, 4);
}

void TowerManager::removeTowerOptions()
{

    auto fadeOutAction = FadeOut::create(0.1f);  // ����Ч��
    auto removeSelfAction = RemoveSelf::create();  // �Ƴ�����ڵ�
    auto callback = CallFunc::create([&]() {
        auto flyScene = dynamic_cast<FlyScene*>(this->getScene());
        if (flyScene) {
            flyScene->tower = false;
        }
        });
    auto sequence = Sequence::create(
        Spawn::create(fadeOutAction, nullptr),  // ͬʱ���е���
        DelayTime::create(0.1f),
        removeSelfAction,
        callback,
        nullptr
    );
    if (options.up) {// �Ƴ�����ѡ��
        options.up->removeAllChildren();
        options.up->runAction(sequence);  // ���ж�������
        options.up = nullptr;
        //return;
    }
    if (options.build) {// �Ƴ�����ѡ��
        options.build->removeAllChildren();
        options.build->runAction(sequence);  // ���ж�������
        options.build = nullptr;
        //return;
    }
    if (options.remove) {// �Ƴ�����ѡ��
        options.remove->removeAllChildren();
        options.remove->runAction(sequence);  // ���ж�������
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

                    // �����������״̬
                    if (towers == tower) {
                        // �Ƴ�����
                        it = flyScene->towerList.erase(it);
                    }
                    else {
                        // ���»��ŵĹ���
                        ++it;
                    }
                }
                tower->removeFromParent();
                break;  // ����ÿ��λ�����ֻ��һ���������ҵ����Ƴ�����˳�ѭ��
            }
        }
    }
}


