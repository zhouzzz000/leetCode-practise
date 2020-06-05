#include<iostream>
using namespace std;
int a[10000];
void quick_sort(int begin,int end){
	if(begin >= end) return;
	int i = begin, j = end;
	int x = a[begin];
	while(i<j){
		while(i < j && a[j] > x){
			j--;
		}
		if(i < j){
			a[i++] = a[j];
		}
		while(i < j && a[i] < x){
			i++;
		}
		if(i < j){
			a[j--] = a[i];
		}
	}
	a[j] = x;
	quick_sort(begin,j-1);
	quick_sort(j+1,end);
}
int main() 
{
	int n;
	cin >> n;
	while(n != 0){
		for(int i=0; i<n;i++){
			cin >> a[i];
		}
		if(n==1){
			cout << a[0] << endl;
			cin >> n;
			continue;
		}
		if(n==2){
			cout << (a[0]+a[1])/2 << endl;
			cin >> n;
			continue;
		}
		quick_sort(0,n-1);
		if(n%2 == 0)cout << (a[n/2]+a[n/2-1])/2 << endl;
		else cout << a[n/2] << endl;
		cin >> n;
	}
	return 0;
}