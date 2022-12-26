## Functor in C++

### What is functor

    A functor or function object is a C++ class that acts like a function.

    Functors can be called using the function call syntax, and can yield values and accept parameters like regular functions.

### Examples

#### Ex 1

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

#### Ex 2

```
// Ex2 String Appender

class StringAppender {
public:
    explicit StringAppender(const string& str): toAppend(str){}

    void operator() (const string& str) const {
        cout << str << ' ' << toAppend << endl;
    }

private:
    const string toAppend;
};

//Ex2
StringAppender name("is awesome");
name("Smitesh");

```

#### Ex 3

```
// Ex3 Find String shorter than number

class ShorterThan {
public:
    explicit ShorterThan(size_t maxLen) : length(maxLen) {};

    bool operator()(const string& str) const {
        return str.length() < length;
    }
private:
    const size_t length;
};

//Ex3
ShorterThan st(5);
vector<string> v;
v.push_back("Smtiesh");
v.push_back("Ami");
v.push_back("Anu");
v.push_back("Om");
v.push_back("Rameshpatel");

// this returns total counts less than strings length 5
cout<<(count_if(v.begin(), v.end(), st));

```
