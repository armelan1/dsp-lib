#ifndef DSP_MOVING_AVERAGE_HPP
#define DSP_MOVING_AVERAGE_HPP

#include <cstddef>
#include <vector>

namespace dsp {

class MovingAverage
{
public:
    explicit MovingAverage(std::size_t window);
    void reset();
    void push(float sample);
    bool ready() const;
    float value() const;

    std::size_t window_size() const { return window_size_; }

private:
    std::size_t window_size_;
    std::vector<float> buffer_;
    std::size_t index_;
    std::size_t count_;
    float sum_;
};

} // namespace dsp

#endif
