#include <iostream>
#include"SmartPointer.h"
using namespace std;
using namespace DTLib;

class Test{
private:
    int value;
public:
    Test(){
        cout << "Test()" << endl;
    }
    ~Test(){
            cout << "~Test()" << endl;
        }
    void print(){
        value = 25;
        cout << "void print() : " << value << endl;
    }


};
int main()
{
    SmartPointer<Test> p1 = new Test();//Test()  SmartPointer(T*p = NULL)--1
    SmartPointer<Test> p2(p1);          //SmartPointer(const SmartPointer& obj)--2
    cout << "p1 = " << p1.isNull() << endl;//isNull()--6   p1 = 1
    cout << "p2 = " << p2.isNull() << endl;//isNull()--6   p2 = 0

    SmartPointer<Test> p3;             //SmartPointer(T*p = NULL)--1
    p3 = p2;//SmartPointer& operator= (const SmartPointer& obj)--3
    cout << "p2 = " << p2.isNull() << endl;
    cout << "p3 = " << p3.isNull() << endl;

    p3->print();     //  <==>(p3.operator ->())->print();
    (*p3).print();//<==>(p3.operator *()).print()   T& operator *()--5

    return 0;
}

