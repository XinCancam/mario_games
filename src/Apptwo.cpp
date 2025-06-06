#include <iostream>
#include <map>

#include "App.hpp"

#include "Util/Logger.hpp"
void App::two() {
     //mario Animated--------------------------------
    std::cout<<"null"<<std::endl;
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
    m_player->SetPosition({-510, 0});
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
    // bg=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/background/sky.png");
    // bg->SetPosition({0, 0});
    // bg->SetZIndex(1);
    // m_obj2.AddChild(bg);
    m_obj2.RemoveChild(bg);
    gameover=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/background/gameover.png");
    gameover->SetPosition({0, 0});
    gameover->SetZIndex(99);
    gameover->SetVisible(false);
    m_UI.AddChild(gameover);
    //-----------------UI--------------------------
    world=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/UI/world.png");
    world1=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/UI/1.png");
    world2=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/UI/-.png");
    world3=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/UI/3.png");
    world->SetPosition({-570, 280});
    world1->SetPosition({-500, 280});
    world2->SetPosition({-475, 275});
    world3->SetPosition({-450, 280});
    world->SetZIndex(99);
    world1->SetZIndex(99);
    world2->SetZIndex(99);
    world3->SetZIndex(99);
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
    worlds=13;
    coins=0;
    updatetime=0;
    mushroom_count=0;
    //-------------------------------------------------
    std::cout<<"null1"<<std::endl;
    auto result = m_background->NextPhase(3); // result 是 int (*)[30][200]
    std::cout<<"null2"<<std::endl;
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 200; j++) {
            Map[i][j] = (*result)[i][j]; // 解引用指標並複製資料
            if((*result[i][j]==NULL)) {
                std::cout<<"null"<<std::endl;
            }
        }
    }
    for(int i=0;i<30;i++) {
        for(int j=0;j<200;j++) {
            map_animate[i][j]=0;
            if((*result)[i][j]==1||(*result)[i][j]==9) {
                map_objects[i][j]=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/ground3.png");
               // std::cout<<"ok";
                map_objects[i][j]->SetPosition({-640+(j*48.0f),600-(i*48.0f)});
                map_objects[i][j]->SetZIndex(6);
                m_Root.AddChild(map_objects[i][j]);
                Map[i][j]=2;
                //std::cout <<"ok1"<< std::endl;
            }
            else if((*result)[i][j]==7||(*result)[i][j]==16||(*result)[i][j]==4) {
                map_objects[i][j]=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/brick3.png");
                map_objects[i][j]->SetPosition({-640+(j*48.0f),600-(i*48.0f)});
                map_objects[i][j]->SetZIndex(3);
                m_Root.AddChild(map_objects[i][j]);
                //std::cout <<"ok2"<< std::endl;
                Map[i][j]=4;
            }
            else if((*result)[i][j]==3) {
                map_objects[i][j]=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/mystery1_3.png");
                map_objects[i][j]->SetPosition({-640+(j*48.0f),600-(i*48.0f)});
                map_objects[i][j]->SetZIndex(3);
                m_Root.AddChild(map_objects[i][j]);
                item[mushroom_count]->SetPosition(map_objects[i][j]->GetPosition());
                mushroom_count++;
                //std::cout <<"ok3"<< std::endl;
            }
            else if((*result)[i][j]==8) {
                map_objects[i][j]=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/slab3.png");
                map_objects[i][j]->SetPosition({-640+(j*48.0f),600-(i*48.0f)});
                map_objects[i][j]->SetZIndex(3);
                m_Root.AddChild(map_objects[i][j]);
                //std::cout <<"ok4"<< std::endl;
                Map[i][j]=1;
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
            flagpole->SetZIndex(2);
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
        else if(Map[i][j]==150) {
            map_objects[i][j]=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/axe3.png");
            map_objects[i][j]->SetPosition({-640+(j*48.0f),600-(i*48.0f)});
            map_objects[i][j]->SetZIndex(3);
            m_Root.AddChild(map_objects[i][j]);
            //std::cout <<"ok6"<< std::endl;
        }
        else if(Map[i][j]==18) {
            map_objects[i][j]=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/castle_bridge.png");
            map_objects[i][j]->SetPosition({-640+(j*48.0f),600-(i*48.0f)});
            map_objects[i][j]->SetZIndex(3);
            m_Root.AddChild(map_objects[i][j]);
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
        goomba[i]->SetZIndex(8);
        goomba[i]->SetImage(1);
        goomba[i]->SetVisible(true);
        m_Root.AddChild(goomba[i]);
        enemyx[i]=-2.0f;
        goomba_dead[i]=false;
        goomba_dead_fire[i]=false;
        goomba_dead_animate[i]=0;
    }

    goomba[0]->SetPosition({0, 0});
    goomba[1]->SetPosition({300, 0});
    goomba[2]->SetPosition({620, 0});
    enemyx[2]*=-1;
    goomba[3]->SetPosition({1020, 0});
    goomba[4]->SetPosition({4670, 0});
    goomba[5]->SetPosition({5000, 0});
    goomba[6]->SetPosition({4800, 0});
    goomba[7]->SetPosition({4870, 0});
    goomba[8]->SetPosition({2900, 0});
    goomba[9]->SetPosition({100, 100});
    std::vector<std::string> fireballimg;
    std::vector<std::string> fireballimgp;
    for (int i = 0; i < 4; ++i) {
        fireballimg.emplace_back(GA_RESOURCE_DIR"/Image/Fire/fireball" + std::to_string(i + 1) + ".png");
    }
    for (int i = 0; i < 3; ++i) {
        fireballimgp.emplace_back(GA_RESOURCE_DIR"/Image/Fire/fireball_explode" + std::to_string(i + 1) + ".png");
    }
    fireball=std::make_shared<AnimatedCharacter>(fireballimg,fireballimgp,mario_stand,mario_stand,mario_stand,mario_stand,mario_stand,mario_stand,mario_stand,mario_stand,mario_stand,mario_stand,mario_stand);
    fireball->SetZIndex(6);
    fireball->SetImage(1);
    fireball->SetPosition(m_player->GetPosition());
    m_Root.AddChild(fireball);
    fireball->SetVisible(false);
    intopipe=false;
    outpipe=false;
    Animate_time=0;
    mario_size=1;
    end=false;
    m_up=false;
    player_dead=false;
    player_dead_animate=0;
    mario_hitbox={18.0f,24.0f};
    m_PlayerPosition={0.0f,0.0f};
    //startscreen->SetVisible(false);
    //m_UI.RemoveChild(startscreen);
    std::vector<std::string> bowserimg;
    for (int i = 0; i < 2; ++i) {
        bowserimg.emplace_back(GA_RESOURCE_DIR"/Image/enemy/bowser" + std::to_string(i + 1) + ".png");
    }
    std::vector<std::string> bowser_fireballimg;
    for (int i = 0; i < 2; ++i) {
        bowser_fireballimg.emplace_back(GA_RESOURCE_DIR"/Image/enemy/bowser_fireball" + std::to_string(i + 1) + ".png");
    }
    bowser=std::make_shared<AnimatedCharacter>(bowserimg,mario_stand,mario_stand,mario_stand,mario_stand,mario_stand,mario_stand,mario_stand,mario_stand,mario_stand,mario_stand,mario_stand,mario_stand);
    bowser_fireball=std::make_shared<AnimatedCharacter>(bowser_fireballimg,mario_stand,mario_stand,mario_stand,mario_stand,mario_stand,mario_stand,mario_stand,mario_stand,mario_stand,mario_stand,mario_stand,mario_stand);
    bowser->SetImage(1);
    bowser->SetZIndex(6);
    bowser->SetPosition({8096,0});
    bowser_fireball->SetImage(1);
    bowser_fireball->SetZIndex(6);
    bowser_x=0.0f;
    bowser_y=0.0f;
    bowser_count=0;
    bowser_jumpcount=0;
    bowser_jump=false;
    touchaxe=false;
    mario_op=false;
    touchcam=0;
    bowser->m_Transform.scale.x*=-1;
    m_Root.AddChild(bowser);
    bowser_fireball->SetVisible(false);
    bowser_fireball->SetPosition(bowser->GetPosition());
    bowser_fireball->m_Transform.scale.x*=-1;
    m_Root.AddChild(bowser_fireball);
    toad=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/Character/toad.png");
    toad->SetZIndex(6);
    toad->SetPosition({8720,-157.0f});
    m_Root.AddChild(toad);;
    std::cout<<"k"<<std::endl;
    m_CurrentState = State::UPDATE;
}
