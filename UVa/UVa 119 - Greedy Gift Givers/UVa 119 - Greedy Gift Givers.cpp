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
ui getind(vector<string>* vect , string s)
{
	for(ui y = 0 ; y < vect->size() ; y++)
		if(s.length() != (*vect)[y].length())continue;
		else
		{
			for(ui i = 0 ; i < s.length() ; i++)
			{
				if((*vect)[y][i] != s[i])break;
				else if(i==s.length()-1)return y;
			}
		}
}
int main()
{
	ui t , t0 , n , given , valuegiven;
	char instr[13] , ingiven[13];
	bool line = 0;
	vector<string> a;
	vector<ui> b;
	while(cin>>t)
	{
		t0 = t;
		while(t--)
		{
			cin>>instr;
			a.push_back(instr);
			b.push_back(0);
		}
		while(t0--)
		{
			scanf("%s %lld %lld " , instr , &given , &n);
			if(n)
			valuegiven = given -(given % n);
			else valuegiven = 0;
			b[getind(&a , instr)] -= valuegiven;
			if(n)
				valuegiven = given / n;
			else valuegiven = 0;
			while(n--)
			{
				scanf("%s" , ingiven);
				b[getind(&a, ingiven)] += valuegiven;
			}
		}
		if(line)cout<<endl;
		for(ui y = 0 ; y < a.size() ; y++)
		{
			cout<<a[y]<<" "<<b[y]<<endl;
		}
		a.clear();
		b.clear();
		line++;
	}
}

