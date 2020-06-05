#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<ctime>
#include<algorithm>
#include<sstream>
#include<queue>
#include<cassert>
#include<stack>
using namespace std;


class Solution {
public:
    string reverseLeftWords(string s, int n) {
		int l = 0, m = n, r = s.size();
		char ctr[s.size()];
		int j = 0;
		for(int i=m;i < r;i++)
		{
			ctr[j++] = s[i];
		}
		for(int i=l;i < m;i++)
		{
			ctr[j++] = s[i];
		}
		// cout << j << endl;
		string ans(ctr,ctr+j);
		return ans;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        string ret = Solution().reverseLeftWords(s, n);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}