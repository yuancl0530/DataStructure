#ifndef _HEAP_CPP
#define _HEAP_CPP
#define SIZE 100
template <class T>
class Heap
{
private:
    T *d;
    int HeapSize;
    int memsize;
    void heapify(int);
    void increasemen();
public:
    Heap();
    ~Heap();
    void push(T);
    T top();
    void pop();
    bool empty();
};
template<class T>
void Heap<T>::heapify(int i)
{
    int l=2*i;
    int r=l+1;
    int Max=i;
    if (l<=HeapSize && d[l]<d[Max]) Max=l;
    if (r<=HeapSize && d[r]<d[Max]) Max=r;
    if (Max != i){
        T tmp = d[i];
        d[i]=d[Max];
        d[Max]=tmp;
        heapify(Max);
    }
}
template <class T>
Heap<T>::Heap()
{
    d=new T[SIZE];
    HeapSize=0;
    memsize=SIZE;
}
template <class T>
Heap<T>::~Heap()
{
    delete d;
}
template<class T>
T Heap<T>::top()
{
    return d[1];
}
template <class T>
void Heap<T>::push(T e)
{
    if (HeapSize+1 == memsize)
        increasemen();
    d[++HeapSize]=e;
    int t=HeapSize;
    while (t>=1){
        heapify(t);
        t>>=1;
    }
}
template<class T>
void Heap<T>::pop()
{
    d[1]=d[HeapSize--];
    heapify(1);
}
template <class T>
void Heap<T>::increasemen()
{
    T *tmp=new T[2*memsize];
    for (int i=1;i<memsize;++i){
        tmp[i]=d[i];
    }
    delete d;
    memsize<<=1;
    d=tmp;
}
template <class T>
bool Heap<T>::empty()
{
    return HeapSize == 0;
}
#endif
