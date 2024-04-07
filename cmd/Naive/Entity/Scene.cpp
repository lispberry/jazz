#include <Entity/Scene.hpp>
#include <Entity/Square.hpp>
#include <fstream>
#include <json.hpp>

namespace {
[[nodiscard]] auto LoadSquare(const json& entity)
{
    const auto width = entity.at("size").get<int>();

    return std::make_unique<Square>(
        width,
        entity.at("x").get<int>(),
        entity.at("y").get<int>());
}

[[nodiscard]] auto LoadEntity(const json& entity) -> tl::expected<std::unique_ptr<Entity>, LoadError>
{
    const std::string& type = entity["type"];
    if (type == "square") {
        return LoadSquare(entity);
    }
    return tl::make_unexpected(LoadError::InvalidFormat);
}
}

[[nodiscard]] auto LoadScene(const std::filesystem::path& path) -> tl::expected<std::vector<std::unique_ptr<Entity>>, LoadError>
{
    auto stream = std::ifstream(path);
    if (!stream.is_open()) {
        return tl::make_unexpected(LoadError::FileNotFound);
    }

    try {
        auto scene = json::parse(stream);
        std::vector<std::unique_ptr<Entity>> entities;
        for (const auto& entry : scene) {
            auto entity = LoadEntity(entry);
            if (!entity.has_value()) {
                return tl::make_unexpected(entity.error());
            }
            entities.emplace_back(std::move(entity.value()));
        }
        return entities;
    } catch (std::exception&) {
        return tl::make_unexpected(LoadError::InvalidFormat);
    }
}