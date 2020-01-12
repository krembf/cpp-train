#include <iostream>
using namespace std;

namespace inheritancetrain
{
struct A
{
    virtual void f() { cout << "Class A" << endl; }
};

struct B : A
{
    virtual void f(int) { cout << "Class B" << endl; }
};

struct C : B
{
    void f() { cout << "Class C" << endl; }
};

///
// Expected output:
// Class A
// Class C
///
void Ex0_VirtualFunctions()
{
    cout << "Executing " << __PRETTY_FUNCTION__ << endl;
    
    B b;
    C c;
    A *pa1 = &b;
    A *pa2 = &c;
    //   b.f();
    pa1->f();
    pa2->f();
}
} // namespace inheritancetrain