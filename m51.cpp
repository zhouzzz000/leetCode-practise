#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<ctime>
#include<algorithm>
#include<sstream>
#include<queue>
#include<stack>
using namespace std;

class Solution {
public:
	int a[50000];
    int reversePairs(vector<int>& nums) {
		int n = nums.size();
		int ans=0;
		mergeSort(nums,0,n-1,ans);
		for(int i=0;i<n;i++)
		{
			cout<< nums[i] << " ";
		}
		cout << endl;
		
		return ans;
    }
	
	void mergeSort(vector<int> &nums,int begin, int end,int &ans)
	{
		if(begin >= end) return;
		int mid = (begin+end)/2;
		mergeSort(nums,begin,mid,ans);
		mergeSort(nums,mid+1,end,ans);
		merge(nums,begin,mid,end,ans);
	}
	void merge(vector<int> &nums,int begin,int mid, int end,int &ans)
	{
		int i=begin,j=mid+1;
		int t=0;
		while(i<=mid && j<=end)
		{
			if(nums[i] <= nums[j])
			{
				a[t++] = nums[i];
				ans += j-(mid+1);
				i++;
			}else{
				a[t++] = nums[j]; 
				
				j++;
			}
		}
		while(i<=mid)
		{
			a[t++] = nums[i];
			i++;
			ans += j-(mid+1);
		}
		while(j<=end)
		{
			a[t++] = nums[j];
			j++;
		}
		for(i=0;i<t;i++)
		{
			nums[i+begin] = a[i];
		}
	}
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().reversePairs(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}