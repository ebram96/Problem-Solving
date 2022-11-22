//It's all about what U BELIEVE
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#include<cmath>
#include<bitset>
#include<vector>
#include<cstring>
#include<stdio.h>
#include<iostream>
#include<algorithm>
#define endl '\n'
#define PI acos(-1)
#define INF ~(1<<31)
#define pb push_back
#define pob pop_back
#define wtm while(t--)
#define wnm while(n--)
#define lsone(Z) (Z&-Z)
#define MOD 1000000007
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
int t , cnt[26] , mx , len;
char s[2001];
set<char>res;
int main()
{
	//readf
	scanf("%d ",&t);
	while(t--)
	{
		mx = 0;
		res.clear();
		scanf("%[^\n]",s);
		getchar();
		mset(cnt , 0);
		len = strlen(s);
		fo(0,y,len)if(isalpha(s[y]))
		{
			s[y] = tolower(s[y]);
			cnt[s[y]-'a']++;
			if(cnt[s[y]-'a']>mx)
			{
				mx = cnt[s[y]-'a'];
				res.clear();
				res.insert(s[y]);
			}
			else if(cnt[s[y]-'a']==mx)
				res.insert(s[y]);
		}
		for(auto j : res)
			printf("%c",j);
		puts("");
	}
}

