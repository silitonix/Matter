#ifndef _MATTER
#define _MATTER

#include "core/compositor.h"
class Global {
 public:
  struct {
    bool verbose = false;
  } conf = {};

  Compositor compositor;
  void setup();
};

#endif  // !_MATTER
