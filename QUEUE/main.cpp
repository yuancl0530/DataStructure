#include <iostream>
#include "queue.h"
using namespace std;

int main()
{
	Queue q;
	for (int i = 1;i <= 10;i++){
		q.push(i);
		cout<<q.back()<<endl;
	}
	int i = 5;
	while (!q.empty()){
		cout<<q.front()<<endl;
		q.pop();
	}
	return 0;
}
