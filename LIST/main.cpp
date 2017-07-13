#include <iostream>
#include "list.h"
using namespace std;
int main()
{
	List list;
	for (int i = 10;i;i--){
		list.insert(i);
	}
	list.sort();
	list.show();
	return 0;
}
