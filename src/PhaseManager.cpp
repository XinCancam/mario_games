#include "PhaseResourceManger.hpp"

#include "Util/Logger.hpp"

PhaseResourceManger::PhaseResourceManger() {
    m_Background = std::make_shared<BackgroundImage>();
}

void PhaseResourceManger::NextPhase() {
    if (m_Phase == 7) return;
    LOG_DEBUG("Passed! Next phase: {}", m_Phase);
    m_Background->NextPhase(m_Phase);
    m_TaskText->NextPhase(m_Phase++);
}
