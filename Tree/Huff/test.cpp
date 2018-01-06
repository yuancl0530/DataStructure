#include <iostream>
#include "Heap.cpp"
using namespace std;

int main()
{
	int n,t,op;
	heap<int> H;
	cin>>n;
	while (n--){
		cin>>op;
		if (op==0){
			cin>>t;
			H.push(t);
		}
		else 
			H.pop();
		cout<<H.top()<<endl;
	}
	return 0;
}
