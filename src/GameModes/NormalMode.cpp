#include <Settings.hpp>
#include <src/Game.hpp>
#include <src/GameModes/NormalMode.hpp>
#include <src/states/PlayingState.hpp>

NormalMode::NormalMode(PlayingState* playingState): GameMode{playingState} {}

void NormalMode::handle_inputs(const sf::Event& event) noexcept
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        ps->bird->jump();
    }

    if (Game::key_is_pressed() && event.key.code == Settings::PAUSE_KEY)
    {
        ps->state_machine->change_state("pause", ps->selectedMode, ps->world, ps->bird, ps->score);
    }
}

void NormalMode::generateLogs(float dt, World* world) noexcept
{
    world->logs_spawn_timer += dt;

    if (world->logs_spawn_timer >= Settings::TIME_TO_SPAWN_LOGS)
    {
        world->logs_spawn_timer = 0.f;

        std::uniform_int_distribution<int> dist{ -20, 20 };
        float y = std::max(-Settings::LOG_HEIGHT + 10, std::min(world->last_log_y + dist(world->rng), Settings::VIRTUAL_HEIGHT + 90 - Settings::LOG_HEIGHT));

        world->last_log_y = y;

        world->logs.push_back(world->log_factory.create(Settings::VIRTUAL_WIDTH, y));
    }
}
