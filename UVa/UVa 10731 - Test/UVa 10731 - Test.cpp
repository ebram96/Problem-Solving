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
int n , t , disc[26] , low[26] , cnt_ch;
vi adj[26] , st;
vstr res;
bool same_comp[26] , input[26] , line;
void dfs(int node)
{
	low[node] = disc[node] = t++;
	same_comp[node] = 1;
	st.pb(node);
	int sz = adj[node].size() , u;
	fo(0,y,sz)
	{
		u = adj[node][y];
		if(disc[u]==-1)dfs(u);
		if(same_comp[u])low[node] = min(low[node],low[u]);
	}
	if(low[node]==disc[node])
	{
		string tmp;
		tmp.pb(node+'A');
		while(st.back()!=node)
		{
			same_comp[st.back()] = 0;
			tmp.pb(st.back()+'A');
			st.pob();
		}
		st.pob();
		same_comp[node] = 0;
		sort(allof(tmp));
		res.pb(tmp);
	}
}
int main()
{
	//readf
	char u , inp[5];
	while(scanf("%d",&n)&&n)
	{
		mset(disc,-1);
		mset(input,0);
		cnt_ch = t = 0;
		fo(0,y,26)adj[y].clear();
		res.clear();
		fo(0,y,n)
		{
			fo(0,i,5)scanf(" %c ",&inp[i]);
			scanf(" %c ",&u);
			input[u-'A'] = 1;
			fo(0,i,5)
			{
				input[inp[i]-'A'] = 1;
				if(u!=inp[i])
					adj[u-'A'].pb(inp[i]-'A');
			}
		}
		fo(0,y,26)if(disc[y]==-1&&input[y])
			dfs(y);
		sort(allof(res));
		int res_sz = res.size() , str_sz;
		lne;
		fo(0,y,res_sz)
		{
			str_sz = res[y].size();
			printf("%c",res[y][0]);
			fo(1,i,str_sz)printf(" %c",res[y][i]);
			puts("");
		}
	}
}

