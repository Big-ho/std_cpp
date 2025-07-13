#ifndef RNG_HPP
#define RNG_HPP

#include <chrono>
#include <random>
#include <vector>

namespace std_cpp::utils {

class RNG {
 public:
  RNG() : rng(std::chrono::steady_clock::now().time_since_epoch().count()) {}

  // 정수형 랜덤 벡터
  template <typename T>
  auto get_int_list(int count) -> std::vector<T> {
    std::vector<T> result;
    result.reserve(count);
    for (int i = 0; i < count; ++i) {
      result.push_back(i);
    }
    std::shuffle(result.begin(), result.end(), rng);

    return result;
  }

 private:
  std::mt19937 rng;
};

}  // namespace std_cpp::utils

#endif  // RNG_HPP
