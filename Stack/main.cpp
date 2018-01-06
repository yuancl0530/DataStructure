#include <iostream>
#include <cstdio>
#include "stack1.cpp"
using namespace std;

bool check(int *a,int *b,int n)
{
	stack<int>S;
	int j=0;
	for (int i=0;i<n;++i){
		S.push(a[i]);
		while (!S.empty()&&b[j]==S.top()){
			S.pop();
			++j;
		}
	}
	if (S.empty())
		return true;
	return false;
}
int a[100],b[100];
int main()
{
	int n;
	cin>>n;
	for (int i=0;i<n;++i)
		cin>>a[i];
	for (int i=0;i<n;++i)
		cin>>b[i];
	if (check(a,b,n))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
