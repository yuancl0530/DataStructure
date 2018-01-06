#include <iostream>
#include <cstring>
#include "list.cpp"
using namespace std;
void read(SqList<int> &L)
{
	int a;
	while (scanf("%d",&a) || getchar()!='#')
		L.ListInsert(L.ListLength()+1,a);
}

void Union(SqList<int> &A,SqList<int> &B,SqList<int> &C)
{
	int i;
  	for (i=1;i<=A.ListLength();++i)
		if (!C.LocateElem(A.GetElem(i)))
			C.ListInsert(C.ListLength()+1,A.GetElem(i));
	for (i=1;i<=B.ListLength();++i)
		if (!C.Locat	SqList<int> C;
	Union(A,B,C);
	printf("A集合与B集合的并集\n");
	C.ListTraverse();
eElem(B.GetElem(i)))
			C.ListInsert(C.ListLength()+1,B.GetElem(i));
}
void jiaoji(SqList &A,SqList &B,SqList &C)
{
	for (int i=1;i<=A.ListLength();++i){
		if (B.LocateElem(A.GetElem(i))){
			C.ListInsert(C.ListLength()+1,A.GetElem(i));
		}
	}
}
void chaji(SqList &A,SqList &B,SqList &C)
{
	for (int i=1;i<=A.ListLength();++i){
		if (!B.LocateElem(A.GetElem(i))){
			C.ListInsert(C.ListLength()+1,A.GetElem(i));
		}
	}
int main()
{
	SqList<int> A,B;
	printf("请输入集合A，输入#结束\n");
	read(A);
	printf("请输入集合B，输入#结束\n");
	read(B);
	SqList<int> D;
	Union(A,B,D);
	printf("A集合与B集合的并集\n");
	C.ListTraverse();

	SqList<int> E;
	Union(A,B,E);
	printf("A集合与B集合的并集\n");
	C.ListTraverse();
	return 0;
}
