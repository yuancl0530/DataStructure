#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
template <class T>
struct Node
{
	T date;
	Node *left,*right;
	Node(){left=right=NULL;}
};
template <class T>
class set
{
private:
	Node<T> *root;
public:
	set(){root=NULL;};
	void insert(T);
	
}
int main()
{


	return 0;
}
