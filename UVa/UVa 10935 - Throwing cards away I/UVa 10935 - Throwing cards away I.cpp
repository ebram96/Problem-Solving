//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<cstring>
#include<map>
#include<cmath>
#include<set>
#define fo(y , z) for(int y = 0 ; y < z ; y++)
#define ui unsigned int
#define ull unsigned long long
#define pb push_back
#define gcu getchar_unlocked
#define wtm while(t--)
#define non if(!n)break;
#define frop freopen("/home/ebram96/Desktop/in" , "r" , stdin);	freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
bool bin_s(string a , string b){return a > b;}
int main()
{
	frop
	int n;
	while(scanf("%d" , &n))
	{
		non
		if(n==1)
		{
			puts("Discarded cards:\nRemaining card: 1");
			continue;
		}
		vector<int> cards(n) , disc;
		fo(y , n)cards[y] = n-y;
		while(cards.size() > 1)
		{
			disc.pb(cards[cards.size()-1]);
			cards.pop_back();
			cards.insert(cards.begin() , cards[cards.size()-1]);
			cards.pop_back();
		}
		printf("Discarded cards: %d" , disc[0]);
		for(ui y =1 ; y < disc.size() ; y++)
			printf(", %d" , disc[y]);
		printf("\nRemaining card: %d\n" , cards[0]);
	}
}
