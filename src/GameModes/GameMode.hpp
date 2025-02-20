#pragma once

#include <SFML/Window.hpp>
#include <list>
#include <memory>
#include <random>


class PlayingState;
class World;

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

    virtual void generateLogs(float dt, World* world) noexcept {}

protected:
    PlayingState* ps;
};