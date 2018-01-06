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
	int length;			//��ǰ���Ա�Ԫ�ص�����	
	int listsize;		//��ǰ���Ա�ĳ���
	int incrementsize;	//ÿ�����ӵĳ���
	void Increase();	//�ڴ��������
public:
	SqList(int listsize=LIST_INIT_SIZE,int incrementsize=LISTINCREMENT);//���캯����ʵ�����Ա�ĳ�ʼ������
	~SqList();					//����������ʵ�����Ա����ٲ���
	void ClearList();           //������Ա�
	bool ListEmety();			//�������Ա��Ƿ�Ϊ��
	int ListLength();			//�������Ա���
	T GetElem(int i);			//�������Ա��i��Ԫ��
	int LocateElem(T e);		//�������Ա��һ�γ���Ԫ��e��λ�ã���������Ԫ��e�򷵻�0
	T PriorElem(T cur_e);		//�������Ա��е�һ�γ���Ԫ��e�ĺ��
	T NextElem(T cur_e);		//�������Ա��е�һ�γ���Ԫ��e��ǰ��
	void ListInsert(int i,T e); //�����Ա��iλ����Ԫ��e
	T ListDelete(int i);		//ɾ�� ���Ա��е�i��Ԫ��
	void ListTraverse();		//��ʾ���Ա�
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