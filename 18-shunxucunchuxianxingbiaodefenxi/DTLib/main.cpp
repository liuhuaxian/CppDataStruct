#include <iostream>
//#include "StaticList.h"
#include "DynamicList.h"
using namespace std;
using namespace DTLib;

int main(){
    cout << "main begin" << endl;
    DynamicList<int>l(5);
    for(int i=0;i<l.capacity();i++){
        l.insert(i);
    }
    for(int i=0;i<l.length();i++){
        cout << l[i] << endl;
    }

    return 0;
}

