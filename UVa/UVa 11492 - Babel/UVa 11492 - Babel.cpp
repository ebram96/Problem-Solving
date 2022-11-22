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
map<string,int>L;
seti words[2000] , langs[4000];
char c[2000];
int n , w , l , dist[2000] , len[2000];
bool is_destination[2000];
struct State
{
	int word , cost;
	inline bool operator<(const State &s)const
	{return s.cost<cost;}
};
inline int dijkstra(int source)
{
	priority_queue<State>pq;
	fo(0,y,n)dist[y] = INF;
	for(auto j : langs[source])
	{
		dist[j] = len[j];
		pq.push({j,len[j]});
	}
	int word , cost;
	while(!pq.empty())
	{
		word = pq.top().word , cost = pq.top().cost;
		if(is_destination[word])return cost;
		pq.pop();
		for(auto j : words[word])
			for(auto k : langs[j])if(dist[k]>cost+len[k]&&c[k]!=c[word])
			{
				pq.push({k,cost+len[k]});
				dist[k] = cost+len[k];
			}
	}
	return -1;
}
int main()
{
	//readf
	char l1[51] , l2[51], source[51] , word[51] , destination[51];
	while(scanf("%d",&n)&&n)
	{
		L.clear();
		fo(0,y,n)words[y].clear() , langs[y].clear();
		fo(n,y,n<<1)langs[y].clear();
		w = l = 0;
		scanf("%s %s",source,destination);
		fo(0,y,n)
		{
			scanf("%s %s %s",l1,l2,word);
			len[y] = strlen(word);
			c[y] = word[0];
			if(!L[l1])L[l1] = ++l;
			if(!L[l2])L[l2] = ++l;
			words[y].insert(L[l1]);
			words[y].insert(L[l2]);
			langs[L[l1]].insert(y);
			langs[L[l2]].insert(y);
		}
		mset(is_destination,0);
		for(auto j : langs[L[destination]])
			is_destination[j] = 1;
		int res = dijkstra(L[source]);
		if(~res)printf("%d\n",res);
		else puts("impossivel");
	}
}

