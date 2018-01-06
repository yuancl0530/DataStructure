#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype> //isdigit(char) ���char�����ַ����棬���򷵻ؼ�
#include "stack.cpp"
/*
stack<��������T>S;//ʵ����һ��ջ
S.pop();//ջ��Ԫ�س�ջ
S.push(T e); //e��ջ
S.empty(); //ջ�շ����棬���򷵻ؼ�

*/
using namespace std;
#define N 500
char s[N];
struct Node //��Ԫ��
{
    int type;//����    0 ����(v:���ֵ�ֵ) 1�����(v:0+,1-,2*,3/,4^) 2����(v:0������ 1������)
    int v;   //ֵ
    Node (int t=0,int v=0):type(t),v(v){}
}E[N],SU[N];//E��׺���ʽת���ɶ�Ԫ�飬SU��׺���ʽת���ɵĶ�Ԫ��

int getE(char *s);//����׺��Ԫ��,��������
int getSU(int );//���׺��Ԫ�飬��������
int cal(char *s);//����
int Qpow(int,int);
int stoi(char *,int ,int );//���ַ���[l,r]����ת��������
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
            if (E[i].v==0)//������
                S.push(E[i]);
            else { //������
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
        else if (E[i].type==1){//�����
            if (S.empty() || S.top().type==2){//ջ�ջ���ջ���������ţ���ջ
                S.push(E[i]);
            }
            else if (S.top().v/2 < E[i].v/2){//����������ȼ���ջ���ߣ���ջ
                S.push(E[i]);
            }
            else{  //��ջ������ջ
                SU[cnt++]=S.top();
                S.pop();
                S.push(E[i]);
            }
        }
        else if (E[i].type==0){//����
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
    int cnt=getSU(getE(s));//�õ���׺�ͺ�׺���ʽ
    stack<Node>S;
    //��׺���ʽ��ֵ
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
