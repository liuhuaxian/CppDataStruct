#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H
using namespace std;
namespace DTLib{
template<typename T>//��ģ��
class SmartPointer{
public:
        SmartPointer(T*p = NULL){//1���캯��
            cout <<"SmartPointer(T*p = NULL)--1"<<endl;
            m_pointer = p;
        }


        SmartPointer(const SmartPointer& obj){//2�������캯��
            cout <<"SmartPointer(const SmartPointer& obj)--2"<<endl;
            m_pointer = obj.m_pointer;
            const_cast<SmartPointer&>(obj).m_pointer = NULL;//
        }

        SmartPointer& operator= (const SmartPointer& obj){//3��ֵ����������
            if(this != &obj){//��ֹ�Լ���ֵ�Լ���
                delete m_pointer;
                m_pointer = obj.m_pointer;
                const_cast<SmartPointer&>(obj).m_pointer = NULL;
            }
            cout <<"SmartPointer& operator= (const SmartPointer& obj)--3"<<endl;
            return *this;
        }



        //����������->��*
        T* operator ->(){//4����ֵΪT*����
            cout<<"T* operator ->()--4"<<endl;
            return m_pointer;
        }
        T& operator *(){//5why����ֵ��&��
            cout <<"T& operator *()--5"<<endl;
            return *m_pointer; //*m_pointer��һ��Test����
        }


        bool isNull(){//6
            cout <<"isNull()--6"<<endl;
            return (m_pointer == NULL);

        }
        T* get(){
            return m_pointer;
        }

        ~SmartPointer(){
                delete m_pointer;
        }
private:
        T* m_pointer;
};
}

#endif // SMARTPOINTER_H


