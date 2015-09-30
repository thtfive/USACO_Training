#include <iostream>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
const int inf=-1000000000;


void countSort(int *arr,int N,int base)
{
    int C[10]{0};
    for(int i=0;i<N;i++)
        C[(arr[i]/base)%10]++;

    for(int i=1;i<10;i++)
        C[i]+=C[i-1];

    int *B=new int[N];
    for(int i=N-1;i>=0;i--)
        B[--C[(arr[i]/base)%10]]=arr[i];

    for(int i=0;i<N;i++)
        arr[i]=B[i];
    delete []B;
}
void RadixSort(int *arr,int N)
{
    for(int base=1;base<10000000;base*=10)
    {
        countSort(arr,N,base);
    }
}
int main()
{
    int arr[10]{4523,3526,2427,14128,9741,48,67,47,5,10};
    RadixSort(arr,10);
    for(int x:arr)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}
