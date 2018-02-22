//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
#include<stdio.h>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<cstring>
#include<cmath>
#include<set>
#define INF ~(1<<31)
#define endl '\n'
#define fo(s,y,z) for(int y=s ; y<(int)z ; y++)
#define pb push_back
#define pob pop_back
#define gcu getchar_unlocked
#define modulo 1000000007
#define wtm while(t--)
#define wnm while(n--)
#define lne if(line)puts("");else line =1
#define lsone(Z) (Z&-Z)
#define readf freopen("/home/ebram96/Desktop/in" , "r" , stdin);
#define writef freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
typedef vector<int> vi;
typedef vector<string> vstr;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pairii ;
typedef pair<ull,ull> pairull;
typedef set<int> seti;
typedef set<ull> setull;
typedef queue<int> qint;
typedef deque<int> dqint;
//int dx[]={-1,-1,0,1,1, 1, 0,-1};
//int dy[]={ 0, 1,1,1,0,-1,-1,-1};
//int dx[]={-1,0,1, 0};
//int dy[]={ 0,1,0,-1};
struct Event{int type , dist , ratio;};
Event e[50];
char inp[12];
int n , prev_ratio , walk , cur_ratio , cur_leak;
double cur_cap , full_cap;
bool traverse(int i)
{
	/*
	 * 0 consumption
	 * 1 leak
	 * 2 gas
	 * 3 mechanic
	 * 4 goal
	 */
	if(i==n)return 1;
	walk = e[i].dist-e[i-1].dist;
	cur_cap-=cur_leak*walk;
	if(cur_cap<(walk*cur_ratio)/100.0)return 0;
	cur_cap-=(walk*cur_ratio)/100.0;
	//cout<<cur_leak<<" "<<cur_cap<<endl;
	if(!e[i].type)cur_ratio = e[i].ratio;
	else if(e[i].type==1)cur_leak++;
	else if(e[i].type==2)cur_cap = full_cap;
	else if(e[i].type==3)cur_leak = 0;
	return traverse(i+1);
}
int main()
{
	//readf
	while(scanf(" 0 Fuel consumption %d",&prev_ratio)&&prev_ratio)
	{
		n = e[n].dist = e[n].type = 0;
		e[n++].ratio = prev_ratio;
		while(scanf("%d %s",&e[n].dist,inp))
		{
			if(!strcmp(inp,"Fuel"))
			{
				scanf("%s %d",inp,&prev_ratio);
				e[n].type = 0;
			}
			else if(!strcmp(inp,"Leak"))e[n].type = 1;
			else if(!strcmp(inp,"Gas"))
			{
				scanf("%s",inp);
				e[n].type = 2;
			}
			else if(!strcmp(inp,"Mechanic"))e[n].type = 3;
			else
			{
				e[n++].type = 4;
				break;
			}
			e[n++].ratio = prev_ratio;
		}
		double lo = 0.0 , hi = 10000.0;
		while(hi-lo>=1e-9)
		{
			full_cap = (hi+lo)/2;
			cur_cap = full_cap;
			cur_ratio = e[0].ratio;
			cur_leak = 0;
			if(traverse(1))hi = full_cap;
			else lo = full_cap;
		}
		printf("%.3lf\n",full_cap);
	}
}

