#pragma once

#include <memory>

class Bird;
class World;
class StateMachine;

class PowerUp
{
public:
    PowerUp(Bird* _bird, std::shared_ptr<World> _world, StateMachine* sm): bird{_bird}, world{_world}, stateMachine{sm} {}

    virtual void enter() noexcept {}

    virtual void solve_collision() noexcept {}

    virtual void exit() noexcept {}

protected:
    Bird* bird;
    std::shared_ptr<World> world;
    StateMachine* stateMachine;
};