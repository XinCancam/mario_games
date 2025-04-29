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
        zero,
        UPDATE,
        gameovers,
        END,
    };

    State GetCurrentState() const { return m_CurrentState; }

    void Start();
    void gameovers();
    void zero();

    void Update();

    void End(); // NOLINT(readability-convert-member-functions-to-static)
    App(): map_objects(20, std::vector<std::shared_ptr<Character>>(200, nullptr)),
            back_objects(20, std::vector<std::shared_ptr<Character>>(200, nullptr)),
            itemx(16,0),itemy(16,0),item(16),goomba(10),enemyx(10),enemyy(10),goomba_dead_animate(10),goomba_dead(10),
            map_animate(20,std::vector<int>(200,0)),itemcoin(16,false),itemtime(16,0){}
private:
    void ValidTask();

private:
    State m_CurrentState = State::zero;
    Util::Renderer m_Root;
    Util::Renderer m_obj;
    Util::Renderer m_obj2;
    Util::Renderer m_UI;
    std::shared_ptr<AnimatedCharacter> m_player;
    std::vector<std::vector<std::shared_ptr<Character>>> map_objects;
    std::vector<std::vector<int>> map_animate;
    std::vector<std::vector<std::shared_ptr<Character>>> back_objects;
    std::vector<std::shared_ptr<Character>> item;
    Collision m_Collision;
    std::shared_ptr<BackgroundImage> m_background;
    std::shared_ptr<Character> time;
    std::shared_ptr<Character> time1;
    std::shared_ptr<Character> time2;
    std::shared_ptr<Character> time3;
    std::shared_ptr<Character> live;
    std::shared_ptr<Character> live1;
    std::shared_ptr<Character> livex;
    std::shared_ptr<Character> world;
    std::shared_ptr<Character> world1;
    std::shared_ptr<Character> world2;
    std::shared_ptr<Character> world3;
    std::shared_ptr<Character> coin;
    std::shared_ptr<Character> coinx;
    std::shared_ptr<Character> coin1;
    std::shared_ptr<Character> coin2;
    int times=0;
    int lives=3;
    int worlds=0;
    int coins=0;
    int updatetime=0;
    int gameoverscale=0;
    std::shared_ptr<Character> gameover;
    std::shared_ptr<Character> startscreen;
    int gameovertime=0;
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
    std::vector<bool> itemcoin;
    std::vector<int> itemtime;
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
