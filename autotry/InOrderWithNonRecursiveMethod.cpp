#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <cstring>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode* root) {
    vector<int>result;
    if(!root)return result;
    stack<TreeNode*>S;
    S.push(root);
    while(!S.empty())
    {
        auto p=S.top();
        S.pop();
        if(p->left||p->right)
        {
            if(p->right)S.push(p->right);
            TreeNode *newnode=new TreeNode(p->val);
            S.push(newnode);
            if(p->left)S.push(p->left);
        }
        else
        {
            result.push_back(p->val);
        }
    }
    return result;
}
int main()
{
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    inorderTraversal(root);
    cout<<"good\n";
    return 0;
}
