 
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
    vector<int> singleNumbers(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i=0;i < n;i++)
        {
            ans = ans^nums[i];
        }
        int x = 1,k = 1;
        while((ans & x) == 0)
        {
            k++;
            x = x<<1;
        }
        int num1=0,num2=0;
		 for(int i=0;i < n;i++)
		 {
			 if((nums[i] & x) > 0)
			 {
				 num1 = num1^nums[i];
			 }
			 else
			 {
				 num2 = num2^nums[i];
			 }
		 }
		vector<int> res;
        res.push_back(num1);
        res.push_back(num2);
        return res;
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
        
        vector<int> ret = Solution().singleNumbers(nums);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}