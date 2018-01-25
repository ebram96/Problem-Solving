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
typedef pair<ull , ull> pairull;
typedef set<int> seti;
typedef set<ull> setull;
typedef queue<int> qint;
typedef deque<int> dqint;
//inline bool bin(string a , string b){return a > b;}
//inline bool bin(int a , int b){return a > b;}
//inline bool bin(ull a , ull b){return a > b;}
int main()
{
	//readf
	int t , d , q , inp, low[10000] , high[10000];
	char maker[21];
	bool line = 0;
	string makers[10000];
	scanf("%d" , &t);
	wtm
	{
		scanf("%d" , &d);
		fo(y , d)
		{
			scanf("%s %d %d" , maker , &low[y] , &high[y]);
			makers[y] = maker;
		}
		scanf("%d" , &q);
		if(line)puts("");else line = 1;
		fo(y , q)
		{
			bool ok = 1;
			scanf("%d" , &inp);
			set<string>fo;
			fo(i , d)
			{
				if(low[i] <= inp && high[i] >= inp)
					fo.insert(makers[i]);
				if(fo.size()>1)
				{
					ok = 0;
					break;
				}
			}
			if(fo.empty())ok = 0;
			puts(ok ? (*fo.begin()).c_str() : "UNDETERMINED");
		}
	}
}
