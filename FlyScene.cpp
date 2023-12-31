#include "SimpleAudioEngine.h"
#include "FlyScene.h"
#include "TowerManager.h"
#include "Tower.h"
#include "LoginScene.h"

#define ROBOT_X 905
#define ROBOT_Y 480
#define SIGN_1_Y 220
#define SIGN_2_X 370
#define SIGN_2_Y 295
#define POS_1_Y 240
#define POS_1_X 830//����
#define POS_2_X 690//����
#define POS_3_X 334//����
#define POS_4_X 194//����
#define POS_5_X 337//������
#define POS_6_X 687//������
#define POS_7_X 440//������
#define POS_2_Y 220//������
#define BOARD_SIZE 70

USING_NS_CC;
Scene* FlyScene::createFlyScene()
{
    return FlyScene::create();
}
int FlyScene::loc_return(float x, float y) {
    
    int jug_1 = 0, jug_2 = 0, jug_3 = 0, jug_4 = 0;
    if (x >= POS_4_X && x <= POS_3_X && y >= POS_1_Y && y <= POS_1_Y + 3 * BOARD_SIZE)
        jug_1 = 1;
    if (x >= POS_5_X && x <= POS_6_X && y >= POS_1_Y + BOARD_SIZE && y <= POS_1_Y + 3 * BOARD_SIZE)
        jug_2 = 1;
    if (x >= POS_2_X && x <= POS_1_X && y >= POS_1_Y && y <= POS_1_Y + 3 * BOARD_SIZE)
        jug_3 = 1;
    if (x >= POS_7_X && x <= POS_7_X + 2 * BOARD_SIZE && y >= POS_2_Y - BOARD_SIZE && y <= POS_2_Y)
        jug_4 = 1;
    if (jug_1 == 1 || jug_2 == 1 || jug_3 == 1 || jug_4 == 1) {
        if (jug_1 == 1) {
            const int loc = (y - POS_1_Y) / BOARD_SIZE;
            if (loc == 0) {
                if (x <= POS_4_X + BOARD_SIZE)
                    return 0;
                else
                    return 1;
            }
            if (loc == 1) {
                if (x <= POS_4_X + BOARD_SIZE)
                    return 2;
                else
                    return 3;
            }
            if (loc == 2) {
                if (x <= POS_4_X + BOARD_SIZE)
                    return 4;
                else
                    return 5;
            }

        }
        if (jug_2 == 1) {
            const int loc = (x - POS_5_X) / BOARD_SIZE;
            if (loc == 0) {
                if (y <= POS_1_Y + 2 * BOARD_SIZE)
                    return 6;
                else
                    return 7;
            }
            if (loc == 1) {
                if (y <= POS_1_Y + 2 * BOARD_SIZE)
                    return 8;
                else
                    return 9;
            }
            if (loc == 2) {
                if (y <= POS_1_Y + 2 * BOARD_SIZE)
                    return 10;
                else
                    return 11;
            }
            if (loc == 3) {
                if (y <= POS_1_Y + 2 * BOARD_SIZE)
                    return 12;
                else
                    return 13;
            }
            if (loc == 4) {
                if (y <= POS_1_Y + 2 * BOARD_SIZE)
                    return 14;
                else
                    return 15;
            }
        }
        if (jug_3 == 1) {
            const int loc = (y - POS_1_Y) / BOARD_SIZE;
            if (loc == 0) {
                if (x <= POS_2_X + BOARD_SIZE)
                    return 16;
                else
                    return 17;
            }
            if (loc == 1) {
                if (x <= POS_2_X + BOARD_SIZE)
                    return 18;
                else
                    return 19;
            }
            if (loc == 2) {
                if (x <= POS_2_X + BOARD_SIZE)
                    return 20;
                else
                    return 21;
            }
        }
        if (jug_4 == 1) {
            if (x <= POS_7_X + BOARD_SIZE)
                return 22;
            else
                return 23;
        }
        return -1;
    }
    else
        return -1;
}
int FlyScene::pos_judge(float x, float y) {
    //�ж�λ��
    if (x >= ROBOT_X - 20 && x <= ROBOT_X + 20 && y >= ROBOT_Y - 50 && y <= ROBOT_Y + 20)
        return 10;
    if (x <= ROBOT_X - 20 && x >= 1024-ROBOT_X + 20 && y >= 576-60 && y <= 576)
        return 20;
    int jug_1 = 0, jug_2 = 0, jug_3 = 0, jug_4 = 0;
    if (x >= POS_4_X && x <= POS_3_X && y >= POS_1_Y && y <= POS_1_Y + 3 * BOARD_SIZE)
        jug_1 = 1;
    if (x >= POS_5_X && x <= POS_6_X && y >= POS_1_Y+ BOARD_SIZE && y <= POS_1_Y + 3 * BOARD_SIZE)
        jug_2 = 1;
    if (x >= POS_2_X && x <= POS_1_X && y >= POS_1_Y  && y <= POS_1_Y + 3 * BOARD_SIZE)
        jug_3 = 1;
    if (x >= POS_7_X && x <= POS_7_X +2* BOARD_SIZE && y >= POS_2_Y- BOARD_SIZE && y <= POS_2_Y)
        jug_4 = 1;
    if (jug_1 == 1 || jug_2 == 1 || jug_3 == 1 || jug_4 == 1) {
        if (jug_1 == 1) {
            const int loc = (y - POS_1_Y) / BOARD_SIZE;
            if (loc == 0) {
                if (x <= POS_4_X + BOARD_SIZE)
                    return my_loc[0][0];
                else
                    return my_loc[1][0];
            }
            if (loc == 1) {
                if (x <= POS_4_X + BOARD_SIZE)
                    return my_loc[2][0];
                else
                    return my_loc[3][0];
            }
            if (loc == 2) {
                if (x <= POS_4_X + BOARD_SIZE)
                    return my_loc[4][0];
                else
                    return my_loc[5][0];
            }
            
        }
        if (jug_2 == 1) {
            const int loc = (x - POS_5_X) / BOARD_SIZE;
            if (loc == 0) {
                if (y <= POS_1_Y + 2*BOARD_SIZE)
                    return my_loc[6][0];
                else 
                    return my_loc[7][0];
            }
            if (loc == 1) {
                if (y <= POS_1_Y + 2 * BOARD_SIZE)
                    return my_loc[8][0];
                else
                    return my_loc[9][0];
            }
            if (loc == 2) {
                if (y <= POS_1_Y + 2 * BOARD_SIZE)
                    return my_loc[10][0];
                else
                    return my_loc[11][0];
            }
            if (loc == 3) {
                if (y <= POS_1_Y + 2 * BOARD_SIZE)
                    return my_loc[12][0];
                else
                    return my_loc[13][0];
            }
            if (loc == 4) {
                if (y <= POS_1_Y + 2 * BOARD_SIZE)
                    return my_loc[14][0];
                else
                    return my_loc[15][0];
            }
        }
        if (jug_3 == 1) {
            const int loc = (y - POS_1_Y) / BOARD_SIZE;
            if (loc == 0) {
                if (x <= POS_2_X + BOARD_SIZE)
                    return my_loc[16][0];
                else
                    return my_loc[17][0];
            }
            if (loc == 1) {
                if (x <= POS_2_X + BOARD_SIZE)
                    return my_loc[18][0];
                else
                    return my_loc[19][0];
            }
            if (loc == 2) {
                if (x <= POS_2_X + BOARD_SIZE)
                    return my_loc[20][0];
                else
                    return my_loc[21][0];
            }
        }
        if (jug_4 == 1) {
                if (x <= POS_7_X + BOARD_SIZE)
                    return my_loc[22][0];
                else
                    return my_loc[23][0];
        }
        return -1;
    }
    else
        return -1;
}
float FlyScene::Location_y(float x, float y) {
    float Y = 0;
    int jug_1 = 0, jug_2 = 0, jug_3 = 0, jug_4 = 0;
    if (x >= POS_4_X && x <= POS_3_X && y >= POS_1_Y && y <= POS_1_Y + 3 * BOARD_SIZE)
        jug_1 = 1;
    if (x >= POS_5_X && x <= POS_6_X && y >= POS_1_Y + BOARD_SIZE && y <= POS_1_Y + 3 * BOARD_SIZE)
        jug_2 = 1;
    if (x >= POS_2_X && x <= POS_1_X && y >= POS_1_Y && y <= POS_1_Y + 3 * BOARD_SIZE)
        jug_3 = 1;
    if (x >= POS_7_X && x <= POS_7_X + 2 * BOARD_SIZE && y >= POS_2_Y - BOARD_SIZE && y <= POS_2_Y)
        jug_4 = 1;
    if (jug_1 == 1||jug_3==1) {
        const int loc = (y - POS_1_Y) / BOARD_SIZE;
        if (loc == 0) {
            Y = POS_1_Y + BOARD_SIZE / 2;
        }
        if (loc == 1) {
            Y = POS_1_Y + BOARD_SIZE*3 / 2;
        }
        if (loc == 2) {
            Y = POS_1_Y + BOARD_SIZE*5 / 2;
        }

    }
    if (jug_2 == 1) {
        if (y <= POS_1_Y + 2 * BOARD_SIZE)
            Y = POS_1_Y + BOARD_SIZE + BOARD_SIZE / 2;
        else
            Y = POS_1_Y + BOARD_SIZE + BOARD_SIZE * 3 / 2;
    }
    if (jug_4 == 1) {
        Y = POS_2_Y - BOARD_SIZE / 2;
    }
    return Y;
}
float FlyScene::Location_x(float x, float y) {
    float X = 0;
    int jug_1 = 0, jug_2 = 0, jug_3 = 0, jug_4 = 0;
    if (x >= POS_4_X && x <= POS_3_X && y >= POS_1_Y && y <= POS_1_Y + 3 * BOARD_SIZE)
        jug_1 = 1;
    if (x >= POS_5_X && x <= POS_6_X && y >= POS_1_Y + BOARD_SIZE && y <= POS_1_Y + 3 * BOARD_SIZE)
        jug_2 = 1;
    if (x >= POS_2_X && x <= POS_1_X && y >= POS_1_Y && y <= POS_1_Y + 3 * BOARD_SIZE)
        jug_3 = 1;
    if (x >= POS_7_X && x <= POS_7_X + 2 * BOARD_SIZE && y >= POS_2_Y - BOARD_SIZE && y <= POS_2_Y)
        jug_4 = 1;
    if (jug_1 == 1) {
            if (x <= POS_4_X + BOARD_SIZE)
                X=POS_4_X + BOARD_SIZE/2;
            else
                X = POS_4_X + BOARD_SIZE*3 / 2;
    }
    if (jug_2 == 1) {
        const int loc = (x - POS_5_X) / BOARD_SIZE;
        if (loc == 0) {
            X= POS_5_X+ BOARD_SIZE / 2;
        }
        if (loc == 1) {
            X = POS_5_X + BOARD_SIZE*3 / 2;
        }
        if (loc == 2) {
            X = POS_5_X + BOARD_SIZE*5 / 2;
        }
        if (loc == 3) {
            X = POS_5_X + BOARD_SIZE*7 / 2;
        }
        if (loc == 4) {
            X = POS_5_X + BOARD_SIZE*9 / 2;
        }
    }
    if (jug_3 == 1) {
            if (x <= POS_2_X + BOARD_SIZE)
                X = POS_2_X + BOARD_SIZE / 2; 
            else
                X = POS_2_X + BOARD_SIZE*3 / 2;
    }
    if (jug_4 == 1) {
        if (x <= POS_7_X + BOARD_SIZE)
            X= POS_7_X + BOARD_SIZE/2;
        else
            X = POS_7_X + BOARD_SIZE *3/ 2;
    }
    return X;
}
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
void FlyScene::SetBarrier() {
    //�ڵ�ͼ�з����ϰ���
    Monster* barrier = Monster::create(4);
    barrier->setPosition(POS_4_X + BOARD_SIZE / 2, POS_1_Y + BOARD_SIZE / 2);
    my_loc[0][0] = -2;
    this->addChild(barrier, 1);
    Monster* barrier1 = Monster::create(5);
    barrier1->setPosition(POS_5_X + BOARD_SIZE / 2, POS_1_Y + BOARD_SIZE + BOARD_SIZE / 2);
    my_loc[6][0] = -2;
    this->addChild(barrier1, 1);
    Monster* barrier2 = Monster::create(6);
    barrier2->setPosition(POS_7_X + BOARD_SIZE, POS_2_Y - BOARD_SIZE / 2);
    my_loc[22][0] = -2;
   my_loc[23][0] = -2;
    this->addChild(barrier2, 1);
    Monster* barrier3 = Monster::create(4);
    barrier3->setPosition(POS_1_X - BOARD_SIZE / 2, POS_1_Y + BOARD_SIZE / 2);
    my_loc[14][0] = -2;
    this->addChild(barrier3, 1);
    Monster* barrier4 = Monster::create(5);
    barrier4->setPosition(POS_5_X +4* BOARD_SIZE+ BOARD_SIZE / 2, POS_1_Y + BOARD_SIZE + BOARD_SIZE / 2);
    my_loc[17][0] = -2;
    this->addChild(barrier4, 1);
}
bool FlyScene::init()
{

    if (!Scene::init())
    {
        return false;
    }
    towerManager = TowerManager::create();  // ��ʼ��towerManager 
    addChild(towerManager);  // ���towerManager������ 
   
    const auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto fly_closeItem = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(FlyScene::menuCloseCallback, this));

    if (fly_closeItem == nullptr ||
        fly_closeItem->getContentSize().width <= 0 ||
        fly_closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        const float x = origin.x + visibleSize.width - fly_closeItem->getContentSize().width / 2;
        const float y = origin.y + fly_closeItem->getContentSize().height / 2;
        fly_closeItem->setPosition(Vec2(x, y));
    }


    auto menu = Menu::create(fly_closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    auto sprite = Sprite::create("12.png");
    if (sprite == nullptr)
    {
        problemLoading("'1.png'");
    }
    else
    {
        sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
        this->addChild(sprite, -1);
    }
    auto route_sprite = Sprite::create("13.png");
    if (route_sprite == nullptr)
    {
        problemLoading("'1.png'");
    }
    else
    {
        route_sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y-52));
        this->addChild(route_sprite, -1);
    }
    //������Ŀ
    auto scene_sprite = Sprite::create("26.png");
    scene_sprite->setPosition(Vec2(1024/2, 576-23));
    this->addChild(scene_sprite, -1);


    //�����ܲ�
    auto carrot_sprite = Sprite::create("14.png");
    carrot_sprite->setPosition(Vec2(ROBOT_X, ROBOT_Y));
    this->addChild(carrot_sprite, 0);

    //�����ܲ�����ֵ
    auto carrot_live = Sprite::create("25.png");
    carrot_live->setPosition(Vec2(ROBOT_X+40, ROBOT_Y));
    this->addChild(carrot_live, 1);
    
    // ��ʼ����ǩ
    lifeLabel = Label::createWithTTF(" 10", "fonts/Marker Felt.ttf", 24);
    if (lifeLabel)
    {
        lifeLabel->setPosition(Vec2(ROBOT_X+60, ROBOT_Y));
        this->addChild(lifeLabel, 1);
    }

    // ��ʼ����ǩ
    monster_label = Label::createWithTTF("Monster Group : 1/5", "fonts/Marker Felt.ttf", 24);
    if (monster_label)
    {
        monster_label->setPosition(Vec2(1024/2, 576-18));
        this->addChild(monster_label, 1);
    }


    // ��ʾ���
    WealthLabel = Label::createWithTTF("500", "fonts/Marker Felt.ttf", 24);
    if (WealthLabel)
    {
        WealthLabel->setPosition(Vec2(1024 / 2-200, 576 - 18));
        this->addChild(WealthLabel, 1);
    }
   
    //������ͣ��ť
    auto stop_closeItem = MenuItemImage::create(
        "29.png",
        "30.png",
        CC_CALLBACK_1(FlyScene::menuStop, this));

    if (stop_closeItem == nullptr ||
        stop_closeItem->getContentSize().width <= 0 ||
        stop_closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        const float x = visibleSize.width/2+250;
        constexpr float y =576-20;
        stop_closeItem->setPosition(Vec2(x, y));
    }


    auto menu1 = Menu::create(stop_closeItem, NULL);
    menu1->setPosition(Vec2::ZERO);
    this->addChild(menu1, 1);


    //���������
    auto wealth_sprite = Sprite::create("27.png");
    wealth_sprite->setPosition(Vec2(1024 / 2 - 250, 576 - 18));
    this->addChild(wealth_sprite, 0);

    //����������
    auto sign_sprite = Sprite::create("15.png");
    sign_sprite->setPosition(Vec2(visibleSize.width - ROBOT_X, ROBOT_Y));
    this->addChild(sign_sprite, 0);
    /*������ʾ����ʱ*/
    // ��ʼ������ʱ����
    countdown = 3;

    // ���� Label�������ó�ʼ͸����Ϊ 255
    label = cocos2d::Label::createWithTTF(std::to_string(countdown), "fonts/Marker Felt.ttf", 150);
    label->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
    this->addChild(label);
    // ������ʱ����ÿ�����һ�ε���ʱ
    this->schedule(CC_SCHEDULE_SELECTOR(FlyScene::updateCountdown), 1.0f, countdown - 1, 0);

   
    // ע��������¼�
    registerMouseEvents();
    
    SetBarrier();
    this->scheduleUpdate();

   
    return true;
}
void FlyScene::updateCountdown(float dt)
{
    // ���µ���ʱ����
    countdown--;

    // ������������
    auto fadeOut = cocos2d::FadeOut::create(0.5f);

    // ����һ��˳��������ִ�е���������Ȼ���Ƴ� Label
    auto sequence = cocos2d::Sequence::create(fadeOut, cocos2d::RemoveSelf::create(), nullptr);

    // �������ʱΪ 0��ִ�е�������
    if (countdown == 0)
    {
        label->runAction(sequence);
        monster_num = 5;
        create_monster(3, monster_num);
        // �����������ӵ���ʱ��������߼�
    }
    else
    {
        // ���� Label ��ʾ������
        label->setString(std::to_string(countdown));
    }
}
void FlyScene::registerMouseEvents()
{
    auto mouseListener = cocos2d::EventListenerMouse::create();

    // ��갴��ʱ�Ļص�����
    mouseListener->onMouseDown = CC_CALLBACK_1(FlyScene::onMouseDown, this);

    // ����������ӵ��¼��ַ���
    _eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);
}
bool FlyScene::onMouseDown(cocos2d::EventMouse* event)
{
    if (isPaused) {
        // �����Ϸ��ͣ��������ͣ���洦�����¼�
        const EventMouse* e = dynamic_cast<EventMouse*>(event);
        if (e) {
            Vec2 clickLocation = Vec2(e->getCursorX(), e->getCursorY());


        }
    }
    else {
        const float mouseX = event->getCursorX();
        const float mouseY = event->getCursorY();
        const float set_x = Location_x(mouseX, mouseY);
        const float set_y = Location_y(mouseX, mouseY);

        if (tower == false) {
            if (pos_judge(mouseX, mouseY) == 0) {
                tower = true;
                // �ڿ�λ����ʾ����
                // ����ѡ��
                cocos2d::Vec2 spritePosition = showAreaAnimation(mouseX, mouseY, event);

            }
            // ���� pos_judge �ķ���ֵ����ͬ���
            if (pos_judge(mouseX, mouseY) == -1) {
                // �ڷǷ�λ����ʾ����
                showClickAnimation(mouseX, mouseY, event);
            }
            if (pos_judge(mouseX, mouseY) == -2) {
                for (auto child :this->getChildren())
                {
                    auto mon = dynamic_cast<Monster*>(child);
                    if (mon && mon->getBoundingBox().containsPoint(Vec2(set_x, set_y)))
                    {
                        mon->loc_x = set_x;
                        mon->loc_y = set_y;
                        bool choice = false;
                        for (auto its = towerList.begin(); its < towerList.end(); ++its) {
                            const Tower* towers = *its;
                            if (location_judge(mon->loc_x, mon->loc_y, towers->tower_locx, towers->tower_locy, towers->distance))
                                choice = true;
                            
                        }
                        if (choice) {
                            monsterList.push_back(mon);
                            monster_num++;
                            my_loc[loc_return(set_x, set_y)][0] = 0;
                            my_loc[loc_return(set_x, set_y)][1] = 0;
                            if (loc_return(set_x, set_y) == 22 || loc_return(set_x, set_y) == 23) {
                                my_loc[22][0] = 0;
                                my_loc[22][1] = 0;
                                my_loc[23][0] = 0;
                                my_loc[23][1] = 0;
                            }
                        }
                        break;  // ����ÿ��λ�����ֻ��һ���������ҵ����Ƴ�����˳�ѭ��
                    }
                }
            }
            if (pos_judge(mouseX, mouseY) == 1) {
                // ��1������λ����ʾ����
                // ����ѡ��
                if (my_loc[loc_return(mouseX, mouseY)][1] == 1) {
                    tower = true;
                    towerManager->showUP_BOTTLEOptions(Vec2(set_x, set_y), 1);
                }
                if (my_loc[loc_return(mouseX, mouseY)][1] == 2) {
                    tower = true;
                    towerManager->showUP_SHITOptions(Vec2(set_x, set_y), 1);
                }
            }
            if (pos_judge(mouseX, mouseY) == 2) {
                // ����ѡ��
                if (my_loc[loc_return(mouseX, mouseY)][1] == 1) {
                    tower = true;
                    towerManager->showUP_BOTTLEOptions(Vec2(set_x, set_y), 2);
                }
                if (my_loc[loc_return(mouseX, mouseY)][1] == 2) {
                    tower = true;
                    towerManager->showUP_SHITOptions(Vec2(set_x, set_y), 2);
                }
            }
            if (pos_judge(mouseX, mouseY) == 3) {
                // ��3������λ����ʾ����
                // �Ƴ�ѡ��
                tower = true;
                if (my_loc[loc_return(mouseX, mouseY)][1] == 1 || my_loc[loc_return(mouseX, mouseY)][1] == 2)
                    towerManager->DELETETOptions(Vec2(set_x, set_y));
                    
            }
            if (pos_judge(mouseX, mouseY) == 10) {
                // �ڵ��λ����ʾ����
                CarrotMove();
            }
        }
    }
    return true;
}

void FlyScene::CarrotMove() {
    auto sprite = Sprite::create();
    this->addChild(sprite,1);
    auto animation = Animation::create();
    for (int i = 1; i <= 6; ++i) {
        std::string frameName = StringUtils::format("f%d.png", i);
        animation->addSpriteFrameWithFileName(frameName);
    }
    animation->setDelayPerUnit(0.1f);  // ����ÿ֡�ĳ���ʱ��
    sprite->setPosition(Vec2(ROBOT_X, ROBOT_Y));
    auto animate = Animate::create(animation);
    auto callback = CallFunc::create([sprite]() {
        sprite->removeFromParent();  
        });
    auto sequence = Sequence::create(animate, callback, nullptr);
    // ���ж�������
    sprite->runAction(sequence);
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("4.mp3");
    // ���ű�������
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("4.mp3", false);
}
void FlyScene::showClickAnimation(float x, float y, cocos2d::EventMouse* event)
{
    // �������鲢���ö���
    auto sprite = cocos2d::Sprite::create("19.png");
    sprite->setPosition(x, y);
    this->addChild(sprite,1);

    // �������ź͵�����������
    auto fadeOutAction = cocos2d::FadeOut::create(0.5f);  // ����Ч��

    // �����������У��������ź͵�������
    auto sequence = cocos2d::Sequence::create(
        cocos2d::Spawn::create( fadeOutAction, nullptr),  // ͬʱ�������ź͵���
        cocos2d::RemoveSelf::create(),  // �Ƴ�����ڵ�
        nullptr
    );

    // �ھ��������ж�������
    sprite->runAction(sequence);
}
cocos2d::Vec2 FlyScene::showAreaAnimation(float x, float y, cocos2d::EventMouse* event)//������////////�������͸��ģ������������
{
    const auto dispatcher = Director::getInstance()->getEventDispatcher();


    // �������鲢���ö���
    auto sprite = cocos2d::Sprite::create("20.png");
    const float set_x = Location_x(x, y);
    const float set_y = Location_y(x, y);
    sprite->setPosition(set_x, set_y);
    this->addChild(sprite, 1);


    towerManager->showTowerOptions(Vec2(set_x, set_y));//��������////////////////
    ///��û��

     // �������ź͵�����������
    auto fadeOutAction = cocos2d::FadeOut::create(0.5f);  // ����Ч��

    // �����������У��������ź͵�������
    auto sequence = cocos2d::Sequence::create(
        cocos2d::Spawn::create(fadeOutAction, nullptr),  // ͬʱ�������ź͵���
        cocos2d::RemoveSelf::create(),  // �Ƴ�����ڵ�
        nullptr

    );

    // �ھ��������ж�������
    sprite->runAction(sequence);


    return cocos2d::Vec2(set_x, set_y);
}

void FlyScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
void FlyScene::menuStop(Ref* pSender)
{
    isPaused = true;
    Director::getInstance()->pause();
    auto sprite = cocos2d::Sprite::create("31.png");
    sprite->setPosition(1024/2, 576/2);
    this->addChild(sprite, 1);
    //������ͣ��ť
    auto return_closeItem = MenuItemImage::create(
        "32.png",
        "33.png",
        CC_CALLBACK_1(FlyScene::menureturn, this));

    if (return_closeItem == nullptr ||
        return_closeItem->getContentSize().width <= 0 ||
        return_closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        constexpr float x = 1024 / 2-10 ;
        constexpr float y = 576 /2+105;
        return_closeItem->setPosition(Vec2(x, y));
    }


    auto menu1 = Menu::create(return_closeItem, NULL);
    menu1->setPosition(Vec2::ZERO);
    this->addChild(menu1, 1);
    //�������¿�ʼ��ť
    auto restart_closeItem = MenuItemImage::create(
        "34.png",
        "35.png",
        CC_CALLBACK_1(FlyScene::menurestart, this));

    if (restart_closeItem == nullptr ||
        restart_closeItem->getContentSize().width <= 0 ||
        restart_closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        constexpr float x = 1024 / 2 - 10;
        constexpr float y = 576 / 2+10 ;
        restart_closeItem->setPosition(Vec2(x, y));
    }


    auto menu2 = Menu::create(restart_closeItem, NULL);
    menu2->setPosition(Vec2::ZERO);
    this->addChild(menu2, 1);
    //�����ؿ�ѡ��ť
    auto rechoice_closeItem = MenuItemImage::create(
        "36.png",
        "37.png",
        CC_CALLBACK_1(FlyScene::menuchoice, this));

    if (rechoice_closeItem == nullptr ||
        rechoice_closeItem->getContentSize().width <= 0 ||
        rechoice_closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        constexpr float x = 1024 / 2 - 10;
        constexpr float y = 576 / 2 - 85;
        rechoice_closeItem->setPosition(Vec2(x, y));
    }


    auto menu3 = Menu::create(rechoice_closeItem, NULL);
    menu3->setPosition(Vec2::ZERO);
    this->addChild(menu3, 1);
    return_menu=menu1;
    return_sprite = sprite;
    restart_sprite = menu2;
    rechoice_sprite = menu3;
 
}
void FlyScene::menureturn(Ref* pSender) {
    isPaused = false;
    Director::getInstance()->resume();
    return_menu->removeFromParent();
    return_sprite->removeFromParent();
    restart_sprite->removeFromParent();
    rechoice_sprite->removeFromParent();
}
void FlyScene::menurestart(Ref* pSender) {
    
    isPaused = false;
    Director::getInstance()->resume();
    Director::getInstance()->replaceScene(FlyScene::create());
}
void FlyScene::menuchoice(Ref* pSender) {
    
    isPaused = false;
    Director::getInstance()->resume();
    Director::getInstance()->replaceScene(LoginChoiceScene::create());
}
void FlyScene::createMasterRunSprite(int choice)
{
    // ��������ʵ��
    Monster* monster = Monster::create(choice);
    monsterList.push_back(monster);
    monster->setTag(1);
    // ���ù��޵�λ�õ�����
    monster->setPosition(Vec2(1024 - ROBOT_X, ROBOT_Y));
    // ��������ӵ���ͼ������
    this->addChild(monster,1);
    // ���ʵ���ʱ�����ù��޵�move������ʹ�俪ʼ�ƶ�
    monster->move(1024 - ROBOT_X, ROBOT_Y,0,-1);
}
void FlyScene::create_monster(int i,int num) {
        this->schedule([=](float delta) {
            createMasterRunSprite(i);
            }, 1, num - 1, 0, "createSprite");
}
void FlyScene::updateMonsterNum() {
    

    // ȷ��������������С����
    monster_num = std::max(0, monster_num - 1);
    if ((carrot_life == 0 || (monster_group == 0&&monster_num==0))) {
        if(carrot_life == 0)
            GameOver(false);
        else
            GameOver(true);
    }
    if (monster_num == 0&&monster_group>0) {
        monster_num = 5;
        if (monster_label)
        {
            monster_label->setString(StringUtils::format("Monster Group : %d/5", 6 - monster_group));
        }
        create_monster(monster_group %3+1, monster_num);
        monster_group--;
    }
    // ���������������������������ص��߼�
    // ���磬�����������Ƿ�Ϊ�㣬���Ϊ����Դ���ʤ��������
}
void FlyScene::updateCarrot() {
    // ȷ��������������С����
    carrot_life = std::max(0, carrot_life - 1);
    if (lifeLabel)
    {
        lifeLabel->setString(StringUtils::format(" %d", carrot_life));
    }
}
void FlyScene::GameOver(bool win) {
    isPaused = true;
    Director::getInstance()->pause();
    //auto lcScene = dynamic_cast<LoginChoiceScene*>(Director::getInstance()->getRunningScene());
    if (win) {
        auto sprite = cocos2d::Sprite::create("38.png");
        sprite->setPosition(1024 / 2, 576 / 2);
        this->addChild(sprite, 1);
       // int valueOfT = lcScene->t;  // ��ȡ t ��ֵ
        //lcScene->t = 1;             // �޸� t ��ֵ
    }
    else {
        auto sprite = cocos2d::Sprite::create("28.png");
        sprite->setPosition(1024 / 2, 576 / 2);
        this->addChild(sprite, 1);
    }
    //�����ؿ�ѡ��ť
    auto rechoice_closeItem = MenuItemImage::create(
        "36.png",
        "37.png",
        CC_CALLBACK_1(FlyScene::menuchoice, this));

    if (rechoice_closeItem == nullptr ||
        rechoice_closeItem->getContentSize().width <= 0 ||
        rechoice_closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        constexpr float x = 1024 / 2-20 ;
        constexpr float y = 576 / 2-20 ;
        rechoice_closeItem->setPosition(Vec2(x, y));
    }


    auto menu3 = Menu::create(rechoice_closeItem, NULL);

    menu3->setPosition(Vec2::ZERO);
    this->addChild(menu3, 1);
}
void FlyScene::update(float dt) {
    // ���������б�����ÿ������
   
    std::vector<Monster*> monsterListCopy;
    for (auto it = monsterList.begin(); it < monsterList.end(); ++it) {
        Monster* monster = *it;
        monsterListCopy.push_back(monster);
       
    }
    for (auto its = towerList.begin(); its < towerList.end(); ++its) {
        Tower* towers = *its;
        const float tower_x = towers->tower_locx;
        const float tower_y = towers->tower_locy;
        Monster* hurt_monster=nullptr;
        if (towers->time == 1000000000000)
            towers->time = 0;
        towers->time++;
        for (auto mon = monsterListCopy.begin(); mon < monsterListCopy.end(); ++mon) {
            Monster* monster = *mon;
            if (location_judge(monster->loc_x, monster->loc_y, tower_x, tower_y, towers->distance))
                hurt_monster = monster;
        }
        if (hurt_monster != nullptr && towers->time % (50 / towers->level) == 0) {
          
            showTowerAttack(Vec2(tower_x, tower_y),Vec2(hurt_monster->loc_x, hurt_monster->loc_y),towers->type);
            hurt_monster->takeDamage(towers->hurt);
            if(towers->type==1)
            TowerAttack(Vec2(hurt_monster->loc_x, hurt_monster->loc_y), towers);
        }
        
    }
    // ���������б�
    
    if (WealthLabel)
    {
        WealthLabel->setString(StringUtils::format("%d", wealth));
    }
}
void FlyScene::tower_change(int locs, int sit, int kind) {
    my_loc[locs][0] = sit;
    my_loc[locs][1] = kind;
}
bool FlyScene::location_judge(float monster_x, float monster_y, float tower_x, float tower_y, float distance) {
    if ((tower_x - monster_x) * (tower_x - monster_x) + (tower_y - monster_y) * (tower_y - monster_y) <= distance * distance)
        return true;
    else
        return false;
}
void FlyScene::showTowerAttack(cocos2d::Vec2 towerposion, cocos2d::Vec2 monsterposion, int type) {
    if (type == 1) {
        auto sprite = Sprite::create("#BOTTLEBULLET.png");
        sprite->setPosition(towerposion);
        constexpr float duration = 0.1f;  // �˶��ĳ���ʱ�䣨�룩
        auto moveTo = MoveTo::create(duration, monsterposion);
        auto fadeOut = FadeOut::create(0.1f);  // ��0.5���ڵ���
        auto callFunc = CallFunc::create([=]() {
            auto sprite1 = Sprite::create("buildA.png");
            sprite1->setPosition(monsterposion);
            addChild(sprite1, 1);
            auto fadeOut1 = FadeOut::create(0.5f);  // ��0.5���ڵ���
            sprite1->runAction(fadeOut1);
            });
        auto sequence = Sequence::create(moveTo, fadeOut, callFunc, nullptr);
        sprite->runAction(sequence);
        addChild(sprite,1);
    }
    if (type == 2) {
        
        auto sprite = Sprite::create("#SHITBULLET.png");
        sprite->setPosition(towerposion);
        constexpr float duration = 0.1f;  // �˶��ĳ���ʱ�䣨�룩
        auto moveTo = MoveTo::create(duration, monsterposion);
        auto fadeOut = FadeOut::create(0.1f);  // ��0.5���ڵ���
        auto callFunc = CallFunc::create([=]() {
            auto sprite1 = Sprite::create("buildA.png");
            sprite1->setPosition(monsterposion);
            addChild(sprite1, 1);
            auto fadeOut1 = FadeOut::create(0.5f);  // ��0.5���ڵ���
            sprite1->runAction(fadeOut1);
            });
        auto sequence = Sequence::create(moveTo, fadeOut, callFunc, nullptr);
        sprite->runAction(sequence);
        addChild(sprite, 1);
    }
}
void FlyScene::TowerAttack(cocos2d::Vec2 targetmonsterPosition,Tower* tower)
{
    // �������������֮�������
    Vec2 direction = targetmonsterPosition - Vec2(tower->tower_locx, tower->tower_locy);
    // �������������֮��ĽǶȣ����ȣ�
    const float angleInRadians = atan2(direction.x, direction.y);

    // ������ת��Ϊ�Ƕ�
    const float angleInDegrees = CC_RADIANS_TO_DEGREES(angleInRadians);

    // ʹ����ת�����
    tower->setRotation(angleInDegrees);  // ����ĽǶȿ�����Ҫ�ʵ�����������ȡ�����������ϵ����ת����
}