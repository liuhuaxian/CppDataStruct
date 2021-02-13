#ifndef EXCEPTION_H
#define EXCEPTION_H


namespace DTLib{
//打印出其所在文件的名字和行号
#define THROW_EXCEPTION(e, m) (throw e(m, __FILE__, __LINE__))
class Exception{//没有对象,用来被继承
protected:
    char* m_message;
    char* m_location;

    //用辅助的init函数完成初始化的工作,前三个构造函数的内部逻辑是差不多的,所以用init函数
    void init(const char *message, const char *file, int line);//用辅助的init函数完成初始化的工作
public:
    Exception(const char* message);
    Exception(const char* file,int line);
    Exception(const char *message, const char *file, int line);

    //异常类对象初始化或者是赋值,从init函数实现可以看出是深拷贝,若是深拷贝这两个函数的实现是少不了滴
    Exception(const Exception &e);//a(b)
   //一般返回值还要继续被处理的情况返回引用,运算符重载返回为引用的就那么几个:[],=,输入输出运算符,自加自减运算符！记住就行了！
    Exception& operator= (const Exception& e);//a=b

    virtual const char* message() const;//具体的功能体现在这2个接口上
    virtual const char* location() const;

    //含有纯虚函数的基类(抽象类)是不可以定义对象的。纯虚函数是不需要提供实现的，等着子类来完成，BUT!但凡定义了析构函数,不管是不是纯虚的,必须实现
    virtual ~Exception();
};

class ArithmeticException:public Exception{//计算异常  1/0
public://构造函数初始化列表
    ArithmeticException():Exception(0){}
    ArithmeticException(const char* message):Exception(message){}
    ArithmeticException(const char* file,int line):Exception(file,line){}
    ArithmeticException(const char *message, const char *file,int line):Exception(message,file,line){}

    ArithmeticException(const ArithmeticException &e):Exception(e){}//拷贝构造函数
    ArithmeticException& operator=(const ArithmeticException& e){
        Exception::operator =(e);//不加&
        return *this;
    }
    ~ArithmeticException() {}
};
class NullPointerException:public Exception{//空指针异常
public:
    NullPointerException():Exception(0){}
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

class IndexOutOfBoundsException: public Exception{//越界异常 访问数组
public:
    IndexOutOfBoundsException():Exception(0){}
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
class NoEnoughMemoryException: public Exception{//内存不足异常 动态申请内存的时候
public:
    NoEnoughMemoryException():Exception(0){}
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
    InvalidParameterExcetion():Exception(0){}
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
