#include "list.h"
#include <iostream>
using namespace std;
List::List()
{
	head = new Node;
	head->next = 0;
	cnt = 0;
}
List::~List()
{
	Node *t;
	while (head->next){
		t = head->next->next;
		cout<<"delete"<<head->next->value<<endl;
		delete head->next;
		head->next = t;
	}
	delete head;
}
void List::insert(int x,int pos)
{
	Node *t,*p;
	if (pos == -1)
		pos = cnt;
	p = head;
	for (int i = 0;i < pos;i++){
		p = p->next;
	}
	t = p->next;
	p->next = new Node(x,t);
	cnt++;
}
void List::show()
{
	Node *t = head->next;
	for (;t;t = t->next){
		cout<<t->value<<endl;
	}

}
void List::del(int pos)
{
	if (pos > cnt)
		pos = cnt;
	Node *t = head;
	Node *p;
	for (int i = 1;i < pos;i++)
		t = t->next;
	p = t->next;
	t->next = p->next;
	cnt--;
	delete p;
}
void List::delList()
{
	Node *t;
	while (head->next){
		t = head->next->next;
		cout<<"delete"<<head->next->value<<endl;
		delete head->next;
		head->next = t;
	}
	cnt = 0;
}
void List::sort()
{
	Node *q,*t,*n1,*n2;
	int count = cnt;
	while (count--){
		q = head;
		while (q->next->next){
			n1 = q->next;
			n2 = n1->next;
			if (*n2 < *n1){
				q->next = n2;
				n1->next = n2->next;
				n2->next = n1;
			}
			q = q->next;
		}
	}
}
bool List::empty()
{
	if (cnt)
		return false;
	else
		return true;
}
