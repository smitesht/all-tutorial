// lambda001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{   

    // Ex 1

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

    // Ex 2
    auto la = [] { return "Hello I'm Lambda function"; };
    std::cout << la()<<endl;

    // Ex 3 Closures

    const char* greetings{ "Hello from colusres" };
    const auto greet = [greetings] {std::cout << greetings << endl; };
    greet();

    // Ex 4 define return type
    auto one = []() -> const char* {return "This is one lambda"; };
    auto two = []() -> auto { return "This is two lambda"; };

    std::cout<<one()<<endl;
    std::cout<<two()<<endl;

    // Ex 5
    vector<string> vstr = { "Smitesh","Ramesh","Ila","Anupam","AmitKumar","SahrukhKan" };

    int len = 6;
    auto ret = count_if(vstr.begin(), vstr.end(), [len](string str) {
        return (str.length() < 10);
        });

    std::cout << ret << endl;

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
