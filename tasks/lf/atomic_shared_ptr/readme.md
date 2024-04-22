# `AtomicSharedPtr`

## Пререквизиты

- [lf/stack](/tasks/lf/stack)

----

В задаче [lf/stack](/tasks/lf/stack) подсчет ссылок был встроен прямо в реализацию лок-фри стека.

В этой задаче мы разделим реализацию лок-фри стека / подсчет ссылок и получим универсальный механизм управления памятью, подходящий для произвольной лок-фри структуры данных.

## `AtomicSharedPtr`

[`AtomicSharedPtr<T>`](shared_ptr.hpp) держит сильную ссылку (`SharedPtr<T>`) на разделяемый объект и позволяет выполнять над ней стандартные атомарные операции: `Store`, `Load`, `CompareExchangeWeak` и т.д.

Можно представлять, что `AtomicSharedPtr<T>` – это `atomic<SharedPtr<T>>`.

Атомарность операций в `AtomicSharedPtr<T>` обеспечивается уже не на уровне процессора, а с помощью специального лок-фри алгоритма.

### References

- [`std::atomic_shared_ptr`](https://en.cppreference.com/w/cpp/experimental/atomic_shared_ptr)

#### Talks

- [Implementing a Lock-free `atomic_shared_ptr`](https://github.com/brycelelbach/cppnow_presentations_2016/blob/master/01_wednesday/implementing_a_lock_free_atomic_shared_ptr.pdf)
- [A Lock-Free Atomic Shared Pointer in Modern Cpp](https://www.youtube.com/watch?v=gTpubZ8N0no)
- [Lock-free Atomic Shared Pointers Without a Split Reference Count? It Can Be Done!](https://www.youtube.com/watch?v=lNPZV9Iqo3U)

#### Реализации

- [`folly::AtomicSharedPtr`](https://github.com/facebook/folly/blob/main/folly/concurrency/AtomicSharedPtr.h)
- [`atomic_shared_ptr`](https://github.com/anthonywilliams/atomic_shared_ptr) by Anthony Williams

## Задание

Вам дана [реализация лок-фри стека](lock_free_stack.hpp). Напишите для нее классы [`SharedPtr<T>` и `AtomicSharedPtr<T>`](shared_ptr.hpp).

Реализация `AtomicSharedPtr<T>` должна быть
- лок-фри (?)
- устойчивой к переполнению счетчика в указателях.

Сравните накладные расходы на управление памятью в реализации стека с помощью `AtomicSharedPtr` и в реализации из [lf/stack](/tasks/lf/stack).
