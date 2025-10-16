#include "global.h"

#include <LLauncher.h>
#include <LLog.h>

#include <cstdlib>

#include "core/compositor.h"

using namespace CZ;

void Global::setup() {
  setenv("CZ_LOUVRE_WAYLAND_DISPLAY", "Matter", 0);

  setenv("CZ_LOUVRE_ENABLE_LIBSEAT", "1", 0);
  setenv("CZ_LOUVRE_LOG_LEVEL", "4", 1);
  setenv("CZ_CORE_LOG_LEVEL", "4", 1);
  setenv("CZ_REAM_LOG_LEVEL", "4", 0);
  setenv("CZ_SRM_LOG_LEVEL", "4", 0);
  setenv("CZ_KAY_LOG_LEVEL", "4", 1);

  setenv("MOZ_ENABLE_WAYLAND", "1", 1);
  setenv("QT_QPA_PLATFORM", "wayland-egl", 1);
  setenv("GDK_BACKEND", "wayland", 1);

  LLauncher::startDaemon();

  if (!compositor.start()) {
    LLog(CZFatal, CZLN, "Failed to start compositor");
    exit(EXIT_FAILURE);
  }

  while (compositor.state() != Compositor::Uninitialized)
    compositor.dispatch(-1);

  exit(EXIT_SUCCESS);
}
