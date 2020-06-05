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
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		int a[1001] = {0};
		int i=0;
		int j=0;
		stack<int> s;
		while(i<popped.size())
		{
			if(a[popped[i]] == 0)
			{
				while(j<pushed.size() && pushed[j] != popped[i] && a[pushed[j]] ==0)
				{
					s.push(pushed[j]);
					a[pushed[j]] = 1;
					cout << pushed[j] << " " << popped[i] << endl;
					j++;
				}
				if(j == pushed.size()) return false;
				a[popped[i]] = 1;
				cout << popped[i] << endl;
				i++;
				j++;
			}
			else if(a[popped[i]] == 1)
			{
				if(s.top() == popped[i])
				{
					s.pop();
					//a[popped[i]]=0;
					i++;
				}
				else return false;
			}
		}
		if(!s.empty()) return false;
		return true;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> pushed = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> popped = stringToIntegerVector(line);
        
        bool ret = Solution().validateStackSequences(pushed, popped);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}