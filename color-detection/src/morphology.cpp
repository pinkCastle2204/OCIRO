#include "../include/morphology.hpp"
#include <opencv2/opencv.hpp>

// 1. Implementation of kernel_sum (Helper for manual morphology)
int kernel_sum(cv::Mat image, int row, int col, int Kernel_size) {
    int sum = 0;
    int offset = Kernel_size / 2;
    for (int i = -offset; i <= offset; i++) {
        for (int j = -offset; j <= offset; j++) {
            sum += (int)image.at<uchar>(row + i, col + j);
        }
    }
    return sum;
}

// 2. Implementation of erosion
cv::Mat erosion(cv::Mat source_image, cv::Mat output_image, int Kernel_size) {
    cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, 
                      cv::Size(2 * Kernel_size + 1, 2 * Kernel_size + 1));
    cv::erode(source_image, output_image, element);
    return output_image;
}

// 3. Implementation of dilation
cv::Mat dilation(cv::Mat source_image, cv::Mat output_image, int kernel_size) {
    cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, 
                      cv::Size(2 * kernel_size + 1, 2 * kernel_size + 1));
    cv::dilate(source_image, output_image, element);
    return output_image;
}

// 4. Implementation of difference (Used for edge detection/gradients)
cv::Mat difference(cv::Mat img_1, cv::Mat img_2, cv::Mat output) {
    cv::absdiff(img_1, img_2, output);
    return output;
}