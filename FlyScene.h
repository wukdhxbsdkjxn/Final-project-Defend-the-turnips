#ifndef __FLY_SCENE_H__
#define __FLY_SCENE_H__
#include "cocos2d.h"
#include "LoginScene.h"
#include "Monster.h"
#include "TowerManager.h"
#include "Tower.h"
class Monster;
class Tower;
class FlyScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createFlyScene();

    virtual bool init();
    int loc_return(float x, float y);
    float Location_x(float x, float y);
    float Location_y(float x, float y);
    void registerMouseEvents();
    bool onMouseDown(cocos2d::EventMouse* event);
    void showClickAnimation(float x, float y, cocos2d::EventMouse* event);
    void menuCloseCallback(cocos2d::Ref* pSender);
    void menuStop(cocos2d::Ref* pSender);
    void menureturn(cocos2d::Ref* pSender);
    void menurestart(cocos2d::Ref* pSender);
    void menuchoice(cocos2d::Ref* pSender);
    void createMasterRunSprite(int choice);
    void create_monster(int i,int num);
    int pos_judge(float x, float y);
    cocos2d::Vec2 showAreaAnimation(float x, float y, cocos2d::EventMouse* event);
    void updateCountdown(float dt) ;
    void updateMonsterNum();
    void updateCarrot();
    void SetBarrier();
    void CarrotMove();
    void GameOver(bool win);
    void update(float dt);
    bool tower = false;
    void tower_change(int locs, int sit, int kind);
    bool location_judge(float monster_x, float monster_y, float tower_x, float tower_y, float distance);
    int my_loc[24][2] = { 0 };
    int monster_group = 4;
    std::vector<Monster*> monsterList;
    std::vector<Tower*> towerList;
    int wealth = 500;
    void showTowerAttack(cocos2d::Vec2 towerposion, cocos2d::Vec2 monsterposion, int type);
    cocos2d::Label* Wealth;
    void TowerAttack(cocos2d::Vec2 targetmonsterPosition, Tower* tower);
    CREATE_FUNC(FlyScene);
private:
    int clickCount = 0;  // 记录点击次数
    int carrot_life = 10;
    int monster_num;
    int countdown;
   
    cocos2d::Label* label;
    cocos2d::Label* monster_label;
    cocos2d::ProgressTimer* healthBar;
    // 显示得分的标签
    cocos2d::Label* lifeLabel;
    cocos2d::Label* WealthLabel;
   
    bool isPaused=false; // 表示游戏是否暂停
    cocos2d::Menu* return_menu;
    cocos2d::Sprite* return_sprite;
    cocos2d::Menu* restart_sprite;
    cocos2d::Menu* rechoice_sprite;
    TowerManager* towerManager;////////炮
    
};

#endif

