#include<iostream>
using namespace std;
// void visit(int first, int cur, int index, int n, int &count)
// {
	// if(index > n) return;
	// if(index == n)
	// {
		// if(cur != first){
			// count++;
		// }
		// return;
	// }
	// for(int i=1; i<=3; i++)
	// {
		// if(i != cur){
		 // visit(first, i, index+1, n, count);
		// }
	// }
	// return ;
// }
// 1:3 2:6 3:6 4:18 5:30 6:66
// => a[i] = a[i-2]*2+a[i-1],a[1]=1,a[2]=6,a[3]=6
int main()
{
	int n;
	long long a[51];
	a[1]=3;
	a[2]=6;
	a[3]=6;
	for(int i = 4; i<51; i++)
	{
		a[i] = a[i-2]*2+a[i-1];
	}
	while(cin >> n)
	{
		// if(n == 1)
		// {
			// cout << 3 << endl;
			// continue;
		// }
		// int count = 0;
		// for(int i=1; i<=3; i++)
		// {
			// visit(i, i, 1, n, count);
		// }
		cout << a[n] << endl;
	}
	return 0;
}