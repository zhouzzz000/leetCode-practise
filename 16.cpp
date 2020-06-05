#include<iostream>
#include<string>
#include<cassert>
using namespace std;
class Solution {
public:
    int strToInt(string str) {
		if(str.size() == 0)return 0;
		int index=0;
		char fcir = ' ';
		char sx[1000]={'\0'};
		int f=1;
		for(int i=0; i<str.size(); i++)
		{
			if(str[i] == ' ' && fcir==' ')continue;
			if(fcir == ' ')
			{
				fcir = str[i];
				if((fcir!='-' && fcir!='+')&&(fcir < '0' || fcir > '9'))
				{
					return 0;
				}
				if(fcir >= '0' && fcir <= '9')
				{
					sx[index++] = fcir;
				}
			}else{
				if(str[i] >= '0' && str[i] <= '9')
				{
					sx[index++] = str[i];
				}else{
					break;
				}
			}
			
		}
		f = fcir=='-'?0:1;
		int px = 0;
		for(px=0; px<index; px++)
		{
			if(sx[px] != '0')
			{
				break;
			}
		}
		if(fcir == ' ') return 0;
		if(index-px <= 0) return 0;
		int len = index-px;
		if(len >= 11)
		{
			if(f == 1) return INT_MAX;
			else return INT_MIN;
		}
		double num;
		for(int i=px; i<index; i++)
		{
			num = num*10+(sx[i]-'0');
		}
		num = f?num:-num;
		if(num > INT_MAX) return INT_MAX;
		if(num < INT_MIN) return INT_MIN;
		return num;
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
        string str = stringToString(line);
        
        int ret = Solution().strToInt(str);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}