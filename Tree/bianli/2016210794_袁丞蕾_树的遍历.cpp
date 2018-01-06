#include <iostream>
#include <cstdio>
#include <cstring>
#include "queue.cpp"
using namespace std;
#define N 100
char s[N];
struct Node
{
	char ch;
	Node *left;
	Node *right;
	Node(char ch=0,Node *left=NULL,Node *right=NULL):ch(ch),left(left),right(right){}
};
Node* BuildTree()
{
	static int i=0;
	if (s[i]!='#' && s[i]){
		Node *t=new Node(s[i]);
		++i;
		t->left=BuildTree();
		t->right=BuildTree();
		return t;
	}
	else{
		++i;
		return NULL;
	}
}
void Last(Node *root)
{
	if (!root) return ;
	Last(root->left);
	Last(root->right);
	cout<<root->ch;
}
void Mid(Node *root)
{
	if (!root) return ;
	Mid(root->left);
	cout<<root->ch;
	Mid(root->right);
}
void Ceng(Node *root)
{
	queue<Node*>Q;
	Q.push(root);
	while (!Q.empty()){
		Node *t=Q.front();
		Q.pop();
		cout<<t->ch;
		if (t->left) Q.push(t->left);
		if (t->right) Q.push(t->right);
	}
}
int main()
{
	cout<<"��������������ַ���"<<endl;
	cin>>s;
	Node *t=BuildTree();
	cout<<"�������"<<endl;
	Last(t);
	cout<<endl;
	cout<<"�������"<<endl;
	Mid(t);
	cout<<endl;
	cout<<"��α���"<<endl;
	Ceng(t);
	cout<<endl;
	return 0;
}
