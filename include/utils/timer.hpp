#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>
#include <ctime>
#include <iostream>
#include <ostream>
#include <string>
#include <utility>

namespace std_cpp::utils {

class Timer {
 public:
  explicit Timer(std::string name = "", std::ostream& ost = std::cout)
      : name_(std::move(name)),
        output_stream_(ost),
        start_time_(std::chrono::high_resolution_clock::now()) {}

  ~Timer() {
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time_).count();

    output_stream_ << "[TIMER] " << name_ << " 실행 시간: " << duration << " 마이크로초\n";
  }

  Timer(const Timer&) = delete;
  auto operator=(const Timer&) -> Timer& = delete;
  Timer(Timer&&) = delete;
  auto operator=(Timer&&) -> Timer& = delete;

  void Reset() { start_time_ = std::chrono::high_resolution_clock::now(); }

 private:
  std::string name_;
  std::ostream& output_stream_;
  std::chrono::high_resolution_clock::time_point start_time_;
};

}  // namespace std_cpp::utils

#endif  // TIMER_HPP
