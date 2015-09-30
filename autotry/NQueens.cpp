#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
    void backtracking(int row,int n,int *R,bool *a,bool *b,bool *c,vector<vector<string>> &result,const string & emptystr)
    {
        if(row==n)
        {
            vector<string> tmp;
            for(int i=0;i<n;i++)
            {
                string strtmp=emptystr;
                strtmp[R[i]]='Q';
                tmp.push_back(strtmp);
            }
            result.push_back(tmp);
            return;
        }
        for(int k=0;k<n;k++)
        {
            if(a[k]&&b[row+k]&&c[row-k+n])
            {
                R[row]=k;
                a[k]=0;b[row+k]=0;c[row-k+n]=0;
                backtracking(row+1,n,R,a,b,c,result,emptystr);
                a[k]=1;b[row+k]=1;c[row-k+n]=1;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        bool feasibleR[n];
        bool feasible2[2*n];
        bool feasible3[2*n];
        string emptystr="";
        for(int i=0;i<n;i++)
        {
            feasibleR[i]=1;
            feasible2[i]=1;
            feasible2[i+n]=1;
            feasible3[i]=1;
            feasible3[i+n]=1;
            emptystr+=".";
        }
        int R[n];
        vector<vector<string>> result;
        backtracking(0,n,R,feasibleR,feasible2,feasible3,result,emptystr);
        return result;
    }

int main()
{
    auto result=solveNQueens(8);
    for(auto &x:result)
    {
        for (auto &y:x)
            cout<<y<<endl;
        cout<<endl;
    }
    return 0;
}
