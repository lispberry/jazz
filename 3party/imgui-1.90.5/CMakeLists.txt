project(ImGui)

file(GLOB IMGUI_SOURCES ./*.cpp)
add_library(${PROJECT_NAME} STATIC ${IMGUI_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC .)
