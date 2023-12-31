#ifndef __FORTOWER_MANAGER_H__
#define __FORTOWER_MANAGER_H__

#include "cocos2d.h"
#include "Tower.h"


class ForTowerManager : public cocos2d::Node {
public:
    CREATE_FUNC(ForTowerManager);

    bool init() override;
    void showTowerOptions(const cocos2d::Vec2& position);
    void showUP_BOTTLEOptions(const cocos2d::Vec2& position, const int& time);
    void showUP_SHITOptions(const cocos2d::Vec2& position, const int& time);
    void showUP_PINOptions(const cocos2d::Vec2& position, const int& time);
    void createUP_BOTTLEOptions(const cocos2d::Vec2& position, const int& time);
    void createUP_SHITOptions(const cocos2d::Vec2& position, const int& time);
    void createUP_PINOptions(const cocos2d::Vec2& position, const int& time);
    void removeTowerAtPosition(const cocos2d::Vec2& position);
    void createshitTower(const cocos2d::Vec2& position, const int& time);
    void createbottleTower(const cocos2d::Vec2& position, const int& time);
    void createpinTower(const cocos2d::Vec2& position, const int& time);
    void createOptions(const cocos2d::Vec2& position);
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

#endif // __TOWER_MANAGER_H__
