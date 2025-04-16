#ifndef APP_HPP
#define APP_HPP

#include "pch.hpp" // IWYU pragma: export

#include "Util/Renderer.hpp"
#include "Character.hpp"
#include "Util/Text.hpp"
#include "PhaseResourceManger.hpp"
#include "AnimatedCharacter.hpp"
#include "BackgroundImage.hpp"
#include "collison.hpp"


class App {
public:
    enum class State {
        START,
        UPDATE,
        END,
    };

    State GetCurrentState() const { return m_CurrentState; }

    void Start();

    void Update();

    void End(); // NOLINT(readability-convert-member-functions-to-static)
    App(): map_objects(20, std::vector<std::shared_ptr<Character>>(200, nullptr)),
            back_objects(20, std::vector<std::shared_ptr<Character>>(200, nullptr)){}
private:
    void ValidTask();

private:
    State m_CurrentState = State::START;
    Util::Renderer m_Root;
    Util::Renderer m_obj;
    Util::Renderer m_obj2;
    std::shared_ptr<AnimatedCharacter> m_player;
    std::vector<std::vector<std::shared_ptr<Character>>> map_objects;
    std::vector<std::vector<std::shared_ptr<Character>>> back_objects;
    Collision m_Collision;
    std::shared_ptr<BackgroundImage> m_background;
    std::shared_ptr<Character> bg;
    std::vector<std::string> mario_stand;
    std::vector<std::string> marioImages;
    std::shared_ptr<AnimatedCharacter> goomba;
    std::vector<std::string> goombaimg;
    std::vector<std::string> goombadeadimg;
    float enemyy=0.0f;
    float enemyx=-2.0f;
    bool player_dead = false;
    bool goomba_dead = false;
    bool m_EnterDown=false;
    float m_speed=1.0f;
    float m_upspeed=22.0f;
    bool m_up=false;
    float downspeed=1.0f;
    int Animate_time=0;
    glm::vec2 m_PlayerPosition=glm::vec2(0.0f,0.0f);
};

#endif
