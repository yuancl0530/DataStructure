#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define QUEUE_INIT_SIZE 1
#define QUEUE_INCREMENT_SIZE 1
template<class T>
class queue
{
private:
	T *elem;
	int Front;
	int Rear;
	int size;
	int incrementsize;
	void IncreaseMem();
public:
	queue(int size=QUEUE_INIT_SIZE,int insize=QUEUE_INCREMENT_SIZE);
	~queue();
	bool empty();
	T front();
	T pop();
	void push(T);
};
template<class T>
queue<T>::queue(int size,int insize):size(size),incrementsize(insize)
{
	Front=Rear=0;
	elem=new T[size];
}
template<class T>
queue<T>::~queue()
{
	Front=Rear=0;
	delete elem;
}
template<class T>
bool queue<T>::empty()
{
	return Front==Rear;
}
template<class T>
T queue<T>::front()
{
	if (empty()){
		cout<<"error,the queue is empty"<<endl;
		exit(-1);
	}
	return elem[Front];
}
template<class T>
void queue<T>::push(T e)
{
	if ((Rear+1)%size==Front)
		IncreaseMem();
	elem[Rear]=e;
	Rear=(Rear+1)%size;
}
template<class T>
T queue<T>::pop()
{
	if (empty()){
		cout<<"error,the queue is empty"<<endl;
		exit(-1);
	}
	int t=Front;
	Front=(Front+1)%size;
	return elem[t];
}
template<class T>
void queue<T>::IncreaseMem()
{
	T *t=new T[size+incrementsize];
	int i=Front;
	for (int j=0;(i+1)%size!=Front;i=(i+1)%size,++j){
		t[j]=elem[i];
	}
	Front=0;
	Rear=size-1;
	size+=incrementsize;
	delete elem;
	elem=t;
}
