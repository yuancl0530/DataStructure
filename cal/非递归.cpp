#include <iostream>
#include <cstring>
#include "stack.cpp"
using namespace std;
#define N 500
struct Node//三元组
{
	int l,r,id;
	Node(int id=0,int l=0,int r=0):id(id),l(l),r(r){}
};

struct Oper//四元组
{
	int op; //num0 +1 -2 *3 /4 ()5 
	int l,r,id;
	Oper(int id=0,int op=0,int l=0,int r=0):op(op),l(l),r(r),id(id){}
};
int stoi(char *s,int l,int r);
int cal(char* s);
char s[N];
int val[N];
int main()
{
	cout<<"请输入算术表达式:"<<endl;
	cin>>s;
	cout<<"运算结果为:"<<endl<<cal(s)<<endl;
	return 0;
}
int cal(char *s)
{
	stack<Node>S;
	stack<Oper>S_cal;
	int num=0;//时间戳
	S.push(Node(num++,0,strlen(s)-1));
	while (!S.empty()){
		int i,cnt=0;
		int id=S.top().id;
		int l=S.top().l;
		int r=S.top().r;
		S.pop();
		bool flag=0;
		for (i=r;i>=l;--i){
			if (s[i]==')')
				++cnt;
			else if (s[i]=='(')
				--cnt;
			if (!cnt &&s[i]=='+'){
				S.push(Node(num++,l,i-1));
				S.push(Node(num++,i+1,r));
				S_cal.push(Oper(id,1,num-2,num-1));
				flag=1;
				break;
			}
			else if (!cnt && s[i]=='-'){
				S.push(Node(num++,l,i-1));
				S.push(Node(num++,i+1,r));
				S_cal.push(Oper(id,2,num-2,num-1));
				flag=1;
				break;
			}
		}
		if (flag)continue;
		flag=0;
		for (i=r;i>=l;--i){
			if (s[i]==')')
				++cnt;
			else if (s[i]=='(')
				--cnt;
			if (!cnt && s[i]=='*'){
				S.push(Node(num++,l,i-1));
				S.push(Node(num++,i+1,r));
				S_cal.push(Oper(id,3,num-2,num-1));
				flag=1;
				break;
			}
			else if (!cnt && s[i]=='/'){
				S.push(Node(num++,l,i-1));
				S.push(Node(num++,i+1,r));
				S_cal.push(Oper(id,4,num-2,num-1));
				flag=1;
				break;
			}
		}
		if (flag)continue;
		if (s[l]=='(' && s[r]==')'){
			S.push(Node(num++,l+1,r-1));
			S_cal.push(Oper(id,5,num-1));
			continue;
		}
		S_cal.push(Oper(id,0,l,r));
	}
	while (!S_cal.empty()){
		int id=S_cal.top().id;
		int op=S_cal.top().op;
		int l=S_cal.top().l;
		int r=S_cal.top().r;
		if (op==0)
			val[id]=stoi(s,l,r);
		else if (op==1)
			val[id]=val[l]+val[r];
		else if (op==2)	
			val[id]=val[l]-val[r];
		else if (op==3)
			val[id]=val[l]*val[r];
		else if (op==4)
			val[id]=val[l]/val[r];
		else if (op==5)
			val[id]=val[l];
		S_cal.pop();
	}
	return val[0];
}
int stoi(char *s,int l,int r)
{
	int ret=0;
	for (int i=l;i<=r;++i)
		ret=10*ret+(s[i]-'0');
	return ret;
}

