#include <iostream>
#include "StaticArray.h"

using namespace std;
using namespace DTLib;

int main(){
    cout << "main begin" << endl;
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
    cout << "*******************" << endl;
    return 0;
}

