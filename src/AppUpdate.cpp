#include <iostream>
#include <ostream>

#include "App.hpp"

#include "Util/Input.hpp"
#include "Util/Keycode.hpp"

void App::Update() {
    //--------------move and change image-----------------------
    //if(Util::Input::IsKeyDown(Util::Keycode::P)){
   // std::cout << m_player->GetPosition().y << std::endl;
        // if(opmode) {
        //     opmode = false;
        //     downspeed=1.0f;
        //     m_PlayerPosition.y=0;
        //     m_PlayerPosition.x=0;
        // }
        // else {
        //     opmode = true;
        //     downspeed=0.0f;
        // }
   // }
    // if(Util::Input::IsKeyDown(Util::Keycode::S)&&(opmode)) {
    //     m_player->SetPosition({m_player->GetPosition().x,m_player->GetPosition().y
    // -22.0f});
    // }
    // if(Util::Input::IsKeyDown(Util::Keycode::W)&&(opmode)) {
    //     m_player->SetPosition({m_player->GetPosition().x,m_player->GetPosition().y
    // +22.0f});
    // }
    // if(Util::Input::IsKeyDown(Util::Keycode::D)&&(opmode)) {
    //     m_player->SetPosition({m_player->GetPosition().x+22.0f,m_player->GetPosition().y});
    // }
    // if(Util::Input::IsKeyDown(Util::Keycode::A)&&(opmode)) {
    //     m_player->SetPosition({m_player->GetPosition().x-22.0f,m_player->GetPosition().y});
    // }
    if(Util::Input::IsKeyPressed(Util::Keycode::D)&&!(Util::Input::IsKeyPressed(Util::Keycode::A)&&(!end))){
        m_PlayerPosition.x+=m_speed;
        if(m_PlayerPosition.x>5.0f) {
            m_PlayerPosition.x=5.0f;
        }
    }
    if(Util::Input::IsKeyPressed(Util::Keycode::U)&&!(fireballac)&&!(fireballdead)&&mario_size==3){
        fireballac=true;
    }
    if(Util::Input::IsKeyPressed(Util::Keycode::A)&&!(Util::Input::IsKeyPressed(Util::Keycode::D)&&(!end))) {
        m_PlayerPosition.x-=m_speed;
        if(m_PlayerPosition.x<-5.0f) {
            m_PlayerPosition.x=-5.0f;
        }
    }
    if(Util::Input::IsKeyDown(Util::Keycode::W)&&!m_up&&(!end)&&!(op)) {
        m_PlayerPosition.y+=m_upspeed;
        m_up=true;
    }
    if(Util::Input::IsKeyPressed(Util::Keycode::W)&&(!end)&&(op)) {
        m_player->SetPosition({m_player->GetPosition().x, m_player->GetPosition().y+3.0f});
    }
    if(Util::Input::IsKeyPressed(Util::Keycode::S)&&(!end)&&(op)) {
        m_player->SetPosition({m_player->GetPosition().x, m_player->GetPosition().y-3.0f});
    }
    if(Util::Input::IsKeyDown(Util::Keycode::P)) {
        if(op) {
            op=false;
        }
        else {
            op=true;
            m_PlayerPosition.y=0.0f;
        }
    }
    if(m_up) {
        if(mario_size==2){m_player->SetImage(5);}
        else if(mario_size==3){m_player->SetImage(8);}
        else {
            m_player->SetImage(2);
        }
    }
    if(m_PlayerPosition.y<-8.0f) {
        m_PlayerPosition.y=-8.0f;
    }
    //std::cout<<"check1"<<std::endl;
    if(!(Util::Input::IsKeyPressed(Util::Keycode::A))&&!(Util::Input::IsKeyPressed(Util::Keycode::D))) {
        m_PlayerPosition.x=0.0f;
        if(m_PlayerPosition.x==0.0f&&(!m_up)) {
            if(mario_size==2){m_player->SetImage(6);}
            else if(mario_size==3){m_player->SetImage(9);}
            else {
                m_player->SetImage(3);
            }
        }
    }
    else {
        if(m_PlayerPosition.x!=0.0f&&(!m_up)) {
            if(mario_size==2){m_player->SetImage(4);}
            else if(mario_size==3){m_player->SetImage(7);}
            else {
                m_player->SetImage(1);
            }
        }
    }
    if(!op) {
        m_PlayerPosition.y-=downspeed;
    }
    for(int i=0;i<10;i++) {
        if(goomba[i]->GetPosition().x<700.f){
            enemyy[i]-=downspeed;
        }
    }
    if(worlds==13) {
        bowser_y-=downspeed;
    }
    //---------------------------------
    //Collison-------------------------

    //std::cout<<"check2"<<std::endl;
    for(int i=0;i<30;i++) {
        for(int j=0;j<200;j++) {
            //std::cout<<i<<" "<<j<<std::endl;
            if (Map[i][j] == 2 || Map[i][j] == 3 || Map[i][j] == 4 || Map[i][j] == 1 || Map[i][j]==120 || Map[i][j]==121 || Map[i][j]==122 || Map[i][j]==123 || Map[i][j]==200||Map[i][j]==124||Map[i][j]==125||Map[i][j]==126||Map[i][j]==127||Map[i][j]==5||Map[i][j]==6||Map[i][j]==128||Map[i][j]==129||Map[i][j]==130||Map[i][j]==131||Map[i][j]==18||Map[i][j]==150) {
                //--------character collison---------------
                //std::cout<<"check3"<<std::endl;
                //std::cout<<i<<" "<<j<<std::endl;
                if (m_Collision.CheckCollision({(m_player->GetPosition().x+m_PlayerPosition.x),(m_player->GetPosition().y)}, map_objects[i][j]->GetPosition(),mario_hitbox.x,mario_hitbox.y,24.0f,24.0f)&&(!player_dead)&&(!intopipe)&&(!op)) {
                    //std::cout<<"check18"<<std::endl;
                    if(m_PlayerPosition.x>0.0f) {
                        //std::cout<<"check12"<<std::endl;
                        float temp1=map_objects[i][j]->GetPosition().x-24.0f;
                        float temp2=m_player->GetPosition().x+mario_hitbox.x;
                        m_player->SetPosition({m_player->GetPosition().x+(temp1-temp2),m_player->GetPosition().y,});
                    }
                    else if(m_PlayerPosition.x<0.0f) {
                        //std::cout<<"check13"<<std::endl;
                        float temp1=map_objects[i][j]->GetPosition().x+24.0f;
                        float temp2=m_player->GetPosition().x-mario_hitbox.x;
                        m_player->SetPosition({m_player->GetPosition().x+(temp1-temp2),m_player->GetPosition().y,});
                    }
                    if(Map[i][j]==150) {
                        touchaxe=true;
                    }
                  m_PlayerPosition.x=0.0f;
                    //std::cout<<map_objects[i][j]->GetPosition().x<<" "<<map_objects[i][j]->GetPosition().y<<std::endl;
                    //std::cout<<m_player->GetPosition().x<<" "<<m_player->GetPosition().y<<std::endl;
                    //std::cout<<"check4"<<std::endl;
                }

                else if (m_Collision.CheckCollision({(m_player->GetPosition().x),(m_player->GetPosition().y+m_PlayerPosition.y)}, map_objects[i][j]->GetPosition(),mario_hitbox.x,mario_hitbox.y,24.0f,24.0f)&&(!player_dead)&&(!intopipe)&&(!opmode)) {
                   // std::cout<<"check19"<<std::endl;
                    if(m_PlayerPosition.y<0.0f) {
                        m_up=false;
                        //std::cout<<"check15"<<std::endl;
                        float temp1=map_objects[i][j]->GetPosition().y+24.0f;
                        float temp2=m_player->GetPosition().y-mario_hitbox.y;
                        m_player->SetPosition({m_player->GetPosition().x,m_player->GetPosition().y+(temp1-temp2),});
                        if(Util::Input::IsKeyDown(Util::Keycode::S)&&(Map[i][j]==124||Map[i][j]==125)) {
                            intopipe=true;
                            temppipe1=i;
                            temppipe2=j;
                        }
                        if(Util::Input::IsKeyDown(Util::Keycode::S)&&(Map[i][j]==128||Map[i][j]==129)) {
                            outpipe=true;
                            temppipe1=i;
                            temppipe2=j;
                        }
                        if(Map[i][j]==150) {
                            touchaxe=true;
                        }
                       // std::cout<<"check5"<<std::endl;
                    }
                    if(m_PlayerPosition.y>0.0f&&Map[i][j]==3) {
                        //std::cout<<"check6"<<std::endl;
                        map_objects[i][j]->SetImage(GA_RESOURCE_DIR"/Image/mapObjects/empty1.png");
                        Map[i][j]=200;
                        float temp1=map_objects[i][j]->GetPosition().y-24.0f;
                        float temp2=m_player->GetPosition().y+mario_hitbox.y;
                        m_player->SetPosition({m_player->GetPosition().x,m_player->GetPosition().y+(temp1-temp2),});
                        for(int x=0;x<16;x++) {
                           // std::cout<<"check7"<<std::endl;
                            if(item[x]->GetPosition()==map_objects[i][j]->GetPosition()&&x%5==0&&mario_size==1) {
                                item[x]->SetVisible(true);
                                item[x]->SetPosition({item[x]->GetPosition().x,map_objects[i][j]->GetPosition().y+48.0f});
                            }
                            else if(item[x]->GetPosition()==map_objects[i][j]->GetPosition()&&x%5==0&&mario_size>=2) {
                                item[x]->SetImage(GA_RESOURCE_DIR"/Image/item/fireflower1.png");
                                item[x]->SetVisible(true);
                                itemx[x]=0.0f;
                                item[x]->SetPosition({item[x]->GetPosition().x,map_objects[i][j]->GetPosition().y+48.0f});
                            }
                            else if(item[x]->GetPosition()==map_objects[i][j]->GetPosition()){
                                item[x]->SetImage(GA_RESOURCE_DIR"/Image/item/coin1.png");
                                coins+=1;
                                item[x]->SetVisible(true);
                                itemx[x]=0.0f;
                                itemcoin[x]=true;
                                item[x]->SetPosition({item[x]->GetPosition().x,map_objects[i][j]->GetPosition().y+48.0f});
                            }
                        }
                    }
                    else if(m_PlayerPosition.y>0.0f&&Map[i][j]==4&&mario_size>1) {
                        //std::cout<<"check7"<<std::endl;
                        m_Root.RemoveChild(map_objects[i][j]);
                        Map[i][j]=201;
                        float temp1=map_objects[i][j]->GetPosition().y-24.0f;
                        float temp2=m_player->GetPosition().y+mario_hitbox.y;
                        m_player->SetPosition({m_player->GetPosition().x,m_player->GetPosition().y+(temp1-temp2),});
                    }

                    m_PlayerPosition.y=0.0f;
                    //std::cout<<map_objects[i][j]->GetPosition().x<<" "<<map_objects[i][j]->GetPosition().y<<std::endl;
                    //std::cout<<m_player->GetPosition().x<<" "<<m_player->GetPosition().y<<std::endl;
                }
                //-----------------------------------------
                for(int k=0;k<10;k++) {
                    if(m_Collision.CheckCollision({(goomba[k]->GetPosition().x+enemyx[k]),(goomba[k]->GetPosition().y)}, map_objects[i][j]->GetPosition(),24.0f,24.0f,24.0f,24.0f)&&goomba_dead_fire[k]==false) {
                        enemyx[k]*=-1;
                    }
                    if(m_Collision.CheckCollision({(goomba[k]->GetPosition().x),(goomba[k]->GetPosition().y+enemyy[k])}, map_objects[i][j]->GetPosition(),24.0f,24.0f,24.0f,24.0f)&&goomba_dead_fire[k]==false) {
                        enemyy[k]=0.0f;
                    }
                }
                for(int x=0;x<16;x++) {
                    //std::cout<<"check8"<<std::endl;
                    if(item[x]->GetVisibility()==true) {

                        if(m_Collision.CheckCollision({(item[x]->GetPosition().x+itemx[x]),(item[x]->GetPosition().y)},map_objects[i][j]->GetPosition(),24.0f,24.0f,24.0f,24.0f)) {
                            itemx[x]*=-1;
                        }
                        if(m_Collision.CheckCollision({(item[x]->GetPosition().x),(item[x]->GetPosition().y+itemy[x])},map_objects[i][j]->GetPosition(),24.0f,24.0f,24.0f,24.0f)) {
                            itemy[x]=0.0f;
                        }
                    }
                }
                if(m_Collision.CheckCollision({fireball->GetPosition().x,fireball->GetPosition().y+fireballspeedy},map_objects[i][j]->GetPosition(),24.0f,24.0f,24.0f,24.0f)) {
                    fireballspeedy=0.0f;
                    fireballspeedy+=6.0f;
                }
                else if(m_Collision.CheckCollision({fireball->GetPosition().x+fireballspeed,fireball->GetPosition().y},map_objects[i][j]->GetPosition(),24.0f,24.0f,24.0f,24.0f)) {
                        fireballspeed=0.0f;
                        fireballdead=true;
                }
                if(worlds==13) {
                    if(m_Collision.CheckCollision({bowser->GetPosition().x,bowser->GetPosition().y+bowser_y},map_objects[i][j]->GetPosition(),48.0f,48.0f,24.0f,24.0f)) {
                        bowser_y=0.0f;
                        bowser_jump=false;
                    }
                    if(m_Collision.CheckCollision({bowser->GetPosition().x+bowser_x,bowser->GetPosition().y},map_objects[i][j]->GetPosition(),48.0f,48.0f,24.0f,24.0f)) {
                        bowser_x=0.0f;
                    }
                    if(touchaxe) {
                        if(Map[i][j]==18) {
                            Map[i][j]=0;
                            m_Root.RemoveChild(map_objects[i][j]);
                        }
                    }
                }
            }
        }
    }
    //------coillson with briges-------------
    if(worlds==12) {
        for(int j=0;j<2;j++) {
            if(j==0) {
                bridges[j]->SetPosition({bridges[j]->GetPosition().x,bridges[j]->GetPosition().y+(2*bridge_upspeed)});
            }
            if(j==1) {
                bridges[j]->SetPosition({bridges[j]->GetPosition().x,bridges[j]->GetPosition().y+(bridge_upspeed)});
            }
            if(bridges[0]->GetPosition().y>600.0f) {
                bridges[0]->SetPosition({bridges[0]->GetPosition().x,-440.0f});
            }
            if(bridges[1]->GetPosition().y>650.0f) {
                bridges[1]->SetPosition({bridges[1]->GetPosition().x,-440.0f});
            }
        }
        for(int i=0;i<2;i++) {
            if(m_Collision.CheckCollision({m_player->GetPosition().x,m_player->GetPosition().y+m_PlayerPosition.y},bridges[i]->GetPosition(),mario_hitbox.x,mario_hitbox.y,72.0f,12.0f)&&(!opmode)) {
                if(m_PlayerPosition.y<=0) {
                    m_up=false;
                    float temp1=bridges[i]->GetPosition().y+12.0f;
                    float temp2=m_player->GetPosition().y-mario_hitbox.y;
                    m_player->SetPosition({m_player->GetPosition().x,m_player->GetPosition().y+(temp1-temp2),});
                }
                m_PlayerPosition.y=0.0f;
            }
            else if(m_Collision.CheckCollision({m_player->GetPosition().x,m_player->GetPosition().y},bridges[i]->GetPosition(),mario_hitbox.x,mario_hitbox.y,72.0f,12.0f)&&(!opmode)) {
                m_PlayerPosition.x=0.0f;
            }
        }
    }
    //---------------------------------------
    //std::cout<<"checkx"<<std::endl;
    //-------mario eat item---------------------
    for(int x=0;x<16;x++) {
        if(item[x]->GetVisibility()==true&&!(itemcoin[x])) {
            if(m_Collision.CheckCollision(item[x]->GetPosition(),m_player->GetPosition(),24.0f,24.0f,mario_hitbox.x,mario_hitbox.y)) {
                if(mario_size==1) {
                    mario_size=2;
                    mario_hitbox={24.0f,48.0f};
                    m_player->SetPosition({m_player->GetPosition().x,m_player->GetPosition().y+24.0f});
                }
                else if(mario_size==2&&itemx[x]==0.0f) {
                    mario_size=3;
                }
                m_Root.RemoveChild(item[x]);
                item[x]->SetVisible(false);

            }
        }
        else if(itemcoin[x]) {
            item[x]->SetPosition({item[x]->GetPosition().x,item[x]->GetPosition().y+10.0f});
            itemtime[x]+=1;
            if(itemtime[x]>10) {
                item[x]->SetVisible(false);
                m_Root.RemoveChild(item[x]);
            }
        }
    }
    //std::cout<<"check4"<<std::endl;
    //---------------------------------------------
    //------------intopipe-------------------------
    //std::cout<<"checkxxx"<<std::endl;
    //---------------------------------------------
    //----------------------fireball------------------------
    if(fireballac) {
        if(fireballbreaktime==0) {
            fireball->SetPosition(m_player->GetPosition());
            fireballbreaktime=1;
            if(playerface==1) {
                fireballspeed=8.0f;
            }
            else if(playerface==-1) {
                fireballspeed=-8.0f;
            }
        }
        fireball->SetVisible(true);
        fireballspeedy-=downspeed;
        if(fireballspeedy<=-5.0f) {
            fireballspeedy=-5.0f;
        }
        fireball->SetPosition({fireball->GetPosition().x+fireballspeed,fireball->GetPosition().y+fireballspeedy});
    }
    if(fireballdead) {
        fireballspeed=0.0f;
        fireballspeedy=0.0f;
        fireballac=false;
        fireballbreaktime+=1;
        fireball->SetImage(2);
        if(fireballbreaktime>15) {
            fireball->SetVisible(false);
            fireball->SetLooping(true);
            fireball->SetImage(1);
            fireball->SetPosition(m_player->GetPosition());
        }
        if(fireballbreaktime>40) {
            fireballdead=false;
            fireballac=false;
            fireballspeed=8.0f;
            fireballbreaktime=0;
        }
    }
    if(fireball->GetPosition().x>640.0f||fireball->GetPosition().x<-640.0f) {
        fireballdead=true;
    }
    //------------------------------------------------------
    //-----------collison with flag--------------------------
    if(worlds!=13&&m_Collision.CheckCollision(m_player->GetPosition(), flagpole->GetPosition(),mario_hitbox.x,mario_hitbox.y,6.0f,480.0f)) {
        if(m_player->GetPosition().y-mario_hitbox.y>flagpole->GetPosition().y-215.0f) {
            m_PlayerPosition.y=-1.0f;
            m_PlayerPosition.x=0.0f;
            flagtime=0;
        }
        else {
            m_PlayerPosition.y=0.0f;
            m_PlayerPosition.x=0.0f;
        }
        if(flag->GetPosition().y-24.0f>flagpole->GetPosition().y-215.0f) {
            end=false;
            flag->SetPosition({flag->GetPosition().x,flag->GetPosition().y-2.0f});
        }
        if(m_player->GetPosition().y-mario_hitbox.y<=flagpole->GetPosition().y-215.0f&&flag->GetPosition().y-24.0f<=flagpole->GetPosition().y-215.0f) {
            end=true;
        }
        if(mario_size==1) {
            m_player->SetImage(11);
        }
        else if(mario_size==2) {
            m_player->SetImage(12);
        }
        else if(mario_size==3) {
            m_player->SetImage(13);
        }
    }
    if(end&&worlds!=13) {
        op=false;
        if(flagtime==0) {
            m_player->SetPosition({m_player->GetPosition().x+(mario_hitbox.x*2)+6.0f,m_player->GetPosition().y});
            m_player->m_Transform.scale.x*=-1;
        }
        flagtime+=1;
        if(flagtime>70) {
            m_player->SetPosition({m_player->GetPosition().x+3.0f,m_player->GetPosition().y});
            if(flagtime==71) {
                m_player->m_Transform.scale.x*=-1;
            }
            if(mario_size==2){m_player->SetImage(4);}
            else if(mario_size==3){m_player->SetImage(7);}
            else {
                m_player->SetImage(1);
            }
            if(m_player->GetPosition().x>castle->GetPosition().x) {
                m_player->SetVisible(false);
                m_PlayerPosition.x=0.0f;
                m_Root.RemoveChild(m_player);
                for(int x=0;x<10;x++) {
                    enemyx[x]=0.0f;
                    enemyy[x]=0.0f;
                }
                for(int x=0;x<10;x++) {
                    m_Root.RemoveChild(goomba[x]);
                }
                for(int i=0;i<30;i++) {
                    for(int j=0;j<200;j++) {
                        if(Map[i][j]==200){Map[i][j]=3;}
                        if(Map[i][j]==201){Map[i][j]=4;}
                        m_Root.RemoveChild(map_objects[i][j]);
                    }
                }
                for(int x=0;x<16;x++) {
                    m_Root.RemoveChild(item[x]);
                }
                m_Root.RemoveChild(coin);
                m_Root.RemoveChild(coinx);
                m_Root.RemoveChild(coin1);
                coin1->SetVisible(false);
                coin2->SetVisible(false);
                m_Root.RemoveChild(coin2);
                m_Root.RemoveChild(time);
                time->SetVisible(false);
                time1->SetVisible(false);
                time2->SetVisible(false);
                time3->SetVisible(false);
                m_Root.RemoveChild(time1);
                m_Root.RemoveChild(time2);
                m_Root.RemoveChild(time3);
                m_Root.RemoveChild(world);
                m_Root.RemoveChild(world1);
                m_Root.RemoveChild(world2);
                m_Root.RemoveChild(world3);
                world3->SetVisible(false);
                m_Root.RemoveChild(livex);
                m_Root.RemoveChild(live1);
                m_Root.RemoveChild(flagpole);
                m_Root.RemoveChild(flag);
                m_Root.RemoveChild(castle);
                m_Root.RemoveChild(fireball);
                live1->SetVisible(false);
                m_obj2.RemoveChild(bg);
                if(m_CurrentState==State::UPDATE) {
                    end=false;
                    flagtime=0;
                    lives=3;
                    if(worlds==11) {
                        m_CurrentState=State::ONE;
                    }
                    else if(worlds==12) {
                        m_Root.RemoveChild(bridges[0]);
                        m_Root.RemoveChild(bridges[1]);
                        m_CurrentState=State::TWO;
                    }
                    else if(worlds==13) {
                        m_CurrentState=State::Win;
                    }
                }
            }
        }
    }
    //std::cout<<"check6"<<std::endl;
    if(worlds==13&&m_Collision.CheckCollision(m_player->GetPosition(),toad->GetPosition(),mario_hitbox.x,mario_hitbox.y,24.0f,24.0f)) {
                m_PlayerPosition.x=0.0f;
                m_Root.RemoveChild(m_player);
                for(int x=0;x<10;x++) {
                    enemyx[x]=0.0f;
                    enemyy[x]=0.0f;
                }
                for(int x=0;x<10;x++) {
                    m_Root.RemoveChild(goomba[x]);
                }
                for(int i=0;i<30;i++) {
                    for(int j=0;j<200;j++) {
                        if(Map[i][j]==200){Map[i][j]=3;}
                        if(Map[i][j]==201){Map[i][j]=4;}
                        m_Root.RemoveChild(map_objects[i][j]);
                    }
                }
                for(int x=0;x<16;x++) {
                    m_Root.RemoveChild(item[x]);
                }
                m_Root.RemoveChild(coin);
                m_Root.RemoveChild(coinx);
                m_Root.RemoveChild(coin1);
                coin1->SetVisible(false);
                coin2->SetVisible(false);
                m_Root.RemoveChild(coin2);
                m_Root.RemoveChild(time);
                time->SetVisible(false);
                time1->SetVisible(false);
                time2->SetVisible(false);
                time3->SetVisible(false);
                m_Root.RemoveChild(time1);
                m_Root.RemoveChild(time2);
                m_Root.RemoveChild(time3);
                m_Root.RemoveChild(world);
                m_Root.RemoveChild(world1);
                m_Root.RemoveChild(world2);
                m_Root.RemoveChild(world3);
                world3->SetVisible(false);
                m_Root.RemoveChild(livex);
                m_Root.RemoveChild(live1);
                m_Root.RemoveChild(flagpole);
                m_Root.RemoveChild(flag);
                m_Root.RemoveChild(castle);
                m_Root.RemoveChild(fireball);
                live1->SetVisible(false);
                m_obj2.RemoveChild(bg);
                if(m_CurrentState==State::UPDATE) {
                    end=false;
                    flagtime=0;
                    lives=3;
                    if(worlds==11) {
                        m_CurrentState=State::ONE;
                    }
                    else if(worlds==12) {
                        m_CurrentState=State::TWO;
                    }
                    else if(worlds==13) {
                        m_CurrentState=State::Win;
                    }
                }
    }
    //-------------------------------------------------------
    //-----------------mario collison goomba----------------------
    for(int i=0;i<10;i++) {
        if(m_Collision.CheckCollision(goomba[i]->GetPosition(),m_player->GetPosition() ,24.0f,24.0f,mario_hitbox.x,mario_hitbox.y)&&goomba_dead[i]==false&&player_dead==false&&!(mari0_sizem)&&!(op)&&!(mario_op)) {
            if(m_PlayerPosition.y<0.0f) {
                goomba_dead[i]=true;
                m_PlayerPosition.y=10.0f;
                mario_op=true;
            }
            else if(mario_size>1){
                mari0_sizem=true;
            }
            else {
                player_dead=true;
            }
            //std::cout<<m_PlayerPosition.x<<" "<<m_PlayerPosition.y<<std::endl;
        }
        if(m_Collision.CheckCollision(goomba[i]->GetPosition(),fireball->GetPosition() ,24.0f,24.0f,24.0f,24.0f)&&goomba_dead[i]==false&&goomba_dead_fire[i]==false&&fireball->GetVisibility()==true) {
            goomba_dead_fire[i]=true;
            fireballdead=true;
        }
        for(int j=0;j<10;j++) {
            if(m_Collision.CheckCollision(goomba[i]->GetPosition(),goomba[j]->GetPosition() ,24.0f,24.0f,24.0f,24.0f)&&goomba_dead[i]==false&&i!=j&&goomba_dead[j]==false) {
                enemyx[j]*=-1;
                enemyx[i]*=-1;
            }
        }
    }
    //std::cout<<"check7"<<std::endl;
    //-------------------------------------
    if(m_PlayerPosition.y<-3.0f){m_up=true;}

    //--------------player dead and restart------------------------
    if(player_dead){

        m_PlayerPosition.x=0.0f;
        m_PlayerPosition.y=0.0f;
        for(int x=0;x<10;x++) {
            enemyx[x]=0.0f;
            enemyy[x]=0.0f;
        }
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
            for(int x=0;x<10;x++) {
                m_Root.RemoveChild(goomba[x]);
            }
            for(int i=0;i<30;i++) {
                for(int j=0;j<200;j++) {
                    if(Map[i][j]==200){Map[i][j]=3;}
                    if(Map[i][j]==201){Map[i][j]=4;}
                    m_Root.RemoveChild(map_objects[i][j]);
                }
            }
            for(int x=0;x<16;x++) {
                m_Root.RemoveChild(item[x]);
            }
            if(lives>0){lives-=1;}
            std::cout<<lives<<std::endl;
            if(lives==0) {
                if(worlds==12) {
                    m_Root.RemoveChild(bridges[0]);
                    m_Root.RemoveChild(bridges[1]);
                }
                if(worlds==13) {
                    m_Root.RemoveChild(toad);
                }
                //std::cout<<"over"<<std::endl;
                m_CurrentState=State::gameovers;
            }
            m_Root.RemoveChild(coin);
            m_Root.RemoveChild(coinx);
            m_Root.RemoveChild(coin1);
            coin1->SetVisible(false);
            coin2->SetVisible(false);
            m_Root.RemoveChild(coin2);
            m_Root.RemoveChild(time);
            time->SetVisible(false);
            time1->SetVisible(false);
            time2->SetVisible(false);
            time3->SetVisible(false);
            m_Root.RemoveChild(time1);
            m_Root.RemoveChild(time2);
            m_Root.RemoveChild(time3);
            m_Root.RemoveChild(world);
            m_Root.RemoveChild(world1);
            m_Root.RemoveChild(world2);
            m_Root.RemoveChild(world3);
            world3->SetVisible(false);
            m_Root.RemoveChild(livex);
            m_Root.RemoveChild(live1);
            m_Root.RemoveChild(flagpole);
            m_Root.RemoveChild(flag);
            m_Root.RemoveChild(castle);
            m_Root.RemoveChild(fireball);
            m_Root.RemoveChild(bowser);
            m_Root.RemoveChild(toad);
            m_Root.RemoveChild(bowser_fireball);
            live1->SetVisible(false);
            if(m_CurrentState==State::UPDATE) {
                if(worlds==11) {
                    m_CurrentState=State::START;

                }
                else if(worlds==12) {
                    m_Root.RemoveChild(bridges[0]);
                    m_Root.RemoveChild(bridges[1]);
                    m_CurrentState=State::ONE;
                }
                else if(worlds==13) {
                    m_CurrentState=State::TWO;
                }
            }
        }
    }
    //----------------------------------------
    //------------mario size with collison-----------------
    if(mari0_sizem) {
        if(player_dead_animate==0&&mario_size>1) {
            mario_size-=1;
            if(mario_size==1) {
                mario_hitbox={18.0f,24.0f};
            }
        }
        if(m_player->GetVisibility()==true) {
            m_player->SetVisible(false);
        }
        else {
            m_player->SetVisible(true);
        }
        if(player_dead_animate<20) {
            m_PlayerPosition.x=0.0f;
            m_PlayerPosition.y=0.0f;
        }
        player_dead_animate+=1;
        if(player_dead_animate>60) {
            player_dead_animate=0;
            mari0_sizem=false;
            if(m_player->GetVisibility()==false) {
                m_player->SetVisible(true);
            }
        }
    }
    //----------------------------------------------------------
    if(m_player->GetPosition().y<-450.0f&&(!opmode)) {
        player_dead=true;
        m_PlayerPosition.x=0.0f;
    }
    m_player->SetPosition({m_PlayerPosition.x+m_player->GetPosition().x,m_PlayerPosition.y+m_player->GetPosition().y});
    for(int k=0;k<10;k++) {
        goomba[k]->SetPosition({goomba[k]->GetPosition().x+enemyx[k],goomba[k]->GetPosition().y+enemyy[k]});
    }
    for(int x=0;x<16;x++) {
        if(item[x]->GetVisibility()==true) {
            item[x]->SetPosition({item[x]->GetPosition().x+itemx[x],item[x]->GetPosition().y+itemy[x]});
            itemy[x]-=downspeed;
        }
    }
    //---------------------------------
    //人物轉向------------------------------------------
    if(m_PlayerPosition.x>0.0f&&m_player->m_Transform.scale.x<0&&!end){
        //std::cout<<"face right:"<<m_PlayerPosition.x<<std::endl;
        m_player->m_Transform.scale.x*=-1;
        playerface*=-1;
    }
    else if(m_PlayerPosition.x<0.0f&&m_player->m_Transform.scale.x>0&&!end) {
        //std::cout<<"face left:"<<m_PlayerPosition.x<<std::endl;
        m_player->m_Transform.scale.x*=-1;
        playerface*=-1;
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
    if(Util::Input::IsKeyDown(Util::Keycode::H)) {
        mario_size+=1;
        if(mario_size>3){mario_size=1;mario_hitbox={18.0f,24.0f};}
        else if(mario_size==2){mario_hitbox={24.0f,48.0f};m_player->SetPosition({m_player->GetPosition().x,+m_player->GetPosition().y+24.0f});}
    }
    for(int k=0;k<10;k++) {
        if(goomba_dead[k]) {
            enemyx[k]=0.0f;
            if(goomba_dead_animate[k]<=25) {
                goomba_dead_animate[k]+=1;
                mario_op=true;
            }
             if(goomba_dead_animate[k]>=10&&goomba_dead_animate[k]<=25) {
                 mario_op=false;
             }
            goomba[k]->SetImage(2);
            if(goomba_dead_animate[k]>25) {
                m_Root.RemoveChild(goomba[k]);
                mario_op=false;
            }
        }
        if(intopipe) {
            goomba[k]->SetVisible(false);
        }
        if(outpipe) {
            goomba[k]->SetVisible(true);
        }
        if(goomba_dead_fire[k]) {
            if(goomba_dead_animate[k]==0) {
                goomba[k]->m_Transform.scale.y*=-1;
                goomba_dead_animate[k]=1;
            }
            enemyx[k]=0.0f;
        }
    }
    //-----------------bowser---------------------------
    if(worlds==13) {
        if(bowser_jump==false&&bowser_jumpcount>=240) {
            bowser_y+=bowser_jumpspeed;
            bowser_jump=true;
            bowser_jumpcount=0;
        }
        if(bowser_jump==false) {
            bowser_jumpcount++;
        }
        if(bowser->GetPosition().x<640.0f) {
            if(bowser->GetPosition().x>448.0f) {
                bowser_x=-2.0f;
                bowser_count++;
            }
            else if(bowser->GetPosition().x<316.0f) {
                bowser_x=2.0f;
                bowser_count++;
            }
            else if(bowser_x==0.0f){
                bowser_x=2.0f;
            }
            if(bowser_count>=6) {
                bowser_count=0;
            }
        }
        if(m_Collision.CheckCollision(m_player->GetPosition(),bowser->GetPosition(),mario_hitbox.x,mario_hitbox.y,48.0f,48.0f)&&!(op)&&mari0_sizem==false) {
            if(mario_size>1) {
                mari0_sizem=true;
            }
            else if(mario_size==1) {
                player_dead=true;
            }
        }
        if(bowser_count==2&&bowser_fireball->GetVisibility()==false) {
            bowser_fireball->SetVisible(true);
            bowser_fireball->SetPosition(bowser->GetPosition());
        }
        if(bowser_fireball->GetVisibility()==true) {
            bowser_fireball->SetPosition({bowser_fireball->GetPosition().x+bowser_fireballspeed,bowser_fireball->GetPosition().y});
        }
        if(bowser_fireball->GetPosition().x<-640.0f) {
            bowser_fireball->SetVisible(false);
        }
        if(m_Collision.CheckCollision(m_player->GetPosition(),bowser_fireball->GetPosition(),mario_hitbox.x,mario_hitbox.y,36.0f,12.0f)&&!(op)&&mari0_sizem==false&&bowser_fireball->GetVisibility()==true) {
            if(mario_size>1) {
                mari0_sizem=true;
            }
            else if(mario_size==1) {
                player_dead=true;
            }
        }
        if(m_Collision.CheckCollision(fireball->GetPosition(),bowser->GetPosition(),24.0f,24.0f,48.0f,48.0f)&&fireball->GetVisibility()==true) {
            fireballdead=true;
        }
        bowser->SetPosition({bowser->GetPosition().x+bowser_x,bowser->GetPosition().y+bowser_y});
    }

    //--------------------------------------------------
    //---------------UI image change------------------
    updatetime+=1;
    if(updatetime==60) {
        updatetime=0;
        times-=1;
        time3->SetImage(GA_RESOURCE_DIR"/Image/UI/"+std::to_string(times%10)+".png");
        time2->SetImage(GA_RESOURCE_DIR"/Image/UI/"+std::to_string(((times%100)-(times%10))/10)+".png");
        time1->SetImage(GA_RESOURCE_DIR"/Image/UI/"+std::to_string(((times)-(times%100))/100)+".png");
        if(times<=0) {
            times=0;
            player_dead=true;
        }
    }
    coin1->SetImage(GA_RESOURCE_DIR"/Image/UI/"+std::to_string((coins-(coins%10))/10)+".png");
    coin2->SetImage(GA_RESOURCE_DIR"/Image/UI/"+std::to_string(coins%10)+".png");
    //------------------------------------------------
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
        if(m_player->GetPosition().x>0.0f&&!(map_objects[19][199]->GetPosition().x<640.0f)&&!(end)) {
            if(worlds==13&&touchaxe==false&&map_objects[15][188]->GetPosition().x<620.0f) {
                    m_Root.Update({0.0f,0.0f});
                    m_obj2.Update({0.0f,0.0f});
            }
            else if(worlds==13&&touchcam<200&&map_objects[15][188]->GetPosition().x<640.0f&&touchaxe==true) {
                m_Root.Update({-3.0f,0.0f});
                m_obj2.Update({0.0f,0.0f});
                touchcam++;
            }
            else {
                m_Root.Update({-(m_PlayerPosition.x),0.0f});
                m_obj2.Update({0.0f,0.0f});
                //m_UI.Update({0.0f,0.0f});
            }
        }
        else{
            m_Root.Update({0.0f,0.0f});
            m_obj2.Update({0.0f,0.0f});
        }
        m_obj.Update({0.0f,0.0f});
        //----------------------------------------------

}
