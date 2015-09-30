#include <iostream>
#include <fstream>
#include <algorithm>
using std::cin;
using std::cout;
using std::sort;
int main()
{
  //  freopen("input.txt","r",stdin);
    int m,n;
    int *dragons;
    int *knights;
    while(cin>>m>>n,m||n)
    {
        dragons=new int[m];
        knights=new int[n];
        for(int i=0;i<m;i++)
            cin>>dragons[i];
        for(int i=0;i<n;i++)
            cin>>knights[i];
        sort(dragons,dragons+m);
        sort(knights,knights+n);
        int cost=0;
        int k=0;
        int counter=0;
        for(int i=0;i<m;i++)
        {
            for(int& j=k;j<n;j++)
            {
                if(knights[j]>=dragons[i])
                {
                    cost+=knights[j];
                    counter++;
                    j++;
                    break;
                }
            }
        }
        if(counter==m)cout<<cost<<"\n";
        else cout<<"Loowater is doomed!\n";
        delete[] dragons;
        delete[] knights;
    }
    return 0;
}
