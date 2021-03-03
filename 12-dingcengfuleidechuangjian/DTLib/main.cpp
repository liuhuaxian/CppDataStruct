#include <iostream>
#include "Exception.h"
#include "object.h"
using namespace std;
using namespace DTLib;

class Test:public Object{
public:
    int i,j;
};
class Child:public Test{
public:
    int k;
};
int main()
{
    Object* obj1 = new Test();
    Object* obj2 = new Child();

    cout << "obj1=" <<obj1 << endl;
    cout << "obj2=" <<obj2 << endl;
    delete obj1;
    delete obj2;
    return 0;
}
/*
��������ʹ�õĲ���C++��Ĭ�ϵ�new��delete�ˣ����Ƕ��㸸����Զ���ʵ��
void *Object::operator new
void *Object::operator new
void Object:: operator delete (void *p)
void Object:: operator delete (void *p)

����һ��Test������Ҫ12���ֽڣ�����4���ֽ��������ŵ�ָ���麯������ָ��
void *Object::operator new12
void *Object::operator new16
obj1=0xf711a8
obj2=0xf711c0
void Object:: operator delete (void *p)0xf711a8
void Object:: operator delete (void *p)0xf711c0

���ݽṹ����������е��඼�̳��Զ���object���㸸��Ļ���
���ǾͿ��Ա�֤�Ӷѿռ����洴�����ݽṹ�����ʱ���Ȼʹ�������ṩ��new��delete��ʵ����
*/