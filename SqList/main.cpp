#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include "sqlist.h"

using namespace std;
#define CL(a) memset(a,0,sizeof (a)) 
#define Cl(a,b) memset(a,b,sizeof (a)) 
#define INF 0x7fffffff
int main()
{
	SqList<float> *L =new SqList<float>;
	int i;
	cout<<L->ListLength()<<endl;
	for (i=0;i<100;i++){
		L->ListInsert(i+1,i);
	}
	L->ListTraverse();
	cout<<L->ListLength()<<endl;
	cout<<L->GetElem(5)<<endl;
	cout<<L->LocateElem(9)<<endl;
	cout<<L->PriorElem(7)<<endl;
	cout<<L->NextElem(99)<<endl;
	for (i=1;i<20;i++)
		L->ListDelete(i);
	cout<<L->ListLength()<<endl;
	L->ClearList();
	delete L;
	return 0;
}

