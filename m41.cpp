#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
class MedianFinder {
public:
	int count;
	int balance;
    priority_queue<int> max_heap;                                 // max heap
    priority_queue<int, vector<int>, greater<int> > min_heap;     // min heap
    /** initialize your data structure here. */
    MedianFinder() {
		balance = 0;
		count = 0;
    }
    
    void addNum(int num) {
		++count;
		if(count == 1)
		{
			max_heap.push(num);
			++balance;
			return ;
		}
		if(num <= max_heap.top())
		{
			max_heap.push(num);
			++balance;
		}else{
			min_heap.push(num);
			--balance;
		}
		
		int flag = count%2;
		if(balance > flag && !max_heap.empty())
		{
			int x = max_heap.top();
			min_heap.push(x);
			max_heap.pop();
			balance-=2;
		}
		else if(balance < flag && !min_heap.empty())
		{
			int x = min_heap.top();
			max_heap.push(x);
			min_heap.pop();
			balance+=2;
		}
    }
    
    double findMedian() {
		int flag = count%2;
		if(flag == 1)
		{
			return (double)max_heap.top();
		}else{
			return (max_heap.top()+min_heap.top())/2.0;
		}
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
 
 int main()
{
	MedianFinder finder;
	while(true)
	{
		char c;
		cin >> c;
		int x;
		if(c == 'a')
		{
			cin >> x;
			finder.addNum(x);
		}
		if(c == 'f')
		{
			double mid = finder.findMedian();
			cout << mid << endl;
		}
		if(c == 'q')
		{
			break;
		}
	}
	
	return 0;
}