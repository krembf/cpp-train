#include <iostream>
#include <vector>
#include <typeinfo>
// #include <cassert>

// Originally from here: https://crascit.com/2015/03/21/practical-uses-for-variadic-templates/

namespace variadictemplatetrain
{
template <class... A>
void func(A... args)
{
    using namespace std;

    cout << "Sizeof args is " << sizeof...(args) << endl;
}

void Ex0_FuncWithVariousArgs()
{
    using namespace std;
    cout << "Executing " << __PRETTY_FUNCTION__ << endl;
    func();
    func(0.5);
    func(1, 2, 3, 4);
}

template <typename T, typename... TArgs>
T *create(TArgs... args)
{
    using namespace std;

    cout << "Creating " << typeid(T).name() << endl;
    T *obj = new T(args...);
    return obj;
}

class A
{
private:
    /* data */
public:
    A(int x, double y = 42.0) {};
    A() {};
    ~A();
};

class B
{
private:
    /* data */
public:
    B(const std::string &str){};
    ~B();
};

void Ex1_CreateClassesViaFactory()
{
    using namespace std;
    cout << "Executing " << __PRETTY_FUNCTION__ << endl;
        
    A *a1 = create<A>();
    A *a2 = create<A>(16, 9.4);
    B *b1 = create<B>("Hello Dolly");
}
} // namespace variadictemplatetrain