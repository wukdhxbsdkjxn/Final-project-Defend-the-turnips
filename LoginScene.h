#ifndef __LOGIN_SCENE_H__
#define __LOGIN_SCENE_H__
#include "cocos2d.h"
#include "FlyScene.h"
class LoginScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createLoginScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void menuStartCallback(cocos2d::Ref* pSender);
    // implement the "static create()" method manually
    CREATE_FUNC(LoginScene);
};
class LoginChoiceScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createChoiceLoginScene();
    virtual bool init();
    void menuCloseCallback(cocos2d::Ref* pSender);
    void menu_fly(cocos2d::Ref* pSender);
    void menu_forest(cocos2d::Ref* pSender);
    CREATE_FUNC(LoginChoiceScene);
};
#endif
