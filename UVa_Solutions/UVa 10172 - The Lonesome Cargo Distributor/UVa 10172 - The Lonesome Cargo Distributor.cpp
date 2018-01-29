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
#include<tuple>
#include<cstring>
#include<cmath>
#include<unordered_map>
#include<climits>
#include<set>
#include<unordered_set>
#define fo(y , z) for(int y = 0 ; y < z ; y++)
#define ui unsigned int
#define ull unsigned long long
#define pairii pair<int , int>
#define pairull pair<unsigned long long , unsigned long long>
#define seti set<int>
#define setull set<unsigned long long>
#define pb push_back
#define gcu getchar_unlocked
#define modulo 1000000007
#define wtm while(t--)
#define wnm while(n--)
#define non if(!n)break;
#define readf freopen("/home/ebram96/Desktop/in" , "r" , stdin);
#define writef freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
//bool bin(string a , string b){return a > b;}
//bool bina(int a , int b){return a > b;}
bool bin(ull a , ull b){return a > b;}
int main()
{
	readf
	int t , n , init_q , inp , occupied , res , ind;
	ui  s , q;
	stack<int>carrier;
	queue<int> stations[100];
	scanf("%d" , &t);
	wtm
	{
		res = occupied = ind = 0;
		scanf("%d %u %u" , &n , &s , &q);
		fo(y , n)
		{
			scanf("%d" , &init_q);
			if(init_q)occupied++;
			fo(i , init_q)
			{
				scanf("%d" , &inp);
				stations[y].push(inp);
			}
		}
		while(occupied || carrier.size())
		{
			//unload
			while(carrier.size())
			{
				if(carrier.top() == ind+1)
					carrier.pop(),res++;
				else if(stations[ind].size() < q)
				{
					if(!stations[ind].size())occupied++;
					stations[ind].push(carrier.top());
					carrier.pop();
					res++;
				}
				else break;
			}
			//load
			while(stations[ind].size())
			{
				if(carrier.size() < s)
				{
					res++;
					carrier.push(stations[ind].front());
					stations[ind].pop();
					if(!stations[ind].size())occupied--;
				}
				else break;
			}
			ind++;
			if(ind == n)ind = 0;
			res+=2;
		}
		printf("%d\n" , res-2);
	}
}
