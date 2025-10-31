#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

#include "core/bubble_sort.hpp"
#include "core/draw.hpp"
#include "core/quick_sort.hpp"
#include "utils/rng.hpp"
#include "utils/timer.hpp"

auto main() -> int {
  try {
    const int kLong = 500;
    const int kShot = 50;

    std_cpp::utils::RNG rng;

    auto long_list = rng.GetShuffledSequence<int>(kLong);
    auto shot_list = rng.GetShuffledSequence<int>(kShot);

    {
      cv::namedWindow("Sort Visualizer", cv::WINDOW_AUTOSIZE);
      std_cpp::DrawBars(shot_list);
      std_cpp::utils::Timer timer("BubbleSort");
      std_cpp::BubbleSort(shot_list);
      cv::destroyWindow("Sort Visualizer");
    }
    {
      cv::namedWindow("Sort Visualizer", cv::WINDOW_AUTOSIZE);
      std_cpp::DrawBars(long_list);
      std_cpp::utils::Timer timer("QuickSort");
      std_cpp::QuickSort(long_list, 0, kLong - 1);
      cv::destroyWindow("Sort Visualizer");
    }

    cv::destroyAllWindows();
  } catch (const std::exception& e) {
    std::cerr << "예외 발생: " << e.what() << "\n";
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;

  return 0;
}
