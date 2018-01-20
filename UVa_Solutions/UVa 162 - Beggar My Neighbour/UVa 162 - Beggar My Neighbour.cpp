// It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<cstring>
#include<cmath>
#define fo(y , z) for(ui y = 0 ; y < z ; y++)
#define ui long long
#define pb push_back
#define pop pop_back()
using namespace std;
short chk(char* s)
{
	if(s[1] == 'A') return 4;
	else if(s[1] == 'K')return 3;
	else if(s[1] == 'Q')return 2;
	else if(s[1] == 'J')return 1;
	else return 0;
}
int main()
{
	char inp[3];
	vector<short> dealer , non , heap;
	short indd , indn , lastcard;
	bool loop , done;
	while(scanf("%s" , inp)&&inp[0] != '#')
	{
		indd = indn = 25;
		loop = done = 0;
		non.pb(chk(inp));
		scanf("%s" , inp);
		dealer.pb(chk(inp));
		fo(y , 25)
		{
			scanf("%s" , inp);
			non.pb(chk(inp));
			scanf("%s" , inp);
			dealer.pb(chk(inp));
		}
		while(1)
		{
			if(done)break;
			if(!non.size())
			{
				printf("1 %2lu\n" , dealer.size());
				break;
			}
			else
			{
				if(loop)
				{
					loop = 0;
					fo(y , lastcard)
					{
						if(!non.size())
						{
							printf("1 %2lu\n" , dealer.size());
							done = 1;
							break;
						}
						if(non[indn])
						{
							heap.pb(non[indn]);
							lastcard = non[indn];
							non.pop;
							indn--;
							loop = 1;
							break;
						}
						else
						{
							heap.pb(non[indn]);
							indn--;
							non.pop;
						}
					}
					if(!loop)
					{
						reverse(heap.begin() , heap.end());
						dealer.insert(dealer.begin() , heap.begin() , heap.end());
						indd+=heap.size();
						heap.clear();
					}
				}
				else
				{
					if(!non[indn])
					{
						heap.pb(non[indn]);
						non.pop;
						indn--;
					}
					else
					{
						loop = 1;
						lastcard = non[indn];
						heap.pb(non[indn]);
						non.pop;
						indn--;
					}
				}
			}
			if(done)break;
			if(!dealer.size())
			{
				printf("2 %2lu\n" , non.size());
				break;
			}
			else
			{
				if(loop)
				{
					loop = 0;
					fo(y , lastcard)
					{
						if(!dealer.size())
						{
							printf("2 %2lu\n" , non.size());
							done = 1;
							break;
						}
						if(dealer[indd])
						{
							heap.pb(dealer[indd]);
							lastcard = dealer[indd];
							dealer.pop;
							indd--;
							loop = 1;
							break;
						}
						else
						{
							heap.pb(dealer[indd]);
							dealer.pop;
							indd--;
						}
					}
					if(!loop)
					{
						reverse(heap.begin() , heap.end());
						non.insert(non.begin() , heap.begin() , heap.end());
						indn+=heap.size();
						heap.clear();
					}
				}
				else
				{
					if(!dealer[indd])
					{
						heap.pb(dealer[indd]);
						dealer.pop;
						indd--;
					}
					else
					{
						loop = 1;
						lastcard = dealer[indd];
						heap.pb(dealer[indd]);
						dealer.pop;
						indd--;
					}
				}
			}
		}
		heap.clear();
		non.clear();
		dealer.clear();
	}
}

