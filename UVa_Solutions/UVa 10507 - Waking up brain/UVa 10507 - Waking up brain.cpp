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
	bool isup[26] , adj[26][26] , toawake[26] , done;
	int n , m , res , cnt , awake;
	char inp[4];
	while(scanf("%d%d",&n,&m)==2)
	{
		res = 0 , awake = 3 , done = 0;
		memset(isup,0,sizeof(isup));
		memset(adj,0,sizeof(adj));
		scanf("%s",inp);
		fo(0,y,3)isup[inp[y]-'A']=1;
		fo(0,y,m)
		{
			scanf("%s",inp);
			adj[inp[0]-'A'][inp[1]-'A']=adj[inp[1]-'A'][inp[0]-'A']=1;
		}
		while(!done)
		{
			res++;
			done = 1;
			memset(toawake,0,sizeof(toawake));
			fo(0,y,26)
			{
				cnt = 0;
				fo(0,x,26)if(adj[y][x]&&isup[x])
				{
					cnt++;
					if(cnt==3)break;
				}
				if(cnt==3&&!isup[y])toawake[y]=1;
			}
			fo(0,y,26)if(toawake[y])
				done=0,isup[y]=1,awake++;
		}
		if(awake!=n)puts("THIS BRAIN NEVER WAKES UP");
		else printf("WAKE UP IN, %d, YEARS\n",res-1);
	}
}
