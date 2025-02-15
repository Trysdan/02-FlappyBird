#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

class Bird;
class World;
class StateMachine;

class PowerUp
{
public:
    PowerUp(Bird* _bird, std::shared_ptr<World> _world, StateMachine* sm): bird{_bird}, world{_world}, stateMachine{sm} {}

    virtual void update(float dt){}

    virtual void enter() noexcept {}

    virtual void solve_collision() noexcept {}

    virtual void exit() noexcept {}

    virtual void render(sf::RenderTarget& target) noexcept{}

protected:
    Bird* bird;
    std::shared_ptr<World> world;
    StateMachine* stateMachine;
};