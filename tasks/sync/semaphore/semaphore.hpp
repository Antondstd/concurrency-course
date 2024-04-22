#pragma once

#include <twist/ed/std/mutex.hpp>
#include <twist/ed/std/condition_variable.hpp>

#include <cstdlib>

class Semaphore {
 public:
  explicit Semaphore(size_t /*tokens*/) {
    // Not implemented
  }

  void Acquire() {
    // Not implemented
  }

  void Release() {
    // Not implemented
  }

 private:
  // Tokens
};
