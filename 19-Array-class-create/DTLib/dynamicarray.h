#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include"Array.h"
#include"Exception.h"
/*DynamicArray设计要点
类模板 1.动态确定内部数组空间的大小 2.实现函数返回数组长度 3.拷贝构造和赋值操作
*/
//template<typename T,int N>
namespace DTLib {
template<typename T>
class DynamicArray:public Array<T>{
protected:
    //T m_space[n];
    int m_length;
public:
    DynamicArray(int length){
        this->m_array = new T[length];
        if(this->m_array != 0){
            this->m_length = length;
        }else{
            THROW_EXCEPTION(NoEnoughMemoryException,"No memory to create DynamicArray object");
        }
    }
    DynamicArray(const DynamicArray<T> &obj){
        this->m_array = new T[obj.m_length];
        if(this->m_array != 0){
            this->m_length = obj.m_length;
            for(int i=0;i<obj.m_length;i++){
                this->m_array[i] = obj.m_array[i];
            }
        }else{
            THROW_EXCEPTION(NoEnoughMemoryException,"No memory to create DynamicArray object");
        }
    }
    DynamicArray<T>& operator=(const DynamicArray<T> &obj){
        if(this != &obj){
            this->m_array = obj.m_array;
            T* array = new T[obj.m_length];
            if(array != NULL){
                for(int i=0;i<obj.m_length;i++){
                    array[i] = obj.m_array[i];
                }
               T* temp = this->m_array;
               this->m_array = array;
               this->m_length = obj.m_length;
               delete[] temp;
            }else{
                THROW_EXCEPTION(NoEnoughMemoryException,"No memory to copy DynamicArray object");
            }
        }
        return* this;
    }

    int length()const{
        return m_length;
    }
    void resize(int length){
        if(m_length != length){
            T*array = new T[length];
            if(array != 0){
                int size = (length<m_length)?length:m_length;
                for(int i=0;i<size;i++){
                       array[i] = this->m_array[i];
                }
                //为了异常安全，需要以下操作
                T* temp = this->m_array;
                this->m_array = array;
                this->m_length = length;

                delete[] temp;
            }
            }else{
                THROW_EXCEPTION(NoEnoughMemoryException,"No memory to resize DynamicArray object");
            }
    }

    ~DynamicArray(){
        delete[]this->m_array;
    }

};

}
#endif // DYNAMICARRAY_H
