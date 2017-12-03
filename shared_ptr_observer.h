#ifndef SHARED_PTR_OBSERVER_H
#define SHARED_PTR_OBSERVER_H

template <typename InfoType> class SharedPtrSubject;

template <typename InfoType> class SharedPtrObserver{
 public:
  virtual void notify(SharedPtrSubject<InfoType> &whoFrom) = 0; // pass the Subject that called the notify method
  virtual ~SharedPtrObserver() = default;
};
#endif
