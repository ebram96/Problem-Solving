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
	int a[9] , min;
	string res;
	while(scanf("%d" , &a[0])==1)
	{
		// 0 1 2 - 3 4 5 - 6 7 8
		// B G C - B G C - B G C
		fo(1,y,9)scanf("%d" , &a[y]);
		min = ~(1<<31);
		if(a[3]+a[6]+a[2]+a[8]+a[1]+a[4]<min)
			min = a[3]+a[6]+a[2]+a[8]+a[1]+a[4] , res = "BCG";
		if(a[3]+a[6]+a[2]+a[5]+a[1]+a[7]<min)
			min = a[3]+a[6]+a[2]+a[5]+a[1]+a[7] , res = "BGC";
		if(a[0]+a[6]+a[5]+a[8]+a[1]+a[4]<min)
			min = a[0]+a[6]+a[5]+a[8]+a[1]+a[4] , res = "CBG";
		if(a[3]+a[0]+a[5]+a[8]+a[1]+a[7]<min)
			min = a[3]+a[0]+a[5]+a[8]+a[1]+a[7] , res = "CGB";
		if(a[0]+a[6]+a[2]+a[5]+a[7]+a[4]<min)
			min = a[0]+a[6]+a[2]+a[5]+a[7]+a[4] , res = "GBC";
		if(a[3]+a[0]+a[2]+a[8]+a[7]+a[4]<min)
			min = a[3]+a[0]+a[2]+a[8]+a[7]+a[4] , res = "GCB";
		printf("%s %d\n" , res.c_str() , min);
	}
}

