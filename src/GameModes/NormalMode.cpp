#include <Settings.hpp>
#include <src/Game.hpp>
#include <src/GameModes/NormalMode.hpp>
#include <src/states/PlayingState.hpp>

NormalMode::NormalMode(PlayingState* playingState): GameMode{playingState} {}

void NormalMode::handle_inputs(const sf::Event& event) noexcept
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        ps->bird->jump();
    }

    if (Game::key_is_pressed() && event.key.code == Settings::PAUSE_KEY)
    {
        ps->state_machine->change_state("pause", ps->world, ps->bird, ps->score);
    }
}