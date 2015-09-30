#include <iostream>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
const int inf=-1000000000;

int lowerbound(vector<int>& nums,int target,int start,int finish)
{
    if(start>finish)return -1;
    if(start==finish)
    {
        return nums[start]==target?start:-1;
    }
    int mid=(start+finish)>>1;
    if(target<=nums[mid])
        return lowerbound(nums,target,start,mid);
    else
        return lowerbound(nums,target,mid+1,finish);
}
int upperbound(vector<int>& nums,int target,int start,int finish)
{
    if(start>finish)return -1;
    if(start==finish)
    {
        return nums[start]==target?start:-1;
    }
    int mid=(start+finish+1)>>1;
    if(target>=nums[mid])
        return upperbound(nums,target,mid,finish);
    else
        return upperbound(nums,target,start,mid-1);
}
vector<int> searchRange(vector<int>& nums, int target) {
    int low=lowerbound(nums,target,0,nums.size()-1);
    int upper=upperbound(nums,target,0,nums.size()-1);
    vector<int>result(2);
    result[0]=low;
    result[1]=upper;
    return result;
}
int main()
{
    vector<int>arr{0,0,0,0,1,2,3,3,4,5,6,6,7,8,8,8,9,9,10,10,11,11};
    auto result=searchRange(arr,0);
    cout<<result[0]<<" "<<result[1]<<endl;
    return 0;
}
