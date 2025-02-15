/*
    ISPPV1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the definition of the class Bird.
*/

#include <Settings.hpp>
#include <src/Bird.hpp>

Bird::Bird(float _x, float _y, float w, float h, std::shared_ptr<World> world, StateMachine* sm) noexcept
    : x{_x}, y{_y}, width{w}, height{h}, vy{0.f}, vx{0.f}, sprite{Settings::textures["bird"]},
    powerUps{std::make_unique<NoPU>(this,world,sm),std::make_unique<BubblePU>(this,world,sm)}, currentPowerUp{NoPowerUp}
{
    sprite.setPosition(x, y);
}

sf::FloatRect Bird::get_collision_rect() const noexcept
{
    return sf::FloatRect{x, y, width, height};
}

void Bird::jump() noexcept
{
    if (!jumping)
    {
        jumping = true;
    }
}

void Bird::update(float dt) noexcept
{
    vy += Settings::GRAVITY * dt;

    if (jumping)
    {
        Settings::sounds["jump"].play();
        vy = -Settings::JUMP_TAKEOFF_SPEED;
        jumping = false;
    }

    y += vy * dt;
    x += vx * dt;
    vx = 0;
    sprite.setPosition(x, y);
    powerUps[currentPowerUp]->update(dt);
}

void Bird::render(sf::RenderTarget& target) const noexcept
{
    target.draw(sprite);
    powerUps[currentPowerUp]->render(target);
}

void Bird::handle_log_collision() noexcept
{
    powerUps[currentPowerUp]->solve_collision();
}

void Bird::set_power_up_to(PUEnum powerUp) noexcept
{
    if(currentPowerUp == powerUp)
    {
        return;
    }
    powerUps[currentPowerUp]->exit();
    currentPowerUp = powerUp;
    powerUps[currentPowerUp]->enter();
}

void Bird::set_ghostly_bird_to(bool on) noexcept
{
    if(on)
    {
        sprite.setColor(sf::Color(255,255,255,128));
    }
    else
    {
        sprite.setColor(sf::Color(255,255,255));
    }
}