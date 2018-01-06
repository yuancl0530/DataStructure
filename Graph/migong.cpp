#include <iostream>
#include <cstdio>
#include <cstring>
#include "queue.cpp"
#include "stack.cpp"
using namespace std;
#define N 100
int n,m;
int G[N][N];
const int dx[]={-1,0,1,0,-1};
const int dy[]={0 ,1,0,-1,0};
int vs[N][N];
struct Node 
{
	int x,y;
	Node (int x=0,int y=0):x(x),y(y){}
};
int from[N][N];
void Bfs()
{
	queue<Node>Q;
	Q.push(Node(0,0));
	bool flag=false;
	vs[0][0]=1;
	while (!Q.empty()){
		int x=Q.front().x;
		int y=Q.front().y;
		Q.pop();
		if (x==n-1 && y==m-1) {flag=true; break;}
		for (int i=1;i<=4;++i){
			int xx=x+dx[i];
			int yy=y+dy[i];
			if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
			if (vs[xx][yy]) continue;
			if (G[xx][yy]) continue;
			vs[xx][yy]=i;
			Q.push(Node(xx,yy));
		}
	}
	if (flag){
		stack<Node>S;
		S.push(Node(n-1,m-1));
		while (S.top().x || S.top().y){
			int x=S.top().x;
			int y=S.top().y;
			int xx=x+dx[(vs[x][y]+2)%4];
			int yy=y+dy[(vs[x][y]+2)%4];
			S.push(Node(xx,yy));
		}
		while (!S.empty()){
			cout<<S.top().x<<" "<<S.top().y<<endl;
			S.pop();
		}
	}
	else{
		cout<<"Error"<<endl;
	}
}
int main()
{
	cin>>n>>m;
	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j){
			cin>>G[i][j];
		}
	}
	Bfs();
	return 0;
}
