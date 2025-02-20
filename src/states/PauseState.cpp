/*
    ISPPV1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the definition of the class CountDownBaseState.
*/

#include <Settings.hpp>
#include <src/text_utilities.hpp>
#include <src/states/PauseState.hpp>
#include <src/states/StateMachine.hpp>

PauseState::PauseState(StateMachine* sm) noexcept
    : BaseState{sm}
{

}

void PauseState::enter(std::shared_ptr<World> _world, std::shared_ptr<Bird> _bird, std::shared_ptr<GameMode> _selectedMode, int _score) noexcept
{
    selectedMode = _selectedMode;
    world = _world;
    bird = _bird;
    score = _score;
}

void PauseState::handle_inputs(const sf::Event& event) noexcept
{
    if (event.key.code == sf::Keyboard::Return)
    {
        state_machine->change_state("playing", selectedMode, world, bird, score);
    }
}

void PauseState::update(float dt) noexcept
{
}

void PauseState::render(sf::RenderTarget& target) const noexcept
{
    world->render(target);
    bird->render(target);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 2, "PAUSE", Settings::HUGE_TEXT_SIZE, "font", sf::Color::White, true);
}