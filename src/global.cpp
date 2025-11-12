#include "global.hpp"

#include <LLauncher.h>
#include <LLog.h>

#include "core/compositor.hpp"

using namespace CZ;

int Global::initialize() {
  setenv("CZ_LOUVRE_WAYLAND_DISPLAY", "matter", 0);

  setenv("CZ_LOUVRE_ENABLE_LIBSEAT", "1", 0);
  setenv("CZ_LOUVRE_LOG_LEVEL", opt.log_level, 0);
  setenv("CZ_CORE_LOG_LEVEL", opt.log_level, 0);
  setenv("CZ_REAM_LOG_LEVEL", opt.log_level, 0);
  setenv("CZ_SRM_LOG_LEVEL", opt.log_level, 0);
  setenv("CZ_KAY_LOG_LEVEL", opt.log_level, 0);

  // setenv("MOZ_ENABLE_WAYLAND", "1", 1);
  // setenv("QT_QPA_PLATFORM", "wayland-egl", 1);
  // setenv("GDK_BACKEND", "wayland", 1);

  LLauncher::startDaemon();

  compositor = new Compositor;

  if (!compositor->start()) {
    LLog(CZFatal, CZLN, "Failed to start compositor");
    return EXIT_FAILURE;
  }

  while (compositor->state() != Compositor::Uninitialized)
    compositor->dispatch(-1);

  return EXIT_SUCCESS;
}
