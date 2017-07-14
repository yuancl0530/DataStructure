#include "queue.h"
Queue::Queue()
{
	Front = new Node(-1);
	Back = new Node(-1,Front,0);
	Front->next = Back;
	cnt = 0;
}
Queue::~Queue()
{
	while (size()){
		pop();
	}
	delete Front;
	delete Back;
}
void Queue::push(int x)
{
	Node *t = new Node(x);
	Node *p = Back->prev;
	p->next = t;
	t->prev = p;
	t->next = Back;
	Back->prev = t;
	cnt++;
}
void Queue::pop()
{
	if (Front->next == Back)
		return ;
	Node *p = Front->next;
	Front->next = p->next;
	p->next->prev = Front;
	delete p;
	cnt--;
}
int Queue::size()
{
	return cnt;
}
int Queue::front()
{
	return Front->next->value;
}
int Queue::back()
{
	return Back->prev->value;
}
bool Queue::empty()
{
	return cnt == 0;
}
