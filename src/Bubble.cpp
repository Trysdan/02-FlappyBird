#include <src/Bubble.hpp>
#include <Settings.hpp>

Bubble::Bubble(float _x, float _y) noexcept: x{_x}, y{_y}, sprite{Settings::textures["bubble"]}, touched{false} {}

void Bubble::update(float dt) noexcept
{
    x -= Settings::MAIN_SCROLL_SPEED*dt;
    sprite.setPosition(x,y);
}

sf::FloatRect Bubble::get_collision_rect() const noexcept
{
    return sf::FloatRect(x,y,bubble_dimension,bubble_dimension);
}

bool Bubble::collides(const sf::FloatRect& rect) const noexcept
{
    return get_collision_rect().intersects(rect);
}

void Bubble::render(sf::RenderTarget& target) const noexcept
{
    if(touched)
    {
        return;
    }
    target.draw(sprite);
}

bool Bubble::is_out_of_game() const noexcept
{
    return x < -bubble_dimension;
}

void Bubble::update_touched(const sf::FloatRect& rect) noexcept
{
    if(touched)
    {
        return;
    }
    if(collides(rect))
    {
        touched = true;
    }
}

void Bubble::reset(float _x, float _y) noexcept
{
    x = _x;
    y = _y;
    touched = false;
}