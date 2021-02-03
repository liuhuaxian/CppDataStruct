
#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

namespace DTLib{
template<typename T>//类模板
class SmartPointer{
public:
        SmartPointer(T*p = nullptr){//构造函数
            m_pointer = p;
        }
        SmartPointer(const SmartPointer& obj){//拷贝构造函数
            m_pointer = obj.m_pointer;
            const_cast<SmartPointer&>(obj).m_pointer = nullptr;//
        }

        SmartPointer& operator= (const SmartPointer& obj){//赋值操作符重载
            if(this != &obj){//防止自己赋值自己玩
                delete m_pointer;
                m_pointer = obj.m_pointer;
                const_cast<SmartPointer&>(obj).m_pointer = nullptr;
            }
            return *this;
        }



        //操作符重载->和*
        T* operator ->(){//返回值为T类型
            return m_pointer;
        }
        T operator *(){//why返回值加&

            return *m_pointer;//这里用*this不行吗？待测试
        }


        bool isnull(){
            return (m_pointer == nullptr);

        }
        T* get(){
            return m_pointer;
        }

        ~SmartPointer(){
                delete m_pointer;
        }


private:
        T* m_pointer = nullptr;
};
}











#endif // SMARTPOINTER_H

