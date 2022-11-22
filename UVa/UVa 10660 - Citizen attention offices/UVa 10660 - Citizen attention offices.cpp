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
int main()
{
	//readf
	bool perm[25];
	int city[5][5] , t , n , r , c , dest , tot , sum , res[5];
	scanf("%d",&t);
	wtm
	{
		scanf("%d",&n);
		memset(perm,0,sizeof(perm));
		memset(city,0,sizeof(city));
		fo(0,y,5)perm[24-y]=1;
		fo(0,y,n)scanf("%d%d",&r,&c),scanf("%d",&city[r][c]);
		tot=~(1<<31);
		do
		{
			sum &= ~sum;
			fo(0,x,5)fo(0,y,5)if(city[x][y])
			{
				dest=~(1<<31);
				fo(0,i,25)if(perm[i])
					dest=min(dest,abs(i/5-x)+abs(i%5-y));
				dest*=city[x][y];
				sum+=dest;
			}
			if(tot >= sum)
			{
				tot = sum;
				for(int y=0 , resi = 0 ; y < 25 && resi < 5 ; y++)
					if(perm[y])res[resi++]=y;
			}
		}while(next_permutation(perm,perm+25));
		printf("%d",res[0]);
		fo(1,y,5)printf(" %d",res[y]);
		puts("");
	}
}
