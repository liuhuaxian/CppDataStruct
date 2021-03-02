#include <iostream>
#include "Exception.h"
#include "object.h"
using namespace std;
using namespace DTLib;
#include"SmartPointer.h"
class Test:public Object{
public:
    int i,j;
};
class Child:public Test{
public:
    int k;
};
int main()
{

    return 0;
}

