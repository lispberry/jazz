include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )
FetchContent_MakeAvailable(googletest)

if (win32)
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

enable_testing()

include(GoogleTest)

function(add_unit_test target_name)
    add_executable(${target_name} ${ARGN})
    target_link_libraries(${target_name} GTest::gtest_main GTest::gtest)
    gtest_discover_tests(${target_name})
endfunction(add_unit_test target_name)
