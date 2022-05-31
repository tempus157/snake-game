#include "Scene.hpp"
#include "../private/Input.hpp"
#include "PropertyEvent.hpp"

Scene::Scene() : mount([] {}), update([] {}), destroy([] {}) {}

Scene::Scene(const Object &object)
    : mount([] {}),
      update([=] {
          object.update(Vector2::Zero);
      }),
      destroy([] {
          Input::clearKeyPress();
          PropertyEvent::clearUpdate();
      }) {}
