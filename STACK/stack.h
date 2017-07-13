#ifndef STACK_H
#define STACK_H
struct Node
{
	int value;
	Node *next;
	Node(int x=0,Node *n = 0)
	{
		value = x;
		next = n;
	}
};
class Stack
{
private:
	int cnt;
	Node *head;
	Node *Top;
public:
	Stack();
	~Stack();
	void pop();
	void push(int x);
	void clear();
	int top();
	bool empty();
};
#endif

