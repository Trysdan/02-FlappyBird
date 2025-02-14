#pragma once

#include<SFML/Graphics.hpp>

class Bubble
{
public:
    Bubble(float _x, float _y) noexcept;

    void update(float dt) noexcept;

    sf::FloatRect get_collision_rect() const noexcept;

    bool collides(const sf::FloatRect& rect) const noexcept;

    void render(sf::RenderTarget& target) const noexcept;

    bool is_out_of_game() const noexcept;

    void update_touched(const sf::FloatRect& rect) noexcept;

    void reset(float _x, float _y) noexcept;

private:
    float x;
    float y;
    const float bubble_dimension{24};
    sf::Sprite sprite;
    bool touched;
};