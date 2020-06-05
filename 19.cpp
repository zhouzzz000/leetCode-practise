#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<ctime>
#include<algorithm>
#include<sstream>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
		int i=0;
		int j=nums.size()-1;
		while(i<j)
		{
			while(i<j && nums[i]%2!=0)
			{
				i++;
			}
			while(i<j && nums[j]%2!=1)
			{
				j--;
			}
			if(i<j)
			{
				cout << i << " " << j << endl;
				int t=nums[i];
				nums[i] = nums[j];
				nums[j] = t;
				i++;
				j--;
			}
		}
		return nums;
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

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        vector<int> ret = Solution().exchange(nums);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}