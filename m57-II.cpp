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
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        if(target < 3) return ans;
        if(target == 3)
        {
            vector<int> temp;
            temp.push_back(1);
            temp.push_back(2);
            ans.push_back(temp);
            return ans;
        }
        int r = target,l=1;
        while(r - l >2)
        {
			if(l > target/2+1) break;
            int sum = (r*(r-l))/2;
            int sum1 = ((r-1-l+1)*(r-1+l))/2;
            int sum2 = ((r-l-1+1)*(r+l+1))/2;
			 // cout << l << " "<< r << " "<< sum1 << " " << sum2 << endl;
			if(sum1 > target && sum2 > target && r-l<3) break;
            if(sum1 >= target) r--;
            else if(sum2 >= target) l++;
			else{
				l++;
				r++;
			}				
            if(sum1 == target || sum2 == target)
            {
                vector<int> temp;
                for(int i=l; i<=r; i++)
                {
                    temp.push_back(i);
                }
                ans.push_back(temp);
				l++;
				r++;
            }
        }
		if( target % 2 == 1 && l <= target/2)
		{
			vector<int> temp;
			temp.push_back(target/2);
			temp.push_back(target/2 + 1);
			ans.push_back(temp);
		}
        return ans;
    }
};

int main() {
    int line;
	Solution so;
    while (cin >> line) {
        vector<vector<int>> ans = so.findContinuousSequence(line);
        for(int i=0;i<ans.size();i++)
		{
			for(int j=0;j<ans[i].size();j++)
			{
			   cout << ans[i][j] << " ";
			}
			cout << endl;
		}
    }
    return 0;
}