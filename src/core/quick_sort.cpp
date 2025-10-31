#include "core/quick_sort.hpp"

#include <cstddef>
#include <optional>

#include "core/draw.hpp"

namespace std_cpp {

template <typename T>
auto Partition(std::vector<T>& data, size_t begin_index, size_t end_index)
    -> std::optional<size_t> {
  const T kPivot = data[begin_index];
  size_t low = begin_index + 1;
  size_t high = end_index;

  while (true) {
    while (low <= end_index && data[low] < kPivot) {
      low++;
    }
    while (high >= begin_index + 1 && data[high] > kPivot) {
      high--;
    }
    if (low >= high) {
      break;
    }

    std::swap(data[low], data[high]);
    if (std_cpp::DrawBars(data)) {
      return std::nullopt;
    }
    low++;
    high--;
  }
  std::swap(data[begin_index], data[high]);
  if (std_cpp::DrawBars(data)) {
    return std::nullopt;
  }

  return high;
}

template <typename T>
void QuickSort(std::vector<T>& data, size_t begin_index, size_t end_index) {
  if (begin_index >= end_index) {
    return;
  }

  auto pivot_opt = Partition(data, begin_index, end_index);
  if (!pivot_opt.has_value()) {
    return;  // 사용자 종료 ('q)
  }

  size_t pivot = pivot_opt.value();

  if (pivot > begin_index) {
    QuickSort(data, begin_index, pivot - 1);
  }
  if (pivot < end_index) {
    QuickSort(data, pivot + 1, end_index);
  }
}

template void QuickSort<int>(std::vector<int>&, size_t, size_t);

}  // namespace std_cpp
