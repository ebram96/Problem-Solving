//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<cstring>
#include<unordered_map>
#define fo(y , z) for(int y = 0 ; y < z ; y++)
#define ui unsigned int
#define pb push_back
using namespace std;
int main()
{
	int t , len , n , oud , c = 1;
	double res , target;
	scanf("%d" , &t);
	char a[20] , b[20];
	bool line = 0;
	while(t--)
	{
		res = 0.0;
		oud = target = 0;
		scanf("%d" , &n);
		while(n--)
		{
			scanf("%s " , a);
			if(!strcmp(a , "fool"))
			{
				oud++;
				res+=4.5;
			}
			else
			{
				fgets(b , 20 , stdin);
				if(!strcmp("one" , a))
				{
					if(b[strlen(b)-3] == 'p')
					{
						oud++;
						res+=4.5;
					}
					else res+=0.5;
				}
				else if(strlen(a)==10)
				{
					oud++;
					res+=4.5;
				}
				else if(!strcmp("king" , a))
					res+=4.5;
				else if(a[0] == 'q')
					res+=3.5;
				else if(a[0] == 'j')
					res+=1.5;
				else if(!strcmp("knight" , a))
					res+=2.5;
				else res+=0.5;
			}
		}
		if(!oud)target = 56;
		else if(oud == 1)target = 51;
		else if(oud == 2)target = 41;
		else if(oud == 3)target = 36;
		if(line)puts("");
		else line = 1;
		if(res < target)printf("Hand #%d\nGame lost by %g point(s).\n" , c++ , target - res);
		else printf("Hand #%d\nGame won by %g point(s).\n" , c++ , res - target);
	}
}
