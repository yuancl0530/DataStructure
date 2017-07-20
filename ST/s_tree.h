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
	void consture(Node *p);
	void insert_(int x,Node *root);
	Node* max(Node *root);
	Node* min(Node *root);
	void del(Node *p);
public:
	STree();
	~STree();
	int max();
	int min();
	void insert(int x);
	Node *find(int x);
	void del(int x);
};
#endif
