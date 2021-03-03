#include <iostream>
#include "StaticArray.h"
#include "DynamicArray.h"
using namespace std;
using namespace DTLib;


int main(){
    cout << "main begin" << endl;
    DynamicArray<int> d(5);
    for(int i=0;i<5;i++){
        d[i] =i+1;
    }
    for(int i=0;i<5;i++){
        cout << d[i] << endl;
    }
    cout << "*******************" << endl;

    DynamicArray<int> d1;
    d1 = d;
    for(int i=0;i<5;i++){
        cout << d[i] << endl;
    }
    d1.resize(3);
    cout << "*******************" << endl;
    for(int i=0;i<d1.length();i++){
        cout << d1[i] << endl;
    }
    return 0;
}

