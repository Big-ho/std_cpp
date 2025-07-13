#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>
#include <iostream>
#include <string>
#include <utility>

namespace std_cpp::utils {

class Timer {
 public:
  Timer(std::string name = "")
      : name_(std::move(name)),
        start_time_(std::chrono::high_resolution_clock::now()) {}

  ~Timer() {
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(
                        end_time - start_time_)
                        .count();
    std::cout << "[TIMER] " << name_ << " 실행 시간: " << duration
              << " 마이크로초\n";
  }

  Timer(const Timer&) = delete;
  auto operator=(const Timer&) -> Timer& = delete;
  Timer(Timer&&) = delete;
  auto operator=(Timer&&) -> Timer& = delete;

  void reset() { start_time_ = std::chrono::high_resolution_clock::now(); }

 private:
  std::string name_;
  std::chrono::high_resolution_clock::time_point start_time_;
};

}  // namespace std_cpp::utils

#endif  // TIMER_HPP
