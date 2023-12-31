#ifndef __FOREST_SCENE_H__
#define __FOREST_SCENE_H__
#include "cocos2d.h"
#include "LoginScene.h"
#include "ForestMonster.h"
#include "ForestTowerManager.h"
#include "Tower.h"
class ForMonster;
class Tower;
class ForestScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createForestScene();
    virtual bool init();
    void menuCloseCallback(cocos2d::Ref* pSender);
    void menuStop(cocos2d::Ref* pSender);
    void menureturn(cocos2d::Ref* pSender);
    void menurestart(cocos2d::Ref* pSender);
    void menuchoice(cocos2d::Ref* pSender);
    void updateCountdown(float dt);
    void create_monster(int i, int num);
    void createMasterRunSprite(int choice);
    int wealth = 500;
    std::vector<ForMonster*> monsterList;
    void updateMonsterNum();
    void updateCarrot();
    void GameOver(bool win);
    int monster_group = 4;
    int my_loc[24][2] = { 0 };
    int loc_return(float x, float y);
    float Location_x(float x, float y);
    float Location_y(float x, float y);
    int pos_judge(float x, float y);
    void registerMouseEvents();
    bool onMouseDown(cocos2d::EventMouse* event);
    bool tower = false;
    std::vector<Tower*> towerList;
    void CarrotMove();
    void showClickAnimation(float x, float y, cocos2d::EventMouse* event);
    cocos2d::Vec2 showAreaAnimation(float x, float y, cocos2d::EventMouse* event);
    bool location_judge(float monster_x, float monster_y, float tower_x, float tower_y, float distance);
    void SetBarrier();
    void update(float dt);
    void tower_change(int locs, int sit, int kind);
    void showTowerAttack(cocos2d::Vec2 towerposion, cocos2d::Vec2 monsterposion, int type);
    void TowerAttack(cocos2d::Vec2 targetmonsterPosition, Tower* tower);

    CREATE_FUNC(ForestScene);
private:
    int clickCount = 0;  // 记录点击次数
    cocos2d::ProgressTimer* healthBar;
    // 显示得分的标签
    int carrot_life = 10;
    int monster_num;
    cocos2d::Label* label;
    int countdown;
    bool isPaused = false; // 表示游戏是否暂停
    cocos2d::Label* lifeLabel;
    cocos2d::Label* WealthLabel;
    cocos2d::Label* monster_label;
    ForTowerManager* TowerManager;/////////炮
    cocos2d::Menu* return_menu;
    cocos2d::Sprite* return_sprite;
    cocos2d::Menu* restart_sprite;
    cocos2d::Menu* rechoice_sprite;
};

#endif
