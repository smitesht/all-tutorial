## Lambda function in C++

### What is Lambda function

Lambda functions or expressions are inline anonymous functions or closures, which can be used as function objects or passed as arguments to other functions.
Generally, lambda functions are short snippets of the code that are not to be reused and therefore do not require a name.

### [ CaptureClosuers ] ( parameters ) -> return-type { body }

- #### Capture Closures: This specifies what external variables or objects the lambda expression can access.
  It can be empty, or it can contain one of the following.
   - ##### []: empty capture list - The lambda doesn't capture any external variables.
   - ##### [var]: Captures a specific variable by value.
   - ##### [&var]: Captures a specific variable by reference
   - ##### [=]: Capture ALL external variables by values.
   - ##### [&]: Capture ALL external variables by reference.

- #### Parameter list: Defines the input parameters of the lambda function.
- #### Return Type: return of the lambda body
- #### body: body or logic of the lambda function
 

### Examples

```
auto add = [](int num1, int num2) -> int {
  return (num1 + num2);
};

cout << add(1, 2)<< endl;
```

#### Ex

```
auto la = [] { return "Hello I'm Lambda function"; };
std::cout << la()<<endl;
```

#### Ex

```
// Ex

vector<int> v = { 2,3,4,6,8,10,32,56,43,76,56,85,43 };
    for_each(v.begin(), v.end(), [](auto x) {
        if ((x % 2) == 0) {
            cout << x << " is even" << endl;
            }
        else
        {
            cout << x << " is odd" << endl;
        }
        });

```

#### Ex Lambda using Capture Clouser

```
int x = 10;

auto increment = [&x](){
     x++;
    };

increment();
cout << x << endl; // display 11
```

#### Ex Lambda using Capture Clouser to access all the outside elements

```
int num1 = 5, num2 = 6;

auto multiply = [=]() -> int {
    return num1 * num2;
    };

cout << multiply();  // 30
```

#### Ex

```
// Ex Find String shorter than the number

const char* greetings{ "Hello from colusres" };
const auto greet = [greetings] {std::cout << greetings << endl; };
greet();
```

#### Ex

```
//Ex
auto one = []() -> const char* {return "This is one lambda"; };
auto two = []() -> auto { return "This is two lambda"; };

std::cout<<one()<<endl;
std::cout<<two()<<endl;

```

#### Ex

```
// Ex 
vector<string> vstr = { "Smitesh","Ramesh","Ila","Anupam","AmitKumar","SahrukhKan" };

int len = 6;
auto ret = count_if(vstr.begin(), vstr.end(), [len](string str) {
    return (str.length() < 10);
    });

std::cout << ret << endl;

```

### constexpr Lambdas

### What is constexpr

The constexpr specifier promises the variable or a function can be evaluated during compile time.
The compiler emits an error if the expression cannot be evaluated during compile time.

```
int main()
{
   constexpr int n = 123; //OK, 123 is a compile-time constant
   // expression
   constexpr double d = 456.78; //OK, 456.78 is a compile-time constant // expression
   constexpr double d2 = d; //OK, d is a constant expression
   int x = 123;
   constexpr int n2 = x; //compile-time error
   // the value of x is not known during // compile-time
}
```

In C++17, lambdas are implicitly constexpr if possible. 
Any lambda can be used in compile-time contexts provided the features it uses are valid for compile-time contexts.
(e.g. only literal types, NO static variable, No virtual, NO try/catch, No new/delete).

```

auto squared = [](auto val) { // implicitly constexpr since C++17
  return val*val;
};

std::array<int,squared(5)> a; // OK since C++17 => std::array<int,25>

```

When we use static in the lambda function, the constexpr will not work and the compiler throws an error.
However, we can use lambda expressions with static and without constexpr.

```
auto squared2 = [](auto val) { // implicitly constexpr since C++17
static int calls = 0; // OK, but disables lambda for constexpr contexts
...
return val*val;
};
std::array<int,squared2(5)> a; // ERROR: static variable in compile-time context
std::cout << squared2(5) << '\n'; // OK
```

To find out at compile time whether a lambda is valid for a compile-time context, you can declare it as constexpr

```

auto squared3 = [](auto val) constexpr { // OK since C++17
    return val*val;
};


With specified return types the syntax looks as follows:


auto squared3i = [](int val) constexpr -> int { // OK since C++17
   return val*val;
};

```

## Passing Copies of this to lambdas

When using lambdas in member functions, we have no implicit access to the object the member function is called for.
Inside the lambda, without capturing this in any form, we cannot use members of the object.

```
class C {
  private:
     std::string name;
   public:
     ...
     void foo()
     {
        auto l1 = [] { std::cout << name << '\n'; }; // ERROR
        auto l2 = [] { std::cout << this->name << '\n'; }; // ERROR
         ...
     }
};
```

In C++11 and C++14, e have to pass ***this*** either by value or by reference:

```
class C {
   private:
      std::string name;
    public:
      ...
      void foo() {
          auto l1 = [this] { std::cout << name << '\n'; }; // OK
          auto l2 = [=] { std::cout << name << '\n'; }; // OK
          auto l3 = [&] { std::cout << name << '\n'; }; // OK
          ...
        }
};
```

However, the above approach creates a problem when the lifetime of the lambda exceeds the lifetime of the object upon which the member function is invoked.
For example, when lambda defines the task of a new thread, which should use its own copy of the object to avoid any concurrency or lifetime issues. 

In C++17, we can explicitly ask to capture a copy of the current object by capturing ****this*** :

```
class C {
  private:
    std::string name;
  public:
    ...
    void foo() {
      auto l1 = [*this] { std::cout << name << '\n'; };
      ...
    }
};


That is, the capture *this means that a copy of the current object is passed to the lambda.
Still you can combine capturing *this with other captures, as long as there is no contradiction for
handling this:

auto l2 = [&, *this] { ... }; // OK
auto l3 = [this, *this] { ... }; // ERROR

```
