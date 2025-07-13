#include "core/bubble_sort.hpp"

#include "core/draw.hpp"

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
        if (std_cpp::draw_bars(data)) {
          return;  // 사용자 종료 ('q')
        };
        swapped = true;
      }
    }
    list_size--;
  }
}

template void bubble_sort<int>(std::vector<int>&);

}  // namespace std_cpp