#include "../include/approximator.hpp"

using namespace sctoolbox;

double Approximator::approximate() const
{
    const double step = (b - a) / (double)n; // Divide interval in sub-intervals
    double result = 0.0;
    for (unsigned int i = 0; i < n; ++i)
    {
        result += approximate_step(a + i * step, a + (i + 1) * step); // Evaluate integral for each sub-interval
    }
    return result;
}