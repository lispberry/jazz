#pragma once

#include <Entity/Entity.hpp>
#include <Entity/Scene.hpp>
#include <TypeTraits/Core.hpp>

class Square final : public Entity {
public:
    COPY_AND_MOVE_CLASS(Square)

    Square(int size, double x, double y)
        : m_size(size)
        , m_x(x)
        , m_y(y)
    {
    }

    auto Draw(SDL_Renderer* renderer) const -> void override;
    auto Update(double dt) -> void override;

private:
    int m_size = 0;
    double m_x = 0;
    double m_y = 0;
};
