#include <src/PowerUps/BubblePU.hpp>

BubblePU::BubblePU(Bird* _bird, std::shared_ptr<World> _world, StateMachine* sm): PowerUp{_bird,_world,sm} {}

void BubblePU::enter() noexcept
{}

void solve_collision() noexcept
{}

void exit() noexcept
{}