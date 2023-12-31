#include "SimpleAudioEngine.h"
#include "ForestScene.h"
#include "ForestTowerManager.h"
#include "Tower.h"
#define FOR_CARROT_X 830
#define FOR_CARROT_Y 120
#define MON_START_X 80
#define MON_START_Y 450
#define MON_1_X 770
#define MON_2_Y 280
#define MON_3_X 240
#define FPOS_1_Y 380
#define FPOS_2_Y 310
#define FPOS_1_X 740
#define FPOS_2_X 180
#define FPOS_3_Y 230
#define FPOS_4_Y 160
#define FPOS_3_X 280
#define FPOS_4_X 840
#define FPOS_5_X 830
#define FPOS_6_X 900
#define FPOS_5_Y 450
#define FPOS_6_Y 240
#define FPOS_7_X 200
#define FPOS_8_X 130
#define FPOS_7_Y 160
#define FPOS_8_Y 300
#define FPOS_9_X 420
#define FPOS_0_X 630
#define FPOS_9_Y 70
#define FPOS_0_Y 0
#define BOARD_SIZE 70
USING_NS_CC;
void ForestScene::SetBarrier() {
    ForMonster* barrier = ForMonster::create(4);
    barrier->setPosition(FPOS_1_X - BOARD_SIZE / 2, FPOS_2_Y + BOARD_SIZE / 2);
    my_loc[7][0] = -2;
    this->addChild(barrier, 1);
    ForMonster* barrier1 = ForMonster::create(5);
    barrier1->setPosition(FPOS_3_X + BOARD_SIZE / 2, FPOS_4_Y+ BOARD_SIZE / 2);
    my_loc[8][0] = -2;
    this->addChild(barrier1, 1);
    ForMonster* barrier2 = ForMonster::create(6);
    barrier2->setPosition(FPOS_3_X + BOARD_SIZE / 2+2* BOARD_SIZE, FPOS_4_Y + BOARD_SIZE / 2);
    my_loc[10][0] = -2;
    this->addChild(barrier2, 1);
    ForMonster* barrier3 = ForMonster::create(4);
    barrier3->setPosition(FPOS_3_X + BOARD_SIZE / 2 + 3 * BOARD_SIZE, FPOS_4_Y + BOARD_SIZE / 2);
    my_loc[11][0] = -2;
    this->addChild(barrier3, 1);
    ForMonster* barrier4 = ForMonster::create(5);
    barrier4->setPosition(FPOS_3_X + BOARD_SIZE / 2 + 5 * BOARD_SIZE, FPOS_4_Y + BOARD_SIZE / 2);
    my_loc[13][0] = -2;
    this->addChild(barrier4, 1);
}
Scene* ForestScene::createForestScene()
{
    return ForestScene::create();
}
int ForestScene::loc_return(float x, float y) {
    int jug_1 = 0, jug_2 = 0, jug_3 = 0, jug_4 = 0,jug_5=0;
    if (x >= FPOS_2_X && x <= FPOS_1_X && y >= FPOS_2_Y && y <= FPOS_1_Y)
        jug_1 = 1;
    if (x >= FPOS_3_X && x <= FPOS_4_X && y >= FPOS_4_Y && y <= FPOS_3_Y)
        jug_2 = 1;
    if (x >= FPOS_5_X && x <= FPOS_6_X && y >= FPOS_6_Y && y <= FPOS_5_Y)
        jug_3 = 1;
    if (x >= FPOS_8_X && x <= FPOS_7_X  && y >= FPOS_7_Y && y <= FPOS_8_Y)
        jug_4 = 1;
    if (x >= FPOS_9_X && x <= FPOS_0_X && y >= 0 && y <= FPOS_9_Y)
        jug_5 = 1;
    if (jug_1 == 1 || jug_2 == 1 || jug_3 == 1 || jug_4 == 1||jug_5==1) {
        if (jug_1 == 1) {
            int loc = (x - FPOS_2_X) / BOARD_SIZE;
            if (loc == 0) {               
                    return 0;
            }
            if (loc == 1) {
                    return 1;
            }
            if (loc == 2) {
                return 2;
            }
            if (loc == 3) {
                return 3;
            }
            if (loc == 4) {
                return 4;
            }
            if (loc == 5) {
                return 5;
            }
            if (loc == 6) {
                return 6;
            }
            if (loc == 7) {
                return 7;
            }

        }
        if (jug_2 == 1) {
            int loc = (x - FPOS_3_X) / BOARD_SIZE;
            if (loc == 0) {
                return 8;
            }
            if (loc == 1) {
                return 9;
            }
            if (loc == 2) {
                return 10;
            }
            if (loc == 3) {
                return 11;
            }
            if (loc == 4) {
                return 12;
            }
            if (loc == 5) {
                return 13;
            }
            if (loc == 6) {
                return 14;
            }
            if (loc == 7) {
                return 15;
            }
        }
        if (jug_3 == 1) {
            int loc = (y - FPOS_6_Y) / BOARD_SIZE;
            if (loc == 0) {
                return 16;
            }
            if (loc == 1) {
                return 17;
            }
            if (loc == 2) {
                return 18;
            }
        }
        if (jug_4 == 1) {
            int loc = (y - FPOS_7_Y) / BOARD_SIZE;
            if (loc == 0) {
                return 19;
            }
            if (loc == 1) {
                return 20;
            }
        }
        if (jug_5 == 1) {
            int loc = (x - FPOS_9_X) / BOARD_SIZE;
            if (loc == 0) {
                return 21;
            }
            if (loc == 1) {
                return 22;
            }
            if (loc == 2) {
                return 23;
            }
        }
        return -1;
    }
    else
        return -1;
}
int ForestScene::pos_judge(float x, float y) {
    if (y >= FOR_CARROT_Y - 20 && y <= FOR_CARROT_Y + 20 && x >= FOR_CARROT_X - 50 && x <= FOR_CARROT_X + 50)
        return 10;
    if (x <= 905 - 20 && x >= 1024 - 905 + 20 && y >= 576 - 60 && y <= 576)
        return 20;
    int jug_1 = 0, jug_2 = 0, jug_3 = 0, jug_4 = 0, jug_5 = 0;
    if (x >= FPOS_2_X && x <= FPOS_1_X && y >= FPOS_2_Y && y <= FPOS_1_Y)
        jug_1 = 1;
    if (x >= FPOS_3_X && x <= FPOS_4_X && y >= FPOS_4_Y && y <= FPOS_3_Y)
        jug_2 = 1;
    if (x >= FPOS_5_X && x <= FPOS_6_X && y >= FPOS_6_Y && y <= FPOS_5_Y)
        jug_3 = 1;
    if (x >= FPOS_8_X && x <= FPOS_7_X && y >= FPOS_7_Y && y <= FPOS_8_Y)
        jug_4 = 1;
    if (x >= FPOS_9_X && x <= FPOS_0_X && y >= 0 && y <= FPOS_9_Y)
        jug_5 = 1;
    if (jug_1 == 1 || jug_2 == 1 || jug_3 == 1 || jug_4 == 1 || jug_5 == 1) {
        if (jug_1 == 1) {
            int loc = (x - FPOS_2_X) / BOARD_SIZE;
            if (loc == 0) {
                return my_loc[0][0];
            }
            if (loc == 1) {
                return my_loc[1][0];
            }
            if (loc == 2) {
                return my_loc[2][0];
            }
            if (loc == 3) {
                return my_loc[3][0];
            }
            if (loc == 4) {
                return my_loc[4][0];
            }
            if (loc == 5) {
                return my_loc[5][0];
            }
            if (loc == 6) {
                return my_loc[6][0];
            }
            if (loc == 7) {
                return my_loc[7][0];
            }

        }
        if (jug_2 == 1) {
            int loc = (x - FPOS_3_X) / BOARD_SIZE;
            if (loc == 0) {
                return my_loc[8][0];
            }
            if (loc == 1) {
                return my_loc[9][0];
            }
            if (loc == 2) {
                return my_loc[10][0];
            }
            if (loc == 3) {
                return my_loc[11][0];
            }
            if (loc == 4) {
                return my_loc[12][0];
            }
            if (loc == 5) {
                return my_loc[13][0];
            }
            if (loc == 6) {
                return my_loc[14][0];
            }
            if (loc == 7) {
                return my_loc[15][0];
            }
        }
        if (jug_3 == 1) {
            int loc = (y - FPOS_6_Y) / BOARD_SIZE;
            if (loc == 0) {
                return my_loc[16][0];
            }
            if (loc == 1) {
                return my_loc[17][0];
            }
            if (loc == 2) {
                return my_loc[18][0];
            }
        }
        if (jug_4 == 1) {
            int loc = (y - FPOS_7_Y) / BOARD_SIZE;
            if (loc == 0) {
                return my_loc[19][0];
            }
            if (loc == 1) {
                return my_loc[20][0];
            }
        }
        if (jug_5 == 1) {
            int loc = (x - FPOS_9_X) / BOARD_SIZE;
            if (loc == 0) {
                return my_loc[21][0];
            }
            if (loc == 1) {
                return my_loc[22][0];
            }
            if (loc == 2) {
                return my_loc[23][0];
            }
        }
        return -1;
    }
    else
        return -1;
}
float ForestScene::Location_y(float x, float y){
    float Y = 0;
    int jug_1 = 0, jug_2 = 0, jug_3 = 0, jug_4 = 0, jug_5 = 0;
    if (x >= FPOS_2_X && x <= FPOS_1_X && y >= FPOS_2_Y && y <= FPOS_1_Y)
        jug_1 = 1;
    if (x >= FPOS_3_X && x <= FPOS_4_X && y >= FPOS_4_Y && y <= FPOS_3_Y)
        jug_2 = 1;
    if (x >= FPOS_5_X && x <= FPOS_6_X && y >= FPOS_6_Y && y <= FPOS_5_Y)
        jug_3 = 1;
    if (x >= FPOS_8_X && x <= FPOS_7_X && y >= FPOS_7_Y && y <= FPOS_8_Y)
        jug_4 = 1;
    if (x >= FPOS_9_X && x <= FPOS_0_X && y >= 0 && y <= FPOS_9_Y)
        jug_5 = 1;
    if (jug_1 == 1 || jug_2 == 1 || jug_3 == 1 || jug_4 == 1 || jug_5 == 1) {
        if (jug_1 == 1) {
            Y = (FPOS_2_Y + FPOS_1_Y) / 2;
        }
        if (jug_2 == 1) {
            Y = (FPOS_3_Y + FPOS_4_Y) / 2;
        }
        if (jug_3 == 1) {
            int loc = (y - FPOS_6_Y) / BOARD_SIZE;
            Y = FPOS_6_Y + BOARD_SIZE * loc + BOARD_SIZE / 2;
        }
        if (jug_4 == 1) {
            int loc = (y - FPOS_7_Y) / BOARD_SIZE;
            Y = FPOS_7_Y + BOARD_SIZE * loc + BOARD_SIZE / 2;
        }
        if (jug_5 == 1) {
            Y = (FPOS_9_Y + FPOS_0_Y) / 2;
        }
    }
    
        return Y;
}
float ForestScene::Location_x(float x, float y) {
    float X = 0;
    int jug_1 = 0, jug_2 = 0, jug_3 = 0, jug_4 = 0, jug_5 = 0;
    if (x >= FPOS_2_X && x <= FPOS_1_X && y >= FPOS_2_Y && y <= FPOS_1_Y)
        jug_1 = 1;
    if (x >= FPOS_3_X && x <= FPOS_4_X && y >= FPOS_4_Y && y <= FPOS_3_Y)
        jug_2 = 1;
    if (x >= FPOS_5_X && x <= FPOS_6_X && y >= FPOS_6_Y && y <= FPOS_5_Y)
        jug_3 = 1;
    if (x >= FPOS_8_X && x <= FPOS_7_X && y >= FPOS_7_Y && y <= FPOS_8_Y)
        jug_4 = 1;
    if (x >= FPOS_9_X && x <= FPOS_0_X && y >= 0 && y <= FPOS_9_Y)
        jug_5 = 1;
    if (jug_1 == 1 || jug_2 == 1 || jug_3 == 1 || jug_4 == 1 || jug_5 == 1) {
        if (jug_1 == 1) {
            int loc = (x - FPOS_2_X) / BOARD_SIZE;
            X = FPOS_2_X + BOARD_SIZE * loc + BOARD_SIZE / 2;
        }
        if (jug_2 == 1) {
            int loc = (x - FPOS_3_X) / BOARD_SIZE;
            X = FPOS_3_X + BOARD_SIZE * loc + BOARD_SIZE / 2;
        }
        if (jug_3 == 1) {
            X = (FPOS_5_X + FPOS_6_X) / 2;
        }
        if (jug_4 == 1) {
            X = (FPOS_7_X + FPOS_8_X) / 2;
        }
        if (jug_5 == 1) {
            int loc = (x - FPOS_9_X) / BOARD_SIZE;
            X = FPOS_9_X + BOARD_SIZE * loc + BOARD_SIZE / 2;
        }
    }

    return X;
}
void ForestScene::registerMouseEvents()
{
    auto mouseListener = cocos2d::EventListenerMouse::create();

    // ��갴��ʱ�Ļص�����
    mouseListener->onMouseDown = CC_CALLBACK_1(ForestScene::onMouseDown, this);

    // ����������ӵ��¼��ַ���
    _eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);
}
bool ForestScene::onMouseDown(cocos2d::EventMouse* event)
{
    if (isPaused) {
        // �����Ϸ��ͣ��������ͣ���洦�����¼�
        EventMouse* e = dynamic_cast<EventMouse*>(event);
        if (e) {
            Vec2 clickLocation = Vec2(e->getCursorX(), e->getCursorY());
        }
    }
    else {
        float mouseX = event->getCursorX();
        float mouseY = event->getCursorY();
        float set_x = Location_x(mouseX, mouseY);
        float set_y = Location_y(mouseX, mouseY);

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
                for (auto child : this->getChildren())
                {
                    auto mon = dynamic_cast<ForMonster*>(child);
                    if (mon && mon->getBoundingBox().containsPoint(Vec2(set_x, set_y)))
                    {
                        mon->loc_x = set_x;
                        mon->loc_y = set_y;
                        bool choice = false;
                        for (auto its = towerList.begin(); its < towerList.end(); ++its) {
                            Tower* towers = *its;
                            if (location_judge(mon->loc_x, mon->loc_y, towers->tower_locx, towers->tower_locy, towers->distance))
                                choice = true;

                        }
                        if (choice) {
                            monsterList.push_back(mon);
                            monster_num++;
                            my_loc[loc_return(set_x, set_y)][0] = 0;
                            my_loc[loc_return(set_x, set_y)][1] = 0;
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
                    TowerManager->showUP_BOTTLEOptions(Vec2(set_x, set_y), 1);
                }
                if (my_loc[loc_return(mouseX, mouseY)][1] == 2) {
                    tower = true;
                    TowerManager->showUP_SHITOptions(Vec2(set_x, set_y), 1);
                }
                if (my_loc[loc_return(mouseX, mouseY)][1] == 3) {
                    tower = true;
                    TowerManager->showUP_PINOptions(Vec2(set_x, set_y), 1);
                }
            }
            if (pos_judge(mouseX, mouseY) == 2) {
                // ����ѡ��
                if (my_loc[loc_return(mouseX, mouseY)][1] == 1) {
                    tower = true;
                    TowerManager->showUP_BOTTLEOptions(Vec2(set_x, set_y), 2);
                }
                if (my_loc[loc_return(mouseX, mouseY)][1] == 2) {
                    tower = true;
                    TowerManager->showUP_SHITOptions(Vec2(set_x, set_y), 2);
                }
                if (my_loc[loc_return(mouseX, mouseY)][1] == 3) {
                    tower = true;
                    TowerManager->showUP_PINOptions(Vec2(set_x, set_y), 2);
                }
            }
            if (pos_judge(mouseX, mouseY) == 3) {
                // ��3������λ����ʾ����
                // �Ƴ�ѡ��
                tower = true;
                if (my_loc[loc_return(mouseX, mouseY)][1] == 1 || my_loc[loc_return(mouseX, mouseY)][1] == 2)
                    TowerManager->DELETETOptions(Vec2(set_x, set_y));

            }
            if (pos_judge(mouseX, mouseY) == 10) {
                // �ڵ��λ����ʾ����
                CarrotMove();
            }
        }
    }
    return true;
}
void ForestScene::CarrotMove() {
    auto sprite = Sprite::create();
    this->addChild(sprite, 1);
    auto animation = Animation::create();
    for (int i = 1; i <= 6; ++i) {
        std::string frameName = StringUtils::format("f%d.png", i);
        animation->addSpriteFrameWithFileName(frameName);
    }
    animation->setDelayPerUnit(0.1f);  // ����ÿ֡�ĳ���ʱ��
    sprite->setPosition(Vec2(FOR_CARROT_X, FOR_CARROT_Y));
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
void ForestScene::showClickAnimation(float x, float y, cocos2d::EventMouse* event)
{
    // �������鲢���ö���
    auto sprite = cocos2d::Sprite::create("19.png");
    sprite->setPosition(x, y);
    this->addChild(sprite, 1);

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
}
cocos2d::Vec2 ForestScene::showAreaAnimation(float x, float y, cocos2d::EventMouse* event)//������////////�������͸��ģ������������
{
    auto dispatcher = Director::getInstance()->getEventDispatcher();


    // �������鲢���ö���
    auto sprite = cocos2d::Sprite::create("20.png");
    float set_x = Location_x(x, y);
    float set_y = Location_y(x, y);
    sprite->setPosition(set_x, set_y);
    this->addChild(sprite, 1);


    TowerManager->showTowerOptions(Vec2(set_x, set_y));//��������////////////////
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
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
bool ForestScene::init()
{

    if (!Scene::init())
    {
        return false;
    }
    TowerManager = ForTowerManager::create();  // ��ʼ��
    addChild(TowerManager);  // ���towerManager������
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto fly_closeItem = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(ForestScene::menuCloseCallback, this));

    if (fly_closeItem == nullptr ||
        fly_closeItem->getContentSize().width <= 0 ||
        fly_closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - fly_closeItem->getContentSize().width / 2;
        float y = origin.y + fly_closeItem->getContentSize().height / 2;
        fly_closeItem->setPosition(Vec2(x, y));
    }


    auto menu = Menu::create(fly_closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    auto sprite = Sprite::create("50.png");
    if (sprite == nullptr)
    {
        problemLoading("'1.png'");
    }
    else
    {
        sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
        this->addChild(sprite, -1);
    }
    auto route_sprite = Sprite::create("51.png");
    if (route_sprite == nullptr)
    {
        problemLoading("'1.png'");
    }
    else
    {
        route_sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 52));
        this->addChild(route_sprite, -1);
    }
    //������Ŀ
    auto scene_sprite = Sprite::create("26.png");
    scene_sprite->setPosition(Vec2(1024 / 2, 576 - 23));
    this->addChild(scene_sprite, -1);

    //�����ܲ�
    auto carrot_sprite = Sprite::create("14.png");
    carrot_sprite->setPosition(Vec2(FOR_CARROT_X, FOR_CARROT_Y));
    this->addChild(carrot_sprite, 0);

    //�����ܲ�����ֵ
    auto carrot_live = Sprite::create("25.png");
    carrot_live->setPosition(Vec2(FOR_CARROT_X + 40, FOR_CARROT_Y));
    this->addChild(carrot_live, 1);

    // ��ʼ����ǩ
    lifeLabel = Label::createWithTTF(" 10", "fonts/Marker Felt.ttf", 24);
    if (lifeLabel)
    {
        lifeLabel->setPosition(Vec2(FOR_CARROT_X + 60, FOR_CARROT_Y));
        this->addChild(lifeLabel, 1);
    }

    // ��ʼ����ǩ
    monster_label = Label::createWithTTF("Monster Group : 1/5", "fonts/Marker Felt.ttf", 24);
    if (monster_label)
    {
        monster_label->setPosition(Vec2(1024 / 2, 576 - 18));
        this->addChild(monster_label, 1);
    }

    // ��ʾ���
    WealthLabel = Label::createWithTTF("500", "fonts/Marker Felt.ttf", 24);
    if (WealthLabel)
    {
        WealthLabel->setPosition(Vec2(1024 / 2 - 200, 576 - 18));
        this->addChild(WealthLabel, 1);
    }

    //������ͣ��ť
    auto stop_closeItem = MenuItemImage::create(
        "29.png",
        "30.png",
        CC_CALLBACK_1(ForestScene::menuStop, this));

    if (stop_closeItem == nullptr ||
        stop_closeItem->getContentSize().width <= 0 ||
        stop_closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = visibleSize.width / 2 + 250;
        float y = 576 - 20;
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
    sign_sprite->setPosition(Vec2(MON_START_X, MON_START_Y));
    this->addChild(sign_sprite, 0);
  
    /*������ʾ����ʱ*/
    // ��ʼ������ʱ����
    countdown = 3;

    // ���� Label�������ó�ʼ͸����Ϊ 255
    label = cocos2d::Label::createWithTTF(std::to_string(countdown), "fonts/Marker Felt.ttf", 150);
    label->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
    this->addChild(label);
    // ������ʱ����ÿ�����һ�ε���ʱ
    this->schedule(CC_SCHEDULE_SELECTOR(ForestScene::updateCountdown), 1.0f, countdown - 1, 0);



    // ע��������¼�
    registerMouseEvents();

    SetBarrier();
    this->scheduleUpdate();

    return true;
}
void ForestScene::updateCountdown(float dt)
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
void ForestScene::create_monster(int i, int num) {
    this->schedule([=](float delta) {
        createMasterRunSprite(i);
        }, 1, num - 1, 0, "createSprite");
}
void ForestScene::createMasterRunSprite(int choice)
{
    // ��������ʵ��
    ForMonster* monster = ForMonster::create(choice);
    monsterList.push_back(monster);
    monster->setTag(1);
    // ���ù��޵�λ�õ�����
    monster->setPosition(Vec2(MON_START_X, MON_START_Y));
    // ��������ӵ���ͼ������
    this->addChild(monster, 1);
    // ���ʵ���ʱ�����ù��޵�move������ʹ�俪ʼ�ƶ�
    monster->move(MON_START_X, MON_START_Y, 1, 0);
}
void ForestScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
void ForestScene::menuStop(Ref* pSender)
{
    isPaused = true;
    Director::getInstance()->pause();
    auto sprite = cocos2d::Sprite::create("31.png");
    sprite->setPosition(1024 / 2, 576 / 2);
    this->addChild(sprite, 1);
    //������ͣ��ť
    auto return_closeItem = MenuItemImage::create(
        "32.png",
        "33.png",
        CC_CALLBACK_1(ForestScene::menureturn, this));

    if (return_closeItem == nullptr ||
        return_closeItem->getContentSize().width <= 0 ||
        return_closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = 1024 / 2 - 10;
        float y = 576 / 2 + 105;
        return_closeItem->setPosition(Vec2(x, y));
    }


    auto menu1 = Menu::create(return_closeItem, NULL);
    menu1->setPosition(Vec2::ZERO);
    this->addChild(menu1, 1);
    //�������¿�ʼ��ť
    auto restart_closeItem = MenuItemImage::create(
        "34.png",
        "35.png",
        CC_CALLBACK_1(ForestScene::menurestart, this));

    if (restart_closeItem == nullptr ||
        restart_closeItem->getContentSize().width <= 0 ||
        restart_closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = 1024 / 2 - 10;
        float y = 576 / 2 + 10;
        restart_closeItem->setPosition(Vec2(x, y));
    }


    auto menu2 = Menu::create(restart_closeItem, NULL);
    menu2->setPosition(Vec2::ZERO);
    this->addChild(menu2, 1);
    //�����ؿ�ѡ��ť
    auto rechoice_closeItem = MenuItemImage::create(
        "36.png",
        "37.png",
        CC_CALLBACK_1(ForestScene::menuchoice, this));

    if (rechoice_closeItem == nullptr ||
        rechoice_closeItem->getContentSize().width <= 0 ||
        rechoice_closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = 1024 / 2 - 10;
        float y = 576 / 2 - 85;
        rechoice_closeItem->setPosition(Vec2(x, y));
    }


    auto menu3 = Menu::create(rechoice_closeItem, NULL);
    menu3->setPosition(Vec2::ZERO);
    this->addChild(menu3, 1);
    return_menu = menu1;
    return_sprite = sprite;
    restart_sprite = menu2;
    rechoice_sprite = menu3;

}
void ForestScene::menureturn(Ref* pSender) {
    isPaused = false;
    Director::getInstance()->resume();
    return_menu->removeFromParent();
    return_sprite->removeFromParent();
    restart_sprite->removeFromParent();
    rechoice_sprite->removeFromParent();
}
void ForestScene::menurestart(Ref* pSender) {

    isPaused = false;
    Director::getInstance()->resume();
    Director::getInstance()->replaceScene(ForestScene::create());
}
void ForestScene::menuchoice(Ref* pSender) {

    isPaused = false;
    Director::getInstance()->resume();
    Director::getInstance()->replaceScene(LoginChoiceScene::create());
}
void ForestScene::updateMonsterNum() {


    // ȷ��������������С����
    monster_num = std::max(0, monster_num - 1);
    if ((carrot_life == 0 || (monster_group == 0 && monster_num == 0))) {
        if (carrot_life == 0)
            GameOver(false);
        else
            GameOver(true);
    }
    if (monster_num == 0 && monster_group > 0) {
        monster_num = 5;
        if (monster_label)
        {
            monster_label->setString(StringUtils::format("Monster Group : %d/5", 6 - monster_group));
        }
        create_monster(monster_group % 3 + 1, monster_num);
        monster_group--;
    }
    // ���������������������������ص��߼�
    // ���磬�����������Ƿ�Ϊ�㣬���Ϊ����Դ���ʤ��������
}
void ForestScene::updateCarrot() {
    // ȷ��������������С����
    carrot_life = std::max(0, carrot_life - 1);
    if (lifeLabel)
    {
        lifeLabel->setString(StringUtils::format(" %d", carrot_life));
    }
}
void ForestScene::GameOver(bool win) {
    isPaused = true;
    Director::getInstance()->pause();
    if (win) {
        auto sprite = cocos2d::Sprite::create("38.png");
        sprite->setPosition(1024 / 2, 576 / 2);
        this->addChild(sprite, 1);
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
        CC_CALLBACK_1(ForestScene::menuchoice, this));

    if (rechoice_closeItem == nullptr ||
        rechoice_closeItem->getContentSize().width <= 0 ||
        rechoice_closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = 1024 / 2 - 20;
        float y = 576 / 2 - 20;
        rechoice_closeItem->setPosition(Vec2(x, y));
    }


    auto menu3 = Menu::create(rechoice_closeItem, NULL);
    menu3->setPosition(Vec2::ZERO);
    this->addChild(menu3, 1);
}
bool ForestScene::location_judge(float monster_x, float monster_y, float tower_x, float tower_y, float distance) {
    if ((tower_x - monster_x) * (tower_x - monster_x) + (tower_y - monster_y) * (tower_y - monster_y) <= distance * distance)
        return true;
    else
        return false;
}
void ForestScene::update(float dt) {
    // ���������б�����ÿ������

    std::vector<ForMonster*> monsterListCopy;
    for (auto it = monsterList.begin(); it < monsterList.end(); ++it) {
        ForMonster* monster = *it;
        monsterListCopy.push_back(monster);

    }
    for (auto its = towerList.begin(); its < towerList.end(); ++its) {
        Tower* towers = *its;
        float tower_x = towers->tower_locx;
        float tower_y = towers->tower_locy;
        ForMonster* hurt_monster = nullptr;
        if (towers->time == 1000000000000)
            towers->time = 0;
        towers->time++;
        for (auto mon = monsterListCopy.begin(); mon < monsterListCopy.end(); ++mon) {
            ForMonster* monster = *mon;
            if (location_judge(monster->loc_x, monster->loc_y, tower_x, tower_y, towers->distance))
                hurt_monster = monster;
        }
        if (hurt_monster != nullptr && towers->time % (50 / towers->level) == 0) {

            showTowerAttack(Vec2(tower_x, tower_y), Vec2(hurt_monster->loc_x, hurt_monster->loc_y), towers->type);
            hurt_monster->takeDamage(towers->hurt);
            if (towers->type == 1)
                TowerAttack(Vec2(hurt_monster->loc_x, hurt_monster->loc_y), towers);
            if (towers->type == 3)
                TowerAttack(Vec2(hurt_monster->loc_x, hurt_monster->loc_y), towers);
        }

    }
    // ���������б�

    if (WealthLabel)
    {
        WealthLabel->setString(StringUtils::format("%d", wealth));
    }
}
void ForestScene::tower_change(int locs, int sit, int kind) {
    my_loc[locs][0] = sit;
    my_loc[locs][1] = kind;
}
void ForestScene::showTowerAttack(cocos2d::Vec2 towerposion, cocos2d::Vec2 monsterposion, int type) {
    if (type == 1) {
        auto sprite = Sprite::create("#BOTTLEBULLET.png");
        sprite->setPosition(towerposion);
        float duration = 0.1f;  // �˶��ĳ���ʱ�䣨�룩
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
    if (type == 2) {

        auto sprite = Sprite::create("#SHITBULLET.png");
        sprite->setPosition(towerposion);
        float duration = 0.1f;  // �˶��ĳ���ʱ�䣨�룩
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
    if (type == 3) {

        auto sprite = Sprite::create("#PINBULLET.png");
        sprite->setPosition(towerposion);
        float duration = 0.1f;  // �˶��ĳ���ʱ�䣨�룩
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
void ForestScene::TowerAttack(cocos2d::Vec2 targetmonsterPosition, Tower* tower)
{
    // �������������֮�������
    Vec2 direction = targetmonsterPosition - Vec2(tower->tower_locx, tower->tower_locy);
    // �������������֮��ĽǶȣ����ȣ�
    float angleInRadians = atan2(direction.x, direction.y);

    // ������ת��Ϊ�Ƕ�
    float angleInDegrees = CC_RADIANS_TO_DEGREES(angleInRadians);

    // ʹ����ת�����
    tower->setRotation(angleInDegrees);
}