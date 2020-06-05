#include<iostream>
#include<cstring>
using namespace std;
int a[100001];
int main()
{
	int n;
	while(cin >> n)
	{
		memset(a,0,sizeof(a));
		int count = 1;
		for(int i=2; i<=n/2; i++)
		{
			a[i] = !a[i];
			for(int j=2; j<=n/i; j++)
			{
				a[i*j] = !a[i*j];
			}
		}
		for(int i=n/2+1; i<=n; i++)
		{
			a[i] = !a[i];
		}
		for(int i=2; i<=n; i++)
		{
			if(a[i] == 0) count++;
		}
		cout << count << endl;
	}
	return 0;
}