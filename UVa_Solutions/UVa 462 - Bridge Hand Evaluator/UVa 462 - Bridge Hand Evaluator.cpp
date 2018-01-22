//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<cstring>
#include<map>
#define fo(y , z) for(int y = 0 ; y < z ; y++)
#define ui unsigned int
#define pb push_back
using namespace std;
inline int plus_s(char c)
{
	switch(c)
	{
	case 'K':
		return 3;
	case 'Q':
		return 2;
	case 'J':
		return 1;
	default:
		return 4;
	}
}
inline int get_suit(char s)
{
	switch (s)
	{
	case 'S':
		return 0;
	case 'H':
		return 1;
	case 'D':
		return 2;
	default:
		return 3;
	}
}
inline int get_ind(char s)
{
	switch(s)
	{
	case 'K':
		return 0;
	case 'Q':
		return 1;
	case 'J':
		return 2;
	default:
		return 3;
	}
}
int main()
{
	char inp[3];
	int strength , strength_tr;
	while(scanf("%s" , inp) == 1)
	{
		strength = strength_tr = 0;
		map<char , int> cnt ;
		vector<char> res;
		int pict[4][4] , max;
		bool stop[4] = {0} , all_stopped = 1;
		memset(pict  , 0 , 16*sizeof(int));
		/*In order :
		 * S H D C
		 *
		 * King 0
		 * Queen 1
		 * Jack 2
		 * Ace 3
		 */
		if(isalpha(inp[0]))
			if(inp[0] != 'T')
				strength += plus_s(inp[0]);
		cnt[inp[1]]++;
		max = 1;
		res.pb(inp[1]);
		if(isalpha(inp[0]))
			if(inp[0] != 'T')
				pict[get_suit(inp[1])][get_ind(inp[0])]++;
		fo(y , 12)
		{
			scanf("%s" , inp);
			if(isalpha(inp[0]))
				if(inp[0] != 'T')
					strength += plus_s(inp[0]);
			cnt[inp[1]]++;
			if(isalpha(inp[0]))
				if(inp[0] != 'T')
					pict[get_suit(inp[1])][get_ind(inp[0])]++;
		}
		fo(y , 4)
		{
			char c;
			switch(y)
			{
			case 0:
				c = 'S';
				break;
			case 1:
				c = 'H';
				break;
			case 2:
				c = 'D';
				break;
			default:
				c = 'C';
			}
			if(cnt[c] > max)
			{
				res.clear();
				res.pb(c);
				max = cnt[c];
			}
			else if(cnt[c] == max)res.pb(c);
			if(pict[y][3])stop[y]++;
			else if(pict[y][0] && cnt[c] >= 2)stop[y]++;
			else if(pict[y][1] && cnt[c] > 2)stop[y]++;
			if(!stop[y])all_stopped = 0;
			if(cnt[c]==1)
			{
				if(pict[y][0])
					strength--;
			}
			if(cnt[c] < 3)
			{
				if(pict[y][1])
					strength-=pict[y][1];
			}
			if(cnt[c] < 4)
			{
				if(pict[y][2])
					strength-=pict[y][2];
			}
			if(!cnt[c])strength_tr+=2;
			else if(cnt[c] == 1)strength_tr+=2;
			else if(cnt[c] == 2)strength_tr++;
		}
		strength_tr+=strength;
		if(strength_tr < 14)puts("PASS");
		else if(all_stopped && strength >= 16)
			puts("BID NO-TRUMP");
		else
		{
			if(res.size() == 1)printf("BID %c\n" , res[0]);
			else
			{
				if(find(res.begin() , res.end() , 'S')!=res.end())
					puts("BID S");
				else if(find(res.begin() , res.end() , 'H')!=res.end())
					puts("BID H");
				else if(find(res.begin() , res.end() , 'D')!=res.end())
					puts("BID D");
				else
					puts("BID C");
			}
		}
	}
}
