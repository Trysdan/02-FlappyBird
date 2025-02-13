#include <src/Game.hpp>
#include <src/GameModes/NormalMode.hpp>

NormalMode::NormalMode(PlayingState* playingState): GameMode{playingState} {}

void NormalMode::handle_inputs(const sf::Event& event) noexcept
{}