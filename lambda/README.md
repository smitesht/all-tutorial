## Lambda function in C++

### What is Lambda function

    A lambda function is the inline anonymouse function based on functor.

    Syntax:
    [ContactClosuers](Parameters){body}

### Examples

#### Ex 1

```
auto la = [] { return "Hello I'm Lambda function"; };
std::cout << la()<<endl;
```

#### Ex 2

```
// Ex2

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

#### Ex 3

```
// Ex3 Find String shorter than number

const char* greetings{ "Hello from colusres" };
const auto greet = [greetings] {std::cout << greetings << endl; };
greet();
```

#### Ex 4

```
//Ex3
auto one = []() -> const char* {return "This is one lambda"; };
auto two = []() -> auto { return "This is two lambda"; };

std::cout<<one()<<endl;
std::cout<<two()<<endl;

```

#### Ex 5

```
// Ex 5
vector<string> vstr = { "Smitesh","Ramesh","Ila","Anupam","AmitKumar","SahrukhKan" };

int len = 6;
auto ret = count_if(vstr.begin(), vstr.end(), [len](string str) {
    return (str.length() < 10);
    });

std::cout << ret << endl;

```
