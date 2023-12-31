#include "Monster.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

Monster::Monster()
    : health(10),speed(0.001f) // 初始生命值为100
{
}

Monster::~Monster(){}

bool Monster::init(int n)
{
    if (n == 1) {
        if (Sprite::initWithFile("16.png"))
        {
           
            // 创建血条
            healthBar = cocos2d::ProgressTimer::create(cocos2d::Sprite::create("21.png"));
            healthBar->setType(cocos2d::ProgressTimer::Type::BAR);
            healthBar->setMidpoint(cocos2d::Vec2(0, 0.5));
            healthBar->setBarChangeRate(cocos2d::Vec2(1, 0));
            healthBar->setPercentage(100);  // 初始化血量为100%

            // 设置血条的位置，这里假设血条应该在怪物的顶部
            healthBar->setPosition(Vec2(getContentSize().width / 2, getContentSize().height));

            // 将血条添加到怪物精灵上
            addChild(healthBar);

            return true;
        }
    }
    if (n == 2) {
        if (Sprite::initWithFile("17.png"))
        {
          
            // 创建血条
            healthBar = cocos2d::ProgressTimer::create(cocos2d::Sprite::create("21.png"));
            healthBar->setType(cocos2d::ProgressTimer::Type::BAR);
            healthBar->setMidpoint(cocos2d::Vec2(0, 0.5));
            healthBar->setBarChangeRate(cocos2d::Vec2(1, 0));
            healthBar->setPercentage(100);  // 初始化血量为100%

            // 设置血条的位置，这里假设血条应该在怪物的顶部
            healthBar->setPosition(Vec2(getContentSize().width / 2, getContentSize().height));

            // 将血条添加到怪物精灵上
            addChild(healthBar);
            return true;
        }
    }
    if (n == 3) {
        if (Sprite::initWithFile("18.png"))
        {
           
            // 创建血条
            healthBar = cocos2d::ProgressTimer::create(cocos2d::Sprite::create("21.png"));
            healthBar->setType(cocos2d::ProgressTimer::Type::BAR);
            healthBar->setMidpoint(cocos2d::Vec2(0, 0.5));
            healthBar->setBarChangeRate(cocos2d::Vec2(1, 0));
            healthBar->setPercentage(100);  // 初始化血量为100%

            // 设置血条的位置，这里假设血条应该在怪物的顶部
            healthBar->setPosition(Vec2(getContentSize().width / 2, getContentSize().height));

            // 将血条添加到怪物精灵上
            addChild(healthBar);
            return true;
        }
    }
    if (n == 4) {
        if (Sprite::initWithFile("22.png")) {

            //创建血条
            healthBar = cocos2d::ProgressTimer::create(cocos2d::Sprite::create("21.png"));
            healthBar->setType(cocos2d::ProgressTimer::Type::BAR);
            healthBar->setMidpoint(cocos2d::Vec2(0, 0.5));
            healthBar->setBarChangeRate(cocos2d::Vec2(1, 0));
            healthBar->setPercentage(100);  // 初始化血量为100%

            // 设置血条的位置，这里假设血条应该在怪物的顶部
            healthBar->setPosition(Vec2(getContentSize().width / 2, getContentSize().height));

            // 将血条添加到怪物精灵上
            addChild(healthBar);
            return true;
        }
    }
    if (n == 5) {
        if (Sprite::initWithFile("23.png")) {
            //创建血条
            healthBar = cocos2d::ProgressTimer::create(cocos2d::Sprite::create("21.png"));
            healthBar->setType(cocos2d::ProgressTimer::Type::BAR);
            healthBar->setMidpoint(cocos2d::Vec2(0, 0.5));
            healthBar->setBarChangeRate(cocos2d::Vec2(1, 0));
            healthBar->setPercentage(100);  // 初始化血量为100%

            // 设置血条的位置，这里假设血条应该在怪物的顶部
            healthBar->setPosition(Vec2(getContentSize().width / 2, getContentSize().height));

            // 将血条添加到怪物精灵上
            addChild(healthBar);
            return true;
        }
    }
    if (n == 6) {
        if (Sprite::initWithFile("24.png")) {
            //创建血条
            healthBar = cocos2d::ProgressTimer::create(cocos2d::Sprite::create("21.png"));
            healthBar->setType(cocos2d::ProgressTimer::Type::BAR);
            healthBar->setMidpoint(cocos2d::Vec2(0, 0.5));
            healthBar->setBarChangeRate(cocos2d::Vec2(1, 0));
            healthBar->setPercentage(100);  // 初始化血量为100%

            // 设置血条的位置，这里假设血条应该在怪物的顶部
            healthBar->setPosition(Vec2(getContentSize().width / 2, getContentSize().height));

            // 将血条添加到怪物精灵上
            addChild(healthBar);
            return true;
        }
    }
    // 初始化怪兽的外观，根据需要添加精灵帧、动画等

    return false;
}

Monster* Monster::create(int n)
{
    //创建怪物
    Monster* monster = new Monster();
    
    if (monster && monster->init(n))
    {
        monster->autorelease();
        return monster;
    }
    CC_SAFE_DELETE(monster);
    return nullptr;
}
void Monster::move(float x, float y, float n_x, float n_y)
{
    //怪物移动的函数
    loc_x = x;
    loc_y = y;
    if (!(x == ROBOT_X - 15 && y == ROBOT_Y) && health > 0)//怪物未移动到萝卜的位置且怪物未死亡
    {    
        setHealth(health*10);
        // 创建你的动作序列，这里使用 MoveBy 作为示例
        auto moveAction = cocos2d::MoveBy::create(speed, cocos2d::Vec2(n_x, n_y));

        // 创建动作序列，包含移动动作和在动作完成时调用 CallFunc 的部分
        auto sequence = cocos2d::Sequence::create(
            moveAction,
            cocos2d::CallFunc::create([this]() {
                cocos2d::Vec2 spritePosition = this->getPosition();
                if (spritePosition.x == 1024 - ROBOT_X && spritePosition.y > SIGN_1_Y)
                    this->move(spritePosition.x, spritePosition.y, 0, -1);  // 递归调用自己
                if (spritePosition.x >= 1024 - ROBOT_X && spritePosition.x < SIGN_2_X && spritePosition.y == SIGN_1_Y)
                    this->move(spritePosition.x, spritePosition.y, 1, 0);  // 递归调用自己
                if (spritePosition.x == SIGN_2_X && spritePosition.y >= SIGN_1_Y && spritePosition.y < SIGN_2_Y)
                    this->move(spritePosition.x, spritePosition.y, 0, 1);  // 递归调用自己
                if (spritePosition.x < 1024 - SIGN_2_X - 15 && spritePosition.x >= SIGN_2_X && spritePosition.y == SIGN_2_Y)
                    this->move(spritePosition.x, spritePosition.y, 1, 0);  // 递归调用自己
                if (spritePosition.x == 1024 - SIGN_2_X - 15 && spritePosition.y > SIGN_1_Y && spritePosition.y <= SIGN_2_Y)
                    this->move(spritePosition.x, spritePosition.y, 0, -1);  // 递归调用自己
                if (spritePosition.x >= 1024 - SIGN_2_X - 15 && spritePosition.y == SIGN_1_Y && spritePosition.x < ROBOT_X - 15)
                    this->move(spritePosition.x, spritePosition.y, 1, 0);  // 递归调用自己
                if (spritePosition.x == ROBOT_X - 15)
                    this->move(spritePosition.x, spritePosition.y, 0, 1);  // 递归调用自己
                }),
            nullptr
                    );

        // 在 Monster 对象上运行动作序列
        this->runAction(sequence);
    }
    else {
        if (x == ROBOT_X - 15 && y == ROBOT_Y) { //怪物移动到萝卜位置，更新萝卜状态
            auto fScene = dynamic_cast<FlyScene*>(this->getScene());
            if (fScene) {
                fScene->updateCarrot();
            }
            die();//怪物消失
        }
    }
}
void Monster::takeDamage(int damage)
{
    //怪物受伤害的逻辑实现
    health -= damage;
    if (health <= 0)
    {
        auto flyScene = dynamic_cast<FlyScene*>(this->getScene());
        flyScene->wealth += 50;
        die();
        //怪物生命值小于0后消失，玩家获得金币
    }
}

void Monster::die()
{
    // 加载背景音乐文件
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("2.mp3");
    // 播放背景音乐
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("2.mp3", false);
    isAlive = false;
    auto flyScene = dynamic_cast<FlyScene*>(this->getScene());
    if (flyScene) {
        for (auto it = flyScene->monsterList.begin(); it != flyScene->monsterList.end(); ) {
            Monster* towers = *it;

            // 检查怪物的生存状态
            if (towers == this) {
                // 移除怪物
                it = flyScene->monsterList.erase(it);
            }
            else {
                // 更新活着的怪物
                ++it;
            }
        }
        this->removeFromParent();
        flyScene->updateMonsterNum();
    }
   
}