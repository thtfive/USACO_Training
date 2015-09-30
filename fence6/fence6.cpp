/*
ID:thtfive
LANG:C++
TASK:fence6
*/
#include<iostream>
#include<fstream>
using namespace std;
#define Max_num 102
int side_Map[Max_num][Max_num];
int side_Node[Max_num];
bool mark[Max_num];
int N;

void heapfy(int *intarray,int start,int length,int *real_index,int *heap_index)
{
   int left=start*2;
   int right=start*2+1;
   int smallest=start;
   if (left<=length&&intarray[left]<intarray[smallest])
        smallest=left;
   if(right<=length&&intarray[right]<intarray[smallest])
        smallest=right;
   if(smallest!=start)
   {
       int tmp=intarray[start];
       intarray[start]=intarray[smallest];
       intarray[smallest]=tmp;
       tmp=real_index[smallest];
       real_index[smallest]=real_index[start];
       real_index[start]=tmp;

       heap_index[real_index[start]]=start;
       heap_index[real_index[smallest]]=smallest;

       heapfy(intarray,smallest,length,real_index,heap_index);

   }
}

int extra_min(int *heap,int &length,int &value,int *real_index,int *heap_index)
{
    int result=real_index[1];
    value=heap[1];
    int tmp=heap[length];
    heap[1]=heap[length];
    tmp=real_index[length];
    real_index[length]=real_index[1];
    real_index[1]=tmp;
    heap_index[real_index[length]]=length;
    heap_index[real_index[1]]=1;

    heap[length]=tmp;
    length--;
    heapfy(heap,1,length,real_index,heap_index);
    return result;
}

int solution(int startnode)
{
    int length=N;

    int flag[N+1];
    for (int i=1;i<=N;i++)
        flag[i]=false;

    int minHeap[N+1];
    int real_index[N+1];
    int heap_index[N+1];

    for (int i=1;i<=N;i++)
    {
        minHeap[i]=1000000;
        real_index[i]=i;
        heap_index[i]=i;
    }

    minHeap[1]=side_Node[startnode];

    heap_index[startnode]=1;
    heap_index[1]=startnode;
    real_index[startnode]=1;
    real_index[1]=startnode;
    int distant;

    extra_min(minHeap,length,distant,real_index,heap_index);
    flag[startnode]=true;

    for (int i=1;i<=side_Map[startnode][0];i++)
    {
        int idx=side_Map[startnode][i];
        if (minHeap[heap_index[idx]]>distant+side_Node[idx])
        {
            minHeap[heap_index[idx]]=distant+side_Node[idx];
            for (int tmp=heap_index[idx];tmp>0;tmp/=2)
                heapfy(minHeap,tmp,length,real_index,heap_index);
        }
    }

    for (int num=2;num<=N;num++)
    {
        int diatant=0;
        int node=extra_min(minHeap,length,distant,real_index,heap_index);

        flag[node]=true;
        for (int k=N;k>=N+1-side_Map[startnode][N+1];k--)
        {
            if(node==side_Map[startnode][k])
            {
                return distant;
            }
        }

        for (int i=1;i<=side_Map[node][0];i++)
        {
            int idx=side_Map[node][i];
            if (!flag[idx]&&minHeap[heap_index[idx]]>distant+side_Node[idx])
            {
                minHeap[heap_index[idx]]=distant+side_Node[idx];
                for (int tmp=heap_index[idx];tmp>0;tmp/=2)
                    heapfy(minHeap,tmp,length,real_index,heap_index);
            }
        }

        for (int i=N;i>=N+1-side_Map[node][N+1];i--)
        {
            int idx=side_Map[node][i];
            if (!flag[idx]&&minHeap[heap_index[idx]]>distant+side_Node[idx])
            {
                minHeap[heap_index[idx]]=distant+side_Node[idx];
                for (int tmp=heap_index[idx];tmp>0;tmp/=2)
                    heapfy(minHeap,tmp,length,real_index,heap_index);
            }
        }
    }
    return 0;
}

int main()
{
    ifstream fin("fence6.in");
    ofstream fout("fence6.out");
    fin>>N;
    for (int i=1;i<=N;i++)
    {
        for (int j=1;j<=N;j++)
        {
            side_Map[i][j]=false;
        }
    }

    for (int i=1;i<=N;i++)
    {
        int node;
        int weight;
        int first;
        int second;
        fin>>node>>weight>>first>>second;
        side_Node[node]=weight;
        int idx;
        side_Map[node][0]=first;
        side_Map[node][N+1]=second;
        for(int k=1;k<=first;k++)
        {
            fin>>idx;
            side_Map[node][k]=idx;
        }
        for (int k=N;k>N-second;k--)
        {
            fin>>idx;
            side_Map[node][k]=idx;
        }
    }

    int result=solution(1);
    for (int i=2;i<=N;i++)
    {
        int tmp=solution(i);
        result=result<tmp?result:tmp;
    }
    cout<<result<<"\n";
    fout<<result<<"\n";

    return 0;
}
