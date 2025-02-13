#pragma once

#include <src/GameModes/GameMode.hpp>

class NormalMode: public GameMode
{
public:
    NormalMode(PlayingState* playingState);

    void handle_inputs(const sf::Event& event) noexcept override;
};