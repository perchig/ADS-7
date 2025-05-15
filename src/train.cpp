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
  Car* currentCar = first;
  int totalCars = 0;

  while (true) {
    if (!currentCar->light) {
      currentCar->light = true;
      countOp++;
      currentCar = currentCar->next;
      countOp++;
      totalCars++;
    } else {
      currentCar->light = false;
      countOp++;
      if (!first->light) {
        break;
      }
      currentCar = currentCar->next;
      countOp++;
    }
  }

  return totalCars;
}

int Train::getOpCount() {
  return countOp;
}
