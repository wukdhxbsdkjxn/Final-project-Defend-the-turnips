//Tower.cpp

#include "Tower.h"

USING_NS_CC;

bool Tower::init(Type initialType) {
    if (!Sprite::initWithFile("bottlezero.png")) {
        return false;
    }

    // ���������ĳ�ʼ���ͺͼ���
    towerType = initialType;
    //level = 1;

    // ��ʼ����������������
    setAnchorPoint(Vec2(0.5, 0.5)); // ����ê��Ϊ����
    setScale(0.8); // �������ű���

    // �������ͺͼ����������������
    updateAppearance();

    return true;
}

Tower* Tower::create(Tower::Type towerType) {
    //��������
    Tower* tower = new (std::nothrow) Tower();
    if (tower && tower->init(towerType)) {
        tower->autorelease();
        return tower;
    }
    else {
        //ɾ������
        delete tower;
        return nullptr;
    }
}

void Tower::setType(Type type) {
    //�����������ࡢ�ȼ���״̬
    towerType = type;
    //����type�ڻ����з�������ͼƬ
    updateAppearance();
}

void Tower::upgrade() {
    //����������������ͼƬ��ʾ
    level++;
    updateAppearance();
}

void Tower::updateAppearance() {
    // �������ͺͼ���������������
    // ���磬���Ը��ݲ�ͬ�����ͺͼ������ò�ͬ�������ߴ��

    std::string textureFilename = "";
    switch (towerType) {
    case Type::BasicBottle:
        textureFilename = "bottlezero.png";
        break;
    case Type::BetterBottle:
        textureFilename = "bottle_better.png";
        break;
    case Type::BestBottle:
        textureFilename = "bottle_best.png";
        break;
    case Type::BasicPin:
        textureFilename = "pinzero.png";
        break;
    case Type::BetterPin:
        textureFilename = "pin_better.png";
        break;
    case Type::BestPin:
        textureFilename = "pin_best.png";
        break;
    case Type::BasicShit:
        textureFilename = "shitzero.png";
        break;
    case Type::BetterShit:
        textureFilename = "better_shit.png";
        break;
    case Type::BestShit:
        textureFilename = "best_shit.png";
        break;
   
    case Type::None:
        ;
        break;
    }

    if (!textureFilename.empty()) {
        setTexture(textureFilename);
    }

   
}



