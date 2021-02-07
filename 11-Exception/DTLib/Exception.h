#ifndef EXCEPTION_H
#define EXCEPTION_H

namespace DTLib{
#define THROW_EXCEPTION(e, m) (throw e(m, __FILE__, __LINE__))//��ӡ���������ļ������ֺ��к�

class Exception{//û�ж���,�������̳�
protected:
    char* m_message;
    char* m_location;

    //�ø�����init������ɳ�ʼ���Ĺ���,ǰ�������캯�����ڲ��߼��ǲ���,������init����
    void init(const char *message, const char *file, int line);//�ø�����init������ɳ�ʼ���Ĺ���
public:
    Exception(const char* message);
    Exception(const char* file,int line);
    Exception(const char *message, const char *file, int line);

    //�쳣������ʼ�������Ǹ�ֵ,��init����ʵ�ֿ��Կ��������,�������������������ʵ�����ٲ��˵�
    Exception(const Exception &e);//a(b)
   //һ�㷵��ֵ��Ҫ����������������������,��������ط���Ϊ���õľ���ô����:[],=,������������,�Լ��Լ����������ס�����ˣ�
    Exception& operator= (const Exception &e);//a=b

    virtual const char* message() const;//����Ĺ�����������2���ӿ���
    virtual const char* location() const;

    //���д��麯���Ļ���(������)�ǲ����Զ������ġ����麯���ǲ���Ҫ�ṩʵ�ֵģ�������������ɣ�BUT!������������������,�����ǲ��Ǵ����,����ʵ��
    virtual ~Exception() = 0;
};

/*class ArithmeticException:public Exception{//�����쳣  1/0
public://���캯����ʼ���б�
    ArithmeticException();
    ArithmeticException(const char* message);
    ArithmeticException(const char* file,int line);
    ArithmeticException(const char *message, const char *file,int line);

    ArithmeticException(const ArithmeticException &e);//�������캯��
    ArithmeticException& operator=(const ArithmeticException &e){
        Exception::operator =(e);//����&
        return *this;
    }
    ~ArithmeticException() {}
};
class NullPointerException:public Exception{//��ָ���쳣
public:
    NullPointerException():Exception(0){}
    NullPointerException(const char* message):Exception(message){}
    NullPointerException(const char* file,int line):Exception(file,line){}
    NullPointerException(const char *message, const char *file,int line):Exception(message,file,line){}

    NullPointerException(const NullPointerException &e):Exception(e){}
    NullPointerException& operator=(const NullPointerException& e){
        Exception::operator =(e);//����&
        return *this;
    }
    ~NullPointerException(){}
};

class IndexOutOfBoundsException: public Exception{//Խ���쳣 ��������
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
class NoEnoughMemoryException: public Exception{//�ڴ治���쳣 ��̬�����ڴ��ʱ��
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
class InvalidParameterExcetion: public Exception{//���������쳣
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
*/
}
#endif // EXCEPTION_H
