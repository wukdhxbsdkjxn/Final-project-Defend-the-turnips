#include "ForestMonster.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

ForMonster::ForMonster()
    : health(10), speed(0.001f) // ��ʼ����ֵΪ100
{
}

ForMonster::~ForMonster() {}

bool ForMonster::init(int n)
{
    if (n == 1) {
        if (Sprite::initWithFile("16.png"))
        {

            // ����Ѫ��
            healthBar = cocos2d::ProgressTimer::create(cocos2d::Sprite::create("21.png"));
            healthBar->setType(cocos2d::ProgressTimer::Type::BAR);
            healthBar->setMidpoint(cocos2d::Vec2(0, 0.5));
            healthBar->setBarChangeRate(cocos2d::Vec2(1, 0));
            healthBar->setPercentage(100);  // ��ʼ��Ѫ��Ϊ100%

            // ����Ѫ����λ�ã��������Ѫ��Ӧ���ڹ���Ķ���
            healthBar->setPosition(Vec2(getContentSize().width / 2, getContentSize().height));

            // ��Ѫ����ӵ����ﾫ����
            addChild(healthBar);

            return true;
        }
    }
    if (n == 2) {
        if (Sprite::initWithFile("17.png"))
        {

            // ����Ѫ��
            healthBar = cocos2d::ProgressTimer::create(cocos2d::Sprite::create("21.png"));
            healthBar->setType(cocos2d::ProgressTimer::Type::BAR);
            healthBar->setMidpoint(cocos2d::Vec2(0, 0.5));
            healthBar->setBarChangeRate(cocos2d::Vec2(1, 0));
            healthBar->setPercentage(100);  // ��ʼ��Ѫ��Ϊ100%

            // ����Ѫ����λ�ã��������Ѫ��Ӧ���ڹ���Ķ���
            healthBar->setPosition(Vec2(getContentSize().width / 2, getContentSize().height));

            // ��Ѫ����ӵ����ﾫ����
            addChild(healthBar);
            return true;
        }
    }
    if (n == 3) {
        if (Sprite::initWithFile("18.png"))
        {

            // ����Ѫ��
            healthBar = cocos2d::ProgressTimer::create(cocos2d::Sprite::create("21.png"));
            healthBar->setType(cocos2d::ProgressTimer::Type::BAR);
            healthBar->setMidpoint(cocos2d::Vec2(0, 0.5));
            healthBar->setBarChangeRate(cocos2d::Vec2(1, 0));
            healthBar->setPercentage(100);  // ��ʼ��Ѫ��Ϊ100%

            // ����Ѫ����λ�ã��������Ѫ��Ӧ���ڹ���Ķ���
            healthBar->setPosition(Vec2(getContentSize().width / 2, getContentSize().height));

            // ��Ѫ����ӵ����ﾫ����
            addChild(healthBar);
            return true;
        }
    }
    if (n == 4) {
        if (Sprite::initWithFile("60.png")) {
            healthBar = cocos2d::ProgressTimer::create(cocos2d::Sprite::create("21.png"));
            healthBar->setType(cocos2d::ProgressTimer::Type::BAR);
            healthBar->setMidpoint(cocos2d::Vec2(0, 0.5));
            healthBar->setBarChangeRate(cocos2d::Vec2(1, 0));
            healthBar->setPercentage(100);  // ��ʼ��Ѫ��Ϊ100%

            // ����Ѫ����λ�ã��������Ѫ��Ӧ���ڹ���Ķ���
            healthBar->setPosition(Vec2(getContentSize().width / 2, getContentSize().height));

            // ��Ѫ����ӵ����ﾫ����
            addChild(healthBar);
            return true;
        }
    }
    if (n == 5) {
        if (Sprite::initWithFile("61.png")) {
            healthBar = cocos2d::ProgressTimer::create(cocos2d::Sprite::create("21.png"));
            healthBar->setType(cocos2d::ProgressTimer::Type::BAR);
            healthBar->setMidpoint(cocos2d::Vec2(0, 0.5));
            healthBar->setBarChangeRate(cocos2d::Vec2(1, 0));
            healthBar->setPercentage(100);  // ��ʼ��Ѫ��Ϊ100%

            // ����Ѫ����λ�ã��������Ѫ��Ӧ���ڹ���Ķ���
            healthBar->setPosition(Vec2(getContentSize().width / 2, getContentSize().height));

            // ��Ѫ����ӵ����ﾫ����
            addChild(healthBar);
            return true;
        }
    }
    if (n == 6) {
        if (Sprite::initWithFile("62.png")) {
            healthBar = cocos2d::ProgressTimer::create(cocos2d::Sprite::create("21.png"));
            healthBar->setType(cocos2d::ProgressTimer::Type::BAR);
            healthBar->setMidpoint(cocos2d::Vec2(0, 0.5));
            healthBar->setBarChangeRate(cocos2d::Vec2(1, 0));
            healthBar->setPercentage(100);  // ��ʼ��Ѫ��Ϊ100%

            // ����Ѫ����λ�ã��������Ѫ��Ӧ���ڹ���Ķ���
            healthBar->setPosition(Vec2(getContentSize().width / 2, getContentSize().height));

            // ��Ѫ����ӵ����ﾫ����
            addChild(healthBar);
            return true;
        }
    }
    // ��ʼ�����޵���ۣ�����Ը�����Ҫ��Ӿ���֡��������

    return false;
}

ForMonster* ForMonster::create(int n)
{
    ForMonster* monster = new ForMonster();

    if (monster && monster->init(n))
    {
        monster->autorelease();
        return monster;
    }
    CC_SAFE_DELETE(monster);
    return nullptr;
}
void ForMonster::move(float x, float y, float n_x, float n_y)
{
    loc_x = x;
    loc_y = y;
    if (!(x == FOR_CARROT_X && y == FOR_CARROT_Y) && health > 0)
    {
        setHealth(health * 10);
        // ������Ķ������У�����ʹ�� MoveBy ��Ϊʾ��
        auto moveAction = cocos2d::MoveBy::create(speed, cocos2d::Vec2(n_x, n_y));

        // �����������У������ƶ��������ڶ������ʱ���� CallFunc �Ĳ���
        auto sequence = cocos2d::Sequence::create(
            moveAction,
            cocos2d::CallFunc::create([this]() {
                cocos2d::Vec2 spritePosition = this->getPosition();
                if (spritePosition.y == MON_START_Y && spritePosition.x < MON_1_X&& spritePosition.x >= MON_START_X)
                    this->move(spritePosition.x, spritePosition.y, 1, 0);  // �ݹ�����Լ�
                if (spritePosition.x == MON_1_X && spritePosition.y > MON_2_Y && spritePosition.y <= MON_START_Y)
                    this->move(spritePosition.x, spritePosition.y, 0, -1);  // �ݹ�����Լ�
                if (spritePosition.y == MON_2_Y && spritePosition.x > MON_3_X&& spritePosition.x <=MON_1_X)
                    this->move(spritePosition.x, spritePosition.y, -1, 0);  // �ݹ�����Լ�
                if (spritePosition.x == MON_3_X && spritePosition.y > FOR_CARROT_Y&& spritePosition.y <= MON_2_Y)
                    this->move(spritePosition.x, spritePosition.y, 0, -1);  // �ݹ�����Լ�
                if (spritePosition.y == FOR_CARROT_Y)
                    this->move(spritePosition.x, spritePosition.y, 1, 0);  // �ݹ�����Լ�
              
                }),
            nullptr
                    );

        // �� Monster ���������ж�������
        this->runAction(sequence);
    }
    else {
        if (x == FOR_CARROT_X && y == FOR_CARROT_Y) {
            auto fScene = dynamic_cast<ForestScene*>(this->getScene());
            if (fScene) {
                fScene->updateCarrot();
            }
            die();
        }
    }
}
void ForMonster::takeDamage(int damage)
{
    //�����ܵ��˺����߼�ʵ��
    health -= damage;
    if (health <= 0)
    {
        auto flyScene = dynamic_cast<ForestScene*>(this->getScene());
        flyScene->wealth += 50;
        die();
    }
}

void ForMonster::die()
{
    // ���ر��������ļ�
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("2.mp3");
    // ���ű�������
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("2.mp3", false);
    isAlive = false;
    auto flyScene = dynamic_cast<ForestScene*>(this->getScene());
    if (flyScene) {
        for (auto it = flyScene->monsterList.begin(); it != flyScene->monsterList.end(); ) {
            const ForMonster* towers = *it;

            // �����������״̬
            if (towers == this) {
                // �Ƴ�����
                it = flyScene->monsterList.erase(it);
            }
            else {
                // ���»��ŵĹ���
                ++it;
            }
        }
        this->removeFromParent();
        flyScene->updateMonsterNum();
    }
}