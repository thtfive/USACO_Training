#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <cassert>
using namespace std;

class Solution {
public:
    void update(int *place, int * base,int *num,int idx,int N)
    {
        int mindata=INT_MAX;
        for (int i=0;i<N;i++)
        {
            while (num[place[i]]*base[i]<=num[idx-1])
                place[i]++;
            mindata=mindata<num[place[i]]*base[i]?mindata:num[place[i]]*base[i];
        }
        num[idx]=mindata;
    }
    int nthUglyNumber(int n) {
        int num[n+1];
        num[1]=1;
        int place[3]{1,1,1};
        int base[3]{2,3,5};
        for (int i=2; i<=n; i++)
        {
            update(place,base,num,i,3);
        }
        return num[n];
    }
};

int main()
{
    Solution obj;
   // for (int i=1;i<=10;i++)
    cout<<obj.nthUglyNumber(1000)<<endl;


    return 0;
}


