#include <iostream>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
const int inf=1000000000;
int Heap_Minimum(int *A,int &length)
{
    if(length<1)return -1;
    return A[1];
}

void Min_Heapfy(int *A,int i,int length)
{
    int l=i*2;
    int r=l+1;
    int smallest=i;
    if(l<=length&&A[smallest]>A[l])
    {
        smallest=l;
    }
    if(r<=length&&A[smallest]>A[r])
    {
        smallest=r;
    }
    if(smallest!=i)
    {
        int tmp=A[smallest];
        A[smallest]=A[i];
        A[i]=tmp;
        Min_Heapfy(A,smallest,length);
    }

}
int Heap_Extract_Min(int *A,int &length)
{
    if(length<1)return -1;
    int minnum=A[1];
    A[1]=A[length];
    length--;
    Min_Heapfy(A,1,length);
    return minnum;
}
void Heap_Decrease_Key(int *A,int i,int key)
{
    A[i]=key;
    while(i>1&&A[i/2]>A[i])
    {
        A[i]=A[i/2];
        A[i/2]=key;
        i/=2;
    }
}
void Heap_Insert(int *A,int &length,int key)
{
    A[++length]=inf;
    Heap_Decrease_Key(A,length,key);
}
void Min_Heap_Build(int *A,int length)
{
    for(int i=length/2;i>0;i--)
    {
        Min_Heapfy(A,i,length);
    }
}
int main()
{
    int A[]{0,52,25,5,2,63,2,1,0,59,35,26,73,22};
    int length=13;
    Min_Heap_Build(A,length);
    for(int i=1;i<=length;i++)
        cout<<A[i]<<" ";
    Heap_Extract_Min(A,length);
    cout<<endl;
    for(int i=1;i<=length;i++)
        cout<<A[i]<<" ";
    Heap_Insert(A,length,-1);
    cout<<endl;
    for(int i=1;i<=length;i++)
        cout<<A[i]<<" ";
    return 0;
}
