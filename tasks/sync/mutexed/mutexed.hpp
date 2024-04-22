#pragma once

#include <twist/ed/std/mutex.hpp>

#include <utility>

template <typename T, class Mutex = twist::ed::std::mutex>
class Mutexed {
  // Define your own OwnerRef
  using OwnerRef = T*;

 public:
  template <typename... Args>
  explicit Mutexed(Args&&... args)
      : object_(std::forward<Args>(args)...) {
  }

  OwnerRef Acquire() {
    return &object_;  // Your code goes here
  }

 private:
  T object_;
  Mutex mutex_;  // Guards access to object_
};

template <typename T>
auto Acquire(Mutexed<T>& object) {
  return object.Acquire();
}
