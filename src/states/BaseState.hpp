/*
    ISPPV1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the declaration of the class BaseState.
*/

#pragma once

#include <memory>

#include <SFML/Graphics.hpp>
#include <src/GameModes/NormalMode.hpp>
#include <src/GameModes/HardMode.hpp>

class StateMachine;
class World;
class Bird;

class BaseState
{
public:
    BaseState(StateMachine* sm) : state_machine(sm), selectedMode{ std::make_shared<GameMode>() } {}

    virtual ~BaseState() {}

    virtual void enter(std::shared_ptr<World> world, std::shared_ptr<Bird> bird, std::shared_ptr<GameMode> selectedMode, int _score) noexcept {}

    virtual void exit() noexcept {}

    virtual void handle_inputs(const sf::Event& event) noexcept {}

    virtual void update(float dt) noexcept {}

    virtual void render(sf::RenderTarget& target) const noexcept {}

    void setGameMode(const std::shared_ptr<GameMode>& mode) noexcept
    {
        selectedMode = mode;
    }


protected:
    StateMachine* state_machine;

    friend class NormalMode;
    friend class HardMode;

    std::shared_ptr<GameMode> selectedMode;
};
