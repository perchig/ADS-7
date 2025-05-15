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
  if (!first) {
    return 0;
  }

  Car* currentCar = first;
  int totalCars = 0;
  bool originalLight = currentCar->light;

  while (true) {
    currentCar->light = !currentCar->light;
    countOp++;
    totalCars++;
    currentCar = currentCar->next;
    countOp++;
    if (currentCar->light == originalLight) {
      break;
    }
  }

  currentCar = first;
  for (int i = 0; i < totalCars; i++) {
    currentCar->light = originalLight;
    currentCar = currentCar->next;
    countOp++;
  }

  return totalCars;
}

int Train::getOpCount() {
  return countOp;
}
