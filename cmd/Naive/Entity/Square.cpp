#include <Entity/Square.hpp>

auto Square::Draw([[maybe_unused]] SDL_Renderer* renderer) const -> void
{
    const auto rect = SDL_Rect {
        .x = static_cast<int>(m_x),
        .y = static_cast<int>(m_y),
        .w = m_size,
        .h = m_size,
    };
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}

auto Square::Update([[maybe_unused]] double dt) -> void
{
    m_x += 25 * dt;
    m_y += 25 * dt;
}