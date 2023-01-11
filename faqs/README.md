## C++ Interview Questions

## Static

### Static Data Members

#### What is static data members

Static class members are data and functions that are associated with the class itself, rather than with the objects of the class.

In the following example, data member x is associated with the class rather than with the object of the class, and only one copy of the static data memeber has been created rather than how many number of objects created for the class.

```
class StaticMembers{
    private:
        static int X;
    public:
        StaticMembers(){
            cout<<"ctor"<<endl;
        }

        static int getStaticMember(){
            return X;
        }
};

int StaticMembers::X = 125;
```

Use static to count the total number of objects created

```
class Car{
    private:
    static int totalCarsProduced;
    string carName, color, modelName;

    public:
    Car():carName("Maruti"),color("White"),modelName("800"){
        totalCarsProduced++;
    };

    Car(string name,string color,string model):carName(name),color(color),modelName(model){
        totalCarsProduced++;
    };

    void Print(){
        cout<<"Car Name:"<<carName<<" Color:"<<color<<" Model:"<<modelName<<endl;
    };

    static int getTotalCars(){
        return totalCarsProduced;
    };

};

int Car::totalCarsProduced=0;

main:
Car c1;
Car c2("Tata","Black","Indica");
Car c3("Hundai","Red","i10");

output:
Car Name:Hundai Color:Red Model:i10
Total Cars:3
```

#### How many copies of statuc data member are shared between the objects of that class?

There is only one copy of statuc data member shared by the objects of that class.

#### How to define the static data member?

syntax of static data member

data-type class-name::static variable name

for example,

```
class StaticMembers{
    private:
        static int X;
};

int StaticMembers::X = 125;
```

#### Why we need static data members

Static data member are need to

1. share the same data among the all objects of class
2. to count how many number of objects created for that class

### Static Data Member Function

#### What is static data member functions

A static data memeber functions are those functions which are assocoated with the class itself, rather than with the objects of the class.

Sometimes static data member functions called services of the class.

#### Why we need static member functions?

There are many situations where we do not need to create object of the class rather only use the functionality of the class, at that time static member functions.

For example, converting data from int to string or string to int, this do not need to create object

```
MyClass.toInt("11.00");
MyClass.toString(11);
```

#### How to declare and use the static function

Syntax:

declare:
static return-type function-name(parameters);

define:
return-type function-name(parameters) {};

use:
class-name::function-name(arg);

```
class StaticClass{
    public:
     static int getCount();

}

int StaticClass::getCount()
{
    return 100;
}

StaticClass::getCount();
```

#### Can we use this pointer in static member function? Why?

NO, because static member function are executed by the class rather than by the objects.

#### Can static member functions are virtual functions? Why?

No, static member functions cannot be virtual because static member functions are bound at compile time, where as virtual functions are bound at runtime polymorphism.

#### Can static member functions access the ordinary data members? Why?

No, a static member functions cannot access the ordinary data members because the address of the current object quietly passed in when any member function is called, but static member function has no this pointer.

## const

Before const first we need to understand how pointers declaration read in C++

Pointers declaration should be read from right to left.

for example,

```
int * can be read as a pointer to int
const int * is a pointer to a int that cannot be changed via that pointer
int* const is a constant pointer to a int.
```

## inline functions

inline functions are functions whose code get inserted at the point where function called. The inline function substitute the code where the function called.

### Why we need inline function

For normal function, when the function call, the arguments are push and pop which create overhead for the small functions. With the inline function, the whole code replaced at the point where the function called. With this speed up the process.

### Syntax of inline function

inline return-type function-name(parameters);

for example,

```
inline int MyFun(int);
```

### Does inline functions are virtual functions? Why?

No, inline functions cannot be virtual function because inline functions are bound at compile time while virtual functions are bound at runtime.

### Which functions are treated as inline function?

Compiler-generated default constructor, copy constructor, destructors, and assignment operator are treated as inline.

## Function Overloading

### What is function overloading

Function overloading means defining multiple functions with the same name but differ in number, type and order of the arguments. It is a compile time polymorphism.

C++ allows to specify more than one definition for a function name or an operator in the same scope.

```
#include <iostream>
#include <string>

using namespace std;

class MyClass {
public:
    int add(int, int);
    float add(float, float);
    string add(string, string);
};

int MyClass::add(int n1, int n2)
{
    return (n1 + n2);
}

float MyClass::add(float n1, float n2)
{
    return (n1 + n2);
}

string MyClass::add(string str1, string str2)
{
    return (str1 + " " + str2);
}

int main()
{
    MyClass c1;

    cout << c1.add(10, 10)<<endl;
    cout << c1.add(20.25f, 30.54f)<<endl;
    cout << c1.add("Smitesh", "Ivy");
}

```
