#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H
#include "SqlList.h"
#include "Exception.h"
/*
类模板
     申请连续堆空间作为顺序存储空间
     动态设置顺寻存储空间的大小
     保证重置顺序存储空间时的异常安全性
函数异常安全的概念
     不泄露任何资源
     不允许破坏数据
函数异常安全的基本保证
     如果异常被抛出
     对象内的任何成员仍然能保持有效状态
     没有数据的破坏及资源泄漏

*/
namespace DTLib{
template <typename T>
class DynamicList:public SqlList<T>
{
protected:
    int m_capacity;  // 顺序存储空间的大小
public:
    ////申请空间
    DynamicList(int capacity){
        this->m_array = new T[capacity];
        if(this->m_array != NULL){
            this->m_capacity = capacity;
            this->m_length = 0;//??
        }else{
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create DynamicList object ...");
        }
    }
    int capacity() const{
        return m_capacity;
    }
    // 重新设置存储空间的大小
    void resize(int capacity){
        if (capacity != m_capacity){
            T *array = new T[capacity];  //注意1 申请新的内存空间，对原内存空间中的数据进行拷贝，以保留原始值。
            if(array!=0){
                int length =(this->m_length < capacity)?this->m_length:capacity;
                for(int i=0;i<length;++i){
                    array[i] = this->m_array[i];        // 注意 2
                }
                T *temp = this->m_array;            // 注意 3

           this->m_array    = array;
           this->m_length   = length;
           this->m_capacity = capacity;
           delete [] temp;                     // 注意 3
        }else{
                THROW_EXCEPTION(NoEnoughMemoryException, "No meomry to resize DynamicList object ...");
            }
        }
    }
    ~DynamicList(){}           // 归还空间
};
}
#endif // DYNAMICLIST_H
