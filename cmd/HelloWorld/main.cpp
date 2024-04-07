#include <cstdint>
#include <fmt/core.h>
#include <span>

[[nodiscard]] auto add(int64_t x, int64_t y) -> decltype(x + y)
{
    return x + y;
}

auto main(int argc, char** argv) -> int
{
    const auto args = std::span(argv, argc);

    if (argc != 2) {
        return 1;
    }
    fmt::println("Hello, {}!", args[1]);

    return 0;
}