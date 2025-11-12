#include "seat/keyboard.hpp"

#include <AK/AKApp.h>
#include <Core/CZCore.h>
#include <Core/CZEase.h>
#include <Core/Events/CZKeyboardKeyEvent.h>
#include <linux/input-event-codes.h>

#include "Cuarzo.h"
#include "LLauncher.h"
#include "Seat/LKeyboard.h"
#include "main.hpp"

using namespace CZ;

void Keyboard::keyEvent(const CZKeyboardKeyEvent& event) {
  const bool L_CTRL{isKeyCodePressed(KEY_LEFTCTRL)};
  const bool R_CTRL{isKeyCodePressed(KEY_RIGHTCTRL)};
  const bool L_SHIFT{isKeyCodePressed(KEY_LEFTSHIFT)};
  const bool L_ALT{isKeyCodePressed(KEY_LEFTALT)};
  const bool mods{L_ALT || L_SHIFT || L_CTRL || R_CTRL};

  sendKeyEvent(event);

  if (!event.isPressed) {
    if (event.code == KEY_ESC && L_CTRL && L_SHIFT) {
      g.compositor->finish();
      return;
    }
    if (event.code == KEY_F1 && !mods) {
      LLauncher::launch("ptyxis");
      return;
    }
  }

  LKeyboard::keyEvent(event);
}
