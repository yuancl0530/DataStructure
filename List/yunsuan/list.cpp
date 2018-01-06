#ifndef SQLIST_CPP
#define SQLIST_CPP

#include <iostream>
#include <string.h>
using namespace std;
const int LIST_INIT_SIZE = 15;
const int LISTINCREMENT = 10;
template <class T>
class SqList
{
private:
	T *elem;
	int length;			//当前线性表元素的数量	
	int listsize;		//当前线性表的长度
	int incrementsize;	//每次增加的长度
	void Increase();	//内存调整函数
public:
	SqList(int listsize=LIST_INIT_SIZE,int incrementsize=LISTINCREMENT);//构造函数，实现线性表的初始化操作
	~SqList();					//析构函数，实现线性表销毁操作
	void ClearList();           //清空线性表
	bool ListEmety();			//返回线性表是否为空
	int ListLength();			//返回线性表长度
	T GetElem(int i);			//返回线性表第i个元素
	int LocateElem(T e);		//返回线性表第一次出现元素e的位置，若不存在元素e则返回0
	T PriorElem(T cur_e);		//返回线性表中第一次出现元素e的后继
	T NextElem(T cur_e);		//返回线性表中第一次出现元素e的前驱
	void ListInsert(int i,T e); //在线性表第i位插入元素e
	T ListDelete(int i);		//删除 线性表中第i个元素
	void ListTraverse();		//显示线性表
};


template <class T> 
SqList<T>::SqList(int listsize,int incrementsize)
{
	this->listsize=listsize;
	this->incrementsize=incrementsize;
	this->length=0;
	elem=new T[listsize];
}
template <class T>
SqList<T>::~SqList()
{
	T *t=elem;
	delete []t;
}
template <class T>
void SqList<T>::ClearList()
{
	length=0;
	memset(elem,0,sizeof(elem));
}
template <class T>
bool SqList<T>::ListEmety()
{
	return !length;
}
template <class T>
int SqList<T>::ListLength()
{
	return length;
}
template <class T>
T SqList<T>::GetElem(int i)
{
	if (i<=0 || i>length){
		cout<<"Error! Can't find the "<<i<<(i%10==1? "st":i%10==2? "nd":"th")<<" elem"<<endl;
		return 0;
	}
	return elem[i-1];
}

template <class T>
int SqList<T>::LocateElem(T e)
{
	for (int i=0;i<length;++i)
		if (e==elem[i])
			return i+1;
	return 0;
}
template <class T>
T SqList<T>::PriorElem(T cur_e)
{
	int t=LocateElem(cur_e)-1;
	if (t<=0 || t>length) {cout<<"Cant find!"<<endl;return 0;}
	return elem[t-1];
}
template <class T>
T SqList<T>::NextElem(T cur_e)
{
	int t=LocateElem(cur_e);
	++t;
	if (t==1||t>length){cout<<"Can't find!"<<endl;return 0;}
	return elem[t-1];
}
template <class T>
void SqList<T>::ListInsert(int i,T e)
{
	if (i<=0 || i>length+1) {cout<<"error"<<endl; return ;}
	if (length==listsize) Increase();
	int t=length;
	--i;
	for (;t>i;--t)
		elem[t]=elem[t-1];
	elem[i]=e;
	++length;
}
template <class T>
T SqList<T>::ListDelete(int i)
{
	if (i<=0||i>length){cout<<"Error! Can't find the "<<i<<(i%10==1? "st":i%10==2? "nd":"th")<<" elem"<<endl;return 0;}
	T ret=elem[--i];
	for (int t=i;t<length-1;++t)
		elem[t]=elem[t+1];
	--length;
	return ret;
}
template <class T>
void SqList<T>::ListTraverse()
{
	for (int i=0;i<length;++i)
		cout<<elem[i]<<" ";
	cout<<endl;
}
template <class T>
void SqList<T>::Increase()
{
	T *t=elem;
	int tmp=length;
	elem = new T[length+incrementsize];
	for (int i=0;i<length;++i)
		elem[i]=t[i];
	listsize+=incrementsize;
	delete []t;
}

#endif 