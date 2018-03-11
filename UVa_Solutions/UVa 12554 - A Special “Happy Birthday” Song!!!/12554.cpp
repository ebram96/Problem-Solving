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
#define l length()
using namespace std;
int main()
{
	string song[16] = {"Happy" , "birthday" , "to" , "you"
					 , "Happy" , "birthday" , "to" , "you"
					 , "Happy" , "birthday" , "to" , "Rujia"
				 	 , "Happy" , "birthday" , "to" , "you" } , inp;
	vector<string> a;
	int n;
	cin>>n;
	while(n--)
	{
		cin>>inp;
		a.push_back(inp);
	}
	bool done = 0;
	for(int y = 0 , ind = 0 ; ; y++ , ind++)
	{
		printf("%s: %s\n" , a[y].c_str() , song[ind].c_str());
		if(y == a.size()-1)
		{
			y = -1;
			done = 1;
		}
		if(done&&ind == 15)break;
		if(ind == 15)ind = -1;
	}
}

