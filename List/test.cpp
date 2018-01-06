#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

#define HEAD 0    //有头结点 1， 无头结点 0
#if HEAD==0
#include "2016210794_袁丞蕾_线性表(链式无头结点).cpp"
#else
#include "2016210794_袁丞蕾_线性表(链式有头结点).cpp"
#endif
int main()
{
	srand((int)time(0));
	List<int> *p=new List<int>;
	int pos,value;
	for (int i=1;i<=10;++i){
		pos=rand()%(p->size()+1);
		if (!pos)++pos;
		value=rand()%1000;
		cout<<"insert "<<value<<" at "<<pos<<endl;
		p->insert(Node<int>(value,0),pos);
	}
	p->show();
	pos=rand()%9+2;
	if (pos==10)--pos;
	Node<int> *t=p->get(pos);
	cout<<"the No."<<pos<<" elem is:"<<t->value<<endl;
	t=p->locate(Node<int>(t->value));
	Node<int>*k=t;
	k=p->pre(t);
	cout<<"the elem before "<<t->value<<" is "<<k->value<<endl;
	k=p->next(t);
	cout<<"the elem after "<<t->value<<" is "<<k->value<<endl;
	value=rand();
	cout<<"insert "<<value<<" before "<<t->value<<endl;
	p->insert_pre(Node<int>(value),t);
	value=rand();
	cout<<"insert "<<value<<" after "<<t->value<<endl;
	p->insert_next(Node<int>(value),t);
	cout<<"after insert:"<<endl;
	p->show();
	cout<<"delete "<<t->value<<endl;
	p->del(t);
	cout<<"after delete:"<<endl;
	p->show();
	cout<<"the size of list:";
	cout<<p->size()<<endl;
	p->clear();
	delete p;
	return 0;
}
