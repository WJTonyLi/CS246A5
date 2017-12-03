#ifndef RAW_PTR_OBSERVER_H_
#define RAW_PTR_OBSERVER_H_

template <typename InfoType> class RawPtrSubject;

template <typename InfoType> class RawPtrObserver{
 public:
  virtual void notify(RawPtrSubject<InfoType> &whoFrom) = 0; // pass the Subject that called the notify method
  virtual ~RawPtrObserver() = default;
};
#endif
