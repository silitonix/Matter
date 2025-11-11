#ifndef _MATTER
#define _MATTER

#include "core/compositor.hpp"
class Global {
 public:
  struct {
    bool verbose = false;
    char log_level[2] = "0";
  } opt;

  Compositor compositor;
  int initialize();
};

#endif  // !_MATTER
