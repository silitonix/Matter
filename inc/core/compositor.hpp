#ifndef _COMPOSITOR
#define _COMPOSITOR

#include <Louvre/LCompositor.h>

#include "LFactoryObject.h"
using namespace CZ;
class Compositor final : public CZ::LCompositor {
 private:
  LFactoryObject* createObjectRequest(LFactoryObject::Type objectType,
                                      const void* params) override;
};

#endif  // !_COMPOSITOR
