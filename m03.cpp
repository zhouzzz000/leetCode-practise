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
#include<cassert>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
		int temp;
		for(int i=0; i<nums.size(); i++)
		{
			if(nums[i] == nums[nums[i]])
			{
				return nums[i];
			}
			else{
				temp = nums[i];
				nums[i] = nums[temp];
				nums[temp] = temp;
			}
		}
		return 0;
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
        
        int ret = Solution().findRepeatNumber(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}