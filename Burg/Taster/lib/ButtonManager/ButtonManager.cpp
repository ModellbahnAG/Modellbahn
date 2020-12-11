#include "ButtonManager.h"

ButtonList* ButtonManager::listHead = NULL;



void ButtonManager::addButton(Button *newButton) {
  ButtonList* link = new ButtonList;

  link->button = newButton;
  link->next = ButtonManager::listHead;

  ButtonManager::listHead = link;
}

void ButtonManager::handleButtons() {
  ButtonList* buttonPtr = ButtonManager::listHead;

  while (buttonPtr != NULL) {
    buttonPtr->button->handleButton();
    buttonPtr = buttonPtr->next;
  }
}

// remove an element from the linked list
void ButtonManager::removeButton(Button* toDelete) {
    ButtonList* prev = ButtonManager::listHead; // empty header
    ButtonList* current = ButtonManager::listHead->next; // the first valid node
    while(current != NULL && current->button != toDelete) {
      prev = current;
      current = current->next; // go to next value
    }

    if(current == NULL) { // if we reached end of list or the list is empty
        Serial.println("Can't remove button: no match found.");
    } else {
        prev->next = current->next; // unlink the node you remove
        delete current; // delete the node
    }
}

void ButtonManager::removeList() {
  delete ButtonManager::listHead;
}
