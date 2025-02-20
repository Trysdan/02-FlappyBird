#pragma once

#include <SFML/Window.hpp>
#include <memory>
#include<iostream>


class PlayingState;

class GameMode
{
public:
    GameMode(PlayingState* playingState): ps{playingState} {}
    GameMode(){}

    virtual void handle_inputs(const sf::Event& event) noexcept {}

    void setPlayingState(PlayingState* playingState) noexcept
    {
        ps = playingState;
    }

protected:
    PlayingState* ps;
};