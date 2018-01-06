#ifndef LIST_CPP
#define LIST_H
#include <iostream>
#include <cstring>
using namespace std;
template <class T>
struct Node 
{
	T value;
	Node *next;
	Node (T v=0,Node *n=NULL):value(v),next(n) {}
	friend bool operator == (Node a,Node b)
	{
		return b.value==a.value;
	}
};
template <class T>
class List
{
private:
	int length; 	        //线性表长度
	Node<T> *head;          //线性表长度
public:
	List();					//构造函数，初始化线性表
	~List();				//析构函数，销毁线性表
	void clear();			//清空线性表
	bool empty();			//返回线性表是否为空
	int size();				//返回线性表中元素的数
	Node<T> *get(int pos);  //返回线性表中第i个元素的指针
	Node<T> *locate(Node<T> e);    //返回线性表中元素e的指针
	Node<T> *pre(Node<T> *e);	   //返回e指向元素的前驱指针
	Node<T> *next(Node<T> *e);	   //返回e指向元素的后继指针
	void insert_pre(Node<T> e,Node<T> *cur);   //在e指向的元素的前面插入元素e
	void insert_next(Node<T> e,Node<T> *cur);  //在e指向的元素的后面插入元素e
	void insert(Node<T> e,int pos);   //在第i个位置插入元素e
	Node<T> del(Node<T> *e);       //删除e指向的元素 
	void show();             //显示线性表 
};

template <class T>
List<T>::List()
{
	length=0;
	head = new Node<T>();
}
template <class T>
List<T>::~List()
{
	clear();
	delete head;
}
template <class T>
void List<T>::clear()
{
	length=0;
	Node<T> *t;
	while (head->next){
		t=head->next;
		head->next=t->next;
		delete t;
	}
}
template <class T>
bool List<T>::empty()
{
	return !length;
}
template <class T>
int List<T>::size()
{
	return length;
}
template <class T>
Node<T> *List<T>::get(int pos)
{
	if (pos<=0||pos>length){
		return NULL;
	}
	Node<T> *p=head;
	for (int i=0;i<pos;++i)
		p=p->next;
	return p;
}
template <class T>
Node<T>* List<T>::locate(Node<T> e)
{
	Node<T> *p=head->next;
	for (;p;p=p->next){
		if (*p==e)
			return p;
	}
	return NULL;
}
template<class T>
Node<T>* List<T>::pre(Node<T> *e)
{
	Node<T> *p=head;
	while (p && p->next != e)
		p=p->next;
	if (p==head) return NULL;
	return p;
}
template <class T>
Node<T>* List<T>::next(Node<T> *e)
{
	return  e->next;
}
template <class T>
void List<T>::insert_pre(Node<T> e,Node<T> *cur)
{
	++length;
	Node<T> *p=head;
	while (p && p->next!=cur)
		p=p->next;
	Node<T> *t=new Node<T>(e);
	t->next=p->next;
	p->next=t;
}
template <class T>
void List<T>::insert(Node<T> e,int pos)
{
	Node<T> *p=head;
	for (int i=0;i+1<pos;++i)
		p=p->next;
	insert_next(e,p);
}
template <class T>
void List<T>::insert_next(Node<T> e,Node<T> *cur)
{
	++length;
	Node<T> *p=cur;
	Node<T> *t=new Node<T>(e);
	t->next=p->next;
	p->next=t;
}
template <class T>
Node<T> List<T>::del(Node<T> *e)
{
	Node<T> ret(*e);
	Node<T> *p=head;
	while (p && p->next!=e)
		p=p->next;
	p->next=e->next;
	delete e;
	--length;
	return ret;
}
template <class T>
void List<T>::show()
{
	Node<T> *p=head->next;
	for (;p;p=p->next)
		cout<<p->value<<" ";
	cout<<endl;
}
#endif












