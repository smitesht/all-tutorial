// map_lambda_01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <string>

using namespace std;

/*
    Lambda Expression In Map

    [CapturesClosers] (Parameter list) -> return-type { body }

*/

class Color {
public:
    Color();
    Color(int r, int g, int b) :m_r(r), m_g(g), m_b(b){}
    int getR() { return m_r; }

    int m_r, m_g, m_b;
};


int main()
{
    // This is the lambda function
    auto comparator = [](const Color& c1, const Color& c2) -> bool {
        return (c1.m_r < c2.m_r);
    };


    // uses of lambda in map
    std::map<Color, int,decltype(comparator)> color_map(comparator);

    color_map[{Color(2, 4, 5)}] = 10;
    color_map[{Color(1, 4, 5)}] = 11;
    color_map[{Color(18, 4, 5)}] = 12;
    color_map[{Color(3, 4, 5)}] = 13;
    color_map[{Color(5, 4, 5)}] = 14;

    for (auto &c : color_map) {
        cout <<c.first.m_r << " " << c.second << endl;
    }

    std::cout << "Hello World!\n";
}


