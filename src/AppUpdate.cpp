#include <iostream>
#include <ostream>

#include "App.hpp"

#include "Util/Input.hpp"
#include "Util/Keycode.hpp"

void App::Update() {
    m_player->SetLooping(true);
    if(Util::Input::IsKeyDown(Util::Keycode::P)&&(!player_dead)) {
        m_player->SetPosition({0,0});
    }

    if(Util::Input::IsKeyPressed(Util::Keycode::D)&&!(Util::Input::IsKeyPressed(Util::Keycode::A))) {
        m_PlayerPosition.x+=m_speed;
        if(m_PlayerPosition.x>2.0f) {
            m_PlayerPosition.x=2.0f;
        }
    }
    if(Util::Input::IsKeyPressed(Util::Keycode::A)&&!(Util::Input::IsKeyPressed(Util::Keycode::D))) {
        m_PlayerPosition.x-=m_speed;
        if(m_PlayerPosition.x<-2.0f) {
            m_PlayerPosition.x=-2.0f;
        }
    }
    if(Util::Input::IsKeyDown(Util::Keycode::W)&&!m_up) {
        m_PlayerPosition.y+=m_upspeed;
        m_up=true;
    }
    if(m_PlayerPosition.y<-5.0f) {
        m_PlayerPosition.y=-5.0f;
    }

    if(!(Util::Input::IsKeyPressed(Util::Keycode::A))&&!(Util::Input::IsKeyPressed(Util::Keycode::D))) {
        m_PlayerPosition.x=0.0f;
        std::vector<std::string> Images;
        Images.emplace_back(GA_RESOURCE_DIR"/Image/Character/mario_stand.png");
        m_player->SetImage(Images);
    }
    else {
        m_player->SetImage(marioImages);
    }
    m_PlayerPosition.y-=downspeed;
    enemyy-=downspeed;
    //Collison-------------------------
    int (*Map)[200]=m_background->NextPhase(1);
    for(int i=0;i<20;i++) {
        for(int j=0;j<200;j++) {
            if (Map[i][j] == 2 || Map[i][j] == 3 || Map[i][j] == 4 || Map[i][j] == 1 || Map[i][j]==120 || Map[i][j]==121 || Map[i][j]==122 || Map[i][j]==123 || Map[i][j]==200) {
                //--------character collison---------------
                if (m_Collision.CheckCollision({(m_player->GetPosition().x+m_PlayerPosition.x),(m_player->GetPosition().y)}, map_objects[i][j]->GetPosition(),5.0f,8.0f,8.0f,8.0f)) {
                  m_PlayerPosition.x=0;
                }
                if (m_Collision.CheckCollision({(m_player->GetPosition().x),(m_player->GetPosition().y+m_PlayerPosition.y)}, map_objects[i][j]->GetPosition(),5.0f,8.0f,8.0f,8.0f)) {
                    if(m_PlayerPosition.y<0.0f) {m_up=false;}
                    if(m_PlayerPosition.y>0.0f&&Map[i][j]==3) {
                        map_objects[i][j]->SetImage(GA_RESOURCE_DIR"/Image/mapObjects/obstacle2.png");
                        Map[i][j]=200;
                    }
                    else if(m_PlayerPosition.y>0.0f&&Map[i][j]==4) {
                        m_Root.RemoveChild(map_objects[i][j]);
                        Map[i][j]=201;
                    }
                    m_PlayerPosition.y=0;
                }
                //-----------------------------------------

                if(m_Collision.CheckCollision({(goomba->GetPosition().x+enemyx),(goomba->GetPosition().y)}, map_objects[i][j]->GetPosition(),8.0f,5.0f,8.0f,8.0f)) {
                    enemyx*=-1;
                }
                if(m_Collision.CheckCollision({(goomba->GetPosition().x),(goomba->GetPosition().y+enemyy)}, map_objects[i][j]->GetPosition(),8.0f,5.0f,8.0f,8.0f)) {
                    enemyy=0.0f;
                }
            }
        }
    }
    if(m_Collision.CheckCollision(goomba->GetPosition(),m_player->GetPosition() ,8.0f,5.0f,5.0f,8.0f)) {
        if(m_PlayerPosition.y<0.0f) {
            m_Root.RemoveChild(goomba);
            goomba->SetPosition({-400,-400});
        }

        else {
            player_dead=true;
        }
        //std::cout<<m_PlayerPosition.x<<" "<<m_PlayerPosition.y<<std::endl;
    }
    if(player_dead){
        m_PlayerPosition.x=0.0f;
        m_PlayerPosition.y=0.0f;
        enemyx=0.0f;
        enemyy=0.0f;
    }
    if(m_player->GetPosition().y<-180.0f) {
        player_dead=true;
    }
    m_player->SetPosition({m_PlayerPosition.x+m_player->GetPosition().x,m_PlayerPosition.y+m_player->GetPosition().y});
    goomba->SetPosition({goomba->GetPosition().x+enemyx,goomba->GetPosition().y+enemyy});

    //---------------------------------
    //人物轉向------------------------------------------
    if(m_PlayerPosition.x>0.0f&&m_player->m_Transform.scale.x<0) {
        //std::cout<<"face right:"<<m_PlayerPosition.x<<std::endl;
        m_player->m_Transform.scale.x*=-1;
    }
    else if(m_PlayerPosition.x<0.0f&&m_player->m_Transform.scale.x>0) {
        //std::cout<<"face left:"<<m_PlayerPosition.x<<std::endl;
        m_player->m_Transform.scale.x*=-1;
    }
    //-------------------------------------------------
    //bounder---------------------------------
        if(m_player->GetPosition().x>319.0f||m_player->GetPosition().x<-319.0f) {
            if(m_player->GetPosition().x>319.0f) {m_player->SetPosition({m_player->GetPosition().x-1.0f,m_player->GetPosition().y});}
            if(m_player->GetPosition().x<319.0f) {m_player->SetPosition({m_player->GetPosition().x+1.0f,m_player->GetPosition().y});}
            m_PlayerPosition.x=0.0f;
        }
    //----------------------------------------
        if(Util::Input::IsKeyDown(Util::Keycode::R)&&player_dead) {
            m_Root.RemoveChild(m_player);
            m_Root.RemoveChild(goomba);
            for(int i=0;i<20;i++) {
                for(int j=0;j<200;j++) {
                    if(Map[i][j]==200){Map[i][j]=3;}
                    if(Map[i][j]==201){Map[i][j]=4;}
                    m_Root.RemoveChild(map_objects[i][j]);
                }
            }
            m_CurrentState=State::START;
        }
    if(Util::Input::IsKeyDown(Util::Keycode::O)) {
        std::cout<<m_player->GetPosition().x<<","<<m_player->GetPosition().y<<std::endl;
        std::cout<<"movement:"<<m_PlayerPosition.x<<","<<m_PlayerPosition.y<<std::endl;
    }

        //std::cout<<m_player->IsLooping()<<std::endl;

        /*
         *  Do not touch the code below as they serve the purpose for validating the tasks,
         *  rendering the frame, and exiting the game.
        */

        if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) || Util::Input::IfExit()) {
            m_CurrentState = State::END;
        }

        if (m_EnterDown) {
            if (!Util::Input::IsKeyPressed(Util::Keycode::RETURN)) {
                ValidTask();
            }
        }

        m_EnterDown = Util::Input::IsKeyPressed(Util::Keycode::RETURN);


        //camera----------------------------------------
        if(m_player->GetPosition().x>0.0f&&!(map_objects[19][199]->GetPosition().x<320.0f)){m_Root.Update({-(m_PlayerPosition.x),0.0f});}
        else{m_Root.Update({0.0f,0.0f});}
        m_obj.Update({0.0f,0.0f});
        //----------------------------------------------
}
