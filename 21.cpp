#include<iostream>
using namespace std;
class Node
{
public:
	int val;
	int cur_min;
	Node *next;
	Node *prev;
	Node(int x){
		val=x;
		cur_min = x;
		next = NULL;
		prev = NULL;
	}
};
class MinStack{
public:
	Node* top_node;
	int count;
	Node* head;
	MinStack(){
		count=0;
		head=NULL;
		top_node=NULL;
	}
	void push(int x)
	{
		if(count == 0)
		{
			head=new Node(x);
			top_node=head;
			++count;
		}else{
			Node* node = new Node(x);
			if(top_node->cur_min < x)
			{
				node->cur_min = top_node->cur_min;
			}
			top_node->next = node;
			node->prev = top_node;
			top_node = top_node->next;
			++count;
		}
	}
	void pop(){
		if(count == 0)return;
		if(count == 1)
		{
			head=NULL;
			top_node=NULL;
			--count;
			return;
		}
		top_node = top_node->prev;
		top_node->next = NULL;
		--count;
	}
	int top(){
		if(count==0)return 0;
		return top_node->val;
	}
	int min(){
		if(count==0) return 0;
		return top_node->cur_min;
	}
};
int main(){
	string s;
	MinStack st;
	while(cin>>s)
	{
		if(s=="push")
		{
			int x;
			cin >> x;
			st.push(x);
		}
		if(s=="pop")
		{
			st.pop();
		}if(s=="top")
		{
			int x;
			x  = st.top();
			cout << x << endl;
		}if(s=="min")
		{
			int x;
			x = st.min();
			cout << x << endl;
		}
	}
}