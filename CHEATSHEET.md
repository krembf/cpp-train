## Difference between **gcc** and **g++**
> GCC stands for GNU Compiler Collection 
```
gcc: GNU C Compiler.
g++: GNU C++ Compiler.
For C, use gcc, for C++ use g++.

The main differences:

gcc will compile: .c/.cpp files as C and C++ respectively.
g++ will compile: .c/.cpp files but they will all be treated as C++ files.
Also if you use g++ to link the object files it automatically links in the std C++ libraries (gcc does not do this).
gcc compiling C files has less predefined macros.
gcc compiling .cpp and g++ compiling *.c/.cpp files has a few extra macros.
```
## **explicit** keyword
> Answer from (https://stackoverflow.com/questions/121162/what-does-the-explicit-keyword-mean)

```
Suppose, you have a class String:
```
```c++
class String {
public:
    String(int n); // allocate n bytes to the String object
    String(const char *p); // initializes object with char *p
};
```
```
Now, if you try:
```
```c++
String mystring = 'x';
```
```
The character 'x' will be implicitly converted to int and then the String(int) constructor will be called. But, this is not what the user might have intended. So, to prevent such conditions, we shall define the constructor as explicit:
```
```c++
class String {
public:
    explicit String (int n); //allocate n bytes
    String(const char *p); // initialize sobject with string p
};
```

## Abstract Class 
> Answer from (https://www.ibm.com/support/knowledgecenter/SSLTBW_2.3.0/com.ibm.zos.v2r3.cbclx01/cplr142.htm)

>An abstract class is a class that is designed to be specifically used as a base class. An abstract class contains at least one pure virtual function. You declare a pure virtual function by using a pure specifier (= 0) in the declaration of a virtual member function in the class declaration.
```
The following is an example of an abstract class:
```
```c++
class AB {
public:
  virtual void f() = 0;
};
```
```
Virtual member functions are inherited. A class derived from an abstract base class will also be abstract unless you override each pure virtual function in the derived class.
```
```
For example
```
```c++
class AB {
public:
  virtual void f() = 0;
};

class D2 : public AB {
  void g();
};

int main() {
  D2 d;
}
```
```
The compiler will not allow the declaration of object d because D2 is an abstract class; it inherited the pure virtual function f()from AB. The compiler will allow the declaration of object d if you define function D2::f(), as this overrides the inherited pure virtual function AB::f(). Function AB::f() needs to be overridden if you want to avoid the abstraction of D2.

Note that you can derive an abstract class from a nonabstract class, and you can override a non-pure virtual function with a pure virtual function.
```