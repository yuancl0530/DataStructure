#include "s_tree.h"
#include <iostream>
STree::STree()
{
	ROOT = 0;
}
STree::~STree()
{
	if (ROOT)
		consture(ROOT);
	
}
void STree::consture(Node *p)
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
		ROOT = new Node(x,0);
		if (!ROOT){
			std::cout<<"No space"<<std::endl;
			return ;
		}
	}
	else {
		if (x < root->value){
			if (!root->left){
				root->left = new Node(x,root);
			}
			else{
				insert_(x,root->left);
			}
		}
		else{
			if (!root->right){
				root->right = new Node(x,root);
			}
			else{
				insert_(x,root->right);
			}
		}
	}
}
int STree::max()
{
	if (!ROOT){
		std::cout<<"no root"<<std::endl;
		return -1;
	}
	return 	max(ROOT)->value;
}
Node* STree::max(Node * root)
{
	if (root->right == 0)
		return root;
	else
		return max(root->right);
}
int STree::min()
{
	if (!ROOT){
		std::cout<<"no root"<<std::endl;
		return -1;
	}
	return min(ROOT)->value;
}
Node* STree::min(Node * root)
{
	if (root->left == 0)
		return root;
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
void STree::del(int x)
{	Node *k;
	while (k = find(x)){
		del(k);
	}
}
void STree::del(Node *p)
{
	if (!p)
		return;
	if (p == ROOT){
		Node *temp = min(ROOT->right);
		ROOT->value = temp->value;
		del(temp);
		return;
	}
	Node **t;
	if (p->father->left && p->father->left->value == p->value){
		t = &(p->father->left);
	}
	else{
		t = &(p->father->right);
	}
	if (!(p->left || p->right)){
		*t = 0;
		delete p;
	}
	else if (p->left && !p->right){
		*t = p->left;
		p->left->father = p->father;
		delete p;
	}
	else if (p->right && !p->left){
		*t = p->right;
		p->right->father = p->father;
		delete p;
	}
	else {
		Node *temp = min(p->right);
		p->value = temp->value;
		del(temp);
	}
}
