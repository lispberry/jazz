#include <Entity/Scene.hpp>
#include <SDL.h>
#include <fmt/core.h>
#include <span>

[[nodiscard]] auto add(int64_t x, int64_t y) -> decltype(x + y)
{
    return x + y;
}

auto main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) -> int
{
    constexpr auto windowName = "Naive";
    constexpr auto width = 1280;
    constexpr auto height = 720;

    // SDL Create windows and surface
    SDL_Window* window
        = SDL_CreateWindow(windowName,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            width,
            height,
            SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == nullptr) {
        fmt::print("Failed to create window: {}\n", SDL_GetError());
        return 1;
    }
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        fmt::print("Could not create a renderer: {}", SDL_GetError());
        return -1;
    }

    auto scene = LoadScene("Asset/scene.json");
    if (!scene.has_value()) {
        fmt::print("Failed to load scene: {}\n", static_cast<int>(scene.error()));
        return 1;
    }

    // SDL Event loop
    SDL_Event event;
    for (;;) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                SDL_Quit();
                return 0;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        for (auto& entity : scene.value()) {
            entity->Update(0.016);
            entity->Draw(renderer);
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    return 0;
}