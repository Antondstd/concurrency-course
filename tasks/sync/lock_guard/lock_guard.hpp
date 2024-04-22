#pragma once

template <typename Mutex>
class LockGuard {
 public:
  explicit LockGuard(Mutex& /*mutex*/) {
    // Not implemented
  }

  // Non-copyable
  LockGuard(const LockGuard&) = delete;
  LockGuard& operator=(const LockGuard&) = delete;

  // Non-movable
  LockGuard(LockGuard&&) = delete;
  LockGuard& operator=(LockGuard&&) = delete;

 private:
  // ???
};
