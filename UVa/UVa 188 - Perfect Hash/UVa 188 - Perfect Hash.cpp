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
char s[1001];
vi w;
inline int word_to_int(int i)
{
	int word = s[i++]-'a'+1;
	while(isalpha(s[i]))
	{
		word<<=5;
		word += s[i++]-'a'+1;
	}
	w.pb(word);
	return i;
}
int main()
{
	//readf
	int len , c , n;
	bool tie;
	while(scanf("%[^\n]\n",s)==1)
	{
		w.clear();
		puts(s);
		n = 0;
		len = strlen(s);
		fo(0,y,len)if(isalpha(s[y]))
			y = word_to_int(y) , n++;
		c = INF;
		fo(0,y,n)c = min(c,w[y]);
		fo(0,i,n)
		{
			tie = 0;
			fo(i+1,j,n)
			if((c/w[i]%n)==(c/w[j]%n))
			{
				tie = 1;
				c = min((c/w[i]+1)*w[i] , (c/w[j]+1)*w[j]);
				break;
			}
			if(tie)i=-1;
		}
		printf("%d\n\n",c);
	}
}

