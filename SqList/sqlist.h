#ifndef SQLIST_H
#define SQLIST_H
const int LIST_INIT_SIZE = 10;
const int LISTINCREMENT = 10;
template <class T>
class SqList
{
private:
	T *elem;
	int length;
	int listsize;
	int incrementsize;
	void Increase();
public:
	SqList(int listsize=LIST_INIT_SIZE,int incrementsize=LISTINCREMENT);
	~SqList();
	void ClearList();
	bool ListEmety();
	int ListLength();
	T GetElem(int i);
	int LocateElem(T e);
	T PriorElem(T cur_e);
	T NextElem(T cur_e);
	void ListInsert(int i,T e);
	T ListDelete(int i);
	void ListTraverse();
};
#include "sqlist.cpp"
#endif 
