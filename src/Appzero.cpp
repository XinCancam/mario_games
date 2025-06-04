//
// Created by linx9 on 2025/4/29.
//

#include <iostream>
#include <ostream>

#include "App.hpp"

#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
//----------for start screen--------------------
void App::zero() {
    if(firstzero==0) {
        startscreen=std::make_shared<Character>(GA_RESOURCE_DIR"/Image/background/startscreen.png");
        startscreen->SetVisible(true);
        startscreen->SetPosition({0,0});
        startscreen->m_Transform.scale*=1;
        m_UI.AddChild(startscreen);
    }
    firstzero=1;
    gameovertime=0;
    lives=3;
    if(Util::Input::IsKeyDown(Util::Keycode::R)) {
        m_CurrentState=State::TWO;
        firstzero=0;
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) || Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }
    m_UI.Update({0.0f,0.0f});
}
