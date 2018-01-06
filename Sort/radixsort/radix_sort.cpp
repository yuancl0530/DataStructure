/*********************************
Date: Thu Oct 26 16:11:46 CST 2017
Author: ycl
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
#define INFLL 0x7fffffffffffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
int f[]={1,10,100,1000,10000,100000,1000000};
int getRadix(int a,int i)
{
	return a/f[i-1]%10;
}
int cnt[maxn];
int a[maxn],b[maxn];
void radix(int *a,int *b,int n,int k)
{
	CL(cnt);
	for (int i=0;i<n;++i)
		++cnt[getRadix(a[i],k)];
	for (int i=1;i<10;++i)
		cnt[i]+=cnt[i-1];
	for (int i=n-1;i>=0;--i)
		b[--cnt[getRadix(a[i],k)]]=a[i];
}
void radixSort(int *a,int n)
{
	int i=1;
	while (i<=5){
		radix(a,b,n,i++);
		if (i<=5)
			radix(b,a,n,i++);
		else
			for (int i=0;i<n;++i)
				a[i]=b[i];
	}
}
int main()
{
	int n;
	cin>>n;
	for (int i=0;i<n;++i)
		cin>>a[i];
	radixSort(a,n);
	for (int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
