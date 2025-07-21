#pragma once

#include <cstddef>
#include <vector>

namespace dsp {
    class Average
    {
    public:
        static float mean(const std::vector<float>& values);
    };
} // namespace dsp