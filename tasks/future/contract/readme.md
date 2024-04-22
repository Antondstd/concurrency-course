# `Contract`

Напишите wait-free реализацию асинхронного one-shot контракта.

## API

```cpp
void ContractExample() {
  // Вызов Contract<T>() создает пару (Future<T>, Promise<T>)
  auto [f, p] = future::Contract<int>();

  std::thread producer([p = std::move(p)] mutable {
    // Поток-producer _обязан_ выполнить Promise (ровно один раз)
    // Метод `Set` "потребляет" Promise, он определен для rvalue reference
    std::move(p).Set(7);
  });

  // Поток-consumer _обязан_ потребить фьючу (ровно один раз)
  // Синхронно дожидаемся значения с помощью свободной функции future::Get
  int v = future::Get(std::move(f));
  
  fmt::println("v -> {}", v);
}
```

## `Consume`

`Future` предоставляет единственный способ потребить будущее значение – подписаться
на него с помощью метода `Consume`:

```cpp
auto [f, p] = future::Contract<int>();

// "Подписываемся" на f = потребляем Future
std::move(f).Consume([](int /*ignore*/) {
  fmt::println("Done");
});

// Выполняем контракт и исполняем коллбэк
std::move(p).Set(4);
``` 

Синхронное ожидание `Future` заключено в свободной функции `future::Get`:

```cpp
// T Get(Future<T>)

// Подписываемся на f и паркуем поток на futex-e до тех пор, пока 
// producer не выполнит контракт
auto v = future::Get(std::move(f));
```
