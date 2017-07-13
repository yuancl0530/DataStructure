#include "stack.h"
Stack::Stack()
{
	head = new Node(0,0);
	Top = head;
	cnt = 0;
}

void Stack::push(int x)
{
	Top = new Node(x,Top);
	cnt++;
}
void Stack::pop()
{
	if (!cnt)
		return;
	Node *t = Top;
	Top = Top->next;
	cnt--;
	delete t;
}
int Stack::top()
{
	return Top->value;
}
Stack::~Stack()
{
	while (cnt)
		pop();
	delete head;
}
void Stack::clear()
{
	while (cnt)
		pop();
}
bool Stack::empty()
{
	return !cnt;
}
