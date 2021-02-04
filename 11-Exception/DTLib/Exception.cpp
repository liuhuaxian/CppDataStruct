#include "Exception.h"

#include <cstring>//拷贝字符串的函数
#include <cstdlib>

namespace DTLib{
//函数参数message指针指向的字符串可能位于栈上/堆空间/全局数据区,没办法控制message所指向的外部字符串的生命周期
void Exception::init(const char *message, const char *file, int line){
    //m_message = message//该写法是不安全的,原因见第7行  解决办法：拷贝一份字符串出来
}
ArithmeticException::ArithmeticException(const char* message):Exception(message, 0, 0){}//:后边的Exception()??
ArithmeticException::ArithmeticException(const char *message, const char *file,int line):Exception(message,file, line){}

Exception::Exception(const char *message, const char *file, int line){
//strdup()在内部调用了malloc()为变量分配内存，不需要使用返回的字符串时，
//需要用free()释放相应的内存空间，否则会造成内存泄漏。
       m_message =  strdup(message);
       if(file != NULL){
           char s[16] = {0};
            itoa(line, s, 10);
            m_location = static_cast<char*>(malloc(strlen(file) + strlen(s) + 2));
            m_location = strcpy(m_location, file);
            m_location = strcat(m_location, ":");
            m_location = strcat(m_location, s);
        }else{
            m_location = 0;
        }
}
Exception::Exception(const Exception &e){
    m_message = strdup(e.m_message);
    m_location = strdup(e.m_location);
}

Exception& Exception::operator= (const Exception &e){
    if(this != &e){
        free(m_message);
        free(m_location);
    }
    m_message = strdup(e.m_message);
    m_location = strdup(e.m_location);
    return *this;
}

const char* Exception::message() const{
    return m_message;
}
const char* Exception::location() const{
    return m_location;
}
Exception::~Exception(){
    delete m_message;
    delete m_location;
}
}


