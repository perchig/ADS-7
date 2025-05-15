// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

Train::~Train() {
  if (first) {
    Car* current = first;
    do {
      Car* temp = current->next;
      delete current;
      current = temp;
    } while (current != first);
  }
}

void Train::addCar(bool light) {
  Car* newCar = new Car{light, nullptr, nullptr};
  if (!first) {
    first = newCar;
    first->next = first;
    first->prev = first;
  } else {
    Car* last = first->prev;
    last->next = newCar;
    newCar->prev = last;
    newCar->next = first;
    first->prev = newCar;
  }
}

int Train::getLength() {
countOp = 0;
  Car* current;
  while (true) {
    current = first;
    int total = 0;
    if (!current->light) {
        current->light = true;
    }
    current = current->next;
    countOp += 2;
    while (!current->light) {
      current = current->next;
      countOp += 2;
      total++;
    }
    current->light = false;
    if (!first->light) {
      return total + 1;
    }
  }

int Train::getOpCount() {
  return countOp;
}
