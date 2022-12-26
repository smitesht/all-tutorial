// functor001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


//* ex1
//* This is the test functor

class MyFunctor {
public:
    void operator() (const string& str) const;
};

void MyFunctor::operator()(const string& str) const
{
    cout << str << endl;
}



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


int main()
{
    std::cout << "Hello World!\n";

    //ex1
    MyFunctor funct;
    funct("This is test");

    //Ex2
    StringAppender name("is awesome");
    name("Smitesh");

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
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
