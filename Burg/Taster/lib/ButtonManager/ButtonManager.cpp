#include "ButtonManager.h"

ButtonListItem* ButtonManager::head = NULL;

void ButtonManager::begin() {
  Timer1.initialize(100000);
  Timer1.attachInterrupt(ButtonManager::handleButtons); // handleButtons every 0.1 seconds
}

void ButtonManager::addButton(Button *newButton) {
  ButtonListItem* link = new ButtonListItem;

  link->button = newButton;
  link->next = ButtonManager::head;

  ButtonManager::head = link;
}

void ButtonManager::handleButtons() {
  noInterrupts();
  Serial.println(millis());
  ButtonListItem* buttonPtr = ButtonManager::head;

  while (buttonPtr != NULL) {
    buttonPtr->button->handleButton();
    buttonPtr = buttonPtr->next;
  }
  interrupts();
}
