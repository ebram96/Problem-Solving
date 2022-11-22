//It's all about what U BELIEVE
#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
#include<stdio.h>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<cstring>
#include<cmath>
#include<set>
#define endl '\n'
#define fo(s , y , z) for(int y = s ; y < (int)z ; y++)
#define lne if(line)puts("");else line = 1;
#define pb push_back
#define pob pop_back
#define gcu getchar_unlocked
#define modulo 1000000007
#define wtm while(t--)
#define wnm while(n--)
#define lsone(Z) (Z&-Z)
#define readf freopen("/home/ebram96/Desktop/in" , "r" , stdin);
#define writef freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
typedef vector<int> vi;
typedef vector<string> vstr;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int , int> pairii;
typedef pair<ull , ull> pairull;
typedef set<int> seti;
typedef set<ull> setull;
typedef queue<int> qint;
typedef deque<int> dqint;
//int dx[]={-1,-1,0,1,1, 1, 0,-1};
//int dy[]={ 0, 1,1,1,0,-1,-1,-1};
struct Book
{
	string author;
	bool shelved , returned;
};
map<string,Book> books;
inline bool bin(string &b,string &a)
{
	if(books[a].author==books[b].author)
		return a>b;
	return books[a].author>books[b].author;
}
int main()
{
	//readf
	//NO NEED FOR A MAP IN THIS PROBLEM
	//I'M JUST TOO LAZY TO RE-CODE IT :P
	char title[81] , author[82] , op[7], isend;
	vstr shelve;
	int all = 0 , prev , ret;
	while(isend = gcu())
	{
		if(isend=='E')
		{
			scanf("%s ",title);
			break;
		}
		all++;
		scanf("%[^\"]\" by %[^\n]\n",title,author);
		shelve.pb(title);
		books[title].author = author;
		books[title].shelved = 1;
		books[title].returned = 0;
	}
	sort(shelve.begin(),shelve.end(),bin);
	ret = 0;
	while(scanf("%s ",op)&&op[0]!='E')
	{
		scanf("\"%[^\"]\" ",title);
		if(op[0]=='B')books[title].shelved = 0;
		else if(op[0]=='R')books[title].returned = 1,ret++;
		else
		{
			if(!ret)
			{
				puts("END");
				continue;
			}
			prev = -1;
			fo(0,y,all)
			{
				if(!ret)break;
				if(books[shelve[y]].shelved)
				{
					prev = y;
					continue;
				}
				if(!books[shelve[y]].returned)continue;
				if(prev==-1)printf("Put \"%s\" first\n",shelve[y].c_str());
				else printf("Put \"%s\" after \"%s\"\n",shelve[y].c_str(),shelve[prev].c_str());
				prev = y;
				ret--;
				books[shelve[y]].shelved = 1;
				books[shelve[y]].returned = 0;
			}
			puts("END");
		}
	}
}

