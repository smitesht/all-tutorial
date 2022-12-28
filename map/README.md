## Map in C++ STL

### What is Map

    Map is an associated container that contain key, value pair. It is like a dictionary where each key is a unique and stored in memory as a tree form (AVL/Red Black Tree).

    The main advantages of Map is to quick access of the element while the disadvantage is maintanance of map.

### Examples

#### Ex 1

```
//_ ex1
// Uses of Map when Key as a user defined type

struct Student{
    int id;
    string name;
    int age;

    // Sort based on student id
    bool operator < (const Student& s) const {
        return (id < s.id);
    }
};


std::map<Student, int> student_map;

std::pair<Student, int> s1({1,"John",10}, 10);
student_map.insert(s1);

student_map.insert(std::pair<Student,int>({  4,"Will",11  },11));

student_map.insert(std::pair<Student, int>({ 3,"Tom",12 }, 12));

student_map.insert(std::pair<Student, int>({ 2,"Robert",10 }, 13));

student_map.insert(std::pair<Student, int>({ 5,"Tina",10 }, 14));

for (auto& s : student_map) {
        cout << s.first.name << " " << s.second <<endl;
    }

```

#### Ex 2

##### Lambda Expression In Map

##### [CapturesClosers] (Parameter list) -> return-type { body }

```
// Ex2 Map using Lambda expression

class Color {
public:
    Color();
    Color(int r, int g, int b) :m_r(r), m_g(g), m_b(b){}
    int getR() { return m_r; }

    int m_r, m_g, m_b;
};

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

```
