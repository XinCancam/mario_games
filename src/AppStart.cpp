#include <iostream>
#include <map>

#include "App.hpp"

#include "Util/Logger.hpp"

void App::Start() {
    LOG_TRACE("Start");
    //mario Animated--------------------------------
    std::vector<std::string> Imagebigrun;
    Imagebigrun.reserve(3);
    std::vector<std::string> Imagefirerun;
    Imagebigrun.reserve(3);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(i==0) {
                marioImages.emplace_back(GA_RESOURCE_DIR"/Image/Character/mario_run" + std::to_string(j + 1) + ".png");
            }
            else if(i==1) {
                Imagebigrun.emplace_back(GA_RESOURCE_DIR"/Image/Big/mario_run" + std::to_string(j + 1) + ".png");
            }
            else if(i==2) {
                Imagefirerun.emplace_back(GA_RESOURCE_DIR"/Image/Fire/mario_run" + std::to_string(j + 1) + ".png");
            }
            //std::cout << i << std::endl;
        }
    }
    mario_stand.emplace_back(GA_RESOURCE_DIR"/Image/Character/mario_stand.png");
    std::vector<std::string> Imagestandbig;
    std::vector<std::string> Imagestandfire;
    Imagestandbig.emplace_back(GA_RESOURCE_DIR"/Image/Big/mario_stand.png");
    Imagestandfire.emplace_back(GA_RESOURCE_DIR"/Image/Fire/mario_stand.png");
    std::vector<std::string> Imagej;
    std::vector<std::string> Imagejbig;
    std::vector<std::string> Imagejfire;
    std::vector<std::string> mariodead;
    std::vector<std::string> marioflag;
    std::vector<std::string> marioflag2;
    std::vector<std::string> marioflag3;
    Imagej.emplace_back(GA_RESOURCE_DIR"/Image/Character/mario_jump.png");
    Imagejbig.emplace_back(GA_RESOURCE_DIR"/Image/Big/mario_jump.png");
    Imagejfire.emplace_back(GA_RESOURCE_DIR"/Image/Fire/mario_jump.png");
    mariodead.emplace_back(GA_RESOURCE_DIR"/Image/Character/mario_dead.png");
    marioflag.emplace_back(GA_RESOURCE_DIR"/Image/Character/mario_climb.png");
    marioflag2.emplace_back(GA_RESOURCE_DIR"/Image/Big/mario_climb.png");
    marioflag3.emplace_back(GA_RESOURCE_DIR"/Image/Fire/mario_climb.png");
    //----------------------------------------------
    m_player = std::make_shared<AnimatedCharacter>(marioImages,Imagej,mario_stand,Imagebigrun,Imagejbig,Imagestandbig,Imagefirerun,Imagejfire,Imagestandfire,mariodead,marioflag,marioflag2,marioflag3);
    m_player->SetPosition({0, 0});
    m_player->SetZIndex(5);
    m_player->SetImage(1);
    m_Root.AddChild(m_player);
    player_dead=false;
    mushroom_count=0;
    for(int x=0;x<16;x++) {
        itemx[x]=2.0f;
        itemy[x]=0.0f;
    }
    for(int i=0;i<16;i++) {
        item[i]=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/item/mushroom.png");
        item[i]->SetPosition({0, 0});
        item[i]->SetZIndex(1);
        item[i]->SetVisible(false);
        itemcoin[i]=false;
        itemtime[i]=0;
        m_Root.AddChild(item[i]);
    }
    m_background=std::make_shared<BackgroundImage>();
    bg=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/background/sky.png");
    bg->SetPosition({0, 0});
    bg->SetZIndex(1);
    m_obj2.AddChild(bg);
    gameover=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/background/gameover.png");
    gameover->SetPosition({0, 0});
    gameover->SetZIndex(99);
    gameover->SetVisible(false);
    m_UI.AddChild(gameover);
    //-----------------UI--------------------------
    world=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/UI/world.png");
    world1=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/UI/1.png");
    world2=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/UI/-.png");
    world3=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/UI/1.png");
    world->SetPosition({-570, 280});
    world1->SetPosition({-500, 280});
    world2->SetPosition({-475, 275});
    world3->SetPosition({-450, 280});
    world->SetZIndex(2);
    world1->SetZIndex(2);
    world2->SetZIndex(2);
    world3->SetZIndex(2);
    world1->m_Transform.scale*=0.4;
    world2->m_Transform.scale*=0.4;
    world3->m_Transform.scale*=0.4;
    m_obj.AddChild(world);
    m_obj.AddChild(world1);
    m_obj.AddChild(world2);
    m_obj.AddChild(world3);

    live=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/UI/live2.png");
    live1=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/UI/0.png");
    live1->SetImage(GA_RESOURCE_DIR"/Image/UI/"+std::to_string(lives)+".png");
    livex=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/UI/x.png");
    live->SetPosition({-230, 280});
    live1->SetPosition({-130, 280});
    livex->SetPosition({-160, 280});
    live->SetZIndex(100);
    live1->SetZIndex(100);
    livex->SetZIndex(100);
    live1->m_Transform.scale*=0.4;
    livex->m_Transform.scale*=0.4;
    m_obj.AddChild(live);
    m_obj.AddChild(live1);
    m_obj.AddChild(livex);

    time=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/UI/time.png");
    time1=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/UI/4.png");
    time2=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/UI/0.png");
    time3=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/UI/0.png");
    time->SetPosition({-40, 280});
    time1->SetPosition({30, 280});
    time2->SetPosition({52, 280});
    time3->SetPosition({73, 280});
    time->SetZIndex(100);
    time1->SetZIndex(100);
    time2->SetZIndex(100);
    time3->SetZIndex(100);
    time1->m_Transform.scale*=0.4;
    time2->m_Transform.scale*=0.4;
    time3->m_Transform.scale*=0.4;
    m_obj.AddChild(time);
    m_obj.AddChild(time1);
    m_obj.AddChild(time2);
    m_obj.AddChild(time3);
    coin=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/UI/money.png");
    coinx=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/UI/x.png");
    coin1=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/UI/0.png");
    coin2=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/UI/0.png");
    coin->SetPosition({-400, 280});
    coinx->SetPosition({-370, 280});
    coin1->SetPosition({-340, 280});
    coin2->SetPosition({-315, 280});
    coin->SetZIndex(100);
    coin1->SetZIndex(100);
    coinx->SetZIndex(100);
    coin2->SetZIndex(100);
    coin2->m_Transform.scale*=0.4;
    coin->m_Transform.scale*=0.4;
    coin1->m_Transform.scale*=0.4;
    coinx->m_Transform.scale*=0.4;
    m_obj.AddChild(coin);
    m_obj.AddChild(coinx);
    m_obj.AddChild(coin1);
    m_obj.AddChild(coin2);
    times=400;
    worlds=11;
    coins=0;
    updatetime=0;

    //-------------------------------------------------
    auto result = m_background->NextPhase(1); // result 是 int (*)[20][200]
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 200; j++) {
            Map[i][j] = (*result)[i][j]; // 解引用指標並複製資料
        }
    }
    for(int i=0;i<30;i++) {
        for(int j=0;j<200;j++) {
            map_animate[i][j]=0;
            if(Map[i][j]==2) {
                map_objects[i][j]=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/ground1.png");
               // std::cout<<"ok";
                map_objects[i][j]->SetPosition({-640+(j*48.0f),600-(i*48.0f)});
                map_objects[i][j]->SetZIndex(6);
                m_Root.AddChild(map_objects[i][j]);
                //std::cout <<"ok1"<< std::endl;
            }
            else if(Map[i][j]==4) {
                map_objects[i][j]=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/brick1.png");
                map_objects[i][j]->SetPosition({-640+(j*48.0f),600-(i*48.0f)});
                map_objects[i][j]->SetZIndex(3);
                m_Root.AddChild(map_objects[i][j]);
                //std::cout <<"ok2"<< std::endl;
            }
            else if(Map[i][j]==3) {
                map_objects[i][j]=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/mystery1_1.png");
                map_objects[i][j]->SetPosition({-640+(j*48.0f),600-(i*48.0f)});
                map_objects[i][j]->SetZIndex(3);
                m_Root.AddChild(map_objects[i][j]);
                item[mushroom_count]->SetPosition(map_objects[i][j]->GetPosition());
                mushroom_count++;
                //std::cout <<"ok3"<< std::endl;
            }
            else if(Map[i][j]==1) {
                map_objects[i][j]=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/slab1.png");
                map_objects[i][j]->SetPosition({-640+(j*48.0f),600-(i*48.0f)});
                map_objects[i][j]->SetZIndex(3);
                m_Root.AddChild(map_objects[i][j]);
                //std::cout <<"ok4"<< std::endl;
            }
        else if(Map[i][j]==120||Map[i][j]==124||Map[i][j]==128) {
            map_objects[i][j]=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/pipe_lefttop.png");
            map_objects[i][j]->SetPosition({-640+(j*48.0f),600-(i*48.0f)});
            map_objects[i][j]->SetZIndex(6);
            m_Root.AddChild(map_objects[i][j]);
            map_objects[i][j]->m_Transform.scale*=3;
            //std::cout <<"ok6"<< std::endl;
        }
        else if(Map[i][j]==121||Map[i][j]==125||Map[i][j]==129) {
            map_objects[i][j]=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/pipe_righttop.png");
            map_objects[i][j]->SetPosition({-640+(j*48.0f),600-(i*48.0f)});
            map_objects[i][j]->SetZIndex(6);
            m_Root.AddChild(map_objects[i][j]);
            map_objects[i][j]->m_Transform.scale*=3;
            //std::cout <<"ok6"<< std::endl;
        }
        else if(Map[i][j]==122||Map[i][j]==126||Map[i][j]==130) {
            map_objects[i][j]=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/pipe_leftbottom.png");
            map_objects[i][j]->SetPosition({-640+(j*48.0f),600-(i*48.0f)});
            map_objects[i][j]->SetZIndex(6);
            m_Root.AddChild(map_objects[i][j]);
            map_objects[i][j]->m_Transform.scale*=3;
            //std::cout <<"ok6"<< std::endl;
        }
        else if(Map[i][j]==123||Map[i][j]==127||Map[i][j]==131) {
            map_objects[i][j]=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/pipe_rightbottom.png");
            map_objects[i][j]->SetPosition({-640+(j*48.0f),600-(i*48.0f)});
            map_objects[i][j]->SetZIndex(6);
            m_Root.AddChild(map_objects[i][j]);
            map_objects[i][j]->m_Transform.scale*=3;
            //std::cout <<"ok6"<< std::endl;
        }
        else if(Map[i][j]==5) {
            map_objects[i][j]=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/ground2.png");
            map_objects[i][j]->SetPosition({-640+(j*48.0f),600-(i*48.0f)});
            map_objects[i][j]->SetZIndex(6);
            m_Root.AddChild(map_objects[i][j]);
            //std::cout <<"ok6"<< std::endl;
        }
        else if(Map[i][j]==6) {
            map_objects[i][j]=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/brick2.png");
            map_objects[i][j]->SetPosition({-640+(j*48.0f),600-(i*48.0f)});
            map_objects[i][j]->SetZIndex(6);
            m_Root.AddChild(map_objects[i][j]);
            //std::cout <<"ok6"<< std::endl;
        }
        else if(Map[i][j]==10) {
            flag=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/flag.png");
            flag->SetZIndex(3);
            flagpole=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/flagpole.png");
            flagpole->SetZIndex(3);
            flagpole->SetPosition({-640+(j*48.0f),792-(i*48.0f)});
            m_Root.AddChild(flagpole);
            flag->SetPosition({-667+(j*48.0f),960-(i*48.0f)});
            m_Root.AddChild(flag);
            //std::cout <<"ok6"<< std::endl;
        }

        else if(Map[i][j]==11) {
            castle=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/castle.png");
            castle->SetPosition({-640+(j*48.0f),646-(i*48.0f)});
            castle->SetZIndex(4);
            castle->m_Transform.scale*=3;
            m_Root.AddChild(castle);
            //std::cout <<"ok6"<< std::endl;
        }
        std::cout <<i<<" "<<j<< std::endl;
        }
    }

    goombaimg.reserve(2);
    for (int i = 0; i < 2; ++i) {
        goombaimg.emplace_back(GA_RESOURCE_DIR"/Image/enemy/goomba1_" + std::to_string(i + 1) + ".png");
    }
    goombadeadimg.emplace_back(GA_RESOURCE_DIR"/Image/enemy/goomba1_dead.png");
    for(int i=0;i<10;i++) {
        goomba[i]=std::make_shared<AnimatedCharacter>(goombaimg,goombadeadimg,mario_stand,mario_stand,mario_stand,mario_stand,mario_stand,mario_stand,mario_stand,mario_stand,mario_stand,mario_stand,mario_stand);
        goomba[i]->SetZIndex(6);
        goomba[i]->SetImage(1);
        m_Root.AddChild(goomba[i]);
        enemyx[i]=-2.0f;
        goomba_dead[i]=false;
        goomba_dead_animate[i]=0;
    }

    goomba[0]->SetPosition({800, 0});
    goomba[1]->SetPosition({1600, 0});
    goomba[2]->SetPosition({2400, 0});
    goomba[3]->SetPosition({4000, 0});
    goomba[4]->SetPosition({4100, 0});
    goomba[5]->SetPosition({5600, 0});
    goomba[6]->SetPosition({6500, 0});
    goomba[7]->SetPosition({7300, 0});
    goomba[8]->SetPosition({8500, 0});
    goomba[9]->SetPosition({9200, 0});
    std::cout<<"k"<<std::endl;
    intopipe=false;
    Animate_time=0;
    mario_size=1;
    player_dead_animate=0;
    mario_hitbox={18.0f,24.0f};
    m_PlayerPosition={0.0f,0.0f};
    //startscreen->SetVisible(false);
    //m_UI.RemoveChild(startscreen);
    m_CurrentState = State::UPDATE;
}
