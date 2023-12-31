// Tower.h
#ifndef __TOWER_H__
#define __TOWER_H__

#include "cocos2d.h"
class Tower : public cocos2d::Sprite {
public:
    //��������������(��������͵ȼ���
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
    //��ʼ������
    virtual bool init(Type towerType);
    //��������
    static Tower* create(Type towerType);
    //������������
    void setType(Type type);
    //��������
    void upgrade();
    //�������չʾ��������������ı����
    void updateAppearance();
    //����λ��
    float tower_locx;
    float tower_locy;
    //����������Χ
    float distance;
    //�����˺�ֵ
    int hurt;
    int type;
    long long time = 0;
    //�����ȼ�
    int level;
private:
    //��������
    Type towerType;
};

#endif // __TOWER_H__