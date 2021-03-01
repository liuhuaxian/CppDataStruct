#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H
#include"Object.h"
namespace DTLib{
//类模板
template<typename T>
class SmartPointer:public Object{
protected:
    T* m_pointer = nullptr;
public:
    SmartPointer(T* p = nullptr){
        m_pointer = p;
    }
    SmartPointer(const SmartPointer &obj){
        m_pointer = obj.m_pointer;
        const_cast<SmartPointer&>(obj).m_pointer = nullptr;
    }
    //=操作符重载
    SmartPointer& operator=(const SmartPointer &obj){
        if(this != &obj){
            delete m_pointer;//赋值之前先删除
            m_pointer = obj.m_pointer;
            const_cast<SmartPointer&>(obj).m_pointer = nullptr;
        }
        return *this;
    }
    T *operator->(){
        return m_pointer;
    }
    T &operator*(){
        return *m_pointer;
    }
    bool isNull(){
        return (m_pointer==nullptr);
    }
    T *get(){
        return m_pointer;
    }
    ~SmartPointer(){
        delete m_pointer;
    }
};



}











#endif // SMARTPOINTER_H
