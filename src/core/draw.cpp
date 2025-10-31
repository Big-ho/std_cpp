#include "core/draw.hpp"

#include <chrono>
#include <opencv2/core/types.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/photo.hpp>
#include <thread>

const int kWidth = 2000;
const int kHeight = 1000;
const cv::Scalar kBackground = cv::Scalar(255, 255, 255);
const cv::Scalar kBarColor = cv::Scalar(0, 0, 0);
const int kBarThickness = 1;
const int kDelayMS = 1;
const int kAnimeSpeedMs = 1;

namespace std_cpp {

auto DrawBars(const std::vector<int>& data) -> bool {
  cv::Mat img(kWidth, kHeight, CV_8UC3, kBackground);

  int bar_width = kWidth / static_cast<int>(data.size());

  for (int i = 0; i < data.size(); i++) {
    int pos_x = i * bar_width;
    int pos_y = kHeight - data[i];

    cv::Point top_left(pos_x, pos_y);
    cv::Point bottom_right(pos_x + bar_width, kHeight);

    cv::rectangle(img, top_left, bottom_right, kBarColor, kBarThickness);
  }

  cv::imshow("Sort Visualizer", img);
  int key = cv::waitKey(kDelayMS);
  if (key == 'q' || key == 'Q') {
    cv::destroyAllWindows();
    return true;
  }
  std::this_thread::sleep_for(std::chrono::milliseconds(kAnimeSpeedMs));

  return false;
}

}  // namespace std_cpp
