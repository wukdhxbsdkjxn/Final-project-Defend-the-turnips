//Tower.cpp

#include "Tower.h"

USING_NS_CC;

bool Tower::init(Type initialType) {
    if (!Sprite::initWithFile("bottlezero.png")) {
        return false;
    }

    // 设置炮塔的初始类型和级别
    towerType = initialType;
    //level = 1;

    // 初始化炮塔的其他属性
    setAnchorPoint(Vec2(0.5, 0.5)); // 设置锚点为中心
    setScale(0.8); // 设置缩放比例

    // 根据类型和级别设置炮塔的外观
    updateAppearance();

    return true;
}

Tower* Tower::create(Tower::Type towerType) {
    //创建炮塔
    Tower* tower = new (std::nothrow) Tower();
    if (tower && tower->init(towerType)) {
        tower->autorelease();
        return tower;
    }
    else {
        //删除炮塔
        delete tower;
        return nullptr;
    }
}

void Tower::setType(Type type) {
    //设置炮塔种类、等级的状态
    towerType = type;
    //根据type在画面中放置炮塔图片
    updateAppearance();
}

void Tower::upgrade() {
    //炮塔升级，并更新图片显示
    level++;
    updateAppearance();
}

void Tower::updateAppearance() {
    // 根据类型和级别更新炮塔的外观
    // 例如，可以根据不同的类型和级别设置不同的纹理、尺寸等

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



