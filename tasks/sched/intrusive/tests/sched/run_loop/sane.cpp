#include <exe/sched/run_loop.hpp>
#include <exe/sched/task/submit.hpp>

#include <twist/sim.hpp>

#include <wheels/test/framework.hpp>

#include <twist/test/assert.hpp>

static_assert(twist::build::IsolatedSim());

using namespace exe;  // NOLINT

TEST_SUITE(RunLoop) {
  SIMPLE_TEST(NoSynchronization) {
    twist::sim::sched::CoopScheduler scheduler;
    twist::sim::Simulator simulator{&scheduler};

    auto result = simulator.Run([] {
      sched::RunLoop loop;

      sched::task::Submit(loop, []{});
      TWIST_TEST_ASSERT(loop.Run() == 1, "Missing task");

      size_t atomic_count = twist::sim::stat::AtomicCount();
      TWIST_TEST_ASSERT(atomic_count == 0, "Unexpected synchronization");
    });

    ASSERT_TRUE_M(result.Ok(), result.std_err);
  }
}

RUN_ALL_TESTS()
