#pragma once

#include <exe/future/type/future.hpp>
#include <exe/future/type/result.hpp>

#include <exe/result/trait/is_result.hpp>
#include <exe/future/combine/seq/result/as.hpp>

#include <utility>  // std::move

namespace exe::future {

template <typename T>
TryFuture<T> TryFirst(TryFuture<T>, TryFuture<T>) {
  std::abort();  // Not implemented
}

template <typename T>
Future<T> PlainFirst(Future<T>, Future<T>) {
  static_assert(!result::trait::IsResult<T>);

  std::abort();  // Not implemented
}

template <typename A, typename B>
auto First(Future<A> f, Future<B> g) {
  if constexpr (result::trait::IsResult<A> || result::trait::IsResult<B>) {
    return TryFirst(AsTryFuture(std::move(f)), AsTryFuture(std::move(g)));
  } else {
    return PlainFirst(std::move(f), std::move(g));
  }
}

}  // namespace exe::future
