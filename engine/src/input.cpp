#include <iostream>
#include "input/input.h"

namespace Engine {
    Input::Input() = default;
    Input::~Input() = default;

    void Input::update() {
        for (ButtonState& key : m_keyboard) {
            key.previous = key.current;
        }
    }

    void Input::onKeyDown(std::uint8_t keyCode) {
        std::cout << "Key Down: " << static_cast<char>(keyCode) << '\n';
        m_keyboard[keyCode].current = true;
    }

    void Input::onKeyUp(std::uint8_t keyCode) {
        std::cout << "Key Up: " << static_cast<char>(keyCode) << '\n';
        m_keyboard[keyCode].current = false;
    }

    bool Input::isKeyDown(std::uint8_t keyCode) const {
        return m_keyboard[keyCode].current;
    }

    bool Input::isKeyPressed(std::uint8_t keyCode) const {
        return m_keyboard[keyCode].current && !m_keyboard[keyCode].previous;
    }

    bool Input::isKeyReleased(std::uint8_t keyCode) const {
        return !m_keyboard[keyCode].current && m_keyboard[keyCode].previous;
    }

    void Input::GetMousePosition() {
        // Implementation for getting the mouse position
    }

    bool Input::isMouseButtonDown() {
        // Implementation for checking if a mouse button is down
        return false;
    }
}