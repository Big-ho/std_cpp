#include <chrono>
#include <opencv2/core/types.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/photo.hpp>
#include <thread>

const int WIDTH = 2000;
const int HEIGHT = 1000;
const cv::Scalar BACKGROUND = cv::Scalar(255, 255, 255);
const cv::Scalar BAR_COLOR = cv::Scalar(0, 0, 0);
const int BAR_THICKNESS = 1;
const int DELAY_MS = 1;
const int ANIME_SPEED_MS = 1;

namespace std_cpp {

auto draw_bars(const std::vector<int>& data) {
  cv::Mat img(HEIGHT, WIDTH, CV_8UC3, BACKGROUND);

  int bar_width = WIDTH / (int)data.size();

  for (int i = 0; i < data.size(); i++) {
    int pos_x = i * bar_width;
    int pos_y = HEIGHT - data[i];

    cv::Point top_left(pos_x, pos_y);
    cv::Point bottom_right(pos_x + bar_width, HEIGHT);

    cv::rectangle(img, top_left, bottom_right, BAR_COLOR, BAR_THICKNESS);
  }

  cv::imshow("Sort Visualizer", img);
  int key = cv::waitKey(DELAY_MS);
  if (key == 'q' || key == 'Q') {
    cv::destroyAllWindows();
    return true;
  }
  std::this_thread::sleep_for(std::chrono::milliseconds(ANIME_SPEED_MS));

  return false;
}

}  // namespace std_cpp
