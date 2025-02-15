#pragma once

#include <src/PowerUps/PowerUp.hpp>
#include <SFML/Graphics.hpp>

class NoPU: public PowerUp
{
public:
    NoPU(Bird* _bird, std::shared_ptr<World> _world, StateMachine* sm);

    void update(float dt) noexcept override;

    void enter() noexcept override;

    void solve_collision() noexcept override;

    void exit() noexcept override;

    void render(sf::RenderTarget& target) noexcept override;
};