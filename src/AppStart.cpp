#include <iostream>
#include <map>

#include "App.hpp"

#include "Util/Logger.hpp"

void App::Start() {
    LOG_TRACE("Start");

    marioImages.reserve(3);
    for (int i = 0; i < 3; ++i) {
        marioImages.emplace_back(GA_RESOURCE_DIR"/Image/Character/mario_run" + std::to_string(i + 1) + ".png");
    }

    m_player = std::make_shared<AnimatedCharacter>(marioImages);
    m_player->SetPosition({-200, 0});
    m_player->SetZIndex(5);
    m_Root.AddChild(m_player);
    player_dead=false;
    m_background=std::make_shared<BackgroundImage>();
    time=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/time.png");
    time->SetPosition({250, 130});
    time->SetZIndex(5);
    m_obj.AddChild(time);
    bg=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/background/sky.png");
    bg->SetPosition({0, 0});
    bg->SetZIndex(1);
    m_obj.AddChild(bg);
     int (*Map)[200] = m_background->NextPhase(1);

    for(int i=0;i<20;i++) {
        for(int j=0;j<200;j++) {
            if(Map[i][j]==2) {
                map_objects[i][j]=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/stone.png");
               // std::cout<<"ok";
                map_objects[i][j]->SetPosition({-320+(j*16),150-(i*16)});
                map_objects[i][j]->SetZIndex(2);
                m_Root.AddChild(map_objects[i][j]);
                //std::cout <<"ok1"<< std::endl;
            }
            else if(Map[i][j]==4) {
                map_objects[i][j]=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/wall.png");
                map_objects[i][j]->SetPosition({-320+(j*16),150-(i*16)});
                map_objects[i][j]->SetZIndex(2);
                m_Root.AddChild(map_objects[i][j]);
                //std::cout <<"ok2"<< std::endl;
            }
            else if(Map[i][j]==3) {
                map_objects[i][j]=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/box.png");
                map_objects[i][j]->SetPosition({-320+(j*16),150-(i*16)});
                map_objects[i][j]->SetZIndex(2);
                m_Root.AddChild(map_objects[i][j]);
                //std::cout <<"ok3"<< std::endl;
            }
            else if(Map[i][j]==1) {
                map_objects[i][j]=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/obstacle1.png");
                map_objects[i][j]->SetPosition({-320+(j*16),150-(i*16)});
                map_objects[i][j]->SetZIndex(2);
                m_Root.AddChild(map_objects[i][j]);
                //std::cout <<"ok4"<< std::endl;
            }
            else if(Map[i][j]==17) {
                map_objects[i][j]=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/grass.png");
                map_objects[i][j]->SetPosition({-320+(j*16),150-(i*16)});
                map_objects[i][j]->SetZIndex(3);
                m_Root.AddChild(map_objects[i][j]);
                //std::cout <<"ok5"<< std::endl;
            }
            else if(Map[i][j]==5) {
                map_objects[i][j]=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/cloud_1.png");
                map_objects[i][j]->SetPosition({-320+(j*16),150-(i*16)});
                map_objects[i][j]->SetZIndex(3);
                m_Root.AddChild(map_objects[i][j]);
                //std::cout <<"ok6"<< std::endl;
            }
            else if(Map[i][j]==120) {
                map_objects[i][j]=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/pipe_lefttop.png");
                map_objects[i][j]->SetPosition({-320+(j*16),150-(i*16)});
                map_objects[i][j]->SetZIndex(3);
                m_Root.AddChild(map_objects[i][j]);
                //std::cout <<"ok6"<< std::endl;
            }
            else if(Map[i][j]==121) {
                map_objects[i][j]=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/pipe_righttop.png");
                map_objects[i][j]->SetPosition({-320+(j*16),150-(i*16)});
                map_objects[i][j]->SetZIndex(3);
                m_Root.AddChild(map_objects[i][j]);
                //std::cout <<"ok6"<< std::endl;
            }
            else if(Map[i][j]==122) {
                map_objects[i][j]=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/pipe_leftbottom.png");
                map_objects[i][j]->SetPosition({-320+(j*16),150-(i*16)});
                map_objects[i][j]->SetZIndex(3);
                m_Root.AddChild(map_objects[i][j]);
                //std::cout <<"ok6"<< std::endl;
            }
            else if(Map[i][j]==123) {
                map_objects[i][j]=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/mapObjects/pipe_rightbottom.png");
                map_objects[i][j]->SetPosition({-320+(j*16),150-(i*16)});
                map_objects[i][j]->SetZIndex(3);
                m_Root.AddChild(map_objects[i][j]);
                //std::cout <<"ok6"<< std::endl;
            }
            //std::cout <<i<<" "<<j<< std::endl;
        }
    }

    goombaimg.reserve(2);
    for (int i = 0; i < 2; ++i) {
        goombaimg.emplace_back(GA_RESOURCE_DIR"/Image/enemy/a" + std::to_string(i + 1) + ".png");
    }
    goombadeadimg.emplace_back(GA_RESOURCE_DIR"/Image/enemy/a3.png");

    goomba=std::make_shared<AnimatedCharacter>(goombaimg);
    goomba->SetPosition({0, 0});
    goomba->SetZIndex(6);
    m_Root.AddChild(goomba);
    std::cout<<"k"<<std::endl;
    enemyx=-1.0f;
    goomba_dead=false;
    m_CurrentState = State::UPDATE;
}
