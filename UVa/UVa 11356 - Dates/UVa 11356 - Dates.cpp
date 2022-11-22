//It's all about what U BELIEVE
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#include<cmath>
#include<bitset>
#include<vector>
#include<cstring>
#include<stdio.h>
#include<iostream>
#include<algorithm>
#define endl '\n'
#define PI acos(-1)
#define INF ~(1<<31)
#define pb push_back
#define pob pop_back
#define wtm while(t--)
#define wnm while(n--)
#define MOD 1000000007
#define lsone(Z) (Z&-Z)
#define gcu getchar_unlocked
#define allof(Z) Z.begin(),Z.end()
#define rallof(Z) Z.rbegin(),Z.rend()
#define mset(z,v) memset(z,v,sizeof(z))
#define lne if(line)puts("");else line =1
#define fo(s,y,z) for(int y=s ; y<(int)z ; y++)
#define readf freopen("/home/ebram96/Desktop/in" , "r" , stdin);
#define writef freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
typedef unsigned long long ull;
typedef pair<ull,ull> pairull;
typedef pair<int,int> pairii;
typedef vector<string> vstr;
typedef deque<int> dqint;
typedef set<ull> setull;
typedef unsigned int ui;
typedef queue<int> qint;
typedef vector<int> vi;
typedef set<int> seti;
typedef long long ll;
//int dx[]={-1,0,1, 0,-1,1, 1,-1};
//int dy[]={ 0,1,0,-1, 1,1,-1,-1};
inline bool isLeap(int year)
{
	if(year%4)
		return 0;
	int a , b , tmp = year;
	a = year%10;
	tmp/=10;
	b = tmp%10;
	if(a || b)
		return 1;
	if(year%400)
		return 0;
	return 1;
}
int main()
{
	//readf
	map<string , int>m;
	m["January"] = 1;
	m["February"] = 2;
	m["March"] = 3;
	m["April"] = 4;
	m["May"] = 5;
	m["June"] = 6;
	m["July"] = 7;
	m["August"] = 8;
	m["September"] = 9;
	m["October"] = 10;
	m["November"] = 11;
	m["December"] = 12;
	int t , year , day , month , k , c = 1;
	int d[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	char s[100];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d-",&year);
		scanf("%[^-]-",s);
		scanf("%d%d",&day,&k);
		month = m[s];
		while(k--)
		{
			if(month == 2 && isLeap(year) && day==28)
			{
				day = 29;
				continue;
			}
			day++;
			if(day > d[month])
			{
				day = 1;
				month++;
				if(month > 12)
					month = 1 , year++;
			}
		}
		printf("Case %d: %d-",c++,year);
		for(auto j : m)if(j.second == month)
			printf("%s-%.2d\n",j.first.c_str(),day);
	}
}

