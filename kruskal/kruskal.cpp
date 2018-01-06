#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100
int father[N];
int n,m;
int find_father(int t)
{
	if (t==father[t])
		return t;
	return father[t]=find_father(father[t]);
}
template <class T>
int partiton(T *a,int l,int r)
{
	int m=l-1;
	for (int i=l;i<=r;++i)
		if (a[i]<=a[r])
			swap(a[i],a[++m]);
	return m;
}
template <class T>
void quick_sort(T *a,int l,int r)
{
	if (l<r){
		int m=partiton(a,l,r);
		quick_sort(a,l,m-1);
		quick_sort(a,m+1,r);
	}
}
struct Edge
{
	int u,v;
	int w;
	Edge(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
	friend bool operator <= (Edge a,Edge b) {return a.w <= b.w; }
}E[N];
void kruskal()
{
	int ret=0;
	quick_sort(E,0,m-1);
	cout<<"保留的边有:"<<endl;
	for (int i=0;i<m;++i){
		int n1=find_father(E[i].u);
		int n2=find_father(E[i].v);
		if (n1!=n2){
			father[n1]=father[n2];
			cout<<E[i].u<<" "<<E[i].v<<endl;
			ret+=E[i].w;
		}
	}
	cout<<"总权值为:"<<ret<<endl;
}
int main()
{
	cout<<"请输入点的个数:";
	cin>>n;
	cout<<"请输入边的条数:";
	cin>>m;
	for (int i=1;i<=n;++i)
		father[i]=i;
	for (i=0;i<m;++i)
		cin>>E[i].u>>E[i].v>>E[i].w;
	kruskal();
	return 0;
}


