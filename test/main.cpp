#include "core/bubble_sort.hpp"
#include "core/quick_sort.hpp"
#include "utils/rng.hpp"
#include "utils/timer.hpp"

auto main() -> int {
  try {
    const int COUNT = 10000;

    std_cpp::utils::RNG rng;

    auto rand_list = rng.get_int_list<int>(COUNT);

    {
      std_cpp::utils::Timer timer("BubbleSort");
      std_cpp::bubble_sort(rand_list);
    }
    {
      std_cpp::utils::Timer timer("QuickSort");
      std_cpp::quick_sort(rand_list, 0, COUNT - 1);
    }

  } catch (const std::exception& e) {
    std::cerr << "예외 발생: " << e.what() << "\n";
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;

  return 0;
}