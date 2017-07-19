#include "s_tree.h"
#include <iostream>
STree::STree()
{
	ROOT = 0;
}
STree::~STree()
{
	if (ROOT)del(ROOT);
}
void STree::del(Node *p)
{
	static int x = 0;
	if (p->left)
		del(p->left);
	if (p->right)
		del(p->right);
	delete p;
}
void STree::insert(int x)
{
	insert_(x,ROOT);
}
void STree::insert_(int x,Node *root)
{
	if (ROOT == 0){
		ROOT = new Node(x);
		if (!ROOT){
			std::cout<<"No space"<<std::endl;
			return ;
		}
	}
	else {
		if (x < root->value){
			if(!root->left ||x > root->left->value){
				Node *p = root->left;
				root->left = new Node(x,root);
				root->left->left = p;
			}
			else insert_(x,root->left);
		}
		else{
			if(!root->right||x < root->right->value){
				Node *p = root->right;
				root->right = new Node(x,root);
				root->right->right = p;
			}
			else insert_(x,root->right);

		}
	}
}
int STree::max()
{
	if (!ROOT){
		std::cout<<"no root"<<std::endl;
		return -1;
	}
	max(ROOT);
}
int STree::max(Node * root)
{
	if (root->right == 0)
		return root->value;
	else
		return max(root->right);
}
int STree::min()
{
	if (!ROOT){
		std::cout<<"no root"<<std::endl;
		return -1;
	}
	min(ROOT);
}
int STree::min(Node * root)
{
	if (root->left == 0)
		return root->value;
	else
		return min(root->left);
}
Node *STree::find(int x)
{
	Node *p = ROOT;
	if (!p)
		return 0;
	while (p){
		if (p->value==x){
			return p;
		}
		else if (x < p->value)
			p=p->left;
		else 
			p=p->right;
	}
	return 0;
}
