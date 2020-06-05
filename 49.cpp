#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<ctime>
#include<algorithm>
#include<sstream>
#include<queue>
using namespace std;

class Solution {
public:
	int f[1690] = {0};
	int cur = 0;
	int a,b,c;
    int nthUglyNumber(int n) {
		if(n <= cur)
		{
			return f[n-1];
		}
		if(cur == 0)
		{
			f[0] = 1;
			a = 0;
			b = 0;
			c = 0;
			cur = 1;
		}
		for(int i=cur; i<n; i++)
		{
			f[i] = minNum(f[a]*2, f[b]*3, f[c]*5);
			if(f[i] == f[a]*2) a++;
			if(f[i] == f[b]*3) b++;
			if(f[i] == f[c]*5) c++;
		}
		cur = n;
		return f[n-1];
    }
	int minNum(int x, int y, int z){
		int t = x<y?x:y;
		t = t < z?t:z;
		return t;
	}
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().nthUglyNumber(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}