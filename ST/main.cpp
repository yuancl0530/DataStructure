#include <iostream>
#include <cstdio>
#include "s_tree.h"
using namespace std;
int main()
{
	int x;
	STree tree;
	while (scanf("%d",&x) != EOF){
		tree.insert(x);
	}
	int t;
	cout<<tree.max()<<endl;
	cout<<tree.min()<<endl;
	t=tree.max();
	cout<<t<<endl;
	cout<<p->value<<endl;
	return 0;
}
