#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <stack>
using namespace std;
const int inf=1000000000;
int largestRectangleArea(vector<int>& height) {
    int sz=height.size();
    if(sz==0)return 0;
    height.push_back(0);
    stack<pair<int,int> >S;
    int result=0;
    S.push(make_pair(0,-1));
    for(int i=0;i<=sz;i++)
    {
        if(S.empty()||height[i]>=S.top().first)
        {
            S.push(make_pair(height[i],i));
        }
        else
        {
            while(!S.empty()&&S.top().first>height[i])
            {
                auto P=S.top();S.pop();
                result=max(result,P.first*(i-1-S.top().second));
            }
            S.push(make_pair(height[i],i));
        }
    }
    return result;
}
int main()
{
    vector<int> vv{5,4,3};
    cout<<largestRectangleArea(vv)<<endl;
    return 0;
}
