//It's all about what U BELIEVE
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#include<cmath>
#include<bitset>
#include<vector>
#include<cstring>
#include<stdio.h>
#include<iostream>
#include<algorithm>
#define endl '\n'
#define PI acos(-1)
#define INF ~(1<<31)
#define pb push_back
#define pob pop_back
#define wtm while(t--)
#define wnm while(n--)
#define MOD 1000000007
#define lsone(Z) (Z&-Z)
#define gcu getchar_unlocked
#define allof(Z) Z.begin(),Z.end()
#define rallof(Z) Z.rbegin(),Z.rend()
#define mset(z,v) memset(z,v,sizeof(z))
#define lne if(line)puts("");else line =1
#define fo(s,y,z) for(int y=s ; y<(int)z ; y++)
#define readf freopen("/home/ebram96/Desktop/in" , "r" , stdin);
#define writef freopen("/home/ebram96/Desktop/out" , "w" , stdout);
using namespace std;
typedef unsigned long long ull;
typedef pair<ull,ull> pairull;
typedef pair<int,int> pairii;
typedef vector<string> vstr;
typedef deque<int> dqint;
typedef set<ull> setull;
typedef unsigned int ui;
typedef queue<int> qint;
typedef vector<int> vi;
typedef set<int> seti;
typedef long long ll;
//int dx[]={-1,0,1, 0,-1,1, 1,-1};
//int dy[]={ 0,1,0,-1, 1,1,-1,-1};
inline void printChar(int n,char c)
{
	fo(0,y,n)
		putchar(c);
}
inline void printLine()
{
	putchar('+');
	printChar(10,'-');
	putchar('+');
	printChar(16,'-');
	putchar('+');
	printChar(29,'-');
	printf("+\n");
}
int main()
{
	//readf
	//freopen("keyboard.dat" , "r" , stdin);
	//DO NOT READ FROM A FILE, OTHERWISE YOU WILL GET WA!
	printLine();
	printf("| Keyboard | # of printable | Additionally, the following |\n"
		   "|          |      lines     |  letter keys can be broken  |\n");
	printLine();
	char s[81] , b[27];
	bool broken[26] , used[26] , isPrintable , stop;
	int len , keyboard = 1 , printableLines , breakable;
	while(scanf("%s",b)==1)
	{
		if(!strcmp(b,"finish"))
			break;
		printableLines = breakable = 0;
		len = strlen(b);
		mset(used , 0);
		mset(broken , 0);
		fo(0,y,len)if(isalpha(b[y]))
			broken[tolower(b[y])-'a'] = 1;
		stop = 0;
		while(!stop)
		{
			getchar();
			if(!scanf("%[^\n]",s))
				s[0] = 0;
			stop = !strcmp("END" , s);
			bool usedInLine[26] = {0};
			isPrintable = 1;
			len = strlen(s);
			fo(0,y,len)if(isalpha(s[y]))
			{
				s[y] = tolower(s[y]);
				usedInLine[s[y]-'a'] = 1;
				if(broken[s[y]-'a'])
				{
					isPrintable = 0;
					break;
				}
			}
			if(isPrintable)
			{
				fo(0,y,26)
					used[y] |= usedInLine[y];
				printableLines++;
			}
		}
		putchar('|');
		printChar(3,' ');
		printf("%3d",keyboard);
		printChar(4,' ');
		putchar('|');
		printChar(6,' ');
		printf("%3d",printableLines);
		printChar(7,' ');
		printf("| ");
		fo(0,y,26)if(!used[y]&&!broken[y])
		{
			breakable++;
			putchar(y+'a');
		}
		printChar(60-(1+31+breakable),' ');
		printf("|\n");
		printLine();
		keyboard++;
	}
}

