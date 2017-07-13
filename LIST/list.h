#ifndef LIST_H
#define LIST_H
struct Node
{
	int value;
	Node *next;
	Node(int v = 0,Node *n = 0){
		value = v;
		next = n;
	}
	bool operator < (Node a){
		return value < a.value;
	}
};
class List
{
private:
	Node *head;
	int cnt;
public:
	List();
	~List();
	void insert(int x,int pos = -1);
	void show();
	void del(int pos);
	void delList();
	void sort();
	bool empty();
};
#endif 
