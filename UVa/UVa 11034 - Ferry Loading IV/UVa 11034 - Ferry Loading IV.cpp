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
#define ui unsigned int
#define ull unsigned long long
#define pairii pair<int , int>
#define pairull pair<unsigned long long , unsigned long long>
#define seti set<int>
#define setull set<unsigned long long>
#define qint queue<int>
#define dqint deque<int>
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
	//readf
	int c , l , m , length , res , st;
	char lr[6];
	bool ferry_cars;
	scanf("%d" , &c);
	qint left , right;
	while(c--)
	{
		res = ferry_cars = 0;
		scanf("%d %d" , &l , &m);
		l*=100;
		fo(y , m)
		{
			scanf("%d %s" , &length , lr);
			lr[0] == 'l' ? left.push(length): right.push(length);
		}
		st = 0;
		while(ferry_cars || left.size() || right.size())
		{
			while(left.size()&&left.front()+st<=l)
				st+=left.front() , left.pop() , ferry_cars = 1;
			if(ferry_cars||right.size())res++;
			st = ferry_cars = 0;
			while(right.size()&&right.front()+st<=l)
				st+=right.front() , right.pop() , ferry_cars = 1;
			if(ferry_cars||left.size())res++;
			st = ferry_cars = 0;
		}
		printf("%d\n" , res);
	}
}
