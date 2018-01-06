#include <iostream>
#include <cstdio>
#include <cstring>
#include "vector.cpp"
#include "queue.cpp"
using namespace std;
#define N 100
#define CL(a) memset(a,0,sizeof a)
int G[N][N];
vector<int> E[N];
int vs[N];
int n,m;
void dfs(int u)
{
	cout<<u<<endl;
	vs[u]=1;
	for (int i=0;i<n;++i)
		if (G[u][i] && !vs[i])
			dfs(i);
}
void bfs(int u)
{	
	CL(vs);
	queue<int>Q;
	Q.push(u);
	vs[u]=true;
	while (!Q.empty()){
		u=Q.front();
		cout<<u<<endl;
		Q.pop();
		for (int i=0;i<E[u].size();++i){
			int v=E[u][i];
			if (!vs[v]){
				vs[v]=true;
				Q.push(v);
			}	
		}
	}
}
int main()
{
	cin>>n>>m;
	int u,v;
	for (int i=0;i<m;++i){
		cin>>u>>v;
		G[u][v]=1;
		G[v][u]=1;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	cout<<"dfs:"<<endl;
	dfs(0);
	cout<<"bfs:"<<endl;
	bfs(0);
	return 0;
}
