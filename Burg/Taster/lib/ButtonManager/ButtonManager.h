#ifndef BUTTON_MANAGER_H
#define BUTTON_MANAGER_H
#include <Arduino.h>
#include "Button.h"

struct ButtonListItem {
  Button* button;
  ButtonListItem* next;
};

class ButtonManager {
  public:
    static ButtonListItem* listHead;
    static void addButton(Button* newButton);
    static void handleButtons();
};
#endif
