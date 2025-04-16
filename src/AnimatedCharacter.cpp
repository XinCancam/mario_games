#include "AnimatedCharacter.hpp"


AnimatedCharacter::AnimatedCharacter(const std::vector<std::string>& AnimationPaths1,const std::vector<std::string>& AnimationPaths2,const std::vector<std::string>& AnimationPaths3,
        const std::vector<std::string>& AnimationPaths4,const std::vector<std::string>& AnimationPaths5,const std::vector<std::string>& AnimationPaths6,
        const std::vector<std::string>& AnimationPaths7,const std::vector<std::string>& AnimationPaths8,const std::vector<std::string>& AnimationPaths9,const std::vector<std::string>& AnimationPaths10) {
    Amimation1 = std::make_shared<Util::Animation>(AnimationPaths1, true, 250, true, 0);
    Amimation2 = std::make_shared<Util::Animation>(AnimationPaths2, true, 250, true, 0);
    Amimation3 = std::make_shared<Util::Animation>(AnimationPaths3, true, 250, true, 0);
    Amimation4 = std::make_shared<Util::Animation>(AnimationPaths4, true, 250, true, 0);
    Amimation5 = std::make_shared<Util::Animation>(AnimationPaths5, true, 250, true, 0);
    Amimation6 = std::make_shared<Util::Animation>(AnimationPaths6, true, 250, true, 0);
    Amimation7 = std::make_shared<Util::Animation>(AnimationPaths7, true, 250, true, 0);
    Amimation8 = std::make_shared<Util::Animation>(AnimationPaths8, true, 250, true, 0);
    Amimation9 = std::make_shared<Util::Animation>(AnimationPaths9, true, 250, true, 0);
    Amimation10 = std::make_shared<Util::Animation>(AnimationPaths10, true, 250, true, 0);
}

bool AnimatedCharacter::IfAnimationEnds() const {
    auto animation = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
        return animation->GetCurrentFrameIndex() == animation->GetFrameCount() - 1;
}
void AnimatedCharacter::SetImage(const int x) {
    if(x==1) {
        m_Drawable=Amimation1;
    }
    else if(x==2) {
        m_Drawable=Amimation2;
    }
    else if(x==3) {
        m_Drawable=Amimation3;
    }
    else if(x==4) {
        m_Drawable=Amimation4;
    }
    else if(x==5) {
        m_Drawable=Amimation5;
    }
    else if(x==6) {
        m_Drawable=Amimation6;
    }
    else if(x==7) {
        m_Drawable=Amimation7;
    }
    else if(x==8) {
        m_Drawable=Amimation8;
    }
    else if(x==9) {
        m_Drawable=Amimation9;
    }
    else if(x==10) {
        m_Drawable=Amimation10;
    }

}