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
#define non if(!n)break;
#define lsone(Z) (Z&-Z)
#define readf freopen("/home/ebram96/Desktop/in" , "r" , stdin);
#define writef freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
typedef vector<int> vi;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int , int> pairii;
typedef pair<ull , ull> pairull;
typedef set<int> seti;
typedef set<ull> setull;
typedef queue<int> qint;
typedef deque<int> dqint;
int main()
{
	//readf
	int m , osz , tsz , min , res;
	char c;
	while(scanf("%d" , &m)==1)
	{
		vector<pairii>three , one;
		fo(0,y,m)fo(0,j,m)
		{
			scanf(" %c" , &c);
			if(c=='1')one.pb({y , j});
			else if(c=='3')three.pb({y , j});
		}
		osz = one.size() , tsz = three.size();
		res = 0;
		fo(0,y,osz)
		{
			min = ~(1<<31);
			fo(0,j,tsz)
				if(abs(one[y].first-three[j].first)+abs(one[y].second-three[j].second)<min)
					min = abs(one[y].first-three[j].first)+abs(one[y].second-three[j].second);
			if(min>res)res = min;
		}
		printf("%d\n" , res);
	}
}

