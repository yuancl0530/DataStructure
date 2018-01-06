#include <iostream>
#include "vector.cpp"
using namespace std;

int main()
{
	vector<int> V;
	for (int i=0;i<110;++i)
		V.push_back(i);
	for (int i=0;i<V.size();++i)
		cout<<V[i]<<endl;
	return 0;
}
