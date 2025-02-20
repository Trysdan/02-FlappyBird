/*
    ISPPV1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the definition of the class PlayingBaseState.
*/

#include <Settings.hpp>
#include <src/text_utilities.hpp>
#include <src/states/StateMachine.hpp>
#include <src/states/PlayingState.hpp>
#include <src/Game.hpp>

PlayingState::PlayingState(StateMachine* sm) noexcept
    : BaseState{sm}
{
    selectedMode = std::make_shared<NormalMode>(this);
}

void PlayingState::enter(std::shared_ptr<World> _world, std::shared_ptr<Bird> _bird, std::shared_ptr<GameMode> _selectedMode, int _score) noexcept
{
    selectedMode = _selectedMode;
    selectedMode->setPlayingState(this);

    world = _world;
    world->setGameMode(selectedMode);
    world->reset(true);
    score = _score;
    
    if (_bird == nullptr)
    {
        bird = std::make_shared<Bird>(
            Settings::VIRTUAL_WIDTH / 2 - Settings::BIRD_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 2 - Settings::BIRD_HEIGHT / 2,
            Settings::BIRD_WIDTH, Settings::BIRD_HEIGHT,world,state_machine
        );
    }
    else
    {
        bird = _bird;
    }
}

void PlayingState::handle_inputs(const sf::Event& event) noexcept
{
    selectedMode->handle_inputs(event);
}

void PlayingState::update(float dt) noexcept
{
    bird->update(dt);
    world->update(dt);

    bird->handle_log_collision();

    if (world->update_scored(bird->get_collision_rect()))
    {
        ++score;
        Settings::sounds["score"].play();
    }
}

void PlayingState::render(sf::RenderTarget& target) const noexcept
{
    world->render(target);
    bird->render(target);
    render_text(target, 20, 10, "Score: " + std::to_string(score), Settings::FLAPPY_TEXT_SIZE, "flappy", sf::Color::White);
}

void PlayingState::setGameMode(std::shared_ptr<GameMode> _selectedMode) noexcept
{
    selectedMode = _selectedMode;
}
