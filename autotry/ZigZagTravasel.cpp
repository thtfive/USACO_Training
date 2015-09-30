#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <cassert>
#include <queue>
#include <stack>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root==nullptr)return result;
        queue<pair<TreeNode *,int> >Q;
        stack<int>Stk;
        Q.push(make_pair(root,0));
        vector<int>tmp;
        while(!Q.empty())
        {
            auto P=Q.front();Q.pop();
            if (P.second%2)
            {
                if(tmp.size()>0)
                {
                    result.push_back(tmp);
                    tmp.clear();
                }
                Stk.push(P.first->val);
            }
            else
            {
                if (!Stk.empty())
                {
                    while (!Stk.empty())
                    {
                        tmp.push_back(Stk.top());
                        Stk.pop();
                    }
                    result.push_back(tmp);
                    tmp.clear();
                }
                tmp.push_back(P.first->val);
            }
            if (P.first->left)
                Q.push(make_pair(P.first->left,P.second+1));
            if (P.first->right)
                Q.push(make_pair(P.first->right,P.second+1));

        }
        if (!Stk.empty())
        {
            while (!Stk.empty())
            {
                tmp.push_back(Stk.top());
                Stk.pop();
            }
            result.push_back(tmp);
            tmp.clear();
        }
        if (tmp.size()>0)result.push_back(tmp);
        tmp.clear();
        return result;
    }
};



int main()
{
    TreeNode *root=new TreeNode(3);
    cout<<level<<endl;
//    root->left=new TreeNode(9);
//    root->right=new TreeNode(20);
//    auto p=root->right;
//    p->left=new TreeNode(15);
//    p->right=new TreeNode(7);
    Solution obj;
    auto result=obj.zigzagLevelOrder(root);
    for(auto &y:result)
        for (auto &x:y)
            cout<<x<<" ";
   // for (int i=1;i<=10;i++)



    return 0;
}


