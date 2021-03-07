#include <iostream>
#include "StaticArray.h"
#include"DynamicArray.h"
using namespace std;
using namespace DTLib;

int main(){
    /*cout << "main begin" << endl;
    StaticArray<int, 5> a;

    for (int i=0; i<a.length(); ++i){
        a[i] = i * i;
    }
    for (int i=0; i<a.length(); ++i){
        cout << a[i] << endl;
    }
    cout << "---------" << endl;


    StaticArray<int, 5> a1;
    a1 = a;
    for (int i=0; i<a1.length(); ++i){
        cout << a[i] << endl;
    }
    cout << "*******************" << endl;*/

    DynamicArray<int>a(5);
    for (int i=0; i<a.length(); ++i){
        a[i] = i+1;
    }
    for (int i=0; i<a.length(); ++i){
        cout << a[i] << endl;
    }
    cout << "*******************" << endl;
    a.resize(4);
    for (int i=0; i<a.length(); ++i){
        cout << a[i] << endl;
    }
    return 0;
}

