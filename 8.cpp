#include<iostream>
#include<cstring>
using namespace std;
int a[101][101];
char s[10000];
void paintXY(int x, int y, int xlen, int ylen)
{
	for(int i=0; i<ylen; i++)
	{
		for(int j=0; j<xlen; j++)
		{
			a[y-i][x+j]++;
		}
	}
}
void printAxis()
{
	for(int i=1; i<=50; i++)
	{
		for(int j=1; j<=50; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	memset(a,0,sizeof(a));
	gets(s);
	int i = -1;
	int x[4];
	int j = 0;
	int num=0;
	while(s[++i]!='\0')
	{
		if(s[i]==',')
		{
			continue;
		}
		if(s[i] >= '0' && s[i] <= '9')
		{
			x[j++] = s[i]-'0';
			continue;
		}
		if(s[i] == ';')
		{
			paintXY(x[0],x[1],x[2],x[3]);
			memset(x,0,sizeof(x));
			j=0;
			num++;
		}
	}
	paintXY(x[0],x[1],x[2],x[3]);
	num++;
	int xj=0, yj=0, xjlen=0, yjlen=0;
	for(int i=50; i>=0; i--)
	{
		for(int j=50; j>=0; j--)
		{
			if(a[i][j]==num)
			{
				xj = j;
				yj = i;
				break;
			}
		}
	}
	if(xj == 0)
	{
		cout << "Error";
		return 0;
	}
	int tx=xj, ty=yj;
	while(a[yj][tx] == num)//[2,2,1,1]  1[2,2,1,1]  1
	{
		xjlen++;
		tx--;
	}
	while(a[ty][xj] == num)
	{
		yjlen++;
		ty--;
	}
	xj = tx+1;
	if(xjlen ==0 || yjlen ==0)
	{
		cout << "Error";
		return 0;
	}
	cout << "[" << xj << "," << yj << "," << xjlen << "," << yjlen << "]" << "  " << xjlen*yjlen;
	return 0;
}