#ifndef __FOREST_MONSTER_H__
#define __FOREST_MONSTER_H__
#include "cocos2d.h"
#include "ForestScene.h"

#define FOR_CARROT_X 830
#define FOR_CARROT_Y 120
#define MON_START_X 80
#define MON_START_Y 450
#define MON_1_X 770
#define MON_2_Y 280
#define MON_3_X 240
class ForMonster : public cocos2d::Sprite {
public:
    float getspeed() { return speed; }
    int gethealth() { return health; }
    ForMonster();
    virtual ~ForMonster();

    // 初始化怪兽
    virtual bool init(int n);

    // 创建怪兽实例的静态方法
    static ForMonster* create(int n);

    // 怪兽移动方法
    void move(float x, float y, float n_x, float n_y);

    // 怪兽受伤方法
    void takeDamage(int damage = 0);

    // 怪兽死亡方法
    void die();
    void ForMonster::setHealth(float healthPercentage) {
        // 设置血条的百分比
        healthBar->setPercentage(healthPercentage);
    }
    bool isAlive = true;
    float loc_x = 9999999;
    float loc_y = 9999999;

private:

    int health;
    float speed;
    cocos2d::ProgressTimer* healthBar;
};

#endif
