project(Naive)

add_strict_executable(${PROJECT_NAME}
    main.cpp
    Entity/Entity.hpp
    Entity/Scene.cpp
    Entity/Scene.hpp
    Entity/Square.cpp
    Entity/Square.hpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PRIVATE
    json
    fmt::fmt tl
    ImGui
    TypeTraits
    SDL2::SDL2 SDL2::SDL2main)
# Copy all assets to the build directory
file(COPY Asset DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
