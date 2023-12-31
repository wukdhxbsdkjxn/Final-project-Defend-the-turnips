#ifndef __MONSTER_H__
#define __MONSTER_H__
#include "cocos2d.h"
#include "FlyScene.h"

#define ROBOT_X 905
#define ROBOT_Y 480
#define SIGN_1_Y 220
#define SIGN_2_X 370
#define SIGN_2_Y 295
class Monster : public cocos2d::Sprite {
public:
    float getspeed(){return speed;}
    int gethealth() { return health; }
    Monster();
    virtual ~Monster();

    // 初始化怪兽
    virtual bool init(int n);

    // 创建怪兽实例的静态方法
    static Monster* create(int n);

    // 怪兽移动方法
    void move(float x, float y, float n_x, float n_y);

    // 怪兽受伤方法
    void takeDamage(int damage=0);

    // 怪兽死亡方法
    void die();
    void Monster::setHealth(float healthPercentage) {
        // 设置血条的百分比
        healthBar->setPercentage(healthPercentage);
    }
    //怪物初始存活状态
    bool isAlive = true;

    //怪物的初始位置坐标
    float loc_x = 9999999;
    float loc_y = 9999999;

private:
    
    int health;//怪物生命值
    float speed;//怪物移动速度
    cocos2d::ProgressTimer* healthBar;
};

#endif
