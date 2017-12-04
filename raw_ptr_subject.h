#ifndef SHARED_PTR_SUBJECT_H
#define SHARED_PTR_SUBJECT_H
#include <memory>
#include <vector>
#include <algorithm>
#include "raw_ptr_observer.h"

// DO NOT MODIFY THIS FILE!

template <typename InfoType> class RawPtrObserver;

template <typename InfoType> class RawPtrSubject {
  std::vector<RawPtrObserver<InfoType> *> observers;
 public:
  void attach(RawPtrObserver<InfoType> *o);
  void detach(RawPtrObserver<InfoType> *o);
  void notifyObservers();
  virtual InfoType getInfo() const = 0;
};

template <typename InfoType>
void RawPtrSubject<InfoType>::attach(RawPtrObserver<InfoType> *o) {
  observers.emplace_back(o);
}

template <typename InfoType>
void RawPtrSubject<InfoType>::detach(RawPtrObserver<InfoType> *o) {
  observers.erase(std::remove(observers.begin(), observers.end(), o), observers.end());
}

template <typename InfoType>
void RawPtrSubject<InfoType>::notifyObservers() {
  for (auto ob : observers) ob->notify(*this);
}

#endif
