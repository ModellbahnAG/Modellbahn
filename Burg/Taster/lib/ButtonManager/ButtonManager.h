#ifndef BUTTON_MANAGER_H
#define BUTTON_MANAGER_H

#include <Arduino.h>
#include "Button.h"
#include "TimerOne.h"


struct ButtonListItem {
  Button* button;
  ButtonListItem* next;
};

class ButtonManager {
  public:
    static ButtonListItem* head;
    static void begin();
    static void addButton(Button* newButton);
    static void handleButtons();
};
#endif
