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
int n , code[26] , len , c , res_sz , ind;
char letter , s[101] , res[101];
void rec(int i)
{
	if(res_sz==100)return;
	while(s[i]=='0'&&i<len-1)i++;
	if(i==len)
	{
		res[ind] = 0;
		if(ind)puts(res);
		res_sz++;
		return;
	}
	int cmp;
	fo(0,y,26)if(code[y])
	{
		if(code[y]>9)
		{
			if(i==len-1)continue;
			cmp=(s[i]-'0')*10;
			cmp+=(s[i+1]-'0');
		}
		else cmp=s[i]-'0';
		if(cmp==code[y])
		{
			res[ind++] = y+'a';
			rec(i+1+(code[y]>9));
			ind--;
		}
	}
}
int main()
{
	//readf
	while(scanf("%d",&n)&&n)
	{
		res_sz = ind = 0;
		memset(code,0,sizeof(code));
		fo(0,y,n)
		{
			scanf(" %c",&letter);
			scanf("%d",&code[letter-'a']);
		}
		scanf("%s",s);
		len = strlen(s);
		res_sz = 0;
		printf("Case #%d\n",++c);
		rec(0);
		puts("");
	}
}

