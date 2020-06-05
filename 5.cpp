#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int a[200000];
int main()
{
	int n=0;
	long count = 0;
	memset(a,0,sizeof(a));
	while((scanf("%d",&n))!=EOF)
	{
		for(int i=0; i<n; i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=1; i<n; i++)
		{
			int t = a[i];
			int j;
			for(j=i-1; j>=0; j--)
			{
				if(a[j] > t)
				{
					a[j+1] = a[j];
				}else{
					break;
				}
			}
			a[j+1] = t;
			count += j+1;
		}
		cout << count%(10000009) << endl;
		count = 0;
	}
	return 0;
}	