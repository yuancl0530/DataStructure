#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100
#define SIZE 100
struct Node
{
	int w;
	int id;
	Node *left,*right;
	Node(int w=0,Node *l=0,Node *r=0,int id=-1):id(id),w(w),left(l),right(r){}
	friend bool operator < (Node a,Node b)
	{
		return a.w < b.w;
	}
};
class heap
{
private:
	Node **d;
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
;
int w[N],t[N];
char code[N][N];
char ch[N][N];

Node *createHuffTree(int *w,int n)
{
	heap H;
	for (int i=0;i<n;++i){
		Node *tmp=new Node (w[i],0,0,i);
		H.push(tmp);
	}
	while (!H.empty()){
		Node* t1=H.top();
		H.pop();
		if (H.empty()) return t1;
		Node* t2=H.top();
		H.pop();
		Node *tmp= new Node (t1->w+t2->w,t1,t2);
		H.push(tmp);
	}
	return NULL;
}
void CodeHuff(Node *root,int n=0)
{
	if (root->id==-1){
		t[n]=0;
		CodeHuff(root->left,n+1);
		t[n]=1;
		CodeHuff(root->right,n+1);
	}
	else{
		for (int i=0;i<n;++i)
			code[root->id][i]='0'+t[i];
		code[root->id][n]=0;
	}
}
int main()
{	
	int n;
	cout<<"请输入点的个数"<<endl;
	cin>>n;
	int i;
	for (i=0;i<n;++i){
		cout<<"请输入第"<<i+1<<"个点名称"<<endl;
		cin>>ch[i];
		cout<<"请输入第"<<i+1<<"个点权值"<<endl;
		cin>>w[i];
	}
	Node *huff=createHuffTree(w,n);
	CodeHuff(huff);
	cout<<"哈弗曼编码为:"<<endl;
	for (i=0;i<n;++i)
		cout<<ch[i]<<":"<<code[i]<<endl;
	return 0;
}

heap::heap(int size):size(size)
{
	d=new Node*[size];
	heapsize=0;
}

heap::~heap()
{
	delete d;
}
void heap::push(Node *e)
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
	if (l<=heapsize && d[m]->w > d[l]->w)
		m=l;
	if (r<=heapsize && d[m]->w > d[r]->w)
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
	Node **tmp=new Node*[t];
	for (int i=1;i<=heapsize;++i)
		tmp[i]=d[i];
	delete d;
	d=tmp;
	heapsize=t;
}
