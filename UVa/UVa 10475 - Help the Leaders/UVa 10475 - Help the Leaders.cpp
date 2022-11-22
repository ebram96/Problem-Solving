//It's all about what U BELIEVE
#include<bits/stdc++.h>
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
#define fo(s , y , z) for(int y = s ; y < (int)z ; y++)
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
int n , t , p , s , c , len;
vi proh[15];
char i[16] , j[16];
map<string,int> m;
string topic[16];
bool used[16];
inline bool bin(string &b,string &a)
{
	if(a.size()==b.size())return a>b;
	else return a.size()<b.size();
}
inline bool allowed(int i)
{
	fo(0,y,n)if(used[y])
	{
		int sz = proh[y].size();
		fo(0,x,sz)if(proh[y][x]==i)
			return 0;
	}
	return 1;
}
void generate(int cnt,int i)
{
	if(!cnt)
	{
		int ind;
		for(ind = 0;ind<n;ind++)if(used[ind])
		{
			printf("%s",topic[ind].c_str());
			break;
		}
		ind++;
		fo(ind,y,n)if(used[y])
			printf(" %s",topic[y].c_str());
		puts("");
		return;
	}
	fo(i,y,n)if((!used[y])&&allowed(y))
	{
		used[y] = 1;
		generate(cnt-1,y+1);
		used[y] = 0;
	}
}
int main()
{
	//readf
	//writef
	scanf("%d",&t);
	wtm
	{
		m.clear();
		scanf("%d %d %d",&n,&p,&s);
		fo(0,y,n)
		{
			scanf("%s",i);
			len = strlen(i);
			fo(0,x,len)i[x] = toupper(i[x]);
			topic[y] = i;
			proh[y].clear();
		}
		sort(topic,topic+n,bin);
		fo(0,y,n)m[topic[y]]=y;
		fo(0,y,p)
		{
			scanf("%s %s",i,j);
			len = strlen(i);
			fo(0,x,len)i[x] = toupper(i[x]);
			len = strlen(j);
			fo(0,x,len)j[x] = toupper(j[x]);
			proh[m[i]].pb(m[j]);
			proh[m[j]].pb(m[i]);
		}
		memset(used,0,sizeof(used));
		printf("Set %d:\n",++c);
		generate(s,0);
		puts("");
	}
}

