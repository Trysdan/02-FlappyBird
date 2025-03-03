/*
    ISPPV1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the declaration of the class PlayingBaseState.
*/

#pragma once

#include <src/Bird.hpp>
#include <src/World.hpp>
#include <src/states/BaseState.hpp>

class PlayingState: public BaseState
{

public:
    PlayingState(StateMachine* sm) noexcept;

    void enter(std::shared_ptr<World> _world = nullptr, std::shared_ptr<Bird> _bird = nullptr, std::shared_ptr<GameMode> selectedMode = nullptr, int _score = 0) noexcept override;

    void handle_inputs(const sf::Event& event) noexcept override;

    void update(float dt) noexcept override;

    void render(sf::RenderTarget& target) const noexcept override;

    void setGameMode(std::shared_ptr<GameMode> _selectedMode) noexcept;

private:
    std::shared_ptr<Bird> bird;
    std::shared_ptr<World> world;
    int score{0};

    friend class NormalMode;
    friend class HardMode;

    std::shared_ptr<GameMode> selectedMode;
};
