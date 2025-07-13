#ifndef RNG_HPP
#define RNG_HPP

#include <chrono>
#include <random>
#include <vector>

namespace std_cpp::utils {

class RNG {
 public:
  RNG() : rng_(std::chrono::steady_clock::now().time_since_epoch().count()) {}

  // 정수형 랜덤 벡터
  template <typename T>
  auto getIntList(T min, T max, size_t count) -> std::vector<T> {
    std::vector<T> result;
    result.reserve(count);
    std::uniform_int_distribution<T> dist(min, max);
    for (size_t i = 0; i < count; ++i) {
      result.push_back(dist(rng_));
    }
    return result;
  }

  // 실수형 랜덤 벡터
  template <typename T>
  auto getRealList(T min, T max, size_t count) -> std::vector<T> {
    std::vector<T> result;
    result.reserve(count);
    std::uniform_real_distribution<T> dist(min, max);
    for (size_t i = 0; i < count; ++i) {
      result.push_back(dist(rng_));
    }
    return result;
  }

 private:
  std::mt19937 rng_;
};

}  // namespace std_cpp::utils

#endif  // RNG_HPP
