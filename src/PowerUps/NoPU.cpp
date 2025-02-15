#include <src/PowerUps/NoPU.hpp>

NoPU::NoPU(Bird* _bird, std::shared_ptr<World> _world, StateMachine* sm): PowerUp{_bird,_world,sm} {}

void NoPU::enter() noexcept
{}

void NoPU::solve_collision() noexcept
{}

void NoPU::exit() noexcept
{}