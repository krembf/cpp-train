#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// https://docs.microsoft.com/en-us/cpp/cpp/examples-of-lambda-expressions?view=vs-2019
namespace lambdatrain
{
void abssort(float *x, unsigned n) {
    std::sort(x, x + n, 
    [=] (float a, float b) {
        return (std::abs(a) < std::abs(b));
    }
    );
}

void Ex0_abssort_using_lambda()
{
    using namespace std;
    cout << "Executing " << __PRETTY_FUNCTION__ << endl;
    
    float f[] = {-1.5, 7.0, -1};
    abssort(f, 3);
}

void Ex1_using_various_capture_ways()
{
    using namespace std;
    cout << "Executing " << __PRETTY_FUNCTION__ << endl;

    int i = 3;
    int j = 5;

    // The following lambda expression captures i by value and
    // j by reference.
    auto f = [i, &j] { return i + j; };

    i = 22;
    j = 44;

    // Call f and print its result.
    cout << f() << endl;
}

void Ex2()
{
    using namespace std;
    cout << "Executing " << __PRETTY_FUNCTION__ << endl;
 
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
  	auto lam = [] (int x)  { std::cout << x << std::endl; };
    std::for_each(v.begin(), v.end(), lam); 
}

void Ex3_higher_order_lambda()
{
    using namespace std;
    cout << "Executing " << __PRETTY_FUNCTION__ << endl;

    // The following code declares a lambda expression that returns
    // another lambda expression that adds two numbers.
    // The returned lambda expression captures parameter x by value.
    auto addtwointegers = [](int x) -> function<int(int)> {
        return [=](int y) { return x + y; };
    };

    // The following code declares a lambda expression that takes another
    // lambda expression as its argument.
    // The lambda expression applies the argument z to the function f
    // and multiplies by 2.
    auto higherorder = [](const function<int(int)>& f, int z) {
        return f(z) * 2;
    };

    // Call the lambda expression that is bound to higherorder.
    auto answer = higherorder(addtwointegers(7), 8);

    // Print the result, which is (7+8)*2.
    cout << answer << endl;
}
} // namespace lambdatrain