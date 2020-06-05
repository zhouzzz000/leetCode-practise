#include<iostream>
#include<cstring>
using namespace std;
typedef struct Node{
	char c;
	Node *left;
	Node *right;
}Node;

Node* createTree(char *s, int &index)
{
	if(s[index] == '\0' || s[index] == '#') return NULL;
	Node *n = new Node;
	n->c = s[index];
    n->left = createTree(s, ++index);
	n->right = createTree(s, ++index);
	return n;
}

void inOrderPrint(Node *root)
{
	if(root == NULL) return;
	if(root->left != NULL) inOrderPrint(root->left);
	cout << root->c << " ";
	if(root->right != NULL) inOrderPrint(root->right);
}

int main(){
	char s[100];
	while(cin >> s)
	{
		int index = 0;
		Node *root = createTree(s, index);
		inOrderPrint(root);
		cout << endl;
	}
	return 0;
}
