#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
using namespace std;
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(!m)return 0;
        int n=matrix[0].size();
        int upper[n+1];
        int height[n+1];
        for(int i=0;i<n;i++)
            upper[i]=0;
        stack<pair<int,int> > S;
        int result=0;
        height[n]=0;
        for(int i=0;i<m;i++)
        {

            for(int j=0;j<n;j++)
                if(matrix[i][j]=='1')height[j]=upper[j]+1;
                else height[j]=0;
            for(int j=0;j<=n;j++)
            {
                if(S.empty()||height[j]>S.top().first)
                {
                    S.push(make_pair(height[j],j));
                }
                else
                {
                    while(!S.empty()&&height[j]<=S.top().first)
                    {
                        auto p=S.top();S.pop();
                        cout<<p.first<<" "<<p.second<<endl;
                        if(!S.empty())
                            result=max(result,p.first*(j-1-S.top().second));
                        else
                            result=max(result,p.first*j);
                    }
                    S.push(make_pair(height[j],j));
                }
            }
            while(!S.empty())S.pop();
            for(int j=0;j<n;j++)
                upper[j]=height[j];
        }
        return result;
    }
int main()
{
    cout<<(char)toupper('d');
    return 0;
}
