#include "Scene.hpp"

#include "../private/AsyncHandler.hpp"
#include "../private/Input.hpp"
#include "LifeCycle.hpp"

Scene::Scene() {}

Scene::Scene(const std::vector<const Object> &objects)
    : update([=] {
          for (const auto &object : objects) {
              object.update(Vector2::Zero);
          }
      }) {}
