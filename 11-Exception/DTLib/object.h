#ifndef OBJECT_H
#define OBJECT_H

namespace DTLib{
class Object{
public:
    void *operator new (unsigned int size) noexcept;
    void operator delete (void *p);
    void *operator new[] (unsigned int size) noexcept;
    void operator delete[] (void *p);
    virtual ~Object() = 0;//子类都会有虚函数表的指针，动态类型识别
};


}


#endif // OBJECT_H
