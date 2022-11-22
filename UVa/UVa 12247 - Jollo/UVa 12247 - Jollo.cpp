//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<cstring>
#include<map>
/*#include"head.h"
#include <sys/types.h>
#include <sys/stat.h>*/
#define fo(y , z) for(ui y = 0 ; y < z ; y++)
#define ui unsigned int
#define pb push_back
using namespace std;
bool bin(int a , int b)
{
	return (a > b);
}
// create some function to solve
int main()
{
	//This code needs alot of REFINEMENT
	int a[3] , b[2];
	while(scanf("%d %d %d %d %d\n" , &a[0], &a[1], &a[2], &b[0], &b[1]) == 5)
	{
		if(!a[0])break;
		int t[3] , boole = 0 , r_boole = 0 , t2[3] , tot[5] , co[3];
		copy(b , b+2 , t);
		sort(a , a+3 , bin);
		sort(t , t+2 , bin);
		copy(a , a+3 , tot);
		copy(b , b+2 , tot+3);
		fo(y , 3)
			fo(i , 2)
				if(a[y] > t[i] && t[i] != -1)
				{
					boole++;
					t[i] = -1;
					break;
				}
		if(boole == 2)
		{
			puts("-1");
			continue;
		}
		sort(b , b+2);
		copy(b , b+2 , t);
		t[2] = 1;
		copy(a , a+3 , t2);
		copy(t , t+3 , co);
		while(1)
		{
			if(find(tot , tot+5 , co[2]) != (tot+5))
			{
				co[2]++;
				copy(co , co+3 , t);
				continue;
			}
			if(co[2] >52)
			{
				puts("-1");
				break;
			}
			sort(t , t+3 , bin);
			boole = r_boole = 0;
			copy(t2 , t2+3 , a);
			fo(y , 3)
				fo(i , 3)
					if(t[y] > a[i] && a[i] != -1)
					{
						boole++;
						a[i] = -1;
						break;
					}
			//
			copy(t2 , t2+3 , a);
			fo(y , 3)
				fo(i , 3)
					if(a[y] > t[i] && t[i] != -1)
					{
						r_boole++;
						t[i] = -1;
						break;
					}
			if(boole >= 2 && r_boole < 2)
			{
				printf("%d\n" , co[2]);
				break;
			}
			co[2]++;
			copy(co , co+3 , t);
		}
	}
}
