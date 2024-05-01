project(ImGui)

file(GLOB IMGUI_SOURCES ./*.cpp)
add_library(${PROJECT_NAME} STATIC ${IMGUI_SOURCES}
    backends/imgui_impl_sdl2.cpp
    backends/imgui_impl_sdl2.h
    backends/imgui_impl_sdlrenderer2.cpp
    backends/imgui_impl_sdlrenderer2.h)
target_link_libraries(${PROJECT_NAME} SDL2::SDL2)
target_include_directories(${PROJECT_NAME} PUBLIC .)
