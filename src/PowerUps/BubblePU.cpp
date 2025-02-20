#include <src/World.hpp>
#include <src/PowerUps/BubblePU.hpp>
#include <src/Bird.hpp>
#include <Settings.hpp>
#include <src/text_utilities.hpp>
#include <src/states/StateMachine.hpp>

BubblePU::BubblePU(Bird* _bird, std::shared_ptr<World> _world, StateMachine* sm): PowerUp{_bird,_world,sm}, countDown{10.f}
{
}

void BubblePU::update(float dt) noexcept
{
    countDown -= dt;
    if(countDown <= 0)
    {
        bird->set_power_up_to(NoPowerUp);
    }
}

void BubblePU::enter() noexcept
{
    Settings::music.pause();
    bird->set_ghostly_bird_to(true);
}

void BubblePU::solve_collision() noexcept
{
   if(bird->y >= Settings::VIRTUAL_HEIGHT)
   {
        Settings::sounds["explosion"].play();
        Settings::sounds["hurt"].play();
        bird->set_power_up_to(NoPowerUp);
        stateMachine->change_state("count_down", world->selectedMode);
   }
}

void BubblePU::exit() noexcept
{}

void BubblePU::render(sf::RenderTarget& target) noexcept
{
    render_text(target, Settings::VIRTUAL_WIDTH - 40, 10, std::to_string(int(countDown)), Settings::FLAPPY_TEXT_SIZE, "flappy", sf::Color::White,false);
}