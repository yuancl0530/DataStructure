#ifndef S_TREE_H
#define S_TREE_H
struct Node 
{
	int value;
	Node *father;
	Node *left;
	Node *right;
	Node(int x,Node *f=0,Node* r=0,Node *l=0)
	{
		value = x;
		father = f;
		left = l;
		right = r;
	}
};
class STree
{
private:
	Node *ROOT;
public:
	STree();
	~STree();
	void del(Node *p);
	int max();
	int max(Node *root);
	int min();
	int min(Node *root);
	void insert(int x);
	void insert_(int x,Node *root);
	Node *find(int x);
};
#endif
