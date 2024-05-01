#pragma once

#include <Entity/Entity.hpp>
#include <filesystem>
#include <json.hpp>
#include <memory>
#include <tl/expected.hpp>
#include <vector>

enum class LoadError {
    FileNotFound,
    InvalidFormat,
};

[[nodiscard]] auto LoadScene(const std::filesystem::path& path) -> tl::expected<std::vector<std::unique_ptr<Entity>>, LoadError>;