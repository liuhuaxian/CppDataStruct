#ifndef LIST_H
#define LIST_H

//由于线性表的数据元素类型不确定，so用模板的方式描述线性表(抽象数据类型)

//线性表的顺序存储结构指的是用一段地址连续的存储单元依次存储线性表中的数据元素

namespace DTLib {
class List:public Object//线性表在程序中表现为一种特殊的数据类型
{
public:
    virtual bool insert(const T &e)=0;
    virtual bool insert(int i,const T &e)=0;
    virtual bool remove(int i)=0;
    virtual bool set(int i,const T &e)=0;
    virtual bool get(int i,T &e)const=0;
    virtual int length()const=0;
    virtual void clear()=0;
};

}


#endif // LIST_H
