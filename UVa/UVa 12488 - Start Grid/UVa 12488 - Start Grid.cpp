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
#define endl '\n'
#define fo(s , y , z) for(int y = s ; y < (int)z ; y++)
#define pb push_back
#define pob pop_back
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
int main()
{
	//readf
	int n , a[24] , pos[25] , b[24] , res , i;
	while(scanf("%d",&n)==1)
	{
		res = 0;
		fo(0,y,n)
		{
			scanf("%d",&a[y]);
			pos[a[y]] = y;
		}
		fo(0,y,n)scanf("%d",&b[y]);
		fo(0,y,n)if(a[y]!=b[y])
		{
			i = pos[b[y]];
			while(i>y)
			{
				swap(a[i],a[i-1]);
				pos[a[i]]++;
				i--;
				res++;
			}
		}
		printf("%d\n",res);
	}
}

