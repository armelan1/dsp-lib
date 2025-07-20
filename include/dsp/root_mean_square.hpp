#pragma once

#include <cstddef>
#include <vector>

namespace dsp {
    class RootMeanSquare
    {
    public:
        explicit RootMeanSquare(std::size_t window);
        void reset();
        void push(float sample);
        bool ready() const;
        float value() const;

    private:
        std::size_t window_size_;
        std::vector<float> buffer_;
        std::size_t index_;
        std::size_t count_;
        float sum_of_squares_;
    };

} // namespace dsp