// mini-project-01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
#include <string>
#include <map>

using namespace std;

/*
    This is the functor to use in Map
*/

struct Student{
    int id;
    string name;
    int age;

    // Sort based on student id
    bool operator < (const Student& s) const {
        return (id < s.id);
    }

    // 
};



int main()
{
    bool isContinue = true;
    std::map<Student, int> student_map;

    do {
        int id = 0;
        int age = 0;
        string name = "";
        char yn;

        std::cout << "Enter Student Id"<<std::endl;
        cin >> id;
        cout << "Enter Name" << endl;
        cin >> name;
        cout << "Enter Age" << endl;
        cin >> age;

        Student s({ id, name,age });

        auto it = student_map.find(s);

        if (it == student_map.end())
        {
            student_map[s] = 0;
        }
        else
        {
            student_map[s]++;
            //cout << (it->second)++ << endl;
        }

        cout << "Do you want to continue? Y/N" << endl;
        cin >> yn;

        if (yn == 'Y')
        {
            isContinue = true;
        }
        else
        {
            isContinue = false;
        }
        
        //student_map.insert(std::pair<Student, int>({ id,name,age }, 10));

    } while (isContinue);

  
    /*
        Alternate way of adding data to map
    */

    /*std::pair<Student, int> s1({1,"John",10}, 10);
    student_map.insert(s1);

    student_map.insert(std::pair<Student,int>({  4,"Will",11  },11));

    student_map.insert(std::pair<Student, int>({ 3,"Tom",12 }, 12));

    student_map.insert(std::pair<Student, int>({ 2,"Robert",10 }, 13));

    student_map.insert(std::pair<Student, int>({ 5,"Tina",10 }, 14));*/


    
    /*auto it = student_map.find(s);

    if (it == student_map.end())
    {
        cout << "Nothing" << endl;
    }
    else
    {
        cout << it->second << endl;
    }*/
            

    for (auto& s : student_map) {
        cout << s.first.name << " " << s.second <<endl;
    }
        
}
