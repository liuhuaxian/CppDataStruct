#include <iostream>
//#include "StaticList.h"
#include "DynamicList.h"
using namespace std;
using namespace DTLib;

int main(){
    cout << "main begin" << endl;
    DynamicList<int>l(5);
    for(int i=0;i<l.capacity();i++){
        l.insert(i);//线性表必须先插入元素，才能使用操作符[]访问元素
    }
    for(int i=0;i<l.length();i++){
        cout << l[i] << endl;
    }

    return 0;
}

