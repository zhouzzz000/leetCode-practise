#include<iostream>
#include<string>
#include<cstring>
#include<vector>
/*****
9
-2 1 -3 4 -1 2 1 -5 4
*****/
using namespace std;
class Solution{
public:
		int maxSubArray(vector<int> &nums)
		{
			if(nums.size() == 1)
			{
				return nums[0];
			}
			int maxNum = nums[0];
			int sum = nums[0];
			for(int i=1; i<nums.size(); i++)
			{
				sum = sum<=0?nums[i]:sum + nums[i];
				maxNum = sum>maxNum?sum:maxNum;
			}
			return maxNum;
		}
};

int main()
{
	Solution so;
	vector<int> v;
	while(true){
		int n;
		cin >> n;
		for(int i=0; i<n; i++)
		{
			int x;
			cin >> x;
			v.push_back(x);
		}
		cout << so.maxSubArray(v) << endl;
	}
	return 0;
}