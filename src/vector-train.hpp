#include <iostream>
#include <vector>

namespace vectortrain
{
void Ex0_VectorInitialization()
{
    std::vector<int> vec = {1, 2, 3, 4, 5};

    for (auto elem : vec)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}
} // namespace vectortrain