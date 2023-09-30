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
