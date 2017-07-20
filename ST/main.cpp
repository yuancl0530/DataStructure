#include <iostream>
#include <cstdio>
#include "s_tree.h"
using namespace std;
int main()
{
	int x;
	STree tree;
	while (scanf("%d",&x) !=EOF){
		tree.insert(x);
	}
	int t;
	cout<<tree.max()<<endl;
	cout<<tree.min()<<endl;
	tree.del(tree.min());
	tree.del(tree.max());
	cout<<tree.max()<<endl;
	cout<<tree.min()<<endl;

	return 0;
}
