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
            back_objects(20, std::vector<std::shared_ptr<Character>>(200, nullptr)),
            itemx(16),itemy(16),item(16),goomba(10),enemyx(10),enemyy(10),goomba_dead_animate(10),goomba_dead(10){}
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
    std::vector<std::shared_ptr<Character>> item;
    Collision m_Collision;
    std::shared_ptr<BackgroundImage> m_background;
    std::shared_ptr<Character> bg;
    std::vector<std::string> mario_stand;
    std::vector<std::string> marioImages;
    std::vector<std::shared_ptr<AnimatedCharacter>> goomba;
    std::vector<std::string> goombaimg;
    std::vector<std::string> goombadeadimg;
    std::vector<float> enemyy;
    std::vector<float> enemyx;
    std::vector<float> itemx={0.0f};
    std::vector<float> itemy={0.0f};
    bool player_dead = false;
    std::vector<bool> goomba_dead;
    std::vector<int> goomba_dead_animate;
    int player_dead_animate = 0;
    bool mari0_sizem = false;
    bool m_EnterDown=false;
    int mario_size=1;
    int mushroom_count=0;
    glm::vec2 mario_hitbox=glm::vec2(18.0f,24.0f);
    float m_speed=1.0f;
    float m_upspeed=22.0f;
    bool m_up=false;
    float downspeed=1.0f;
    int Animate_time=0;
    glm::vec2 m_PlayerPosition=glm::vec2(0.0f,0.0f);
};

#endif
