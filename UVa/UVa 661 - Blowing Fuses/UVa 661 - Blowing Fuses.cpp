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
	int n , m , cap , c = 1 , max , cur , in;
	vector<int> a;
	bool line = 0;
	vector<bool> b;
	while(scanf("%d %d %d" , &n , &m , &cap) && n && m && cap)
	{
		max = 0 ;
		cur = 0;
		while(n--)
		{
			cin>>in;
			a.push_back(in);
			b.push_back(0);
		}
		while(m--)
		{
			cin>>in;
			if(b[in-1])
			{
				b[in-1] = 0;
				cur-=a[in-1];
			}
			else
			{
				b[in-1] = 1;
				cur+=a[in-1];
			}
			if(cur>max)max = cur;
		}
		if(line)cout<<endl;
		line = 1;
		cout<<"Sequence "<<c++<<endl;
		if(max>cap)cout<<"Fuse was blown.\n";
		else cout<<"Fuse was not blown.\n"<<"Maximal power consumption was "<<max<<" amperes.\n";
		a.clear();
		b.clear();
	}
	cout<<endl;
}

