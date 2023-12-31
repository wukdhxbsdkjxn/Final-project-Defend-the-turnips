#ifndef __TOWER_MANAGER_H__
#define __TOWER_MANAGER_H__

#include "cocos2d.h"
#include "Tower.h"


class TowerManager : public cocos2d::Node {
public:
    CREATE_FUNC(TowerManager);

    //初始化
    bool init() override;
    //选择炮塔种类的选项
    void showTowerOptions(const cocos2d::Vec2& position);
    //点击BOTTLE后出现升级或删除选项
    void showUP_BOTTLEOptions(const cocos2d::Vec2& position, const int& time);
    //点击SHIT后出现升级或删除选项
    void showUP_SHITOptions(const cocos2d::Vec2& position, const int& time);
    //创建BOTTLE升级或删除选项
    void createUP_BOTTLEOptions(const cocos2d::Vec2& position, const int& time);
    //创建SHIT升级或删除选项
    void createUP_SHITOptions(const cocos2d::Vec2& position, const int& time);
    void removeTowerAtPosition(const cocos2d::Vec2& position);
    //创建SHIT炮塔
    void createshitTower(const cocos2d::Vec2& position, const int& time);
    //创建BOTTLE炮塔
    void createbottleTower(const cocos2d::Vec2& position, const int& time);
    //创建炮塔选项
    void createOptions(const cocos2d::Vec2& position);
    //删除选项
    void DELETETOptions(const cocos2d::Vec2& position);
    bool onTouchBegan(const cocos2d::Touch* touch, const cocos2d::Event* event);
    void removeTowerOptions();
    void noTower();
private:

    struct TowerOptions {
        cocos2d::Menu* build;
        cocos2d::Menu* up;
        cocos2d::Menu* remove;
    };
    TowerOptions options;
    int time = 0;
    cocos2d::Sprite* selectedTower;
    Tower::Type selectedTowerType;
    cocos2d::Vec2 optionsPosition;

};

#endif // __TOWER_MANAGER
