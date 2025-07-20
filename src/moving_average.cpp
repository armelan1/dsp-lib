#include "dsp/moving_average.hpp"

namespace dsp {

MovingAverage::MovingAverage(std::size_t window)
    : window_size_(window),
      buffer_(window, 0.0f),
      index_(0),
      count_(0),
      sum_(0.0f)
{
}

void MovingAverage::reset()
{
    std::fill(buffer_.begin(), buffer_.end(), 0.0f);
    index_ = 0;
    count_ = 0;
    sum_ = 0.0f;
}

void MovingAverage::push(float sample)
{
    if (window_size_ == 0) {
        return;
    }

    if (count_ == window_size_) {
        sum_ -= buffer_[index_];
    } else {
        ++count_;
    }

    buffer_[index_] = sample;
    sum_ += sample;
    index_ = (index_ + 1) % window_size_;
}

bool MovingAverage::ready() const
{
    return count_ == window_size_;
}

float MovingAverage::value() const
{
    if (count_ == 0) {
        return 0.0f;
    }
    return sum_ / static_cast<float>(count_);
}

} // namespace dsp
