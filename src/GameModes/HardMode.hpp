#include <src/GameModes/GameMode.hpp>

class HardMode: public GameMode
{
public:
    HardMode(PlayingState* playingState);

    void handle_inputs(const sf::Event& event) noexcept override;
};