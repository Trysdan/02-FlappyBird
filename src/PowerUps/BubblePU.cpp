#include <src/PowerUps/BubblePU.hpp>

BubblePU::BubblePU(Bird* _bird, std::shared_ptr<World> _world, StateMachine* sm): PowerUp{_bird,_world,sm}, countDown{30.f}
{}

void BubblePU::enter() noexcept
{
    
}

void BubblePU::solve_collision() noexcept
{}

void BubblePU::exit() noexcept
{}