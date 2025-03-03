#pragma once

#include <src/PowerUps/PowerUp.hpp>
#include <SFML/System.hpp>

class BubblePU: public PowerUp
{
public:
    BubblePU(Bird* _bird, std::shared_ptr<World> _world, StateMachine* sm);

    void update(float dt) noexcept override;

    void enter() noexcept override;

    void solve_collision() noexcept override;

    void exit() noexcept override;

    void render(sf::RenderTarget& target) noexcept override;
    
private:
    float countDown;
};