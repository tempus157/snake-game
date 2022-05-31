#include "Scene.hpp"

#include "../private/Input.hpp"
#include "LifeCycle.hpp"

Scene::Scene() : update([] {}), destroy([] {}) {}

Scene::Scene(const Object &object)
    : update([=] {
          object.update(Vector2::Zero);
      }),
      destroy([] {
          LifeCycle::notifyDestroy();
          LifeCycle::clearUpdate();
          LifeCycle::clearDestroy();
          Input::clearKeyPress();
      }) {}
