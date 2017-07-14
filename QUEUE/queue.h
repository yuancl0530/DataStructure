#ifndef QUEUE_H
#define QUEUE_H
struct Node
{
	int value;
	Node *prev;
	Node *next;
	Node(int x ,Node *p = 0,Node *n = 0)
	{
		value  = x;
		prev = p;
		next = n;
	}
};
class Queue
{
private:
	Node *Front;
	Node *Back;
	int cnt;
public:
	Queue();
	~Queue();
	void push(int x);
	void pop();
	int size();
	int front();
	int back();
	bool empty();
};
#endif
