// Tower.h
#ifndef __TOWER_H__
#define __TOWER_H__

#include "cocos2d.h"
class Tower : public cocos2d::Sprite {
public:
    //炮塔的所有类型(包括种类和等级）
    enum class Type {
        BasicBottle,
        BasicShit,
        BetterBottle,
        BetterShit,
        BestBottle,
        BestShit,
        BasicPin,
        BetterPin,       
        BestPin,

        None
    };
    //初始化炮塔
    virtual bool init(Type towerType);
    //创建炮塔
    static Tower* create(Type towerType);
    //设置炮塔类型
    void setType(Type type);
    //炮塔升级
    void upgrade();
    //炮塔外观展示，例如升级后需改变外观
    void updateAppearance();
    //炮塔位置
    float tower_locx;
    float tower_locy;
    //炮塔攻击范围
    float distance;
    //炮塔伤害值
    int hurt;
    int type;
    long long time = 0;
    //炮塔等级
    int level;
private:
    //炮塔类型
    Type towerType;
};

#endif // __TOWER_H__