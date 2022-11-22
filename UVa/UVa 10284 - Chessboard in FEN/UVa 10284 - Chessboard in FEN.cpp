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
#define fo(y , z) for(int y = 0 ; y < z ; y++)
#define ui unsigned int
#define pb push_back
using namespace std;
int main()
{
	char inp[8][9];
	while(scanf("%[^/]/%[^/]/%[^/]/%[^/]/%[^/]/%[^/]/%[^/]/%s" , inp[0], inp[1], inp[2], inp[3], inp[4], inp[5], inp[6], inp[7])==8)
	{
		int res = 0;
		char board[8][8];
		//memset(board , 'o' , 64);
		fo(y , 8)
		{
			int ind = 0;
			fo(i , strlen(inp[y]))
			{
				if(inp[y][i] <= '9')
					fo(a , inp[y][i]-'0')
						board[y][ind++] = 'o';
				else
					board[y][ind++] = inp[y][i];
			}
		}
		fo(y , 8)fo(i , 8)
			if(board[y][i] == 'n'||board[y][i] == 'N')
			{
				if(i < 7)
				{
					if(board[y+2][i+1] == 'o')board[y+2][i+1] = 'x';
				}
				if(i)
				{
					if(board[y+2][i-1] == 'o')board[y+2][i-1] = 'x';
				}
				if(i < 6)
				{
					if(board[y+1][i+2] == 'o')board[y+1][i+2] = 'x';
				}
				if(i > 1)
				{
					if(board[y+1][i-2] == 'o')board[y+1][i-2] = 'x';
				}
				if(y)
				{
					if(i < 6)
					{
						if(board[y-1][i+2] == 'o')board[y-1][i+2] = 'x';
					}
					if(i > 1)
					{
						if(board[y-1][i-2] == 'o')board[y-1][i-2] = 'x';
					}
					if(y > 1)
					{
						if(i < 7)
						{
							if(board[y-2][i+1] == 'o')board[y-2][i+1] = 'x';
						}
						if(i)
						{
							if(board[y-2][i-1] == 'o')board[y-2][i-1] = 'x';
						}
					}
				}
			}
			else if(board[y][i] == 'k' || board[y][i] == 'K')
			{
				if(y)
				{
					if(i)
					{
						if(board[y-1][i-1] == 'o')board[y-1][i-1] = 'x';
					}
					if(board[y-1][i] == 'o')board[y-1][i] = 'x';
					if(i < 7)
					{
						if(board[y-1][i+1] == 'o')board[y-1][i+1] = 'x';
					}
				}
				if(i)
				{
					if(board[y][i-1] == 'o')board[y][i-1] = 'x';
					if(board[y+1][i-1] == 'o')board[y+1][i-1] = 'x';
				}
				if(i < 7)
				{
					if(board[y][i+1] == 'o')board[y][i+1] = 'x';
					if(board[y+1][i+1] == 'o')board[y+1][i+1] = 'x';
				}
				if(board[y+1][i] == 'o')board[y+1][i] = 'x';
			}
			else if(board[y][i] == 'p')
			{
				if(i)
				{
					if(board[y+1][i-1] == 'o')board[y+1][i-1] = 'x';
				}
				if(i < 7)
				{
					if(board[y+1][i+1] == 'o')board[y+1][i+1] = 'x';
				}
			}
			else if(board[y][i] == 'P')
			{
				if(y)
				{
					if(i)
					{
						if(board[y-1][i-1] == 'o')board[y-1][i-1] = 'x';
					}
					if(i < 7)
					{
						if(board[y-1][i+1] == 'o')board[y-1][i+1] = 'x';
					}
				}
			}
			else if(board[y][i] == 'B' || board[y][i] == 'b')
			{
				for(int a = y-1 , b = i-1 ; a >= 0 && b >= 0 ; a-- , b--)
					if(board[a][b] != 'o' && board[a][b] != 'x')
						break;
					else board[a][b] = 'x';
				for(int a = y-1 , b = i+1 ; a >= 0 && b < 8 ; a-- , b++)
					if(board[a][b] != 'o' && board[a][b] != 'x')
						break;
					else board[a][b] = 'x';
				for(int a = y+1 , b = i-1 ; b >= 0 && a < 8 ; a++ , b--)
					if(board[a][b] != 'o' && board[a][b] != 'x')
						break;
					else board[a][b] = 'x';
				for(int a = y+1 , b = i+1 ; b < 8 && a < 8 ; a++ , b++)
					if(board[a][b] != 'o' && board[a][b] != 'x')
						break;
					else board[a][b] = 'x';
			}
			else if(board[y][i] == 'r' || board[y][i] == 'R')
			{
				for(int a = i-1 ; a >= 0 ; a--)
					if(board[y][a] != 'o' && board[y][a] != 'x')
						break;
					else board[y][a] = 'x';
				for(int a = i+1 ; a < 8 ; a++)
					if(board[y][a] != 'o' && board[y][a] != 'x')
						break;
					else board[y][a] = 'x';
				for(int a = y-1 ; a >= 0 ; a--)
					if(board[a][i] != 'o' && board[a][i] != 'x')
						break;
					else board[a][i] = 'x';
				for(int a = y+1 ; a < 8 ; a++)
					if(board[a][i] != 'o' && board[a][i] != 'x')
						break;
					else board[a][i] = 'x';
			}
			else if(board[y][i] == 'q' || board[y][i] == 'Q')
			{
				for(int a = y-1 , b = i-1 ; a >= 0 && b >= 0 ; a-- , b--)
					if(board[a][b] != 'o' && board[a][b] != 'x')
						break;
					else board[a][b] = 'x';
				for(int a = y-1 , b = i+1 ; a >= 0 && b < 8 ; a-- , b++)
					if(board[a][b] != 'o' && board[a][b] != 'x')
						break;
					else board[a][b] = 'x';
				for(int a = y+1 , b = i-1 ; b >= 0 && a < 8 ; a++ , b--)
					if(board[a][b] != 'o' && board[a][b] != 'x')
						break;
					else board[a][b] = 'x';
				for(int a = y+1 , b = i+1 ; b < 8 && a < 8 ; a++ , b++)
					if(board[a][b] != 'o' && board[a][b] != 'x')
						break;
					else board[a][b] = 'x';
				for(int a = i-1 ; a >= 0 ; a--)
					if(board[y][a] != 'o' && board[y][a] != 'x')
						break;
					else board[y][a] = 'x';
				for(int a = i+1 ; a < 8 ; a++)
					if(board[y][a] != 'o' && board[y][a] != 'x')
						break;
					else board[y][a] = 'x';
				for(int a = y-1 ; a >= 0 ; a--)
					if(board[a][i] != 'o' && board[a][i] != 'x')
						break;
					else board[a][i] = 'x';
				for(int a = y+1 ; a < 8 ; a++)
					if(board[a][i] != 'o' && board[a][i] != 'x')
						break;
					else board[a][i] = 'x';
			}
		fo(y , 8)fo(i , 8)if(board[y][i] == 'o')res++;
		printf("%d\n" , res);
	}
}
