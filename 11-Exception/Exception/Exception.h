#ifndef EXCEPTION_H
#define EXCEPTION_H
#include "Object.h"

namespace DTLib{
#define THROW_EXCEPTION(e, m) (throw e(m, __FILE__, __LINE__))//打印出其所在文件的名字和行号
class Exception{
public:
    Exception(const char* message);
    Exception(const char* file,int line);
    Exception(const char *message, const char *file, int line);

    Exception(const Exception &e);
   //一般返回值还要继续被处理的情况返回引用,运算符重载返回为引用的就那么几个:[],=,输入输出运算符,自加自减运算符！记住就行了！
    Exception& operator= (const Exception &e);
    virtual const char* message() const;
    virtual const char* location() const;
};






}
#endif // EXCEPTION_H
