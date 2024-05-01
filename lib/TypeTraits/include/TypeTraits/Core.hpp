#pragma once

#define MOVE_ONLY_CLASS(ClassName)                         \
    ClassName() = default;                                 \
    ~ClassName() = default;                                \
    ClassName(const ClassName&) = delete;                  \
    ClassName(ClassName&&) = default;                      \
    auto operator=(const ClassName&)->ClassName& = delete; \
    auto operator=(ClassName&&)->ClassName& = default;

#define COPY_AND_MOVE_CLASS(ClassName)                      \
    ClassName() = default;                                  \
    ~ClassName() = default;                                 \
    ClassName(const ClassName&) = default;                  \
    ClassName(ClassName&&) = default;                       \
    auto operator=(const ClassName&)->ClassName& = default; \
    auto operator=(ClassName&&)->ClassName& = default;
