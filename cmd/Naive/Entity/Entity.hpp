#pragma once

#include <SDL.h>
#include <memory>

class Entity {
public:
    virtual ~Entity() = default;

    virtual auto Draw([[maybe_unused]] SDL_Renderer* renderer) const -> void = 0;
    virtual auto Update(double dt) -> void = 0;
};
