//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<cstdint>
#include<algorithm>
#include<stdio.h>
#include<map>
#include<bitset>
#include<stack>
#include<queue>
#include<deque>
#include<tuple>
#include<cstring>
#include<cmath>
#include<unordered_map>
#include<climits>
#include<set>
#include<unordered_set>
#define endl '\n'
#define fo(y , z) for(int y = 0 ; y < z ; y++)
#define pb push_back
#define gcu getchar_unlocked
#define modulo 1000000007
#define wtm while(t--)
#define wnm while(n--)
#define non if(!n)break;
#define readf freopen("/home/ebram96/Desktop/in" , "r" , stdin);
#define writef freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
typedef vector<int> vi;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int , int> pairii;
typedef pair<unsigned long long , unsigned long long> pairull;
typedef set<int> seti;
typedef set<unsigned long long> setull;
typedef queue<int> qint;
typedef deque<int> dqint;
//bool bin(string a , string b){return a > b;}
//bool bina(int a , int b){return a > b;}
bool bin(ull a , ull b){return a > b;}
class ufds
{
private:
	int *prnt , *rank , *sz;
public:
	ufds(int n)
	{
		prnt = new int[n+1];
		rank = new int[n+1];
		sz = new int[n+1];
		memset(rank , 0 , (sizeof(int))*(n+1));
		//memset(sz , 1 , (sizeof(int))*(n+1));
		fo(y , n+1)prnt[y] = y , sz[y] = 1;
	}
	int findset(int x)
	{ return prnt[x] == x ? x : prnt[x] = findset(prnt[x]); }
	void joinset(int x ,int y)
	{
		int sx = findset(x) , sy = findset(y);
		if(sx != sy)
		{
			if(rank[sx] > rank[sy])prnt[sy] = sx , sz[sx]+=sz[sy];
			else
			{
				prnt[sx] = sy , sz[sy] += sz[sx];
				if(rank[sx] == rank[sy])rank[sy]++;
			}
		}
	}
	int get_sz(int x)
	{ return sz[findset(x)]; }
};
int main()
{
	//ios::sync_with_stdio(false);cin.tie(0);
	//readf
	int t , n , cnt;
	char name0[21] , name1[21];
	scanf("%d" , &t);
	wtm
	{
		cnt = 1;
		scanf("%d" , &n);
		map<string , int>m;
		ufds s(200002);
		fo(y , n)
		{
			scanf("%s %s" , name0 , name1);
			if(!m[name0])m[name0] = cnt++;
			if(!m[name1])m[name1] = cnt++;
			s.joinset(m[name0] , m[name1]);
			printf("%d\n" , s.get_sz(m[name1]));
		}
	}
}
