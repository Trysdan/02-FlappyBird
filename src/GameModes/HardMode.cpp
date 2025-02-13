#include <Settings.hpp>
#include <src/Game.hpp>
#include <src/GameModes/HardMode.hpp>
#include <src/states/PlayingState.hpp>

HardMode::HardMode(PlayingState* playingState): GameMode{playingState} {}

void HardMode::handle_inputs(const sf::Event& event) noexcept
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        ps->bird->jump();
    }

    if (Game::key_is_pressed())
    {
        switch(event.key.code)
        {
            case Settings::LEFT_KEY:
                ps->bird->vx = -Settings::BIRD_SPEED;
                break;
            case Settings::RIGHT_KEY:
                ps->bird->vx = Settings::BIRD_SPEED;
                break;
            case Settings::PAUSE_KEY:
                ps->state_machine->change_state("pause", ps->world, ps->bird, ps->score);
                break;
            default:
                break;
        }
    }
}