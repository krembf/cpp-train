#include <iostream>
#include <tuple>
#include <numeric>

namespace tupletrain
{
template <typename T>
std::tuple<double, double, double> computeStats(const T &container)
{
    if (container.empty())
    {
        return std::make_tuple(0.0, 0.0, 0.0);
    }

    double minVal = *std::min_element(begin(container), end(container));
    double maxVal = *std::max_element(begin(container), end(container));
    double aveVal = std::accumulate(begin(container), end(container), 0.0) / container.size();

    return std::make_tuple(minVal, maxVal, aveVal);
}

void Ex0_TupleWithTemplate()
{
    using namespace std;
    cout << "Executing " << __PRETTY_FUNCTION__ << endl;
    
    std::vector<double> values = {3.4, 7.2, -9.8, 6.4};
    auto stats = computeStats(values);
    std::cout << "Min: " << std::get<0>(stats) << "\n"
              << "Max: " << std::get<1>(stats) << "\n"
              << "Ave: " << std::get<2>(stats) << std::endl;

    std::vector<int> values2 = {1, 5, 6, 4, 5, 5};
    double minVal;
    double maxVal;
    double aveVal;
    std::tie(minVal, maxVal, aveVal) = computeStats(values2);

    std::cout << "Min: " << minVal << "\n"
              << "Max: " << maxVal << "\n"
              << "Ave: " << aveVal << std::endl;
}
} // namespace tupletrain