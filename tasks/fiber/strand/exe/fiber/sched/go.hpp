#pragma once

#include <exe/fiber/core/body.hpp>
#include <exe/fiber/core/scheduler.hpp>

namespace exe::fiber {

// Considered harmful

void Go(IScheduler&, Body);

void Go(Body);

}  // namespace exe::fiber
