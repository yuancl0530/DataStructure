#ifndef SQLIST_H
#define SQLIST_H
const int LIST_INIT_SIZE = 10;
const int LISTINCREMENT = 10;
#include <iostream>
#include <cstring>
using namespace std;
template <class T>
class SqList
{
private:
	T *elem;
	int length;
	int listsize;
	int incrementsize;
	void Increase();
public:
	SqList(int listsize=LIST_INIT_SIZE,int incrementsize=LISTINCREMENT);
	~SqList();
	void ClearList();
	bool ListEmety();
	int ListLength();
	T GetElem(int i);
	int LocateElem(T e);
	T PriorElem(T cur_e);
	T NextElem(T cur_e);
	void ListInsert(int i,T e);
	T ListDelete(int i);
	void ListTraverse();
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
	memset(elem,0,sizeof (elem));
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
	int t=length-1;
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