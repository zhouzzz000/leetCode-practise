
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
	int a[100][100];
    int movingCount(int m, int n, int k) {
		int ans = 0;
		visit(0,0,m,n,k,ans);
		return ans;
    }
	void visit(int x,int y,int m,int n,int k,int &ans)
	{
		if(x>=m || x<0) return;
		if(y>=n || y<0) return;
		if(a[x][y] == 1) return;
		if(sumFromBit(x,y) > k)
		{
			return;
		}
		// cout << x << " " << y << endl;
		ans++;
		
		a[x][y] = 1;
		visit(x+1,y,m,n,k,ans);
		visit(x,y+1,m,n,k,ans);
		visit(x-1,y,m,n,k,ans);
		visit(x,y-1,m,n,k,ans);
	}
	
	int sumFromBit(int m,int n)
	{
		int sum = 0;
		while(m > 0)
		{
			sum+=m%10;
			m /= 10;
		}
		while(n > 0)
		{
			sum+=n%10;
			n /= 10;
		}
		return sum;
	}
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        int ret = Solution().movingCount(m, n, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}