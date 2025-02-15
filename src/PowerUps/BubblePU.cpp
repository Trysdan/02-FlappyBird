#include <src/PowerUps/BubblePU.hpp>
#include <src/Bird.hpp>
#include <Settings.hpp>

BubblePU::BubblePU(Bird* _bird, std::shared_ptr<World> _world, StateMachine* sm): PowerUp{_bird,_world,sm}, countDown{30.f}
{}

void BubblePU::enter() noexcept
{
    Settings::music.pause();
    bird->set_ghostly_bird_to(true);
}

void BubblePU::solve_collision() noexcept
{
    //Nothing to do here :)
}

void BubblePU::exit() noexcept
{}