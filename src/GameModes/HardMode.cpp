#include <Settings.hpp>
#include <src/Game.hpp>
#include <src/GameModes/HardMode.hpp>
#include <src/states/PlayingState.hpp>
#include <iostream>

HardMode::HardMode(PlayingState* playingState): GameMode{playingState}
{
    timeToSpawnLogs = Settings::TIME_TO_SPAWN_LOGS;
}

void HardMode::handle_inputs(const sf::Event& event) noexcept
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        ps->bird->jump();
    }

    if (Game::key_is_pressed())
    {
        switch(event.key.code)
        {
            case Settings::LEFT_KEY:
                ps->bird->vx = -Settings::BIRD_SPEED;
                break;
            case Settings::RIGHT_KEY:
                ps->bird->vx = Settings::BIRD_SPEED;
                break;
            case Settings::PAUSE_KEY:
                ps->state_machine->change_state("pause", ps->selectedMode, ps->world, ps->bird, ps->score);
                break;
            case sf::Keyboard::P:
                ps->bird->set_power_up_to(BubblePowerUp);
                break;
            case sf::Keyboard::N:
                ps->bird->set_power_up_to(NoPowerUp);
                break;
            default:
                break;
        }
    }
}

void HardMode::generateLogs(float dt, World* world) noexcept
{
    world->logs_spawn_timer += dt;

    if (world->logs_spawn_timer >= timeToSpawnLogs)
    {
        world->logs_spawn_timer = 0.f;

        std::uniform_int_distribution<int> dist{ -20, 20 };
        float y = std::max(-Settings::LOG_HEIGHT + 10, std::min(world->last_log_y + dist(world->rng), Settings::VIRTUAL_HEIGHT + 90 - Settings::LOG_HEIGHT));

        world->last_log_y = y;

        world->logs.push_back(world->log_factory.create(Settings::VIRTUAL_WIDTH, y));

        std::normal_distribution<float> disTime(Settings::TIME_TO_SPAWN_LOGS, 1.0);
        timeToSpawnLogs = disTime(world->rng);

        std::cout << "time: " << timeToSpawnLogs << std::endl;
    }
}