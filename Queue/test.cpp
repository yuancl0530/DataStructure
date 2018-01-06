#include <iostream>
#include <cstdio>
#include <cstring>
#include "queue.cpp"
using namespace std;
int main()
{
	queue<int>Q;
	for (int i=0;i<=10;++i)
		Q.push(i);
	for (int i=0;i<5;++i)
		Q.pop();
	for (int i=0;i<5;++i)
		Q.push(i);
	while (!Q.empty()){
		cout<<Q.front()<<" ";
		Q.pop();
	}
	cout<<endl;
	return 0;
}
