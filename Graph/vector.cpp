#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define SIZE 100
#define INSIZE 10
template <class T>
class vector
{
private:
	T *d;
	int Size;
	int len;
	void increase();
public:
	vector();
	~vector();
	void push_back(T);
	int size();
	T operator [](int);
};
template <class T>
vector<T>::vector()
{
	len=SIZE;
	d=new T[len];
	Size=0;
}
template <class T>
vector<T>::~vector()
{
	delete d;
}
template <class T>
void vector<T>::increase()
{
	T *t=new T[len+INSIZE];
	for (int i=0;i<len;++i)
		t[i]=d[i];
	len+=INSIZE;
	delete d;
	d=t;
}
template <class T>
void vector<T>::push_back(T e)
{
	if (Size==len)
		increase();
	d[Size++]=e;
}
template <class T>
int vector<T>::size()
{
	return Size;
}
template <class T>
T vector<T>::operator [](int i)
{
	return d[i];
}

