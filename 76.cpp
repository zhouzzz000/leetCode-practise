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
    unordered_map<char, int> mapt,mapc;
    bool check()
    {
        for(auto &x : mapt)
        {
          if(mapt[x.first] > mapc[x.first])
          {
            return false;
          }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        for(int i=0;i<m;i++)
        {
            mapt[t[i]]++;
        }
        int begin=0, end=0;
        int ansL=0,ansR=n;
         mapc[s[begin]]++;
        while(end < n)
        {
            if(end-begin+1 < m)
            {
                end++;
                mapc[s[end]]++;
            }
            while(end < n && !check())
            {
                end++;
                mapc[s[end]]++;
            }
            if(end == n) break;
            //cout << begin << " " << end << endl;
            while(check() && begin<end)
            {
                if(end-begin < ansR-ansL)
                {
                    ansR = end;
                    ansL = begin;
                }
                mapc[s[begin]]--;
                begin++;
            }
        }
        return s.substr(ansL, ansR-ansL+1);
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

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        string t = stringToString(line);
        
        string ret = Solution().minWindow(s, t);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}