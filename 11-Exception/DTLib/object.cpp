#include "object.h"
#include<cstdlib>
using namespace DTLib;
//throw()异常规格说明，当前的重载函数是不会抛出任何的重载异常的
void *Object::operator new (unsigned int size) throw(){//创建单个对象的时候会调用


}
void Object:: operator delete (void *p){}
void *Object:: operator new[] (unsigned int size) noexcept{}
void Object:: operator delete[] (void *p){}
virtual Object::~Object() {}//子类都会有虚函数表的指针，动态类型识别
