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
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
		int begin = s.find_first_not_of(' ');
		int end = s.find_last_not_of(' ');
		if(begin > end || end < 0)
		{
			return false;
		}
		if(begin == end)
		{
			if(s[begin] > '9' || s[begin] < '0')
			{
				return false;
			}else{
				return true;
			}
		}
		string str1 = s.substr(begin,end-begin+1);
		string::size_type eIndex = str1.find('e');
		if(eIndex == string::npos) return judgeD(str1);
		else return judgeD(str1.substr(0,eIndex)) && judgeE(str1.substr(eIndex+1));
    }
	bool judgeD(string s){
		cout << s << " 1" << endl;
		int p = false,d = false;
		for(int i = 0; i<s.size(); i++)
		{
			if(s[i] == '-' || s[i] == '+')
			{
				if(i != 0) return false;
			}
			else if(s[i] == '.')
			{
				if(d) return false;
				d=true;
			}
			else if(s[i] > '9' || s[i] < '0')
			{
				return false;
			}
		}
		return true;
	}
	bool judgeE(string s){
		cout << s << " 2" << endl;
		int p = false,d = false;
		for(int i = 0; i<s.size(); i++)
		{
			if(s[i] == '-' || s[i] == '+')
			{
				if(i != 0) return false;
			}
			else if(s[i] > '9' || s[i] < '0')
			{
				return false;
			}
		}
		return true;
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
        
        bool ret = Solution().isNumber(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}