/*
	���ö��Ż�dijkstra�㷨
	heap.cpp����ʵ��Դ����
	stack.cpp��ջʵ�ֵ�Դ����
	vector.cpp���ڽ�����ʵ�ֵ�Դ����
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
	cout<<"�������ĸ���:";
    cin>>n;
	cout<<"������ߵ�����:";
	cin>>m;
    for (int i=0;i<N;++i)node[i].i=i;
    for (i=0;i<m;++i){
        int u,v,w;
		cout<<"�������"<<i+1<<"����:"<<endl;
        cin>>u>>v>>w;
        E[u].push_back(Edge(u,v,w));
        E[v].push_back(Edge(v,u,w));
    }
	cout<<"���������:";
	cin>>start;
	cout<<"�������յ�:";
	cin>>end;
    dijkstra(start);
    cout<<"���·���ĳ���:"<<node[m].dis<<endl;
	cout<<"���·��:"<<endl;
	path(start,end);
    return 0;
}
