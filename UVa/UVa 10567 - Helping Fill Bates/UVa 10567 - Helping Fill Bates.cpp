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
vi cnt[58];
int l , r , q;
char inp[1000001];
int main()
{
	//readf
	scanf("%s %d",inp,&q);
	int len = strlen(inp);
	fo(0,y,len)cnt[inp[y]-'A'].pb(y);
	fo(0,y,58)sort(cnt[y].begin(),cnt[y].end());
	fo(0,z,q)
	{
		scanf("%s",inp);
		len = strlen(inp);
		vi::iterator ind;
		int i = -1 , c;
		bool res = 1;
		l = r = -1;
		fo(0,y,len)
		{
			c = inp[y]-'A';
			ind = upper_bound(cnt[c].begin(),cnt[c].end(),i);
			if(ind==cnt[c].end())
			{
				res = 0;
				break;
			}
			i = *ind;
			if(l==-1)l = *ind;
			else r = *ind;
		}
		if(!res)puts("Not matched");
		else printf("Matched %d %d\n",l,r);
	}
}

