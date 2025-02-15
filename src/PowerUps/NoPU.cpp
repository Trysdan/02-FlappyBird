#include <Settings.hpp>
#include <src/PowerUps/NoPU.hpp>
#include <src/Bird.hpp>
#include <src/World.hpp>
#include <src/states/StateMachine.hpp>

NoPU::NoPU(Bird* _bird, std::shared_ptr<World> _world, StateMachine* sm): PowerUp{_bird,_world,sm} {}

void NoPU::enter() noexcept
{}

void NoPU::solve_collision() noexcept
{
    if (PowerUp::world->collides(bird->get_collision_rect()))
    {
        Settings::sounds["explosion"].play();
        Settings::sounds["hurt"].play();
        stateMachine->change_state("count_down");
    }
}

void NoPU::exit() noexcept
{}