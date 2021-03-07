#ifndef STATICARRAY_H
#define STATICARRAY_H
#include"Array.h"
/*StaticArray设计要点：必须是类模板,替代原生数组 原因： 可以指定数组对象中数据成员的类型
 1.封装原生数组 2.使用模板参数决定数组大小 3.实现函数返回数组长度 4.拷贝构造和赋值操作
*/
namespace DTLib{
template<typename T,int N>
class StaticArray:public Array<T>{
protected:
    T m_space[N];
public:
    StaticArray(){
        this->m_array = m_space;
    }

    StaticArray(const StaticArray<T,N> &obj){
        this->m_array = m_space;
            for(int i=0;i<N;i++){
            m_space[i] = obj.m_space[i];
        }
    }

    StaticArray<T,N> &operator= (const StaticArray<T,N> &obj){
        if(this != &obj){
            for(int i=0;i<N;i++){
            m_space[i] = obj.m_space[i];
          }
        }
        return *this;
    }

    int length() const{
         return N;
    }
};
}
#endif // STATICARRAY_H
