#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include"Array.h"
#include"Exception.h"
namespace DTLib{
template<typename T>
class DynamicArray:public Array<T>{
protected:
    int m_length = 0;

    //优化函数① 在堆空间中申请新的内存，并执行拷贝操作
    T*copy(T*array,int len,int Newlen){
        T* ret = new T[Newlen];
        if(ret != 0){
            int size = (len < Newlen)?len:Newlen;
            for(int i=0;i<size;i++){
                ret[i] = array[i];
            }
        }
        return ret;
    }

    //优化函数② 将指定的堆空间作为内存存储数组使用
    //设置当前成员变量的值的
    void update(T *array, int length){
        if (array != nullptr){
                    T *temp = this->m_array;
                    this->m_array = array;
                    this->m_length = length;
                    delete [] temp;
          }else{
             THROW_EXCEPTION(NoEnoughMemoryException, "No enough memory to update DynmicArray object ...");
          }
    }

    void init(T *array, int length)  // O(1)对象构造时的初始化操作
    {
           if (array != nullptr){
               this->m_array = array;
               this->m_length = length;
           }else{
               THROW_EXCEPTION(NoEnoughMemoryException, "No enough to init DynamicArray object ...");
           }
       }
public:
    DynamicArray(int length = 0){// O(1)
        init(new T[length],length);
    }
    DynamicArray(const DynamicArray<T> &obj){
        init(copy(obj.m_array,obj.m_length,obj.m_length),obj.m_length);
    }

    DynamicArray<T> &operator= (const DynamicArray<T> &obj){
        if(this != &obj){//先复制一个数组出来，然后再将数组设置到当前的成员变量上去
            update(copy(obj.m_array,obj.m_length,obj.m_length),obj.m_length);
        }
        return*this;
    }
//操作符重载函数和resize()存在重复的逻辑，因此要对代码进行优化
    //init 对象构造时的初始化操作,并执行拷贝操作
    //copy 在对空间中申请新的内存，并执行拷贝操作
    //update 将指定的堆空间作为内存存储数组使用
int length()const{
    return m_length;
}
void resize(int length){
    if(length != m_length){
        update(copy(this->m_array,this->m_length,length),length);
        }
    }

    ~DynamicArray(){
        delete[] this->m_array;
    }
};
}
#endif // DYNAMICLIST_H
