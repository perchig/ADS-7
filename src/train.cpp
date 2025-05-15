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
  if (!currentCar->light) {
    currentCar->light = true;
  }
  currentCar = currentCar->next;
  countOp += 2;
  while (!currentCar->light) {
    currentCar = currentCar->next;
    totalCars++;
    countOp += 2;
  }
  currentCar->light = false;
  return totalCars + 1;
}

int Train::getOpCount() {
  return countOp;
}
