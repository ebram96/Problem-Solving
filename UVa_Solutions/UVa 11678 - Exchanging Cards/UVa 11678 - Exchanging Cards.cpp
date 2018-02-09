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
int main()
{
	int a , b , inp , res ;
	while(scanf("%d %d" , &a , &b))
	{
		if(!a && !b)break;
		res = 0;
		map<int , int> am , bm;
		while(a--){scanf("%d" , &inp);am[inp]++;}
		while(b--){scanf("%d" , &inp);bm[inp]++;}
		if(am.size() >= bm.size())
		{
			map<int , int>::iterator beg = bm.begin() , end = bm.end();
			while(beg!=end)
			{
				if(!am[(*beg).first])res++;
				beg++;
			}
		}
		else
		{
			map<int , int>::iterator beg = am.begin() , end = am.end();
			while(beg!=end)
			{
				if(!bm[(*beg).first])res++;
				beg++;
			}
		}
		printf("%d\n" , res);
	}
}
