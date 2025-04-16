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
            std::cout << i << std::endl;
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
    Imagej.emplace_back(GA_RESOURCE_DIR"/Image/Character/mario_jump.png");
    Imagejbig.emplace_back(GA_RESOURCE_DIR"/Image/Big/mario_jump.png");
    Imagejfire.emplace_back(GA_RESOURCE_DIR"/Image/Fire/mario_jump.png");
    mariodead.emplace_back(GA_RESOURCE_DIR"/Image/Character/mario_dead.png");
    //----------------------------------------------
    m_player = std::make_shared<AnimatedCharacter>(marioImages,Imagej,mario_stand,Imagebigrun,Imagejbig,Imagestandbig,Imagefirerun,Imagejfire,Imagestandfire,mariodead);
    m_player->SetPosition({0, 0});
    m_player->SetZIndex(5);
    m_player->SetImage(1);
    m_Root.AddChild(m_player);
    player_dead=false;
    m_background=std::make_shared<BackgroundImage>();
    bg=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/background/sky.png");
    bg->SetPosition({0, 0});
    bg->SetZIndex(1);
    m_obj.AddChild(bg);
    // bg2=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/background/bg1-1.png");
    // bg2->SetPosition({0, 0});
    // bg2->SetZIndex(2);
    // m_obj2.AddChild(bg2);
     int (*Map)[200] = m_background->NextPhase(1);

    for(int i=0;i<20;i++) {
        for(int j=0;j<200;j++) {
            if(Map[i][j]==2) {
                map_objects[i][j]=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/ground1.png");
               // std::cout<<"ok";
                map_objects[i][j]->SetPosition({-640+(j*48.0f),600-(i*48.0f)});
                map_objects[i][j]->SetZIndex(3);
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
                //std::cout <<"ok3"<< std::endl;
            }
            else if(Map[i][j]==1) {
                map_objects[i][j]=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/slab1.png");
                map_objects[i][j]->SetPosition({-640+(j*48.0f),600-(i*48.0f)});
                map_objects[i][j]->SetZIndex(3);
                m_Root.AddChild(map_objects[i][j]);
                //std::cout <<"ok4"<< std::endl;
            }
        else if(Map[i][j]==120) {
            map_objects[i][j]=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/pipe_lefttop.png");
            map_objects[i][j]->SetPosition({-640+(j*48.0f),600-(i*48.0f)});
            map_objects[i][j]->SetZIndex(3);
            m_Root.AddChild(map_objects[i][j]);
            //std::cout <<"ok6"<< std::endl;
        }
        else if(Map[i][j]==121) {
            map_objects[i][j]=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/pipe_righttop.png");
            map_objects[i][j]->SetPosition({-640+(j*48.0f),600-(i*48.0f)});
            map_objects[i][j]->SetZIndex(3);
            m_Root.AddChild(map_objects[i][j]);
            //std::cout <<"ok6"<< std::endl;
        }
        else if(Map[i][j]==122) {
            map_objects[i][j]=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/pipe_leftbottom.png");
            map_objects[i][j]->SetPosition({-640+(j*48.0f),600-(i*48.0f)});
            map_objects[i][j]->SetZIndex(3);
            m_Root.AddChild(map_objects[i][j]);
            //std::cout <<"ok6"<< std::endl;
        }
        else if(Map[i][j]==123) {
            map_objects[i][j]=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/pipe_rightbottom.png");
            map_objects[i][j]->SetPosition({-640+(j*48.0f),600-(i*48.0f)});
            map_objects[i][j]->SetZIndex(3);
            m_Root.AddChild(map_objects[i][j]);
            //std::cout <<"ok6"<< std::endl;
        }
        //std::cout <<i<<" "<<j<< std::endl;
        }
    }

    goombaimg.reserve(2);
    for (int i = 0; i < 2; ++i) {
        goombaimg.emplace_back(GA_RESOURCE_DIR"/Image/enemy/goomba1_" + std::to_string(i + 1) + ".png");
    }
    goombadeadimg.emplace_back(GA_RESOURCE_DIR"/Image/enemy/goomba1_dead.png");

    goomba=std::make_shared<AnimatedCharacter>(goombaimg,goombadeadimg,mario_stand,mario_stand,mario_stand,mario_stand,mario_stand,mario_stand,mario_stand,mario_stand);
    goomba->SetPosition({200, 0});
    goomba->SetZIndex(6);
    goomba->SetImage(1);
    m_Root.AddChild(goomba);
    std::cout<<"k"<<std::endl;
    enemyx=-2.0f;
    goomba_dead=false;
    Animate_time=0;
    m_CurrentState = State::UPDATE;
}
