#include "Exception.h"
#include <cstring>//�����ַ����ĺ���
#include <cstdlib>

namespace DTLib{
//��������messageָ��ָ����ַ�������λ��ջ��/�ѿռ�/ȫ��������,û�취����message��ָ����ⲿ�ַ�������������
void Exception::init(const char *message, const char *file, int line){
    //m_message = message//��д���ǲ���ȫ��,ԭ�����6��  ����취������һ���ַ�������
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
    init(message,0,0);
}
Exception::Exception(const char* file,int line){
    init(0,file,line);
}
Exception::Exception(const char *message, const char *file, int line){
    init(message,file,line);
}


//�������캯���͸�ֵ���������غ��� ���Ҫ��ָ֤����ָ����ڴ�ռ�����Ƕ�����
Exception::Exception(const Exception &e){
    m_message = strdup(e.m_message);
    m_location = strdup(e.m_location);
}
Exception& Exception::operator= (const Exception &e){
    if(this != &e){//�ڽ������֮ǰ,�Ƚ�ԭ��ָ��ָ��Ķѿռ��ͷŵ�
        free(m_message);
        free(m_location);
        m_message = strdup(e.m_message);
        m_location = strdup(e.m_location);
    }
    return *this;
}

const char* Exception::message() const{//����ʵ�ֿɽ�ǰ���virtualȥ��
    return m_message;//���ض�Ӧ�ĳ�Աָ��
}
const char* Exception::location() const{
    return m_location;
}
Exception::~Exception(){
    free(m_message);
    free(m_location);
}
}


