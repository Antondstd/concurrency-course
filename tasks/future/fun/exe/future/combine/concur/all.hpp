#pragma once

#include <exe/future/type/future.hpp>
#include <exe/future/type/result.hpp>

#include <exe/result/trait/is_result.hpp>
#include <exe/future/combine/seq/result/as.hpp>

#include <tuple>
#include <utility>  // std::move

namespace exe::future {

template <typename A, typename B>
TryFuture<std::tuple<A, B>> TryBoth(TryFuture<A>, TryFuture<B>) {
  std::abort();  // Not implemented
}

template <typename A, typename B>
Future<std::tuple<A, B>> PlainBoth(Future<A>, Future<B>) {
  static_assert(!result::trait::IsResult<A>);
  static_assert(!result::trait::IsResult<B>);

  std::abort();  // Not implemented
}

template <typename A, typename B>
auto Both(Future<A> f, Future<B> g) {
  if constexpr (result::trait::IsResult<A> || result::trait::IsResult<B>) {
    return TryBoth(AsTryFuture(std::move(f)), AsTryFuture(std::move(g)));
  } else {
    return PlainBoth(std::move(f), std::move(g));
  }
}

}  // namespace exe::future
