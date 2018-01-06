#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype> //isdigit(char) 如果char是数字返回真，否则返回假
#include "stack.cpp"
/*
stack<数据类型T>S;//实例化一个栈
S.pop();//栈顶元素出栈
S.push(T e); //e进栈
S.empty(); //栈空返回真，否则返回假

*/
using namespace std;
#define N 500
char s[N];
struct Node //二元组
{
    int type;//类型    0 数字(v:数字的值) 1运算符(v:0+,1-,2*,3/,4^) 2括号(v:0左括号 1右括号)
    int v;   //值
    Node (int t=0,int v=0):type(t),v(v){}
}E[N],SU[N];//E中缀表达式转化成二元组，SU后缀表达式转化成的二元组

int getE(char *s);//求中缀二元组,返回数量
int getSU(int );//求后缀二元组，返回数量
int cal(char *s);//计算
int Qpow(int,int);
int stoi(char *,int ,int );//把字符串[l,r]区间转化成数字
int main()
{
    scanf("%s",s);
    printf("%d\n",cal(s));
    return 0;
}
int stoi(char *s,int l,int r)
{
    int ret=0;
    for (int i=l;i<=r;++i){
        ret=ret*10+s[i]-'0';
    }
    return ret;
}
int getE(char *s)
{
    int cnt=0;
    int l;
    int len=strlen(s);
    for (int i=0;i<len;++i){
        if (isdigit(s[i])){
            l=i;
            while (isdigit(s[i+1])) ++i;
            E[cnt].type=0;
            E[cnt++].v=stoi(s,l,i);
        }
        else if (s[i]=='('){
            E[cnt].type=2;
            E[cnt++].v=0;
        }
        else if (s[i]==')'){
            E[cnt].type=2;
            E[cnt++].v=1;
        }
        else if (s[i]=='+'){
            E[cnt].type=1;
            E[cnt++].v=0;
        }
        else if (s[i]=='-'){
            E[cnt].type=1;
            E[cnt++].v=1;
        }
        else if (s[i]=='*'){
            E[cnt].type=1;
            E[cnt++].v=2;
        }
        else if (s[i]=='/'){
            E[cnt].type=1;
            E[cnt++].v=3;
        }
		else if (s[i]=='^'){
			E[cnt].type=1;
			E[cnt++].v=4;
		}
    }
    return cnt;
}
int getSU(int num)
{
    stack<Node>S;
    int cnt=0;
    for (int i=0;i<num;++i){
        if (E[i].type == 2){
            if (E[i].v==0)//左括号
                S.push(E[i]);
            else { //右括号
                while (!S.empty()){
                    if (S.top().type==2 && S.top().v==0){
                        S.pop();
                        break;
                    }
                    SU[cnt++]=S.top();
                    S.pop();
                }
            }
        }
        else if (E[i].type==1){//运算符
            if (S.empty() || S.top().type==2){//栈空或者栈顶是左括号，进栈
                S.push(E[i]);
            }
            else if (S.top().v/2 < E[i].v/2){//运算符的优先级比栈顶高，进栈
                S.push(E[i]);
            }
            else{  //出栈，并进栈
                SU[cnt++]=S.top();
                S.pop();
                S.push(E[i]);
            }
        }
        else if (E[i].type==0){//数字
            SU[cnt++]=E[i];
        }
    }
    while (!S.empty()){
        SU[cnt++]=S.top();
        S.pop();
    }
    return cnt;
}
int Qpow(int a,int n)
{
	int ret=1;
	while (n){
		if (n&1)
			ret*=a;
		a*=a;
		n>>=1;
	}
	return ret;
}
int cal(char *s)
{
    int cnt=getSU(getE(s));//得到中缀和后缀表达式
    stack<Node>S;
    //后缀表达式求值
    for (int i=0;i<cnt;++i){
        if (SU[i].type==0){
            S.push(SU[i]);
        }
        else{
            int v1=S.top().v;
            S.pop();
            int v2=S.top().v;
            S.pop();
            if (SU[i].v==0)
                S.push(Node(0,v1+v2));
            else if (SU[i].v==1)
                S.push(Node(0,v2-v1));
            else if (SU[i].v==2)
                S.push(Node(0,v1*v2));
            else if (SU[i].v==3)
                S.push(Node(0,v2/v1));
			else if (SU[i].v==4)
				S.push(Node(0,Qpow(v2,v1)));
        }
    }
    int ret=S.top().v;
    S.pop();
    return ret;
}
