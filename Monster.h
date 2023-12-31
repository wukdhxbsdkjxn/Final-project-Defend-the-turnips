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

    // ��ʼ������
    virtual bool init(int n);

    // ��������ʵ���ľ�̬����
    static Monster* create(int n);

    // �����ƶ�����
    void move(float x, float y, float n_x, float n_y);

    // �������˷���
    void takeDamage(int damage=0);

    // ������������
    void die();
    void Monster::setHealth(float healthPercentage) {
        // ����Ѫ���İٷֱ�
        healthBar->setPercentage(healthPercentage);
    }
    //�����ʼ���״̬
    bool isAlive = true;

    //����ĳ�ʼλ������
    float loc_x = 9999999;
    float loc_y = 9999999;

private:
    
    int health;//��������ֵ
    float speed;//�����ƶ��ٶ�
    cocos2d::ProgressTimer* healthBar;
};

#endif
