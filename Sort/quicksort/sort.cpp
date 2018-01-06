/*********************************
Date: Thu Sep 21 13:13:36 CST 2017
*********************************/
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <sstream>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
int partition(int *a,int p,int q)
{
	int i=p-1;
	for (int j=p;j<=q;++j){
		if (a[j]<=a[q]){
			swap(a[++i],a[j]);
		}
	}
	return i;
}
void qsort(int *a,int p,int q)
{
	if (p<q){
		int t=partition(a,p,q);
		qsort(a,p,t-1);
		qsort(a,t+1,q);
	}
}
int a[100];
int main()
{
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>a[i];
	qsort(a,0,n-1);
	for (int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;


	return 0;
}
