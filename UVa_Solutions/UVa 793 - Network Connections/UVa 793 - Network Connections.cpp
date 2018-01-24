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
	int* prnt;
public:
	ufds(int n)
	{
		prnt = new int[n+1];
		fo(y , n+1)prnt[y] = y;
	}
	int findset(int x)
	{return prnt[x] == x ? x : prnt[x] = findset(prnt[x]);}
	void joinset(int x ,int y)
	{
		int sx = findset(x) , sy = findset(y);
		if(sx != sy)
		{
			prnt[sx] = sy;
		}
	}
};
int main()
{
	//readf
	int t , n , inp0 , inp1 , ac , wa;
	char q;
	bool line = 0;
	scanf("%d" , &t);
	wtm
	{
		wa = ac = 0;
		scanf("%d\n" , &n);
		ufds s(n);
		while(q = gcu())
		{
			if(q == '\n' || q==EOF)break;
			scanf("%d %d" , &inp0 , &inp1);
			if(q == 'c')s.joinset(inp0 , inp1);
			else if(s.findset(inp0) == s.findset(inp1))ac++;
			else wa++;
			gcu();
		}
		if(line)puts("");
		else line = 1;
		printf("%d,%d\n" , ac , wa);
	}
}
