## C++ Interview Questions

### Static

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
