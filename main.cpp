#include <vector>
#include <functional>
#include <iostream>

//#include "tests.h"
#include "candle.h"

//массив всех тестов, который мы заполняем в функции initTests
static std::vector<std::function<bool()>> tests;

// 2.1. Тесты для body_contains
bool test_body_contains_inside()
{
    Candle candle(10.0, 20.0, 5.0, 15.0);
    return candle.body_contains(12.0); // Должно быть внутри тела
}

bool test_body_contains_exact_open()
{
    Candle candle(10.0, 20.0, 5.0, 15.0);
    return candle.body_contains(10.0); // Равно open
}

bool test_body_contains_outside()
{
    Candle candle(10.0, 20.0, 5.0, 15.0);
    return !candle.body_contains(5.0); // Вне тела
}

// 2.2. Тесты для contains
bool test_contains_inside()
{
    Candle candle(10.0, 20.0, 5.0, 15.0);
    return candle.contains(7.0); // Внутри диапазона
}

bool test_contains_exact_low()
{
    Candle candle(10.0, 20.0, 5.0, 15.0);
    return candle.contains(5.0); // Равно low
}

bool test_contains_outside()
{
    Candle candle(10.0, 20.0, 5.0, 15.0);
    return !candle.contains(25.0); // Вне диапазона
}

// 2.3. Тесты для full_size
bool test_full_size_standard()
{
    Candle candle(10.0, 20.0, 5.0, 15.0);
    return candle.full_size() == 15.0; // 20 - 5 = 15
}

bool test_full_size_equal_high_low()
{
    Candle candle(10.0, 10.0, 10.0, 10.0);
    return candle.full_size() == 0.0; // Высота 0
}

bool test_full_size_negative()
{
    Candle candle(5.0, 12.0, -3.0, 10.0);
    return candle.full_size() == 15.0; // 12 - (-3) = 15
}

void initTests()
{
  tests.push_back(test_body_contains_inside);
  tests.push_back(test_body_contains_exact_open);
  tests.push_back(test_body_contains_outside);

  tests.push_back(test_contains_inside);
  tests.push_back(test_contains_exact_low);
  tests.push_back(test_contains_outside);

  tests.push_back(test_full_size_standard);
  tests.push_back(test_full_size_equal_high_low);
  tests.push_back(test_full_size_negative);
}

int launchTests()
{
  int total = 0;
  int passed = 0;

  for (const auto& test : tests)
  {
    std::cout << "test #" << (total + 1);
    if (test())
    {
      passed += 1;
      std::cout << " passed\n";
    }
    else
    {
      std::cout << " failed\n";
    }
    total += 1;
  }

  std::cout << "\ntests " << passed << "/" << total << " passed!" << std::endl;

  //0 = success
  return total - passed;
}

int main()
{
  initTests();
  return launchTests();
}
