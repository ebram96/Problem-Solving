// It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<map>
#include<cstring>
#include<cmath>
#define fo(y , z) for(ui y = 0 ; y < z ; y++)
#define ui unsigned int
#define pb push_back
using namespace std;
int main()
{
	int t;
	bool line = 0;
	scanf("%d\n\n" , &t);
	while(t--)
	{
		int ind = 0 , n , k , a[100][52];
		string cards[52] , tcards[52] , b[] = { " of Clubs" , " of Diamonds" ,
									" of Hearts" , " of Spades"};
		fo(i , 4)
		{
			for(int y = 2 ; y < 10 ; y++)
			{
				cards[ind].insert(0 , 1 , y+'0');
				cards[ind] += b[i];
				ind++;
			}
			cards[ind++] = "10"+b[i];
			cards[ind++] = "Jack"+b[i];
			cards[ind++] = "Queen"+b[i];
			cards[ind++] = "King"+b[i];
			cards[ind++] = "Ace"+b[i];
		}
		scanf("%d\n" , &n);
		fo(y , n)
			fo(ii , 52)
				scanf("%d" , &a[y][ii]);
		while(n--)
		{
			copy(cards , cards+52 , tcards);
			scanf("%d" , &k);
			fo(y , 52)
				cards[y] = tcards[a[k-1][y]-1];
		}
		if(line)puts("");
		line++;
		fo(y , 52)puts(cards[y].c_str());
	}
}
