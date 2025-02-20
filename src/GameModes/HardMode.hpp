#pragma once

#include <src/GameModes/GameMode.hpp>

class HardMode: public GameMode
{
public:
    HardMode(PlayingState* playingState);
    HardMode(){}

    void handle_inputs(const sf::Event& event) noexcept override;
    void getState() noexcept override;
};