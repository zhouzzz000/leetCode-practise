#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<double> v;
void fun(double &count, int *a, int sum, int index, int n)
{
	if(index == n)
	{
		count++;
		a[sum]++;
		return ;
	}
	for(int i=1; i<=6; i++)
	{
		fun(count, a, sum+i, index+1, n);
	}
}
// int main()
// {
	// int n;
	// cin >> n;
	// int a[67] = {0};
	// double count = 0;
	// fun(count, a, 0, 0, n);
	// cout << count << endl;
	// for(int i=n; i<=n*6; i++)
	// {
		// v.push_back((double)a[i]/count);
	// }
	// for(double a : v)
	// {
		// cout << a << " ";
	// }
	// return 0;
// }
int main()
{
	int n;
	cin >> n;
	int dp[15][70] = {0};
	for(int i=1; i<=6; i++)
	{
		dp[1][i] = 1;
	}
	for(int i=2; i<=n; i++)
	{
		for(int j=i*6; j>=i; j--)
		{
			dp[i][j] = 0;
			for(int k=1; k<=6; k++)
			{
				if(j-k < i-1)
				{
					break;
				}
				dp[i][j] += dp[i-1][j-k];
			}
		}
	}
	double all = pow(6,n);
	for (int i = n; i <= 6 * n; i ++) {
            cout << dp[n][i] * 1.0 / all << " ";
    }
	return 0;
}
