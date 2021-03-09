#ifndef LINKLIST_H
#define LINKLIST_H
#include"List.h"
#include"Exception.h"
/*
课程目标:完成链式存储结构线性表的实现
Object
   ^
   |
List
   ^    设计要点：1.类模板,通过头结点访问后继节点
   |            2.义内部结点类型 Node,用于描述数据域和指针域
LinkList        3.实现线性表的关键操作（增，删，查，等）
*/
namespace DTLib{
template<typename T>
class LinkList:public List<T>{
protected:
    struct Node : public Object{
       T value;
       Node *next;
     };
    mutable Node m_header;//头节点的主要作用就是定位节点
    int m_length;
public:
    LinkList(){
        m_header.next = 0;
        m_length = 0;
    }
    virtual bool insert(const T &e) = 0;//在链表的最后插入新的元素
        //return insert(m_length,e);
    bool insert(int i,const T &e){//在链表的指定位置插入新的元素
        bool ret = ((0 <= i)&&(i <= m_length));
        if(ret){
            Node*node = new Node();
            if(node != 0){
                Node *current = &m_header;
                for(int p=0;p<i;++p){//p在此处的作用是从头开始遍历，知道i处为止
                   current = current->next;
                }
                node->value = e;
                node->next = current->next;
                current->next = node;
                ++m_length;
            }else{
                THROW_EXCEPTION(NoEnoughMemoryException, "No memory to insert new element ...");
            }
        }
        return ret;
    }

    bool remove(int i){
        bool ret = ((0 <= i)&&(i< m_length));
        if(ret){
            Node *current = &m_header;
            for(int p=0;p<i;++p){//p在此处的作用是从头开始遍历，知道i处为止
               current = current->next;
            }
            Node *toDel = current->next;
            current->next = toDel->next;
            delete toDel;
            --m_length;
        }
        return ret;
    }

    bool set(int i,const T &e){
        bool ret = ((0 <= i)&&(i< m_length));
        if(ret){
            Node *current = &m_header;
            for(int p=0;p<i;++p){//p在此处的作用是从头开始遍历，知道i处为止
               current = current->next;
            }
               //current->value = e;
             current->next->value = e;//为什么是next
        }
        return ret;
    }

    T get(int i)const{
        T ret;
        if (!get(i, ret)){
                    THROW_EXCEPTION(IndexOutOfBoundsException, "Invalid parameter i to get element ...");
        }
         return ret;
    }

    bool get(int i, T &e) const {
      bool ret = ((0 <= i) && (i < m_length));
      if (ret){
                Node *current = &m_header;
                for (int p=0; p<i; ++p){
                    current = current->next;
                }
                e = current->next->value;
            }
            return ret;
        }
    int length() const{
           return m_length;
       }

       void clear(){
           while (m_header.next){
               Node *toDel = m_header.next;
               m_header.next = toDel->next;
               delete toDel;
               --m_length;
           }
       }

       ~LinkList(){
           clear();
       }


};

}


#endif // LINKLIST_H
