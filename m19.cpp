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
    bool isMatch(string s, string p) {
		bool f = false;
		dfs(s,0,p,0, f);
		return f;
    }
	void dfs(string s, int sIndex, string p, int pIndex, bool &f)
	{
		if(sIndex == s.size() && pIndex == p.size())
		{
			f = true;
			return;
		}
		if(pIndex == p.size())
		{
			return;
		}
		if(sIndex == s.size())
		{
			return;
		}
		if(p[pIndex] == s[sIndex])
		{
			dfs(s,sIndex+1, p, pIndex+1, f);
		}else if(p[pIndex] == '.'){
			dfs(s,sIndex+1, p, pIndex+1, f);
		}else if(p[pIndex] == '*'){
			char x = p[pIndex-1];
			// cout << x << endl;
			dfs(s,sIndex, p, pIndex+1, f);
			while(sIndex < s.size() && (s[sIndex] == x || x == '.'))
			{
				sIndex++;
			}
			dfs(s,sIndex, p, pIndex+1, f);
			
		}else{
			if(p[pIndex+1] == '*')
			{
				dfs(s,sIndex, p, pIndex+2, f);
			}else{
				f=false;
			}
		}
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        string p = stringToString(line);
        
        bool ret = Solution().isMatch(s, p);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}