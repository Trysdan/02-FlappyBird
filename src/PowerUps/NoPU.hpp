#pragma once

#include <src/PowerUps/PowerUp.hpp>

class NoPU: public PowerUp
{
public:
    NoPU(Bird* _bird, std::shared_ptr<World> _world, StateMachine* sm);

    void enter() noexcept override;

    void solve_collision() noexcept override;

    void exit() noexcept override;
};