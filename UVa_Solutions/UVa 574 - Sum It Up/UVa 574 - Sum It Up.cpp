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
int n , t , a[12] , sz;
dqint sol;
set<dqint> res;
void traverse(int i , int s)
{
	if(s==t)
	{
		res.insert(sol);
		return;
	}
	if(i==n||s>t)return ;
	sol.pb(a[i]);
	traverse(i+1,s+a[i]);
	sol.pop_back();
	traverse(i+1,s);
}
int main()
{
	//readf
	while(scanf("%d%d" , &t , &n)&&n)
	{
		res.clear();
		sol.clear();
		fo(0,y,n)scanf("%d",&a[y]);
		printf("Sums of %d:\n",t);
		traverse(0,0);
		if(res.empty())puts("NONE");
		set<dqint>::reverse_iterator s = res.rbegin() , e=res.rend();
		while(s!=e)
		{
			printf("%d",(*s)[0]);
			sz = (*s).size();
			fo(1,y,sz)printf("+%d",(*s)[y]);
			puts("");
			s++;
		}
	}
}
