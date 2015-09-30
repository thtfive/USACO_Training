#define LOCAL
#include<iostream>
#include<fstream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int>ans;
        int n=nums.size();
        map<int,int>record;
        for(int i=0;i<n;i++)
        {
            if(record[target-nums[i]]==0)
            {
                record[nums[i]]=i+1;
            }
            else
            {
                ans.push_back(record[target-nums[i]]);
                ans.push_back(i+1);
                return ans;
            }
        }
    }
};


int main()
{
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif // LOCAL
    string tmp;
    map <int,int>m;
    m[-1]=3;
    cout<<m[-1]<<endl<<m[0]<<"\n";



    return 0;
}
