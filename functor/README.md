## Functor in C++

### What is functor

    A functor or function object is a C++ class that acts like a function.

    Functors can be called using the function call syntax, and can yield values and accept parameters like regular functions.

### Examples

```
//_ ex1
//_ This is the test functor

class MyFunctor {
public:
void operator() (const string& str) const;
};

void MyFunctor::operator()(const string& str) const
{
cout << str << endl;
}

MyFunctor funct;
funct("This is test");
```
