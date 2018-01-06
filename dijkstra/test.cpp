#include <iostream>
#include "heap.cpp"
using namespace std;

int main()
{
    Heap<int> H;
    for (int i=1000;i>0;--i){
        H.push(i);
    }
    for (int i=0;i<10;++i){
        cout<<H.top()<<endl;
        H.pop();
    }
    return 0;
}
