if (USE_UBSAN)
    add_compile_options(
        "-fsanitize=undefined"
        "-fno-omit-frame-pointer")
    add_link_options("-fsanitize=undefined")
endif()

if (USE_ASAN)
    add_compile_options(
        "-fsanitize=address"
        "-fno-omit-frame-pointer")
    add_link_options("-fsanitize=address")
endif()

if (USE_TSAN)
    add_compile_options(
        "-fsanitize=thread"
        "-fno-omit-frame-pointer")
    add_link_options("-fsanitize=thread")
endif()

if (USE_LIBFUZZER)
    add_compile_options("-fsanitize=fuzzer")
    add_link_options("-fsanitize=fuzzer")
endif()