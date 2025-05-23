#ifndef ANIMATED_CHARACTER_HPP
#define ANIMATED_CHARACTER_HPP

#include <vector>
#include <string>

#include "Util/Animation.hpp"
#include "Util/GameObject.hpp"


class AnimatedCharacter : public Util::GameObject {

public:
    explicit AnimatedCharacter(const std::vector<std::string>& AnimationPaths1,const std::vector<std::string>& AnimationPaths2,const std::vector<std::string>& AnimationPaths3,
        const std::vector<std::string>& AnimationPaths4,const std::vector<std::string>& AnimationPaths5,const std::vector<std::string>& AnimationPaths6,
        const std::vector<std::string>& AnimationPaths7,const std::vector<std::string>& AnimationPaths8,const std::vector<std::string>& AnimationPaths9,const std::vector<std::string>& AnimationPaths10,const std::vector<std::string>& AnimationPaths11,const std::vector<std::string>& AnimationPaths12,const std::vector<std::string>& AnimationPaths13);

    [[nodiscard]] bool IsLooping() const {
        return std::dynamic_pointer_cast<Util::Animation>(m_Drawable)->GetLooping();
    }

    [[nodiscard]] bool IsPlaying() const {
        return std::dynamic_pointer_cast<Util::Animation>(m_Drawable)->GetState() == Util::Animation::State::PLAY;
    }

    void SetLooping(bool looping) {
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
        temp->SetLooping(looping);
    }
    void SetImage(const int x);
    [[nodiscard]] bool IfAnimationEnds() const;
    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }
    [[nodiscard]] const glm::vec2& GetPosition() const { return m_Transform.translation; }
    [[nodiscard]] bool GetVisibility() const { return m_Visible; }
private:
    std::shared_ptr<Util::Animation> Amimation1;
    std::shared_ptr<Util::Animation> Amimation2;
    std::shared_ptr<Util::Animation> Amimation3;
    std::shared_ptr<Util::Animation> Amimation4;
    std::shared_ptr<Util::Animation> Amimation5;
    std::shared_ptr<Util::Animation> Amimation6;
    std::shared_ptr<Util::Animation> Amimation7;
    std::shared_ptr<Util::Animation> Amimation8;
    std::shared_ptr<Util::Animation> Amimation9;
    std::shared_ptr<Util::Animation> Amimation10;
    std::shared_ptr<Util::Animation> Amimation11;
    std::shared_ptr<Util::Animation> Amimation12;
    std::shared_ptr<Util::Animation> Amimation13;
};

#endif //ANIMATED_CHARACTER_HPP
