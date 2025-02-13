#include <src/Game.hpp>
#include <src/GameModes/HardMode.hpp>

HardMode::HardMode(PlayingState* playingState): GameMode{playingState} {}

void HardMode::handle_inputs(const sf::Event& event) noexcept
{
}