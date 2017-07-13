#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
	Stack s;
	for (int i = 1;i < 10;i++)
		s.push(i);
	while (!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
		if (s.top() == 3)
			s.clear();
	}
}
