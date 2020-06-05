#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class Solution{
public:
		int add(int a, int b)
		{
			while(b!=0)
			{
				int plus = (a^b);
				b = (unsigned int)(a&b) << 1;
				a = plus;
			}
			return a;
		}
};

int main()
{
	Solution so;
	int a,b;
	while(cin >> a >> b){
		cout << so.add(a, b) << endl;
	}
	return 0;
}