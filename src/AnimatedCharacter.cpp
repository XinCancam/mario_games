#include "AnimatedCharacter.hpp"


AnimatedCharacter::AnimatedCharacter(const std::vector<std::string>& AnimationPaths) {
    m_Drawable = std::make_shared<Util::Animation>(AnimationPaths, true, 250, true, 0);
}

bool AnimatedCharacter::IfAnimationEnds() const {
    auto animation = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
        return animation->GetCurrentFrameIndex() == animation->GetFrameCount() - 1;
}
void AnimatedCharacter::SetImage(const std::vector<std::string>& ImagePaths) {

    m_Drawable = std::make_shared<Util::Animation>(ImagePaths, true, 250, true, 0);
}