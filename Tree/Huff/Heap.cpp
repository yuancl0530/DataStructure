#include <iostream>
#include <cstdio>

using namespace std;
const int SIZE=100;
class heap
{
private:
	Node *d;
	int heapsize;
	int size;
	void heapfiy(int);
	void increase();
public:
	heap(int size=SIZE);
	~heap();
	void push(Node*);
	void pop();
	Node* top();
	bool empty(){return !heapsize;}
};

heap::heap(int size):size(size)
{
	d=new (Node*)[size];
	heapsize=0;
}

heap::~heap()
{
	delete d;
}
void heap::push(Node e)
{
	++heapsize;
	if (size==heapsize)
		increase();
	d[heapsize]=e;
	int t=heapsize/2;
	while (t>=1){
		heapfiy(t);
		t/=2;
	}
}
Node* heap::top()
{
	return d[1];
}
void heap::pop()
{
	d[1]=d[heapsize--];
	heapfiy(1);
}
void heap::heapfiy(int p)
{
	int l=2*p;
	int r=l+1;
	int m=p;
	if (l<=heapsize && *d[m]>*d[l])
		m=l;
	if (r<=heapsize && *d[m]>*d[r])
		m=r;
	if (m!=p){
		Node* tt=d[p];
		d[p]=d[m];
		d[m]=tt;
		heapfiy(m);
	}
}
void heap::increase()
{
	int t=2*heapsize;
	T *tmp=new (Node*)[t];
	for (int i=1;i<=heapsize;++i)
		tmp[i]=d[i];
	delete d;
	d=tmp;
	heapsize=t;
}
