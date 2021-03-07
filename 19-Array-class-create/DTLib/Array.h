#ifndef ARRAY_H
#define ARRAY_H
#include"Object.h"
#include"Exception.h"

//抽象数组类的实现
/*需求分析
1.创建数组类代替原生数组的使用 2.数组类包含长度信息 3.数组类能够主动发现指定下标越界访问
通过类对象模拟数组的行为 **
*/
//Array 要点设计
//1.抽象类模板,存储空间的位置和大小由子类完成 2.重载数组操作符,判断访问下标是否合法
//3.提供数组长度的抽象访问函数 4.提供数组对象间的复制操作
namespace DTLib{
template<typename T>
class Array:public Object
{
protected:
    T*m_array;
public:
    virtual bool set(int i,const T &e){//O(1)
        bool ret = ((0 <= i)&&(i < length()));
        if(ret){
            m_array[i] = e;
        }
        return ret;
    }
    virtual bool get(int i,T &e)const{
        bool ret = ((0 <= i)&&(i < length()));
        if(ret){
            e =  m_array[i];
        }
        return ret;
    }
    virtual int length()const=0;

    T &operator[](int i){//给普通对象使用
        if((0 <= i)&& (i < length())){
            return m_array[i];
        }else{
            THROW_EXCEPTION(IndexOutOfBoundsException,"Paramter i is invalid ...");
        }
    }
    T operator [](int i)const{//对const对象的照顾
        return const_cast<Array<T>&>(*this)[i];//去除对象的const属性
    }
};





}
#endif // ARRAY_H
