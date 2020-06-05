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
#include<unordered_map>
using namespace std;


class Solution {
public:
    int numTeams(vector<int>& rating) {
		int ans = 0;
		int n = rating.size();
		for(int i=1; i<n-1; i++)
		{
			int iless=0, imore=0;
			int kless=0, kmore=0;
			for(int j=0; j<i; j++)
			{
				if(rating[j] < rating[i])
				{
					iless++;
				}else if(rating[j] > rating[i])
				{
					imore++;
				}
			}
			for(int j=i+1; j<n; j++)
			{
				if(rating[j] < rating[i])
				{
					kless++;
				}else if(rating[j] > rating[i])
				{
					kmore++;
				}
			}
			ans += iless*kmore + imore*kless;
		}
		return ans;
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
        vector<int> rating = stringToIntegerVector(line);
        
        int ret = Solution().numTeams(rating);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}