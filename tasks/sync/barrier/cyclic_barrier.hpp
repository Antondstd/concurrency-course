#pragma once

#include <twist/ed/std/mutex.hpp>
#include <twist/ed/std/condition_variable.hpp>

#include <cstddef>

class CyclicBarrier {
 public:
  explicit CyclicBarrier(size_t /*participants*/) {
    // Not implemented
  }

  void ArriveAndWait() {
    // Not implemented
  }

 private:
  // ???
};
