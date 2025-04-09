
#ifndef COLLISON_HPP
#define COLLISON_HPP
#ifndef COLLISION_HPP
#define COLLISION_HPP
#include <glm/vec2.hpp>


class Collision {
public:
    bool CheckCollision(glm::vec2 obj1,glm::vec2 obj2,float w1,float h1,float w2,float h2);
    float Get_objmin2x(){return objmin2x;}
    float Get_objmax2x(){return objmax2x;}
    float Get_objmin2y(){return objmin2y;}
    float Get_objmax2y(){return objmax2y;}
private:
    float objmin2x=0.0f;
    float objmax2x=0.0f;
    float objmin2y=0.0f;
    float objmax2y=0.0f;
    float objmin1x=0.0f;
    float objmax1x=0.0f;
    float objmin1y=0.0f;
    float objmax1y=0.0f;

};

#endif // COLLISION_HPP

#endif //COLLISON_HPP
