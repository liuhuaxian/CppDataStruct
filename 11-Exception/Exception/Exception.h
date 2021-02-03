#ifndef EXCEPTION_H
#define EXCEPTION_H
#include "Object.h"

namespace DTLib{
#define THROW_EXCEPTION(e, m) (throw e(m, __FILE__, __LINE__))//��ӡ���������ļ������ֺ��к�
class Exception{
public:
    Exception(const char* message);
    Exception(const char* file,int line);
    Exception(const char *message, const char *file, int line);

    Exception(const Exception &e);
   //һ�㷵��ֵ��Ҫ����������������������,��������ط���Ϊ���õľ���ô����:[],=,������������,�Լ��Լ����������ס�����ˣ�
    Exception& operator= (const Exception &e);
    virtual const char* message() const;
    virtual const char* location() const;
};






}
#endif // EXCEPTION_H
