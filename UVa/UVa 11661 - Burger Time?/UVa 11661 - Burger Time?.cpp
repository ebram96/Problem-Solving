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
using namespace std;
int main()
{
	char c;
	bool z , r , d;
	ui res , lastr , lastd , n ;
	while(scanf("%lld\n" , &n) && n)
	{
		lastr = lastd = r = d = z = 0;
		res = 2000001;
		fo(y , n)
		{
			c = getchar();
			if(!z)
			{
				if(c == 'Z'){z++;res = 0;}
				else if(c == 'R'){lastr = y;r=1;}
				else if(c == 'D'){lastd = y;d=1;}
				if(r)
				{
					if(d){
					if(lastd>=lastr)
					{
						if(lastd-lastr<res)res = lastd-lastr;
					}
					else
					{
						if(lastr-lastd<res)res = lastr-lastd;
					}}
				}
			}
		}
		printf("%lld\n" , res);
	}
}

