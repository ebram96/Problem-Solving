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
ui extract(string& s)
{
	ui ret = 0;
	fo(y , s.length())
	{
		if(s[y] >= 65 && s[y] <=90)
			ret+=(s[y]-64);
		else if(s[y] >= 97 && s[y] <= 122)
			ret+=(s[y] - 96);
	}
	return ret;
}
ui sum(ui& n)
{
	ui ret = 0;
	while(n)
	{
		ret+=n%10;
		n/=10;
	}
	while(ret>=10)ret=sum(ret);
	return ret;
}
int main()
{
	string a , b;
	ui x , y;
	while(getline(cin , a), getline(cin , b))
	{
		x = extract(a);
		y = extract(b);
		x = sum(x);
		y = sum(y);
		if(x>y)
			cout<<setprecision(2)<<fixed<<y/(x*1.0)*100<<" %"<<endl;
		else
			cout<<setprecision(2)<<fixed<<x/(y*1.0)*100<<" %"<<endl;
	}
}

