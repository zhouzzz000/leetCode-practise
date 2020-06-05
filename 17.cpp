#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<ctime>
/*****
9
-2 1 -3 4 -1 2 1 -5 4
*****/
using namespace std;
class Solution{
public:
		  vector<string> permutation(string s) {
				string p(s.size(),'\0');
				int f[s.size()]={0};
				
				set<string> st;
				for(int i=0 ; i<s.size(); i++)
				{
					f[i] = 1;
					fun(st,f,i,s,p,0);
					f[i] = 0;
				}
				set<string>::iterator it;
				vector<string> v;
				for(it=st.begin(); it!=st.end();it++)
				{
					v.push_back(*it);
				}
				// vector<string> v(st.begin(),st.end());
				return v;
		  }
		  void fun(set<string> &st,int *f,int cur, string s, string &p,int index)
		  {
			  p[index] = s[cur];
			  if(index == s.size()-1)
			  {
				  // string x(p.substr(0,s.size()));
				  st.insert(p);
				  // m[p] = 1;
				  return;
			  }
			  for(int i=0 ; i<s.size(); i++)
			 {
				 if(f[i] == 0){
					f[i] = 1;
					fun(st,f,i,s,p,index+1);
					f[i] = 0;
				 }
			 }
			 return ;
		  }

};

int main()
{
	string s;
	while(cin >> s)
	{
		vector<string> v;
		clock_t startTime = clock();
		v = Solution().permutation(s);
		clock_t endTime = clock();
		cout << double(endTime-startTime)/CLOCKS_PER_SEC << endl;
	}
	return 0;
}