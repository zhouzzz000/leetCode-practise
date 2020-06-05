#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<map>
/*****
9
-2 1 -3 4 -1 2 1 -5 4
*****/
using namespace std;
class Solution{
public:
		int maxSubArray(vector<int> &nums)
		{
			int l = 0;
			int r = nums.size()-1;
			while(l < r)
			{
				int m = (l+r)/2;
				if(nums[m] > nums[r]) l=m+1;
				else if(nums[m] < nums[l]) r=m;
				else{
					r--;
				}
			}
			return nums[l];
		}
};

int main()
{
	// Solution so;
	// vector<int> v;
	// while(true){
		// int n;
		// cin >> n;
		// for(int i=0; i<n; i++)
		// {
			// int x;
			// cin >> x;
			// v.push_back(x);
		// }
		// cout << so.maxSubArray(v) << endl;
	// }
	map<int, int> m;
	m[1] = 10;
	m[2] = 0;
	cout << m[1] << " " << m[3] << endl;
	return 0;
}