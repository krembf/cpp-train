#include <iostream>
#include <typeinfo>

namespace templatetrain
{
template <class T, class U = int>
class A;

template <class T = float, class U>
class A;

template <class T, class U>
class A
{
public:
    T x;
    U y;
};

void Ex0_TemplateWithDefaultArguments()
{
    using namespace std;

    cout << "Executing " << __PRETTY_FUNCTION__ << endl;

    A<> a;

    // Type of A::x is f
    cout << "Type of A::x is " << typeid(a.x).name() << endl;

    // Type of A::x is i
    cout << "Type of A::y is " << typeid(a.y).name() << endl;

}
} // namespace templatetrain