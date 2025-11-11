#ifndef _KEYBOARD
#define _KEYBOARD

#include <Louvre/Seat/LKeyboard.h>

#include "Cuarzo.h"
using namespace CZ;

class Keyboard final : public LKeyboard {
 public:
  using LKeyboard::LKeyboard;

  void keyEvent(const CZKeyboardKeyEvent& e) override;
};

#endif  // _KEYBOARD
