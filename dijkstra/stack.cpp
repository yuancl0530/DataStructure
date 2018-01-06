#include <iostream>
using namespace std;
const int STACK_INIT_SIZE=1;
const int STACKINCREMENT=1;
template<class T>
class stack
{
private:
	T *elem;
	int Top;
	int stacksize;
	int incrementsize;
	void increaseMem();
public:
	stack(int size=STACK_INIT_SIZE,int increasesize=STACKINCREMENT);
	~stack();
	void clear();
	bool empty();
	int size();
	T top();
	void push(T);
	T pop();
	void traverse();
};
template<class T>
T stack<T>::top()
{
	return elem[Top];
}

template<class T>
void stack<T>::increaseMem()
{
	T * t=new T[stacksize+=incrementsize];
	for (int i=0;i<=Top;++i)
		t[i]=elem[i];
	delete []elem;
	elem =t;
}
template<class T>
stack<T>::stack(int size,int increasesize)
{
	stacksize=size;
	incrementsize=increasesize;
	Top=-1;
	elem = new T[stacksize];
}
template<class T>
stack<T>::~stack()
{
	Top=-1;
	delete []elem;
}
template<class T>
void stack<T>::clear()
{
	Top=-1;
}
template<class T>
bool stack<T>::empty()
{
	return !(Top+1);
}
template<class T>
int stack<T>::size()
{
	return Top+1;
}
template<class T>
void stack<T>::push(T e)
{
	if (Top+1==stacksize)
		increaseMem();
	elem[++Top]=e;
}
template<class T>
T stack<T>::pop()
{
	return elem[Top--];
}
template<class T>
void stack<T>::traverse()
{
	for (int i=Top;i>=0;--i)
		cout<<elem[i]<<" ";
	cout<<endl;
}

