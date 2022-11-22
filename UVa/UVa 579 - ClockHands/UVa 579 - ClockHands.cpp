//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<cstring>
#include<map>
#include<cmath>
/*#include"head.h"
#include <sys/types.h>
#include <sys/stat.h>*/
#define fo(y , z) for(int y = 0 ; y < z ; y++)
#define ui unsigned int
#define pb push_back
using namespace std;
int main()
{
	short h , m;
	while(scanf("%hd:%hd" , &h , &m))
	{
		if(!h&&!m)break;
		float res = (30.0f*h + m*0.5f) - (m*6.0f);
		if(res < 0)res*=-1.0f;
		printf("%.3f\n" , (res >= 180.0f ? abs(res-360.0f) : res));
	}
}
