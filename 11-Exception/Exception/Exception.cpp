#include "Exception.h"

#include <cstring>
#include <cstdlib>

namespace DTLib{
ArithmeticException::ArithmeticException(const char* message):Exception(message, 0, 0){}//:��ߵ�Exception()??
ArithmeticException::ArithmeticException(const char *message, const char *file,int line):Exception(message,file, line){}

Exception::Exception(const char *message, const char *file, int line){
//strdup()���ڲ�������malloc()Ϊ���������ڴ棬����Ҫʹ�÷��ص��ַ���ʱ��
//��Ҫ��free()�ͷ���Ӧ���ڴ�ռ䣬���������ڴ�й©��
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


