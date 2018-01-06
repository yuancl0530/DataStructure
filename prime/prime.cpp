#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define N 1000
#define INF 1<<30
bool vs[N];
int dis[N];
int G[N][N];
int from[N];
int n,m;
void Init()
{
    for (int i=0;i<N;++i){
        dis[i] = INF;
        for (int j=0;j<N;++j)
            G[i][j] = INF;
    }
    CL(vs);
}
int prime(int s=0)
{
    int ret=0;
    dis[s]=0;
    vs[s]=true;
    for (int i=0;i<n;++i)
        if (i!=s)dis[i] = G[s][i];
    for (int cnt=1;cnt<n;++cnt){
        int Min = INF;
        for (int i=0;i<n;++i)
            if (!vs[i] && dis[i] < Min){
                Min = dis[i];
                from[i]=s;
                s=i;
            }
        vs[s]=true;
        ret+=dis[s];
        cout<<s<<" "<<from[s]<<endl;
        for (int i=0;i<n;++i)
            if (!vs[i] && dis[i]>G[s][i])
                dis[i]=G[s][i];
    }
    return ret;
}

int main()
{
    Init();
    int u,v,w;
    cin>>n>>m;
    for (int i=0;i<m;++i){
        cin>>u>>v>>w;
        G[u][v]=w;
        G[v][u]=w;
    }
    int cost = prime();
    cout<<cost<<endl;
    return 0;
}
