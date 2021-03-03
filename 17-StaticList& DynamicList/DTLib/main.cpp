#include <iostream>
#include "StaticList.h"
#include "DynamicList.h"
using namespace std;
using namespace DTLib;

int main(){
    cout << "main begin" << endl;

    StaticList<int,5> sl;

    for (int i = 0; i < sl.capacity(); ++i){
        sl.insert(0, i);
        //cout << sl[i] << endl;
    }

    for (int i = 0; i< sl.length(); ++i){
        cout << sl[i] << endl;
    }

    cout << "--------------" << endl;

    /*sl[0] *= sl[0];

    for (int i = 0; i< sl.length(); ++i){
        cout << sl[i] << endl;
    }*/

    cout << "--------------" << endl;

    try{
       sl[5] = 5;
    }catch (const Exception &e){
        cout << e.message() << endl;
        cout << e.location() << endl;
    }

    cout << "main end" << endl;

    sl.remove(2);
    for (int i = 0; i< sl.length(); ++i){
        cout << sl[i] << endl;
    }
    return 0;
}

