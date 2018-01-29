//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<cstring>
#include<cmath>
#include<set>
#define endl '\n'
#define fo(s , y , z) for(int y = s ; y < (int)z ; y++)
#define lne if(line)puts("");else line = 1;
#define pb push_back
#define gcu getchar_unlocked
#define modulo 1000000007
#define wtm while(t--)
#define wnm while(n--)
#define lsone(Z) (Z&-Z)
#define readf freopen("/home/ebram96/Desktop/in" , "r" , stdin);
#define writef freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
typedef vector<int> vi;
typedef vector<string> vstr;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int , int> pairii;
typedef pair<ull , ull> pairull;
typedef set<int> seti;
typedef set<ull> setull;
typedef queue<int> qint;
typedef deque<int> dqint;
//int dx[]={-1,-1,0,1,1, 1, 0,-1};
//int dy[]={ 0, 1,1,1,0,-1,-1,-1};
int top[50] , t , n , res , pre;
int put(int i,int num)
{
	if(i==n)return num;
	int rt = sqrt(top[i]+num);
	if(!top[i]||(rt*rt==num+top[i]))
	{
		top[i]=num;
		return num+1;
	}
	return put(i+1,num);
}
int main()
{
	//readf
	scanf("%d",&t);
	wtm
	{
		scanf("%d",&n);
		memset(top,0,sizeof(top));
		res = 1;
		do pre=res,res=put(0,res);
		while(res!=pre);
		printf("%d\n",res-1);
	}
}
