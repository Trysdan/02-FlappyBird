#pragma once

#include <SFML/Window.hpp>
#include <memory>

class PlayingState;

class GameMode
{
public:
    GameMode(PlayingState* playingState): ps{playingState} {}

    virtual void handle_inputs(const sf::Event& event) noexcept {}

protected:
    PlayingState* ps;
};