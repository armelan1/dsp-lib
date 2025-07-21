#include "dsp/average.hpp"

namespace dsp {
    float Average::mean(const std::vector<float>& values)
    {
        if (values.empty()) return 0.0f;

        float sum = 0.0f;
        for (float v : values) sum += v;
        return sum / values.size();
    }
} // namespace dsp
