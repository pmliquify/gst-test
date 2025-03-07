#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
        std::string pipeline = "nvarguscamerasrc ! nvvidconv ! appsink";

        // Open the video source using the GStreamer pipeline
        cv::VideoCapture cap(pipeline, cv::CAP_GSTREAMER);
        if (!cap.isOpened()) {
                std::cerr << "Error: Could not open the video source." << std::endl;
                return -1;
        }

        int frameCounter = 0;
        std::cout << "Starting frame capture. Press 'ESC' to exit." << std::endl;

        // Continuous loop for capturing frames
        while (true) {
                cv::Mat frame;
                if (!cap.read(frame)) {
                std::cerr << "Error: Could not read a frame." << std::endl;
                break;
                }

                frameCounter++;
                // Console output: frame number and image dimensions
                std::cout << "Frame " << frameCounter 
                        << " captured (Size: " << frame.cols << " x " << frame.rows << ")" 
                        << std::endl;

                // Check for 'ESC' key press (only works if a window is active)
                if (cv::waitKey(1) == 27) {  // 27 corresponds to the ESC key
                break;
                }
        }

        cap.release();
        return 0;
}
