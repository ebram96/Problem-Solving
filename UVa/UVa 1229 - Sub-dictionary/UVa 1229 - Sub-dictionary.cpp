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
int n , ind , t , disc[101] , low[101];
bool same_comp[101] , in_dictionary[101];
seti adj[101];
vi st;
vstr output;
map<string,int>mp;
char word[101][26];
void add(int node)
{
	if(in_dictionary[node])return;
	in_dictionary[node] = 1;
	output.pb(word[node]);
	for(auto u : adj[node])add(u);
}
void dfs(int node)
{
	low[node] = disc[node] = t++;
	same_comp[node] = 1;
	st.pb(node);
	for(auto u : adj[node])
	{
		if(disc[u]==-1)dfs(u);
		if(same_comp[u])low[node] = min(low[node],low[u]);
	}
	int cnt = 1;
	if(disc[node]==low[node])
	{
		while(st.back()!=node)
		{
			same_comp[st.back()] = 0;
			add(st.back());
			st.pob();
			cnt++;
		}
		st.pob();
		same_comp[node] = 0;
		if(cnt>1)add(node);
	}
}
void clr()
{
	mset(disc,-1);
	mset(in_dictionary,0);
	t = 0;
	ind = 1;
	mp.clear();
	fo(1,y,n+1)adj[y].clear();
	output.clear();
}
int main()
{
	//readf
	char u[26] , v[26] , buff[3000];
	int sz;
	while(scanf("%d",&n)&&n)
	{
		clr();
		fo(0,y,n)
		{
			scanf(" %s",u);
			if(!mp[u])strcpy(word[ind],u),mp[u] = ind++;
			scanf("%[^\n]",buff);
			sz = strlen(buff);
			for(int i = 0,j; i < sz ; i++)
			{
				while(!isalpha(buff[i]))i++;
				j = 0;
				while(isalpha(buff[i]))
					v[j++] = buff[i++];
				v[j] = 0;
				if(!mp[v])strcpy(word[ind],v),mp[v] = ind++;
				adj[mp[u]].insert(mp[v]);
			}
		}
		fo(1,y,n+1)if(disc[y]==-1)
			dfs(y);
		int res_sz = output.size();
		printf("%d\n",res_sz);
		if(res_sz)
		{
			sort(allof(output));
			printf("%s",output[0].c_str());
			fo(1,y,res_sz)printf(" %s",output[y].c_str());
		}
		puts("");
	}
}

