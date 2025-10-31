#ifndef RNG_HPP
#define RNG_HPP

#include <cstddef>
#include <numeric>
#include <random>
#include <vector>

namespace std_cpp::utils {

class RNG {
 public:
  RNG() : rng_(static_cast<int>(rd_())) {}

  template <typename T>
  auto GetShuffledSequence(T count) -> std::vector<T> {
    std::vector<T> result(static_cast<size_t>(count));
    std::iota(result.begin(), result.end(), static_cast<T>(0));
    std::shuffle(result.begin(), result.end(), rng_);

    return result;
  }

 private:
  std::random_device rd_;
  std::mt19937 rng_;
};

}  // namespace std_cpp::utils

#endif  // RNG_HPP
