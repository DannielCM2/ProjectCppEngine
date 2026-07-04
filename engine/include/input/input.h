#pragma once
#include <array>
#include <input/button_state.h>
#include <cstdint>

namespace Engine {
    class Input {
    public:
        Input();
        ~Input();

        void update();

        void onKeyDown(std::uint8_t keyCode);
        void onKeyUp(std::uint8_t keyCode);

        bool isKeyDown(std::uint8_t keyCode) const;
        bool isKeyPressed(std::uint8_t keyCode) const;
        bool isKeyReleased(std::uint8_t keyCode) const;

        void GetMousePosition();
        bool isMouseButtonDown();

    private:
        std::array<ButtonState, 256> m_keyboard;
    };
}