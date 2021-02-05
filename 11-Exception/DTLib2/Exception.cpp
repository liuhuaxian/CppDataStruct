#include "Exception.h"
#include <cstring>//拷贝字符串的函数
#include <cstdlib>

namespace DTLib{
//函数参数message指针指向的字符串可能位于栈上/堆空间/全局数据区,没办法控制message所指向的外部字符串的生命周期
void Exception::init(const char *message, const char *file, int line){
    //m_message = message//该写法是不安全的,原因见第6行  解决办法：拷贝一份字符串出来
    m_message = strdup(message);
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


Exception::Exception(const char* message){
    init(message);
}
Exception::Exception(const char* file,int line){
    init(0,file,line);
}
Exception::Exception(const char *message, const char *file, int line){
    init(message,file,line);
}


//拷贝构造函数和赋值操作符重载函数 深拷贝要保证指针所指向的内存空间必须是独立的
Exception::Exception(const Exception &e){
    m_message = strdup(e.m_message);
    m_location = strdup(e.m_location);
}
Exception& Exception::operator= (const Exception &e){
    if(this != &e){//在进行深拷贝之前,先将原来指针指向的堆空间释放掉
        free(m_message);
        free(m_location);
        m_message = strdup(e.m_message);
        m_location = strdup(e.m_location);
    }
    return *this;
}

const char* Exception::message() const{//具体实现可将前面的virtual去掉
    return m_message;//返回对应的成员指针
}
const char* Exception::location() const{
    return m_location;
}
Exception::~Exception(){
    free(m_message);
    free(m_location);
}
}


