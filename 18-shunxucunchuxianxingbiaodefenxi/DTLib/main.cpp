#include <iostream>
//#include "StaticList.h"
#include "DynamicList.h"
using namespace std;
using namespace DTLib;

int main(){
    cout << "main begin" << endl;
    DynamicList<int>l(5);
    for(int i=0;i<l.capacity();i++){
        //顺序存储结构线性表提供额数组操作符重载，通过重载能够快捷方便的获取目标位置处的数据元素
        //在具体使用方式上类似数组，但是由于本质不同，不能够代替数组使用

        l.insert(i);//线性表必须先插入元素，才能使用操作符[]访问元素 线性表不是数组
    }
    for(int i=0;i<l.length();i++){
        cout << l[i] << endl;
    }

    return 0;
}

