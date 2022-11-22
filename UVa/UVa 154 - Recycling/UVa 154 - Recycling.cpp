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
	int n = 0 , cnt[100], diff , minim , res , iy , ix;
	char a[100][20] , col[] = "gyorb";
	while(scanf("%s",a[0])&&a[0][0]!='#')
	{
		n = 1;
		minim = ~(1<<31);
		memset(cnt,0,sizeof(cnt));
		while(scanf("%s",a[n])&&a[n][0]!='e')
			n++;
		fo(0,y,n)fo(1+y,x,n)
			{
				diff = 0;
				fo(0,i,5)
				{
					fo(0,k,19)if(a[y][k]==col[i])
					{
						iy = k+2;
						break;
					}
					fo(0,k,19)if(a[x][k]==col[i])
					{
						ix = k+2;
						break;
					}
					if(a[y][iy]!=a[x][ix])diff++;
				}
				cnt[y]+=diff;
				cnt[x]+=diff;
			}
		fo(0,y,n)if(cnt[y]<minim)
		{
			res = y+1;
			minim = cnt[y];
		}
		printf("%d\n",res);
	}
}

