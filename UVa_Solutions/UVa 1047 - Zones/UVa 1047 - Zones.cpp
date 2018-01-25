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
struct CommonArea
{
	int sz , towers[20] , customers;
};
int main()
{
	//readf
	CommonArea areas[10];
	bool perm[20],exec[20],in_common,execlude;
	int service[20],c=1,locations[20],n,actual,common,ind;
	ull cmp , res;
	while(scanf("%d%d",&n,&actual))
	{
		if(!(n||actual))break;
		memset(areas,0,sizeof(areas));
		memset(perm,0,sizeof(perm));
		fo(0,y,n)scanf("%d",&service[y]);
		scanf("%d",&common);
		fo(0,y,common)
		{
			scanf("%d",&areas[y].sz);
			fo(0,j,areas[y].sz)
			{
				scanf("%d",&areas[y].towers[j]);
				areas[y].towers[j]--;//zero indexed
			}
			scanf("%d",&areas[y].customers);
		}
		fo(0,y,actual)perm[n-y-1]=1;
		res = 0;
		do
		{
			cmp=0;
			memset(exec,0,sizeof(exec));
			fo(0,y,n)
				if(perm[y])
				{
					cmp+=service[y];
					fo(0,i,common)
					{
						execlude=in_common=0;
						fo(0,j,areas[i].sz)
							if(areas[i].towers[j]==y)in_common=1;
							else if((!exec[areas[i].towers[j]])&&perm[areas[i].towers[j]])execlude=1;
						if(execlude&&in_common)cmp-=areas[i].customers;
					}
					exec[y]=1;
				}
			if(res<=cmp)
			{
				res=cmp;
				ind=0;
				fo(0,y,n)
					if(perm[y])locations[ind++]=y+1;
			}
		}while(next_permutation(perm,perm+n));
		printf("Case Number  %d\n"
				"Number of Customers: %llu\n"
				"Locations recommended:",c++,res);
		fo(0,y,actual)printf(" %d",locations[y]);
		puts("\n");
	}
}

