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
    int cuttingRope(int n) {
		int p[n+1];
		long long maxRes = 1;
		for(int i=2; i <= n/2+1; i++)
		{
			int k = n/i,j;
			for(j=0; j<i-1; j++)
			{
				p[j] = k;
			}
			p[j] = n-(i-1)*k;
			int x = 0;
			while(p[j]-k > 1)
			{
				p[x++] += 1;
				p[j] -= 1; 
			}
			long long res = 1;
			// for(j=0; j<i; j++)
			// {
				// cout << p[j] << " ";
			// }
			// cout << endl;
			for(j=0; j<i; j++)
			{
				res *= p[j];
				if(res > 1000000007){
			        res %= 1000000007;}
			}
			maxRes = max(res,maxRes); 
		}
		return maxRes;
    }
	
	long quick_mod(){return 0;}
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().cuttingRope(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}