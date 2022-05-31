#include "Scene.hpp"

#include "../private/AsyncHandler.hpp"
#include "../private/Input.hpp"
#include "LifeCycle.hpp"

Scene::Scene() : update([] {}), destroy([] {}) {}

Scene::Scene(const Object &object)
    : update([=] {
          object.update(Vector2::Zero);
      }),
      destroy([] {
          AsyncHandler::clearAll();
          LifeCycle::clearUpdate();
          Input::clearKeyPress();
      }) {}
