/*
	利用堆优化dijkstra算法
	heap.cpp：堆实现源代码
	stack.cpp：栈实现的源代码
	vector.cpp：邻接链表实现的源代码
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include "heap.cpp"
#include "vector.cpp"
#include "stack.cpp"
using namespace std;
#define N 100
#define INF 0x7fffffff
struct Edge
{
    int u,v,w;
    Edge(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
};
struct Node
{
    int i,dis,from;
    Node(int i=0,int dis=INF,int from=0):i(i),dis(dis),from(from){}
    friend bool operator < (Node a,Node b)
    {
        return a.dis < b.dis;
    }
}node[N];
vector<Edge>E[N];

void dijkstra(int s)
{
    Heap<Node>H;
    H.push(Node(s,0,-1));
    while (!H.empty()){
        int u=H.top().i;
        int dis=H.top().dis;
        H.pop();
        for (int i=0;i<E[u].size();++i){
            int v=E[u][i].v;
            int w=E[u][i].w;
            if (dis+w < node[v].dis){
                node[v].dis=dis+w;
                node[v].from=u;
                H.push(node[v]);
            }
        }
    }
}
void path(int start,int end)
{
	int t=end;
	stack<int>S;
	do {
		S.push(t);
		t=node[t].from;
	}while (t != start);
	cout<<start;
	while (!S.empty()){
		cout<<"->"<<S.top();
		S.pop();
	}
	cout<<endl;
}
int main()
{
    int n,m,start,end;
	cout<<"请输入点的个数:";
    cin>>n;
	cout<<"请输入边的条数:";
	cin>>m;
    for (int i=0;i<N;++i)node[i].i=i;
    for (i=0;i<m;++i){
        int u,v,w;
		cout<<"请输入第"<<i+1<<"条边:"<<endl;
        cin>>u>>v>>w;
        E[u].push_back(Edge(u,v,w));
        E[v].push_back(Edge(v,u,w));
    }
	cout<<"请输入起点:";
	cin>>start;
	cout<<"请输入终点:";
	cin>>end;
    dijkstra(start);
    cout<<"最短路径的长度:"<<node[m].dis<<endl;
	cout<<"最短路径:"<<endl;
	path(start,end);
    return 0;
}
