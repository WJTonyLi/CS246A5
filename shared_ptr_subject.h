#ifndef SUBJECT_H
#define SUBJECT_H
#include <memory>
#include <vector>
#include "shared_ptr_observer.h"

// DO NOT MODIFY THIS FILE!

template <typename InfoType> class SharedPtrObserver;

template <typename InfoType> class SharedPtrSubject {
  std::vector<std::shared_ptr<SharedPtrObserver<InfoType>>> observers;
 public:
  void attach(std::shared_ptr<SharedPtrObserver<InfoType>> o);
  void notifyObservers();
  virtual InfoType getInfo() const = 0;
};

template <typename InfoType>
void SharedPtrSubject<InfoType>::attach(std::shared_ptr<SharedPtrObserver<InfoType>> o) {
  observers.emplace_back(o);
}

template <typename InfoType>
void SharedPtrSubject<InfoType>::notifyObservers() {
  for (auto ob : observers) ob->notify(*this);
}

#endif
