#ifndef EXCEPTION_H
#define EXCEPTION_H
#define NULL 0
namespace DTLib{
#define THROW_EXCEPTION(e, m) (throw e(m, __FILE__, __LINE__))//打印出其所在文件的名字和行号
class Exception{
public:
    Exception(const char* message);
    Exception(const char* file,int line);
    Exception(const char *message, const char *file, int line);

    Exception(const Exception &e);//a(b)
   //一般返回值还要继续被处理的情况返回引用,运算符重载返回为引用的就那么几个:[],=,输入输出运算符,自加自减运算符！记住就行了！
    Exception& operator= (const Exception &e);//a=b
    virtual const char* message() const;
    virtual const char* location() const;

    //含有纯虚函数的基类是不可以定义对象的。
    virtual ~Exception() = 0;
protected:
    char* m_message;
    char* m_location;
};

class ArithmeticException:public Exception{//计算异常
public://构造函数初始化列表
    ArithmeticException();
    ArithmeticException(const char* message);
    ArithmeticException(const char* file,int line);
    ArithmeticException(const char *message, const char *file,int line);

    ArithmeticException(const ArithmeticException &e);//拷贝构造函数
    ArithmeticException& operator=(const ArithmeticException &e){
        Exception::operator =(e);//不加&
        return *this;
    }
    ~ArithmeticException() {}
};
class NullPointerException:public Exception{//空指针异常
public:
    NullPointerException():Exception(NULL){}
    NullPointerException(const char* message):Exception(message){}
    NullPointerException(const char* file,int line):Exception(file,line){}
    NullPointerException(const char *message, const char *file,int line):Exception(message,file,line){}

    NullPointerException(const NullPointerException &e):Exception(e){}
    NullPointerException& operator=(const NullPointerException& e){
        Exception::operator =(e);//不加&
        return *this;
    }
    ~NullPointerException(){}
};

class IndexOutOfBoundsException: public Exception{//越界异常
public:
    IndexOutOfBoundsException():Exception(NULL){}
    IndexOutOfBoundsException(const char* message):Exception(message){}
    IndexOutOfBoundsException(const char* file,int line):Exception(file,line){}
    IndexOutOfBoundsException(const char *message, const char *file,int line):Exception(message,file,line){}

    IndexOutOfBoundsException(const IndexOutOfBoundsException& e):Exception(e){}
    IndexOutOfBoundsException& operator=(const IndexOutOfBoundsException& e){
        Exception::operator =(e);
        return *this;
    }
    ~IndexOutOfBoundsException(){}
};
class NoEnoughMemoryException: public Exception{//内存不足异常
public:
    NoEnoughMemoryException():Exception(NULL){}
    NoEnoughMemoryException(const char* message):Exception(message){}
    NoEnoughMemoryException(const char* file,int line):Exception(file,line){}
    NoEnoughMemoryException(const char *message, const char *file,int line):Exception(message,file,line){}


    NoEnoughMemoryException(const NoEnoughMemoryException&e):Exception(e){}
    NoEnoughMemoryException& operator=(const NoEnoughMemoryException&e){
        Exception:operator =(e);
        return *this;
    }
    ~NoEnoughMemoryException(){}
};
class InvalidParameterExcetion: public Exception{//参数错误异常
public:
    InvalidParameterExcetion():Exception(NULL){}
    InvalidParameterExcetion(const char* message):Exception(message){}
    InvalidParameterExcetion(const char* file,int line):Exception(file,line){}
    InvalidParameterExcetion(const char *message, const char *file,int line):Exception(message,file,line){}


    InvalidParameterExcetion(const InvalidParameterExcetion& e):Exception(e){}
    InvalidParameterExcetion& operator=(const InvalidParameterExcetion& e){
        Excetion:operator =(e);
        return *this;
    }
    ~InvalidParameterExcetion(){}
};

}
#endif // EXCEPTION_H
