#include <iostream>
#include <cstring>
#include "stack.cpp"
using namespace std;
#define N 500
char s[N];
int stoi(char *s,int l,int r);
int cal(char* s,int l,int r);
int Qpow(int a,int n);
int main()
{
	cout<<"请输入算术表达式:"<<endl;
	cin>>s;
	cout<<"运算结果为:"<<endl<<cal(s,0,strlen(s)-1)<<endl;
	return 0;
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
int stoi(char *s,int l,int r)
{
	int ret=0;
	for (int i=l;i<=r;++i)
		ret=10*ret+(s[i]-'0');
	return ret;
}
int cal(char *s,int l,int r)
{
	int i,cnt=0;
	//找括号外+，-
	for (i=r;i>=l;--i){
		if (s[i]==')')
			++cnt;
		else if (s[i]=='(')
			--cnt;
		if (!cnt &&s[i]=='+')
			return cal(s,l,i-1)+cal(s,i+1,r);
		else if (!cnt && s[i]=='-')
			return cal(s,l,i-1)-cal(s,i+1,r);
	}
	//找* / 
	cnt=0;
	for (i=r;i>=l;--i){
		if (s[i]==')')
			++cnt;
		else if (s[i]=='(')
			--cnt;
		if (s[i]=='*')
			return cal(s,l,i-1)*cal(s,i+1,r);
		else if (s[i]=='/')
			return cal(s,l,i-1)/cal(s,i+1,r);
	}
	//找^
	for (i=r;i>=l;--i){
		if (s[i]=='^')
			return (Qpow(cal(s,l,i-1),cal(s,i+1,r)));
	}
		//去括号
	if (s[l]=='(' && s[r]==')')
		return cal(s,l+1,r-1);
	return stoi(s,l,r);
}

