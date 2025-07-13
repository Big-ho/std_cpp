#include "core/quick_sort.hpp"

#include <vector>

namespace std_cpp {

template <typename T>
auto partition(std::vector<T>& data, size_t begin_index, size_t end_index)
    -> size_t {
  T pivot = data[begin_index];
  size_t low = begin_index + 1;
  size_t high = end_index;

  while (true) {
    while (low <= end_index && data[low] < pivot) {
      low++;
    }
    while (high >= begin_index + 1 && data[high] > pivot) {
      high--;
    }

    if (low >= high) {
      break;
    }
    std::swap(data[low], data[high]);
    low++;
    high--;
  }

  std::swap(data[begin_index], data[high]);
  return high;
}

template <typename T>
void quick_sort(std::vector<T>& data, size_t begin_index, size_t end_index) {
  if (begin_index < end_index) {
    size_t pivot = partition(data, begin_index, end_index);

    if (pivot > 0) {
      quick_sort(data, begin_index, pivot - 1);
    }
    quick_sort(data, pivot + 1, end_index);
  }
}

template void quick_sort<int>(std::vector<int>&, size_t, size_t);
template void quick_sort<double>(std::vector<double>&, size_t, size_t);

}  // namespace std_cpp