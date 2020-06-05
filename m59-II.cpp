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

class MaxQueue {
public:
    stack<int> s;
    queue<int> q;
    int size;
    MaxQueue() {
        size = 0;
    }
    
    int max_value() {
        if(size == 0) return -1;
        return s.top();
    }
    
    void push_back(int value) {
        if(size == 0){
            s.push(value);
        }
        else if(value >= s.top())
        {
            s.push(value);
        }
        q.push(value);
    }
    
    int pop_front() {
        if(q.front() == s.top())
        {
            s.pop();
        }
        int x = q.front();
        q.pop();
        return x;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

int main() {
   MaxQueue* obj = new MaxQueue();
   int param_1 = obj->max_value();
   int value;
   cin >> value;
   obj->push_back(value);
   int param_3 = obj->pop_front();
   return 0;
}