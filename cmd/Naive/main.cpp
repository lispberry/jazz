#include <Entity/Scene.hpp>
#include <SDL.h>
#include <backends/imgui_impl_sdl2.h>
#include <backends/imgui_impl_sdlrenderer2.h>
#include <fmt/core.h>
#include <imgui.h>
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

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0) {
        fmt::print("Couldn't initialize a window: {}\n", SDL_GetError());
        return 1;
    }

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
        return 1;
    }

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad; // Enable Gamepad Controls

    ImGui::StyleColorsLight();
    if (const auto res = ImGui_ImplSDL2_InitForSDLRenderer(window, renderer); !res) {
        fmt::print("Failed to initialize ImGui SDL2\n");
        return 1;
    }
    if (const auto res = ImGui_ImplSDLRenderer2_Init(renderer); !res) {
        fmt::print("Failed to initialize ImGui SDL2 Renderer\n");
        return 1;
    }

    const auto scene = LoadScene("Asset/scene.json");
    if (!scene.has_value()) {
        fmt::print("Failed to load scene: {}\n", static_cast<int>(scene.error()));
        return 1;
    }

    // SDL Event loop
    SDL_Event event;
    for (;;) {
        while (SDL_PollEvent(&event) != 0) {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if (event.type == SDL_QUIT) {
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                SDL_Quit();
                return 0;
            }
        }

        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        ImGui::ShowDemoWindow();
        ImGui::Render();

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        for (auto& entity : scene.value()) {
            entity->Update(0.016);
            entity->Draw(renderer);
        }
        ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    return 0;
}
