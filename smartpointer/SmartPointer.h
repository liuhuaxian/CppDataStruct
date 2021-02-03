#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H
using namespace std;
namespace DTLib{
template<typename T>//类模板
class SmartPointer{
public:
        SmartPointer(T*p = NULL){//1构造函数
            cout <<"SmartPointer(T*p = NULL)--1"<<endl;
            m_pointer = p;
        }


        SmartPointer(const SmartPointer& obj){//2拷贝构造函数
            cout <<"SmartPointer(const SmartPointer& obj)--2"<<endl;
            m_pointer = obj.m_pointer;
            const_cast<SmartPointer&>(obj).m_pointer = NULL;//
        }

        SmartPointer& operator= (const SmartPointer& obj){//3赋值操作符重载
            if(this != &obj){//防止自己赋值自己玩
                delete m_pointer;
                m_pointer = obj.m_pointer;
                const_cast<SmartPointer&>(obj).m_pointer = NULL;
            }
            cout <<"SmartPointer& operator= (const SmartPointer& obj)--3"<<endl;
            return *this;
        }



        //操作符重载->和*
        T* operator ->(){//4返回值为T*类型
            cout<<"T* operator ->()--4"<<endl;
            return m_pointer;
        }
        T& operator *(){//5why返回值加&？
            cout <<"T& operator *()--5"<<endl;
            return *m_pointer; //*m_pointer是一个Test对象
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


