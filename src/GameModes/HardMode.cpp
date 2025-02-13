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

    if (Game::key_is_pressed() && event.key.code == sf::Keyboard::Return)
    {
        ps->state_machine->change_state("pause", ps->world, ps->bird, ps->score);
    }
}