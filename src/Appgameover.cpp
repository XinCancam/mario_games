#include "App.hpp"
#include <iostream>
#include <ostream>
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
void App::gameovers() {
    gameover->SetVisible(true);
    if(gameoverscale==0) {
        gameover->m_Transform.scale*=2;
        gameoverscale=1;
    }
    gameovertime+=1;
    std::cout<<"kk"<<std::endl;
    if(gameovertime>=200) {
        m_CurrentState=State::zero;
        gameover->SetVisible(false);
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) || Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }
    m_UI.Update({0.0f,0.0f});
}
