#include "collison.hpp"

#include <iostream>
#include <ostream>

bool Collision::CheckCollision(glm::vec2 obj1, glm::vec2 obj2,float w1,float h1,float w2,float h2) {
   // std::cout<<"Collision::CheckCollision"<<std::endl;
    objmin2x=(obj2.x-w2);
    objmax2x=(obj2.x+w2);
    objmin2y=(obj2.y-h2);
    objmax2y=(obj2.y+h2);
    objmin1x=(obj1.x-w1);
    objmax1x=(obj1.x+w1);
    objmin1y=(obj1.y-h1);
    objmax1y=(obj1.y+h1);
    return (objmax1x > objmin2x && objmin1x < objmax2x &&
                   objmax1y > objmin2y && objmin1y < objmax2y);
}

