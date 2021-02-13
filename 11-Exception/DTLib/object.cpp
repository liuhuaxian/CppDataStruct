#include "object.h"
#include<cstdlib>
#include<iostream>
using namespace std;
namespace DTLib{
//throw()异常规格说明，当前的重载函数是不会抛出任何的重载异常的
void *Object::operator new (unsigned int size) throw(){//创建单个对象的时候会调用
    cout << "void *Object::operator new" << endl;
    return malloc(size);
}
void Object:: operator delete (void *p){
    cout << "void Object:: operator delete (void *p)" << endl;
    free(p);
}
//创建对象的数组 noexcept是异常规格说明:当前的new不会跑出异常，如果真的无法从堆空间中申请内存时，直接返回一个空
//这样就会保证new申请失败的时候就会返回一个空值，而不是抛出一个异常
void *Object:: operator new[] (unsigned int size) noexcept{
    return malloc(size);
}
void Object:: operator delete[] (void *p){
    free(p);
}
Object::~Object() {//析构函数的纯虚版本也要提供函数体


}//子类都会有虚函数表的指针，动态类型识别
}
