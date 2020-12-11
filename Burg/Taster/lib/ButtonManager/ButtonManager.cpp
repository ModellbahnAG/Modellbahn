#include "ButtonManager.h"

ButtonListItem* ButtonManager::listHead = NULL;



void ButtonManager::addButton(Button *newButton) {
  ButtonListItem* link = new ButtonListItem;

  link->button = newButton;
  link->next = ButtonManager::listHead;

  ButtonManager::listHead = link;
}

void ButtonManager::handleButtons() {
  ButtonListItem* buttonPtr = ButtonManager::listHead;

  while (buttonPtr != NULL) {
    buttonPtr->button->handleButton();
    buttonPtr = buttonPtr->next;
  }
}
