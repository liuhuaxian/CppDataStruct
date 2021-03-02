#ifndef OBJECT_H
#define OBJECT_H

namespace DTLib{
class Object{
public://如果你知道你的函数绝对不会抛出任何异常，应该使用noexcept, 而不是throw().
    void *operator new (unsigned int size) throw();
    void operator delete (void *p);
    void *operator new[] (unsigned int size) ;
    void operator delete[] (void *p);
    virtual ~Object() = 0;//子类都会有虚函数表的指针，动态类型识别 纯虚函数 virtual关键字
};


}


#endif // OBJECT_H
