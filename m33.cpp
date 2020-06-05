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
    bool verifyPostorder(vector<int>& postorder) {
        int n = postorder.size();
        for(int i = n-1;i>0;i--)
        {
            int curNum = postorder[i];
            int j = i-1;
            while(curNum < postorder[j])
            {
                j--;
            }
            //cout << j << endl;
            for(int k = 0;k<=j;k++)
            {
                if(postorder[k] > curNum)
                {
                    return false;
                }
            }
        }
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
        vector<int> postorder = stringToIntegerVector(line);
        bool ret = Solution().verifyPostorder(postorder);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}