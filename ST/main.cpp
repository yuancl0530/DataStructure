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
	int n = 10;
	while (tree.min() != -1){
		tree.del(tree.min());
	
	}
	return 0;
}
