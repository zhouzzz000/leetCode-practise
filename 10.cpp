#include<iostream>
#include<vector>
using namespace std;

/******
1 4 7 11 15
2 5 8 12 19
3 6 9 16 22
10 13 14 17 24
18 21 23 26 30
******/
int main()
{
	vector<vector<int>> v;
	int x;
	for(int i = 0; i < 5; i++)
	{
		vector<int> t;
		for(int j = 0; j < 5; j++)
		{
			cin >> x;
			t.push_back(x);
		}
		v.push_back(t);
	}
	int n;
	while(cin >> n){
		int i=0, j=v[0].size()-1;
		int f = 0;
		while(i<v.size() && j<v[0].size() && j>=0)
		{
			if(v[i][j] == n)
			{
				f=1;
				break;
			}
			if(v[i][j] < n)
			{
				i++;
			}
			else if(v[i][j] > n)
			{
				j--;
			}
		}
		cout << (f?"true":"false")<<endl;
	}
}