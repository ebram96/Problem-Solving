//It's all about what U BELIEVE
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<bitset>
#include<stack>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<set>
#define endl '\n'
#define PI acos(-1)
#define INF ~(1<<31)
#define pb push_back
#define pob pop_back
#define wtm while(t--)
#define wnm while(n--)
#define lsone(Z) (Z&-Z)
#define modulo 1000000007
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
ui apsp[51][51];
int p , r , cnt , tc , u , v , res;
bool done[51];
char s1[1000] , s2[1000];
map<string,int> mp;
vi adj[51];
int dfs(int node)
{
	if(done[node])return 0;
	done[node] = 1;
	int sz = adj[node].size() , ret = 1;
	fo(0,i,sz)ret += dfs(adj[node][i]);
	return ret;
}
int main()
{
	//readf
	while(scanf("%d %d",&p,&r)&&p)
	{
		cnt = 0;
		mp.clear();
		fo(1,i,p+1)
		{
			fo(1,j,p+1)
				apsp[i][j] = 1e8;
			adj[i].clear();
		}
		mset(done,0);
		fo(0,i,r)
		{
			scanf("%s %s",s1,s2);
			if(!mp[s1])mp[s1] = ++cnt;
			if(!mp[s2])mp[s2] = ++cnt;
			u = mp[s1] , v = mp[s2];
			adj[u].pb(v);
			adj[v].pb(u);
			apsp[u][v] = apsp[v][u] = 1;
		}
		cnt = dfs(1);
		printf("Network %d: ",++tc);
		if(cnt!=p)
		{
			puts("DISCONNECTED\n");
			continue;
		}
		res = 0;
		fo(1,k,p+1)fo(1,i,p+1)fo(1,j,p+1)
			apsp[i][j] = min(apsp[i][j] , apsp[i][k]+apsp[k][j]);
		fo(1,i,p+1)fo(1,j,p+1)if(i!=j)
			if(res<apsp[i][j]&&apsp[i][j]<1e8)
				res = apsp[i][j];
		printf("%d\n\n",res);
	}
}

