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
#define lne if(line)puts("");else line = 1;
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
	int n , com , per , *b;
	set<int>num;
	num.insert(0);
	fo(y , 20)num.insert(y+1);
	fo(y , 20)num.insert((y+1)*2);
	fo(y , 20)num.insert((y+1)*3);
	num.insert(50);
	b = new int[num.size()];
	int indb = 0;
	set<int>::iterator beg = num.begin() , end = num.end();
	while(beg != end)b[indb++] = (*beg++);
	while(scanf("%d" , &n))
	{
		if(n <= 0)break;
		com &= per &= 0;
		//fo(y , 62)fo(i , 62)fo(j , 62)
		for(int y = 0 ; y < indb ; y++)
			for(int i = y ; i < indb; i++)
				for(int j = i ; j < indb && b[y]+b[i]+b[j] <= n ; j++)
					if(b[y] + b[i] + b[j] == n)com++;
		if(com)
		fo(y , indb)fo(i , indb)fo(j , indb)
			if(b[y] + b[i] + b[j] == n)per++;
		if(com)
		{
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n" , n , com);
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n**********************************************************************\n" , n , per);
		}
		else
			printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n**********************************************************************\n" , n);
	}
	puts("END OF OUTPUT");
}
