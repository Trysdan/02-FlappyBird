/*
    ISPPV1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the declaration of the class TitleScreenState.
*/

#include <Settings.hpp>
#include <src/text_utilities.hpp>
#include <src/states/StateMachine.hpp>
#include <src/states/TitleScreenState.hpp>
#include<src/Game.hpp>

TitleScreenState::TitleScreenState(StateMachine* sm) noexcept
    : BaseState{sm}, world{}
{
    selectedMode = std::make_shared<NormalMode>();
}

void TitleScreenState::handle_inputs(const sf::Event& event) noexcept {
    if (Game::key_is_pressed()) {
        switch (event.key.code) {
        case sf::Keyboard::N:
            setGameMode(std::make_shared<NormalMode>());
            break;

        case sf::Keyboard::H:
            setGameMode(std::make_shared<HardMode>());
            break;

        case sf::Keyboard::Return: 
            state_machine->change_state("count_down" , selectedMode);
            break;

        default:
            break;
        }
    }
}

void TitleScreenState::update(float dt) noexcept
{
    world.update(dt);
}

void TitleScreenState::render(sf::RenderTarget& target) const noexcept {
    world.render(target);

    // Título del juego
    render_text(target, Settings::VIRTUAL_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 4, "Flappy Bird", Settings::FLAPPY_TEXT_SIZE, "flappy", sf::Color::White, true);

    // Instrucciones para seleccionar modo
    render_text(target, Settings::VIRTUAL_WIDTH / 2, 2 * Settings::VIRTUAL_HEIGHT / 4, "Presiona N para NormalMode", Settings::MEDIUM_TEXT_SIZE, "font", sf::Color::White, true);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, 2 * Settings::VIRTUAL_HEIGHT / 4 + 40, "Presiona H para HardMode", Settings::MEDIUM_TEXT_SIZE, "font", sf::Color::White, true);

    // Mostrar el modo seleccionado
    if (selectedMode) {
        std::string modeText = "Modo seleccionado: " + std::string((dynamic_cast<NormalMode*>(selectedMode.get()) ? "NormalMode" : "HardMode"));
        render_text(target, Settings::VIRTUAL_WIDTH / 2, 2 * Settings::VIRTUAL_HEIGHT / 4 + 80, modeText, Settings::MEDIUM_TEXT_SIZE, "font", sf::Color::Yellow, true);
    }
    else {
        render_text(target, Settings::VIRTUAL_WIDTH / 2, 2 * Settings::VIRTUAL_HEIGHT / 4 + 80, "Ningun modo seleccionado", Settings::MEDIUM_TEXT_SIZE, "font", sf::Color::Red, true);
    }

    // Instrucción para iniciar el juego
    render_text(target, Settings::VIRTUAL_WIDTH / 2, 2 * Settings::VIRTUAL_HEIGHT / 4 + 120, "Presiona Enter para iniciar", Settings::MEDIUM_TEXT_SIZE, "font", sf::Color::White, true);
}