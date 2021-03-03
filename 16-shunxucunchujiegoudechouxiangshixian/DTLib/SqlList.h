#ifndef SQLLIST_H
#define SQLLIST_H
#include"List.h"
#include"Exception"
//顺序存储结构的实现可以使用一维数组来表示  存储空间T*m_marry  当前长度int m_length
namespace DTLib{
template<typename T>
class SqlList:public List<T>{
protected:
    T* m_array;//指向一个数组
    int m_length;//记录当前线性表的长度
public:

    bool insert(const T &e){
        return insert(m_length,e);
    }

    bool insert(int i,const T &e){
        bool ret = ( (0<=i) && (i <= m_length));// 注：目标位置可以为m_length,表示尾部插入
        ret = ret && (m_length+1 <= capacity());//capacity()容器能存储数据的个数
        if(ret){
            for(int p = m_length -1;p >= i;--p){
      //向数组中插入元素：将目标位置(包含目标位置自身)之后的所有元素后移一个位置  i后边的元素向后移动
                m_array[p + 1] = m_array[p];
            }
            m_array[i] = e;
            ++m_length;
        }
        return ret;
    }

    bool remove(int i){//移除m_array[i]元素
        bool ret = ( (0<=i) && (i < m_length));
        if(ret){
            for (int p = i; p < m_length; ++p){
                  m_array[p] = m_array[p+1];//后边的值向前来
            }
            --m_length;
        }
        return ret;
    }
    bool set(int i,const T &e){
        bool ret = ((0 <= i) && (i <= m_length));
        if(ret){
            m_array[i] = e;//设置m_arrary[i]
        }
        return ret;
    }

    bool get(int i,T &e)const{//成员函数后加const不改变类的数据成员
        bool ret = ((0 <= i) && (i <= m_length));
        if(ret){
            e = m_array[i];
        }
        return ret;
    }

    int length()const{
        return m_length;
    }

    void clear(){
        m_length = 0;
    }
//以下2个操作符重载是分const和非const情况的
    T& operator[](int i){
        if((0<= i)&& (i<m_length)){
            return m_array[i];
        }else{
            THROW_EXCEPTION(IndexOutofBoundsException,"Parameter i is invalid ...");
        }
    }

    T operator [](int i)const{//该函数的作用是什么？
        return (const_cast<SqlList&>(*this))[i];
    }
    virtual int capacity()const = 0;//顺序存储空间的最大存储容量，实现是在子类中

};
}
#endif // SQLLIST_H
