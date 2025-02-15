/*
    ISPPV1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the declaration of the class Bird.
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <src/PowerUps/NoPU.hpp>
#include <src/PowerUps/BubblePU.hpp>
#include <array>

enum PUEnum
{
    NoPowerUp = 0,
    BubblePowerUp = 1
};

class Bird
{
public:
    Bird(float _x, float _y, float w, float h, std::shared_ptr<World> world, StateMachine* sm) noexcept;

    Bird(const Bird&) = delete;

    Bird& operator = (Bird) = delete;

    sf::FloatRect get_collision_rect() const noexcept;

    void jump() noexcept;

    void update(float dt) noexcept;

    void render(sf::RenderTarget& target) const noexcept;

    void handle_log_collision() noexcept;

    void set_power_up_to(PUEnum powerUp) noexcept;

    void set_ghostly_bird_to(bool on) noexcept;

private:
    float x;
    float y;
    float width;
    float height;
    float vy;
    float vx;
    sf::Sprite sprite;
    bool jumping{false};

    friend class HardMode;

    friend NoPU;
    friend BubblePU;

    PUEnum currentPowerUp;
    std::array<std::unique_ptr<PowerUp>,2> powerUps;
};
