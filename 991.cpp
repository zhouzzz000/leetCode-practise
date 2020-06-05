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
    int brokenCalc(int X, int Y) {
		int num = 0;
		int minNum = Y;
		fun(X,Y,num,minNum);
		return minNum;
    }
	
	void fun(int x, int y,int num, int &minNum)
	{
		if(x == y || x <=0 || x >= y) return;
		if(x > y)
		{
			num += y-x;
			x=y;
			minNum = min(num,minNum);
			return;
		}
		if(x > y/2)
		{
			if(y%2 == 0){
				num += y-y/2+1;
				x = y;
				minNum = min(num, minNum);
				return ;
			}
		}
		fun( x-1, y,num+1, minNum);
		fun( x*2, y,num+1,minNum);
	}
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int X = stringToInteger(line);
        getline(cin, line);
        int Y = stringToInteger(line);
        
        int ret = Solution().brokenCalc(X, Y);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}