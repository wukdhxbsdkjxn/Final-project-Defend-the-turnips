#include "Monster.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

Monster::Monster()
    : health(10),speed(0.001f) // ��ʼ����ֵΪ100
{
}

Monster::~Monster(){}

bool Monster::init(int n)
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
        if (Sprite::initWithFile("22.png")) {

            //����Ѫ��
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
        if (Sprite::initWithFile("23.png")) {
            //����Ѫ��
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
        if (Sprite::initWithFile("24.png")) {
            //����Ѫ��
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
    // ��ʼ�����޵���ۣ�������Ҫ��Ӿ���֡��������

    return false;
}

Monster* Monster::create(int n)
{
    //��������
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
    //�����ƶ��ĺ���
    loc_x = x;
    loc_y = y;
    if (!(x == ROBOT_X - 15 && y == ROBOT_Y) && health > 0)//����δ�ƶ����ܲ���λ���ҹ���δ����
    {    
        setHealth(health*10);
        // ������Ķ������У�����ʹ�� MoveBy ��Ϊʾ��
        auto moveAction = cocos2d::MoveBy::create(speed, cocos2d::Vec2(n_x, n_y));

        // �����������У������ƶ��������ڶ������ʱ���� CallFunc �Ĳ���
        auto sequence = cocos2d::Sequence::create(
            moveAction,
            cocos2d::CallFunc::create([this]() {
                cocos2d::Vec2 spritePosition = this->getPosition();
                if (spritePosition.x == 1024 - ROBOT_X && spritePosition.y > SIGN_1_Y)
                    this->move(spritePosition.x, spritePosition.y, 0, -1);  // �ݹ�����Լ�
                if (spritePosition.x >= 1024 - ROBOT_X && spritePosition.x < SIGN_2_X && spritePosition.y == SIGN_1_Y)
                    this->move(spritePosition.x, spritePosition.y, 1, 0);  // �ݹ�����Լ�
                if (spritePosition.x == SIGN_2_X && spritePosition.y >= SIGN_1_Y && spritePosition.y < SIGN_2_Y)
                    this->move(spritePosition.x, spritePosition.y, 0, 1);  // �ݹ�����Լ�
                if (spritePosition.x < 1024 - SIGN_2_X - 15 && spritePosition.x >= SIGN_2_X && spritePosition.y == SIGN_2_Y)
                    this->move(spritePosition.x, spritePosition.y, 1, 0);  // �ݹ�����Լ�
                if (spritePosition.x == 1024 - SIGN_2_X - 15 && spritePosition.y > SIGN_1_Y && spritePosition.y <= SIGN_2_Y)
                    this->move(spritePosition.x, spritePosition.y, 0, -1);  // �ݹ�����Լ�
                if (spritePosition.x >= 1024 - SIGN_2_X - 15 && spritePosition.y == SIGN_1_Y && spritePosition.x < ROBOT_X - 15)
                    this->move(spritePosition.x, spritePosition.y, 1, 0);  // �ݹ�����Լ�
                if (spritePosition.x == ROBOT_X - 15)
                    this->move(spritePosition.x, spritePosition.y, 0, 1);  // �ݹ�����Լ�
                }),
            nullptr
                    );

        // �� Monster ���������ж�������
        this->runAction(sequence);
    }
    else {
        if (x == ROBOT_X - 15 && y == ROBOT_Y) { //�����ƶ����ܲ�λ�ã������ܲ�״̬
            auto fScene = dynamic_cast<FlyScene*>(this->getScene());
            if (fScene) {
                fScene->updateCarrot();
            }
            die();//������ʧ
        }
    }
}
void Monster::takeDamage(int damage)
{
    //�������˺����߼�ʵ��
    health -= damage;
    if (health <= 0)
    {
        auto flyScene = dynamic_cast<FlyScene*>(this->getScene());
        flyScene->wealth += 50;
        die();
        //��������ֵС��0����ʧ����һ�ý��
    }
}

void Monster::die()
{
    // ���ر��������ļ�
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("2.mp3");
    // ���ű�������
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("2.mp3", false);
    isAlive = false;
    auto flyScene = dynamic_cast<FlyScene*>(this->getScene());
    if (flyScene) {
        for (auto it = flyScene->monsterList.begin(); it != flyScene->monsterList.end(); ) {
            Monster* towers = *it;

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