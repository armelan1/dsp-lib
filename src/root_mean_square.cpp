#include "dsp/root_mean_square.hpp"
#include <algorithm>
#include <cmath>

namespace dsp {

RootMeanSquare::RootMeanSquare(std::size_t window)
    : window_size_(window),
      buffer_(window, 0.0f),
      index_(0),
      count_(0),
      sum_of_squares_(0.0f)
{
}

void RootMeanSquare::reset()
{
    std::fill(buffer_.begin(), buffer_.end(), 0.0f);
    index_ = 0;
    count_ = 0;
    sum_of_squares_ = 0.0f;
}

void RootMeanSquare::push(float sample)
{
    if (window_size_ == 0)
        return;

    // Subtract old squared value if buffer is full
    if (count_ == window_size_) {
        float old = buffer_[index_];
        sum_of_squares_ -= old * old;
    } else {
        ++count_;
    }

    buffer_[index_] = sample;
    sum_of_squares_ += sample * sample;
    index_ = (index_ + 1) % window_size_;
}

bool RootMeanSquare::ready() const
{
    return count_ == window_size_;
}

float RootMeanSquare::value() const
{
    if (count_ == 0)
        return 0.0f;

    float mean_square = sum_of_squares_ / static_cast<float>(count_);
    return std::sqrt(mean_square);
}

} // namespace dsp
