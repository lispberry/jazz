#pragma once

#include <Entity/Entity.hpp>
#include <Entity/Scene.hpp>

class Square final : public Entity {
public:
    Square(int size, double x, double y)
        : m_size(size)
        , m_x(x)
        , m_y(y)
    {
    }
    Square() = default;
    ~Square() = default;
    Square(const Square&) = default;
    Square(Square&&) = default;
    Square& operator=(const Square&) = default;
    Square& operator=(Square&&) = default;

    // write copy and move constructors default of course

    auto Draw(SDL_Renderer* renderer) const -> void override;
    auto Update(double dt) -> void override;

private:
    int m_size = 0;
    double m_x = 0;
    double m_y = 0;
};