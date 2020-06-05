/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<iostream>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<sstream>
using namespace std;
typedef struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;
void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
          output += "null, ";
          continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if(preorder.size() <=0 ) return NULL;
		int curValue = preorder[0];
		TreeNode* root = new TreeNode(curValue);
		int index = -1;
		for(int i=0; i<inorder.size(); i++)
		{
			if(inorder[i] == curValue)
			{
				index = i;
				break;
			}
		}
		if(index < 0) return NULL;
		if(index < inorder.size()-1) 
			root->right = buildNode(preorder, inorder, 1+index, preorder.size()-1, index+1, inorder.size()-1);
		if(index > 0) 
			root->left = buildNode(preorder, inorder, 1, index, 0, index-1);
		return root;
    }
	TreeNode* buildNode(vector<int>& preorder, vector<int>& inorder, int preBegin, int preEnd, int inBegin, int inEnd)
	{
		if(preBegin > preEnd || inBegin > inEnd) return NULL;
		if(preEnd > preorder.size() || inEnd > inorder.size()) return NULL;
		int culValue = preorder[preBegin];
		TreeNode* node = new TreeNode(culValue);
		if(preBegin == preEnd || inBegin == inEnd) return node;
		int index = -1;
		for(int i=inBegin; i<=inEnd; i++)
		{
			if(inorder[i] == culValue)
			{
				index = i;
				break;
			}
		}
		if(index < 0) return NULL;
		int rLen = inEnd-index;
		int lLen = index-inBegin;
		if(rLen>0) 
			node->right = buildNode(preorder, inorder, preBegin+lLen+1, preEnd, index+1, inEnd);
		if(lLen>0) 
			node->left = buildNode(preorder, inorder, preBegin+1, preBegin+lLen, inBegin, index-1);
		return node;
	}
};


int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> preorder = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> inorder = stringToIntegerVector(line);
        
        TreeNode* ret = Solution().buildTree(preorder, inorder);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}