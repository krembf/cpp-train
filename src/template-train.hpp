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

    a.y = 8;

    // Type of A::x is f
    cout << "Type of A::x is " << typeid(a.x).name() << endl;

    // Type of A::x is i
    cout << "Type of A::y is " << typeid(a.y).name() << endl;

    cout << "Value of x is " << a.x << endl;
    cout << "Value of y is " << a.y << endl;

    A<string, string> b;
    b.x = "Hello Dolly";
    cout << "Type of b.y is " << typeid(b.y).name() << endl;
    cout << "Value of b.x is " << b.x << endl;
}

template <bool a, int s>
class B
{
    public:
    bool available = a;
    int size = s;
};

void Ex1_TemplateWithNonTypeArguments()
{
    using namespace std;
    cout << "Executing " << __PRETTY_FUNCTION__ << endl;
    
    B<false, 42> a;

    // cout << "Type of B::available is " << typeid(a.available).name() << endl;
    cout << "Value of a.available is " << a.available << endl;    

    // cout << "Type of a.size is " << typeid(a.size).name() << endl;
    cout << "Value of a.size is " << a.size << endl;        
}
} // namespace templatetrain