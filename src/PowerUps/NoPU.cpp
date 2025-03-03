#include <Settings.hpp>
#include <src/Bird.hpp>
#include <src/World.hpp>
#include <src/PowerUps/NoPU.hpp>
#include <src/states/StateMachine.hpp>

NoPU::NoPU(Bird* _bird, std::shared_ptr<World> _world, StateMachine* sm): PowerUp{_bird,_world,sm}
{
}

void NoPU::update(float dt) noexcept{}

void NoPU::enter() noexcept
{
    Settings::music.play();
    bird->set_ghostly_bird_to(false);
}

void NoPU::solve_collision() noexcept
{
    if (PowerUp::world->collides(bird->get_collision_rect()))
    {
        Settings::sounds["explosion"].play();
        Settings::sounds["hurt"].play();
        stateMachine->change_state("count_down", world->selectedMode);
    }
}

void NoPU::exit() noexcept
{}

void NoPU::render(sf::RenderTarget& target) noexcept
{}