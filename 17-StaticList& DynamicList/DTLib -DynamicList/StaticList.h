﻿#ifndef STATICLIST_H
#define STATICLIST_H
#include"SqlList.h"
/*
public: 能被 类的对象、类成员函数、子类函数、友元访问。
protected: 只能被类成员函数、子类函数及友元访问，不能被其他任何访问，本身的类对象也不行。
private: 只能被类成员函数及友元访问，不能被其他任何访问，本身的类对象也不行。

protected继承和private继承能降低访问权限：

使用private继承，父类的protected和public属性在子类中变为private
使用protected继承，父类的protected和public属性在子类中变为protected
使用public继承，父类中的protected和public属性不发生改变

StaticList 设计要点 类模板 1.使用原生数组作为顺序存储空间 2.使用模板参数决定数组大小
*/
namespace DTLib{
template <typename T,int N>
class StaticList:public SqlList<T>{//静态定义了一个存储空间
protected:
    T m_space[N];//顺序存储空间
public:
    StaticList(){
        this->m_array = m_space;//开始具体分配内存
        this->m_length = 0;
    }

    int capacity()const{
        return N;
    }
};

}


#endif // STATICLIST_H
