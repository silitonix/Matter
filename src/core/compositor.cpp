#include "core/compositor.hpp"

#include "seat/keyboard.hpp"

using namespace CZ;

LFactoryObject* Compositor::createObjectRequest(LFactoryObject::Type objectType,
                                                const void* params) {
  switch (objectType) {
    case LFactoryObject::Type::LKeyboard: return new Keyboard(params);
    case LFactoryObject::Type::LClient:
      // RResourceTrackerLog();
      return nullptr;
    default: return nullptr;
  }
}
