#include <iostream>
#include <ostream>

#include "App.hpp"

#include "Util/Input.hpp"
#include "Util/Keycode.hpp"

void App::Update() {
    if(Util::Input::IsKeyDown(Util::Keycode::P)&&(!player_dead)) {
        m_player->SetPosition({0,0});
    }

    if(Util::Input::IsKeyPressed(Util::Keycode::D)&&!(Util::Input::IsKeyPressed(Util::Keycode::A))){
        m_PlayerPosition.x+=m_speed;
        if(m_PlayerPosition.x>4.0f) {
            m_PlayerPosition.x=4.0f;
        }
    }
    if(Util::Input::IsKeyPressed(Util::Keycode::A)&&!(Util::Input::IsKeyPressed(Util::Keycode::D))) {
        m_PlayerPosition.x-=m_speed;
        if(m_PlayerPosition.x<-4.0f) {
            m_PlayerPosition.x=-4.0f;
        }
    }
    if(Util::Input::IsKeyDown(Util::Keycode::W)&&!m_up) {
        m_PlayerPosition.y+=m_upspeed;
        m_up=true;
        m_player->SetImage(2);
    }
    if(m_PlayerPosition.y<-8.0f) {
        m_PlayerPosition.y=-8.0f;
    }

    if(!(Util::Input::IsKeyPressed(Util::Keycode::A))&&!(Util::Input::IsKeyPressed(Util::Keycode::D))) {
        m_PlayerPosition.x=0.0f;
        if(m_PlayerPosition.x==0.0f&&(!m_up)) {
            m_player->SetImage(3);
        }
    }
    else {
        if(m_PlayerPosition.x!=0.0f&&(!m_up)) {
            m_player->SetImage(1);
        }
    }
    m_PlayerPosition.y-=downspeed;
    enemyy-=downspeed;
    //Collison-------------------------
    int (*Map)[200]=m_background->NextPhase(1);
    for(int i=0;i<20;i++) {
        for(int j=0;j<200;j++) {
            if (Map[i][j] == 2 || Map[i][j] == 3 || Map[i][j] == 4 || Map[i][j] == 1 || Map[i][j]==120 || Map[i][j]==121 || Map[i][j]==122 || Map[i][j]==123 || Map[i][j]==200) {
                //--------character collison---------------
                if (m_Collision.CheckCollision({(m_player->GetPosition().x+m_PlayerPosition.x),(m_player->GetPosition().y)}, map_objects[i][j]->GetPosition(),18.0f,24.0f,24.0f,24.0f)&&(!player_dead)) {
                    if(m_PlayerPosition.x>0.0f) {
                        float temp1=map_objects[i][j]->GetPosition().x-24.0f;
                        float temp2=m_player->GetPosition().x+18.0f;
                        m_player->SetPosition({m_player->GetPosition().x+(temp1-temp2),m_player->GetPosition().y,});
                    }
                    else if(m_PlayerPosition.x<0.0f) {
                        float temp1=map_objects[i][j]->GetPosition().x+24.0f;
                        float temp2=m_player->GetPosition().x-18.0f;
                        m_player->SetPosition({m_player->GetPosition().x+(temp1-temp2),m_player->GetPosition().y,});
                    }
                  m_PlayerPosition.x=0.0f;
                    //std::cout<<map_objects[i][j]->GetPosition().x<<" "<<map_objects[i][j]->GetPosition().y<<std::endl;
                    //std::cout<<m_player->GetPosition().x<<" "<<m_player->GetPosition().y<<std::endl;
                }
                else if (m_Collision.CheckCollision({(m_player->GetPosition().x),(m_player->GetPosition().y+m_PlayerPosition.y)}, map_objects[i][j]->GetPosition(),18.0f,24.0f,24.0f,24.0f)&&(!player_dead)) {
                    if(m_PlayerPosition.y<0.0f) {m_up=false;}
                    if(m_PlayerPosition.y>0.0f&&Map[i][j]==3) {
                        map_objects[i][j]->SetImage(GA_RESOURCE_DIR"/Image/mapObjects/empty1.png");
                        Map[i][j]=200;
                    }
                    else if(m_PlayerPosition.y>0.0f&&Map[i][j]==4) {
                        m_Root.RemoveChild(map_objects[i][j]);
                        Map[i][j]=201;
                    }
                    m_PlayerPosition.y=0.0f;
                    //std::cout<<map_objects[i][j]->GetPosition().x<<" "<<map_objects[i][j]->GetPosition().y<<std::endl;
                    //std::cout<<m_player->GetPosition().x<<" "<<m_player->GetPosition().y<<std::endl;
                }
                //-----------------------------------------

                if(m_Collision.CheckCollision({(goomba->GetPosition().x+enemyx),(goomba->GetPosition().y)}, map_objects[i][j]->GetPosition(),24.0f,24.0f,24.0f,24.0f)) {
                    enemyx*=-1;
                }
                if(m_Collision.CheckCollision({(goomba->GetPosition().x),(goomba->GetPosition().y+enemyy)}, map_objects[i][j]->GetPosition(),24.0f,24.0f,24.0f,24.0f)) {
                    enemyy=0.0f;
                }
            }
        }
    }
    if(m_Collision.CheckCollision(goomba->GetPosition(),m_player->GetPosition() ,24.0f,24.0f,18.0f,24.0f)&&goomba_dead==false&&player_dead==false) {
        if(m_PlayerPosition.y<0.0f) {
            goomba_dead=true;
            m_PlayerPosition.y=10.0f;
        }

        else{
            player_dead=true;
        }
        //std::cout<<m_PlayerPosition.x<<" "<<m_PlayerPosition.y<<std::endl;
    }
    if(player_dead){
        m_PlayerPosition.x=0.0f;
        m_PlayerPosition.y=0.0f;
        enemyx=0.0f;
        enemyy=0.0f;
        m_player->SetImage(10);
        Animate_time+=1;
        if(Animate_time>30&&Animate_time<50) {
            m_player->SetPosition({m_player->GetPosition().x,m_player->GetPosition().y+5.0f});
        }
        else if(Animate_time>50) {
            m_player->SetPosition({m_player->GetPosition().x,m_player->GetPosition().y-6.0f});
        }
        if(Animate_time>120) {
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
    }
    if(m_player->GetPosition().y<-450.0f) {
        player_dead=true;
        m_PlayerPosition.x=0.0f;
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
        if(m_player->GetPosition().x>630.0f||m_player->GetPosition().x<-630.0f) {
            if(m_player->GetPosition().x>630.0f) {m_player->SetPosition({m_player->GetPosition().x-1.0f,m_player->GetPosition().y});}
            if(m_player->GetPosition().x<-630.0f) {m_player->SetPosition({m_player->GetPosition().x+1.0f,m_player->GetPosition().y});}
            m_PlayerPosition.x=0.0f;
        }
    //----------------------------------------

    if(Util::Input::IsKeyDown(Util::Keycode::O)) {
        std::cout<<m_player->GetPosition().x<<","<<m_player->GetPosition().y<<std::endl;
        std::cout<<"movement:"<<m_PlayerPosition.x<<","<<m_PlayerPosition.y<<std::endl;
    }
    if(goomba_dead) {
        enemyx=0.0f;
        if(Animate_time<=25) {
            Animate_time+=1;
        }
        goomba->SetImage(2);
        if(Animate_time>25) {
            m_Root.RemoveChild(goomba);
        }
    }
    if(Util::Input::IsKeyDown(Util::Keycode::I)) {

    }
       // std::cout<<m_player->IsLooping()<<std::endl;

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
        if(m_player->GetPosition().x>0.0f&&!(map_objects[19][199]->GetPosition().x<640.0f)) {
            m_Root.Update({-(m_PlayerPosition.x),0.0f});
            m_obj2.Update({-(m_PlayerPosition.x),0.0f});
        }
        else {
            m_Root.Update({0.0f,0.0f});
            m_obj2.Update({0.0f,0.0f});
        }
        m_obj.Update({0.0f,0.0f});
        //----------------------------------------------
}
