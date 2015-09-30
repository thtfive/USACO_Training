#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <cassert>
#include <queue>
#include <set>
#include <stack>
#include <cmath>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *first=head;
        ListNode *second=head;
        while (first && second)
        {
            cout<<"first:"<<first<<endl;
            cout<<"second:"<<second<<endl;
            second=second->next;
            if (first==second)
                return true;
            if (!second)return false;
            second=second->next;
            if (first==second)return true;
            first=first->next;
        }
        return false;
    }
};
int main()
{
    Solution obj;
    ListNode *root=new ListNode(1);
    root->next=new ListNode(2);
    cout<<obj.hasCycle(root)<<endl;

    return 0;
}


