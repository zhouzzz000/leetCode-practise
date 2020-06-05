#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class Solution{
public:
		int lengthOfLongestSubstring(string s)
		{
			if(s.size() ==0 )return 0;
			int a[27];
			memset(a,-1,sizeof(a));
			a[s[0]-'a'] = 0;
			int max_num=0;
			int l=0;
			for(int i=1; i<s.size(); i++)
			{
				int index=s[i]-'a';
				if(a[index] < 0)
				{
					max_num = max(max_num, i-l+1);
					a[index] = i;
				}else{
					l = max(l, a[index]+1);
					a[index] = i;
					max_num = max(max_num, i-l+1);
				}
			}
			return max_num;
		}
};

int main()
{
	Solution so;
	string s;
	while(cin >> s){
		cout << so.lengthOfLongestSubstring(s) << endl;
	}
	return 0;
}