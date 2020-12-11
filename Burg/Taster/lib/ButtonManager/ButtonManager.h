#ifndef BUTTON_MANAGER_H
#define BUTTON_MANAGER_H

#include <Arduino.h>
#include "Button.h"

struct ButtonList {
  Button* button;
  ButtonList* next;
};

class ButtonManager {
  public:
    static ButtonList* listHead;            // Liste aller Buttons

    static void addButton(Button* newButton);   // fügt neuen Button zur Liste hinzu
    static void handleButtons();                // überprüft, welcher Taster gedrückt wurde oder ob einer wieder aktiviert werden kann

    static void removeButton(Button* toDelete);
    static void removeList();
};

#endif
