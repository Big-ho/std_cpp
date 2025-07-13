#include "core/bubble_sort.hpp"

#include <vector>

namespace std_cpp {

template <typename T>
void bubble_sort(std::vector<T>& data) {
  size_t list_size = data.size();
  if (list_size < 2) {
    return;
  };

  bool swapped = true;
  while (swapped) {
    swapped = false;
    for (size_t i = 0; i + 1 < list_size; i++) {
      if (data[i + 1] < data[i]) {
        std::swap(data[i], data[i + 1]);
        swapped = true;
      }
    }
    list_size--;
  }
}

template void bubble_sort<int>(std::vector<int>&);
template void bubble_sort<double>(std::vector<double>&);

}  // namespace std_cpp