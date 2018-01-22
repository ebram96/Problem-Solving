//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<cstring>
#include<cmath>
#include<set>
#define endl '\n'
#define fo(s , y , z) for(int y = s ; y < (int)z ; y++)
#define lne if(line)puts("");else line = 1;
#define pb push_back
#define pob pop_back
#define gcu getchar_unlocked
#define modulo 1000000007
#define wtm while(t--)
#define wnm while(n--)
#define lsone(Z) (Z&-Z)
#define readf freopen("/home/ebram96/Desktop/in" , "r" , stdin);
#define writef freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
typedef vector<int> vi;
typedef vector<string> vstr;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int , int> pairii;
typedef pair<ull , ull> pairull;
typedef set<int> seti;
typedef set<ull> setull;
typedef queue<int> qint;
typedef deque<int> dqint;
//int dx[]={-1,-1,0,1,1, 1, 0,-1};
//int dy[]={ 0, 1,1,1,0,-1,-1,-1};
int a[9876544];
bool used[10] , dig[10];
inline bool uniq(int n)
{
	memset(used,0,sizeof(used));
	memset(dig,0,sizeof(dig));
	while(n)
		if(used[n%10])return 0;
		else dig[n%10] = used[n%10]=1 , n/=10;
	return !used[0];
}
inline string to_str(int n)
{
	string ret = "";
	while(n)ret+=n%10 , n/=10;
	reverse(ret.begin() , ret.end());
	return ret;
}
inline bool valid(int& n)
{
	if(!uniq(n))return 0;
	string s = to_str(n);
	int len = s.size();
	int i = 0;
	memset(used,0,sizeof(used));
	do
	{
		used[s[i]]=1;
		i+=s[i];
		i%=len;
	}while(i&&!used[s[i]]);
	if(i)return 0;
	fo(1,y,10)if(dig[y]&&!used[y])
		return 0;
	return 1;
}
int main()
{
	//readf
	int n , c=0;
	for(int y = 9876543 ; y > 9 ; y--)
		a[y]=valid(y)?y:a[y+1];
	while(scanf("%d",&n)&&n)
		printf("Case %d: %d\n",++c,a[n]);
}
